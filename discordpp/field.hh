//
// Created by Aidan on 10/13/2021.
//

#pragma once
#if __cplusplus >= 202002L
#include <concepts>
#endif

struct nulled_t {};
inline static const nulled_t nulled;
struct omitted_t {};
inline static const omitted_t omitted;
struct uninitialized_t {};
inline static const uninitialized_t uninitialized;

template <typename T> class field {
  protected:
    enum state { uninitialized_e, present_e, omitted_e, nulled_e };

    field(std::unique_ptr<T> t, state s) : t_(std::move(t)), s_(s) {}

    std::unique_ptr<T> t_;
    state s_;

  public:
    field() : t_(nullptr), s_(uninitialized_e) {}
    field(uninitialized_t) : t_(nullptr), s_(uninitialized_e) {}
    field(const T &t) : t_(std::make_unique<T>(t)), s_(present_e) {}
    field(const field<T> &f)
        : t_(f.t_ ? std::make_unique<T>(*f.t_) : nullptr), s_(f.s_) {}
#if __cplusplus >= 202002L

    template <typename F>
    field(const F &f) requires std::convertible_to<F, T>
        : t_(std::make_unique<T>(f)) {}

#else

    template<size_t N, typename = std::enable_if<std::is_same_v<T, std::string>>>
    field(char const (&t)[N])
        : t_(std::make_unique<T>(t)) {}

#endif

    operator bool() const { return s_ == present_e; }
    T *operator->() {
        if (s_ != present_e) {
            throw std::logic_error("This field is not present.");
        }
        return &*t_;
    }
    const T *operator->() const {
        if (s_ != present_e) {
            throw std::logic_error("This field is not present.");
        }
        return &*t_;
    }
    T &operator*() {
        if (s_ != present_e) {
            throw std::logic_error("This field is not present.");
        }
        return *t_;
    }
    const T &operator*() const {
        if (s_ != present_e) {
            throw std::logic_error("This field is not present.");
        }
        return *t_;
    }
    field<T> &operator=(const T &t) {
        t_.reset(new T(t));
        s_ = present_e;
        return *this;
    }
    field<T> &operator=(const field<T> &f) {
        t_.reset(f.t_ ? new T(*f.t_) : nullptr);
        s_ = present_e;
        return *this;
    }

    [[nodiscard]] bool is_uninitialized() const {
        return s_ == uninitialized_e;
    }
    [[nodiscard]] bool is_present() const { return s_ == present_e; }
    [[nodiscard]] bool is_omitted() const { return s_ == omitted_e; }
    [[nodiscard]] bool is_null() const { return s_ == nulled_e; }

    friend void to_json(nlohmann::json &j, const field<T> &f) {
        switch (f.s_) {
        case uninitialized_e:
            throw std::logic_error(
                "You can't convert an uninitialized field to JSON");
            break;
        case present_e:
            // if constexpr (std::is_enum_v<T>) {
            //     j = static_cast<typename
            //     std::underlying_type<T>::type>(*f.t_);
            // } else {
            j = *f.t_;
            //}
            break;
        case nulled_e:
            j = nullptr;
            break;
        case omitted_e:
            throw std::logic_error(
                "You can't convert an omitted field to JSON");
            break;
        }
    }
    friend void from_json(const nlohmann::json &j, field<T> &f) {
        if (j.is_null()) {
            f.t_ = nullptr;
            f.s_ = nulled_e;
        } else {
            f.t_ = std::make_unique<T>(j.get<T>());
            f.s_ = present_e;
        }
    }
};
template <typename T> class nullable_field : public field<T> {
  public:
    nullable_field() : field<T>(nullptr, field<T>::uninitialized_e) {}
    nullable_field(const T &t) : field<T>(t) {}
    nullable_field(uninitialized_t)
        : field<T>(nullptr, field<T>::uninitialized_e) {}
    nullable_field(nulled_t) : field<T>(nullptr, field<T>::nulled_e) {}
    nullable_field(std::nullptr_t) : field<T>(nullptr, field<T>::nulled_e) {}
    virtual nullable_field &operator=(nulled_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::nulled_e;
        return *this;
    }
    virtual nullable_field &operator=(std::nullptr_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::nulled_e;
        return *this;
    }
};
template <typename T> class omittable_field : public field<T> {
  public:
    omittable_field() : field<T>(nullptr, field<T>::omitted_e) {}
    omittable_field(const T &t) : field<T>(t) {}
    omittable_field(uninitialized_t)
        : field<T>(nullptr, field<T>::uninitialized_e) {}
    omittable_field(omitted_t) : field<T>(nullptr, field<T>::omitted_e) {}
    virtual omittable_field &operator=(omitted_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::omitted_e;
        return *this;
    }
};
template <typename T> class nullable_omittable_field : public field<T> {
  public:
    nullable_omittable_field() : field<T>(nullptr, field<T>::omitted_e) {}
    nullable_omittable_field(const T &t) : field<T>(t) {}
    nullable_omittable_field(uninitialized_t)
        : field<T>(nullptr, field<T>::uninitialized_e) {}
    nullable_omittable_field(nulled_t)
        : field<T>(nullptr, field<T>::nulled_e) {}
    nullable_omittable_field(std::nullptr_t)
        : field<T>(nullptr, field<T>::nulled_e) {}
    nullable_omittable_field(omitted_t)
        : field<T>(nullptr, field<T>::omitted_e) {}
    virtual nullable_omittable_field &operator=(nulled_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::nulled_e;
        return *this;
    }
    virtual nullable_omittable_field &operator=(std::nullptr_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::nulled_e;
        return *this;
    }
    virtual nullable_omittable_field &operator=(omitted_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::omitted_e;
        return *this;
    }
};
