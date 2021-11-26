//
// Created by Aidan on 11/9/2021.
//

#ifdef DEFINE_OBJECT_OPEN
#error There is already an open Object definition
#endif
#define DEFINE_OBJECT_OPEN

#ifndef Name
#error An object needs a name
#endif

class Name
#ifdef Parent
    : public Parent
#endif
{
  public:
#define field(...) ML99_OVERLOAD(field_, __VA_ARGS__)
#define field_2(TYPE, NAME) ML99_JUST(field<TYPE> NAME = uninitialized)
#define field_3(TYPE, KEY, NAME) ML99_JUST(field<TYPE> NAME = uninitialized)
#define nullable_field(...) ML99_OVERLOAD(nullable_field_, __VA_ARGS__)
#define nullable_field_2(TYPE, NAME) ML99_JUST(nullable_field<TYPE> NAME = uninitialized)
#define nullable_field_3(TYPE, KEY, NAME) ML99_JUST(nullable_field<TYPE> NAME = uninitialized)
#define omittable_field(...) ML99_OVERLOAD(omittable_field_, __VA_ARGS__)
#define omittable_field_2(TYPE, NAME) ML99_JUST(omittable_field<TYPE> NAME = omitted)
#define omittable_field_3(TYPE, KEY, NAME) ML99_JUST(omittable_field<TYPE> NAME = omitted)
#define nullable_omittable_field(...) ML99_OVERLOAD(nullable_omittable_field_, __VA_ARGS__)
#define nullable_omittable_field_2(TYPE, NAME) ML99_JUST(nullable_omittable_field<TYPE> NAME = omitted)
#define nullable_omittable_field_3(TYPE, KEY, NAME) ML99_JUST(nullable_omittable_field<TYPE> NAME = omitted)
#define static_field(...) ML99_OVERLOAD(static_field_, __VA_ARGS__)
#define static_field_3(TYPE, NAME, VALUE) ML99_NOTHING()
#define static_field_4(TYPE, KEY, NAME, VALUE) ML99_NOTHING()
#define static_nullable_field(...) ML99_OVERLOAD(static_nullable_field_, __VA_ARGS__)
#define static_nullable_field_3(TYPE, NAME, VALUE) ML99_NOTHING()
#define static_nullable_field_4(TYPE, KEY, NAME, VALUE) ML99_NOTHING()
#define static_omittable_field(...) ML99_OVERLOAD(static_omittable_field_, __VA_ARGS__)
#define static_omittable_field_3(TYPE, NAME, VALUE) ML99_NOTHING()
#define static_omittable_field_4(TYPE, KEY, NAME, VALUE) ML99_NOTHING()
#define static_nullable_omittable_field(...) ML99_OVERLOAD(static_nullable_omittable_field_, __VA_ARGS__)
#define static_nullable_omittable_field_3(TYPE, NAME, VALUE) ML99_NOTHING()
#define static_nullable_omittable_field_4(TYPE, KEY, NAME, VALUE) ML99_NOTHING()
#define static_nullable_omittable_field(...) ML99_OVERLOAD(static_nullable_omittable_field_, __VA_ARGS__)
#define static_nullable_omittable_field_3(TYPE, NAME, VALUE) ML99_NOTHING()
#define static_nullable_omittable_field_4(TYPE, KEY, NAME, VALUE) ML99_NOTHING()
#define forward_field(...) ML99_OVERLOAD(forward_field_, __VA_ARGS__)
#define forward_field_2(TYPE, NAME) ML99_JUST(field<TYPE> NAME = uninitialized)
#define forward_field_3(TYPE, KEY, NAME) ML99_JUST(field<TYPE> NAME = uninitialized)
#define forward_nullable_field(...) ML99_OVERLOAD(forward_nullable_field_, __VA_ARGS__)
#define forward_nullable_field_2(TYPE, NAME) ML99_JUST(nullable_field<TYPE> NAME = uninitialized)
#define forward_nullable_field_3(TYPE, KEY, NAME) ML99_JUST(nullable_field<TYPE> NAME = uninitialized)
#define forward_omittable_field(...) ML99_OVERLOAD(forward_omittable_field_, __VA_ARGS__)
#define forward_omittable_field_2(TYPE, NAME) ML99_JUST(omittable_field<TYPE> NAME = omitted)
#define forward_omittable_field_3(TYPE, KEY, NAME) ML99_JUST(omittable_field<TYPE> NAME = omitted)
#define forward_nullable_omittable_field(...) ML99_OVERLOAD(forward_nullable_omittable_field_, __VA_ARGS__)
#define forward_nullable_omittable_field_2(TYPE, NAME) ML99_JUST(nullable_omittable_field<TYPE> NAME = omitted)
#define forward_nullable_omittable_field_3(TYPE, KEY, NAME) ML99_JUST(nullable_omittable_field<TYPE> NAME = omitted)
#define exclude_field(...) ML99_OVERLOAD(NAME_, __VA_ARGS__)
#define exclude_field_1(NAME) ML99_NOTHING()
#define exclude_field_2(KEY, NAME) ML99_NOTHING()
    Name(ML99_LIST_EVAL_COMMA_SEP(ML99_listMap(v(ML99_maybeUnwrap), ML99_listFilter(v(ML99_isJust), ML99_list(v(Fields))))))
#undef exclude_field_2
#undef exclude_field_1
#undef exclude_field
#undef forward_nullable_omittable_field_3
#undef forward_nullable_omittable_field_2
#undef forward_nullable_omittable_field
#undef forward_omittable_field_3
#undef forward_omittable_field_2
#undef forward_omittable_field
#undef forward_nullable_field_3
#undef forward_nullable_field_2
#undef forward_nullable_field
#undef forward_field_3
#undef forward_field_2
#undef forward_field
#undef static_nullable_omittable_field_4
#undef static_nullable_omittable_field_3
#undef static_nullable_omittable_field
#undef static_omittable_field_4
#undef static_omittable_field_3
#undef static_omittable_field
#undef static_nullable_field_4
#undef static_nullable_field_3
#undef static_nullable_field
#undef static_field_4
#undef static_field_3
#undef static_field
#undef nullable_omittable_field_3
#undef nullable_omittable_field_2
#undef nullable_omittable_field
#undef omittable_field_3
#undef omittable_field_2
#undef omittable_field
#undef nullable_field_3
#undef nullable_field_2
#undef nullable_field
#undef field_3
#undef field_2
#undef field
#ifndef Parent
#define field(...) ML99_OVERLOAD(field_, __VA_ARGS__)
#define field_2(TYPE, NAME) ML99_JUST(NAME(NAME))
#define field_3(TYPE, KEY, NAME) ML99_JUST(NAME(NAME))
#define nullable_field(...) ML99_OVERLOAD(nullable_field_, __VA_ARGS__)
#define nullable_field_2(TYPE, NAME) ML99_JUST(NAME(NAME))
#define nullable_field_3(TYPE, KEY, NAME) ML99_JUST(NAME(NAME))
#define omittable_field(...) ML99_OVERLOAD(omittable_field_, __VA_ARGS__)
#define omittable_field_2(TYPE, NAME) ML99_JUST(NAME(NAME))
#define omittable_field_3(TYPE, KEY, NAME) ML99_JUST(NAME(NAME))
#define nullable_omittable_field(...) ML99_OVERLOAD(nullable_omittable_field_, __VA_ARGS__)
#define nullable_omittable_field_2(TYPE, NAME) ML99_JUST(NAME(NAME))
#define nullable_omittable_field_3(TYPE, KEY, NAME) ML99_JUST(NAME(NAME))
        : ML99_LIST_EVAL_COMMA_SEP(ML99_listMap(v(ML99_maybeUnwrap), ML99_listFilter(v(ML99_isJust), ML99_list(v(Fields)))))
#undef nullable_omittable_field_3
#undef nullable_omittable_field_2
#undef nullable_omittable_field
#undef omittable_field_3
#undef omittable_field_2
#undef omittable_field
#undef nullable_field_3
#undef nullable_field_2
#undef nullable_field
#undef field_3
#undef field_2
#undef field
#else
#define static_field(...) ML99_OVERLOAD(static_field_, __VA_ARGS__)
#define static_field_3(TYPE, NAME, VALUE) ML99_JUST(VALUE)
#define static_field_4(TYPE, KEY, NAME, VALUE) ML99_JUST(VALUE)
#define static_nullable_field(...) ML99_OVERLOAD(static_nullable_field_, __VA_ARGS__)
#define static_nullable_field_3(TYPE, NAME, VALUE) ML99_JUST(VALUE)
#define static_nullable_field_4(TYPE, KEY, NAME, VALUE) ML99_JUST(VALUE)
#define static_omittable_field(...) ML99_OVERLOAD(static_omittable_field_, __VA_ARGS__)
#define static_omittable_field_3(TYPE, NAME, VALUE) ML99_JUST(VALUE)
#define static_omittable_field_4(TYPE, KEY, NAME, VALUE) ML99_JUST(VALUE)
#define static_nullable_omittable_field(...) ML99_OVERLOAD(static_nullable_omittable_field_, __VA_ARGS__)
#define static_nullable_omittable_field_3(TYPE, NAME, VALUE) ML99_JUST(VALUE)
#define static_nullable_omittable_field_4(TYPE, KEY, NAME, VALUE) ML99_JUST(VALUE)
#define forward_field(...) ML99_OVERLOAD(forward_field_, __VA_ARGS__)
#define forward_field_2(TYPE, NAME) ML99_JUST(NAME)
#define forward_field_3(TYPE, KEY, NAME) ML99_JUST(NAME)
#define forward_nullable_field(...) ML99_OVERLOAD(forward_nullable_field_, __VA_ARGS__)
#define forward_nullable_field_2(TYPE, NAME) ML99_JUST(NAME)
#define forward_nullable_field_3(TYPE, KEY, NAME) ML99_JUST(NAME)
#define forward_omittable_field(...) ML99_OVERLOAD(forward_omittable_field_, __VA_ARGS__)
#define forward_omittable_field_2(TYPE, NAME) ML99_JUST(NAME)
#define forward_omittable_field_3(TYPE, KEY, NAME) ML99_JUST(NAME)
#define forward_nullable_omittable_field(...) ML99_OVERLOAD(forward_nullable_omittable_field_, __VA_ARGS__)
#define forward_nullable_omittable_field_2(TYPE, NAME) ML99_JUST(NAME)
#define forward_nullable_omittable_field_3(TYPE, KEY, NAME) ML99_JUST(NAME)
#define exclude_field(...) ML99_OVERLOAD(exclude_field_, __VA_ARGS__)
#define exclude_field_1(NAME) ML99_JUST(omitted)
#define exclude_field_2(KEY, NAME) ML99_JUST(omitted)
        : Parent(ML99_LIST_EVAL_COMMA_SEP(ML99_listMap(v(ML99_maybeUnwrap), ML99_listFilter(v(ML99_isJust), ML99_list(v(Fields))))))
#undef exclude_field_2
#undef exclude_field_1
#undef exclude_field
#undef forward_nullable_omittable_field_3
#undef forward_nullable_omittable_field_2
#undef forward_nullable_omittable_field
#undef forward_omittable_field_3
#undef forward_omittable_field_2
#undef forward_omittable_field
#undef forward_nullable_field_3
#undef forward_nullable_field_2
#undef forward_nullable_field
#undef forward_field_3
#undef forward_field_2
#undef forward_field
#undef static_nullable_omittable_field_4
#undef static_nullable_omittable_field_3
#undef static_nullable_omittable_field
#undef static_omittable_field_4
#undef static_omittable_field_3
#undef static_omittable_field
#undef static_nullable_field_4
#undef static_nullable_field_3
#undef static_nullable_field
#undef static_field_4
#undef static_field_3
#undef static_field
#endif
    {}
    Name(const json &j) { from_json(j, *this); }

#ifndef Parent
#define field(...) ML99_OVERLOAD(field_, __VA_ARGS__)
#define field_2(TYPE, NAME) ML99_JUST(field<TYPE> NAME;)
#define field_3(TYPE, KEY, NAME) ML99_JUST(field<TYPE> NAME;)
#define nullable_field(...) ML99_OVERLOAD(nullable_field_, __VA_ARGS__)
#define nullable_field_2(TYPE, NAME) ML99_JUST(nullable_field<TYPE> NAME;)
#define nullable_field_3(TYPE, KEY, NAME) ML99_JUST(nullable_field<TYPE> NAME;)
#define omittable_field(...) ML99_OVERLOAD(omittable_field_, __VA_ARGS__)
#define omittable_field_2(TYPE, NAME) ML99_JUST(omittable_field<TYPE> NAME;)
#define omittable_field_3(TYPE, KEY, NAME) ML99_JUST(omittable_field<TYPE> NAME;)
#define nullable_omittable_field(...) ML99_OVERLOAD(nullable_omittable_field_, __VA_ARGS__)
#define nullable_omittable_field_2(TYPE, NAME) ML99_JUST(nullable_omittable_field<TYPE> NAME;)
#define nullable_omittable_field_3(TYPE, KEY, NAME) ML99_JUST(nullable_omittable_field<TYPE> NAME;)
#define static_field(...) ML99_OVERLOAD(static_field_, __VA_ARGS__)
#define static_field_3(TYPE, NAME, VALUE) ML99_JUST(const field<TYPE> NAME = Parent::NAME;)
#define static_field_4(TYPE, KEY, NAME, VALUE)  ML99_JUST(const field<TYPE> NAME = Parent::NAME;)
#define static_nullable_field(...) ML99_OVERLOAD(static_nullable_field_, __VA_ARGS__)
#define static_nullable_field_3(TYPE, NAME, VALUE) ML99_JUST(const nullable_field<TYPE> NAME = Parent::NAME;)
#define static_nullable_field_4(TYPE, KEY, NAME, VALUE) ML99_JUST(const nullable_field<TYPE> NAME = Parent::NAME;)
#define static_omittable_field(...) ML99_OVERLOAD(static_omittable_field_, __VA_ARGS__)
#define static_omittable_field_3(TYPE, NAME, VALUE) ML99_JUST(const omittable_field<TYPE> NAME = Parent::NAME;)
#define static_omittable_field_4(TYPE, KEY, NAME, VALUE) ML99_JUST(const omittable_field<TYPE> NAME = Parent::NAME;)
#define static_nullable_omittable_field(...) ML99_OVERLOAD(static_nullable_omittable_field_, __VA_ARGS__)
#define static_nullable_omittable_field_3(TYPE, NAME, VALUE) ML99_JUST(const nullable_omittable_field<TYPE> NAME = Parent::NAME;)
#define static_nullable_omittable_field_4(TYPE, KEY, NAME, VALUE) ML99_JUST(const nullable_omittable_field<TYPE> NAME = Parent::NAME;)
#define forward_field(...) ML99_OVERLOAD(forward_field_, __VA_ARGS__)
#define forward_field_2(TYPE, NAME) ML99_NOTHING()
#define forward_field_3(TYPE, KEY, NAME) ML99_NOTHING()
#define forward_nullable_field(...) ML99_OVERLOAD(forward_nullable_field_, __VA_ARGS__)
#define forward_nullable_field_2(TYPE, NAME) ML99_NOTHING()
#define forward_nullable_field_3(TYPE, KEY, NAME) ML99_NOTHING()
#define forward_omittable_field(...) ML99_OVERLOAD(forward_omittable_field_, __VA_ARGS__)
#define forward_omittable_field_2(TYPE, NAME) ML99_NOTHING()
#define forward_omittable_field_3(TYPE, KEY, NAME) ML99_NOTHING()
#define forward_nullable_omittable_field(...) ML99_OVERLOAD(forward_nullable_omittable_field_, __VA_ARGS__)
#define forward_nullable_omittable_field_2(TYPE, NAME) ML99_NOTHING()
#define forward_nullable_omittable_field_3(TYPE, KEY, NAME) ML99_NOTHING()
#define exclude_field(...) ML99_OVERLOAD(NAME_, __VA_ARGS__)
#define exclude_field_1(NAME) ML99_JUST(private: using Parent::NAME; public:)
#define exclude_field_2(KEY, NAME) ML99_JUST(private: using Parent::NAME; public:)
    ML99_LIST_EVAL(ML99_listMap(v(ML99_maybeUnwrap), ML99_listFilter(v(ML99_isJust), ML99_list(v(Fields)))))
#undef exclude_field_2
#undef exclude_field_1
#undef exclude_field
#undef forward_nullable_omittable_field_3
#undef forward_nullable_omittable_field_2
#undef forward_nullable_omittable_field
#undef forward_omittable_field_3
#undef forward_omittable_field_2
#undef forward_omittable_field
#undef forward_nullable_field_3
#undef forward_nullable_field_2
#undef forward_nullable_field
#undef forward_field_3
#undef forward_field_2
#undef forward_field
#undef static_nullable_omittable_field_4
#undef static_nullable_omittable_field_3
#undef static_nullable_omittable_field
#undef static_omittable_field_4
#undef static_omittable_field_3
#undef static_omittable_field
#undef static_nullable_field_4
#undef static_nullable_field_3
#undef static_nullable_field
#undef static_field_4
#undef static_field_3
#undef static_field
#undef nullable_omittable_field_3
#undef nullable_omittable_field_2
#undef nullable_omittable_field
#undef omittable_field_3
#undef omittable_field_2
#undef omittable_field
#undef nullable_field_3
#undef nullable_field_2
#undef nullable_field
#undef field_3
#undef field_2
#undef field
#endif

#ifndef Parent
#define JSON_TO(KEY, NAME) if(!nlohmann_json_t.NAME.is_omitted()) {nlohmann_json_j[KEY] = nlohmann_json_t.NAME;}
#define field(...) ML99_OVERLOAD(field_, __VA_ARGS__)
#define field_2(TYPE, NAME) ML99_JUST(JSON_TO(#NAME, NAME))
#define field_3(TYPE, KEY, NAME) ML99_JUST(JSON_TO(KEY, NAME))
#define nullable_field(...) ML99_OVERLOAD(nullable_field_, __VA_ARGS__)
#define nullable_field_2(TYPE, NAME) ML99_JUST(JSON_TO(#NAME, NAME))
#define nullable_field_3(TYPE, KEY, NAME) ML99_JUST(JSON_TO(KEY, NAME))
#define omittable_field(...) ML99_OVERLOAD(omittable_field_, __VA_ARGS__)
#define omittable_field_2(TYPE, NAME) ML99_JUST(JSON_TO(#NAME, NAME))
#define omittable_field_3(TYPE, KEY, NAME) ML99_JUST(JSON_TO(KEY, NAME))
#define nullable_omittable_field(...) ML99_OVERLOAD(nullable_omittable_field_, __VA_ARGS__)
#define nullable_omittable_field_2(TYPE, NAME) ML99_JUST(JSON_TO(#NAME, NAME))
#define nullable_omittable_field_3(TYPE, KEY, NAME) ML99_JUST(JSON_TO(KEY, NAME))
    friend void to_json(nlohmann::json &nlohmann_json_j,
                        const Name &nlohmann_json_t) {
        auto &j = nlohmann_json_j;
        const auto &t = nlohmann_json_t;
#ifdef ToJsonExtra
        ToJsonExtra;
#endif
        ML99_LIST_EVAL(ML99_listMap(v(ML99_maybeUnwrap), ML99_listFilter(v(ML99_isJust), ML99_list(v(Fields)))))
    }
#undef nullable_omittable_field_3
#undef nullable_omittable_field_2
#undef nullable_omittable_field
#undef omittable_field_3
#undef omittable_field_2
#undef omittable_field
#undef nullable_field_3
#undef nullable_field_2
#undef nullable_field
#undef field_3
#undef field_2
#undef field
#undef field

#undef JSON_TO
#define JSON_FROM(KEY, NAME) if (nlohmann_json_j.contains(KEY)) {nlohmann_json_j.at(KEY).get_to(nlohmann_json_t.NAME);}
#define field(...) ML99_OVERLOAD(field_, __VA_ARGS__)
#define field_2(TYPE, NAME) ML99_JUST(JSON_FROM(#NAME, NAME))
#define field_3(TYPE, KEY, NAME) ML99_JUST(JSON_FROM(KEY, NAME))
#define nullable_field(...) ML99_OVERLOAD(nullable_field_, __VA_ARGS__)
#define nullable_field_2(TYPE, NAME) ML99_JUST(JSON_FROM(#NAME, NAME))
#define nullable_field_3(TYPE, KEY, NAME) ML99_JUST(JSON_FROM(KEY, NAME))
#define omittable_field(...) ML99_OVERLOAD(omittable_field_, __VA_ARGS__)
#define omittable_field_2(TYPE, NAME) ML99_JUST(JSON_FROM(#NAME, NAME))
#define omittable_field_3(TYPE, KEY, NAME) ML99_JUST(JSON_FROM(KEY, NAME))
#define nullable_omittable_field(...) ML99_OVERLOAD(nullable_omittable_field_, __VA_ARGS__)
#define nullable_omittable_field_2(TYPE, NAME) ML99_JUST(JSON_FROM(#NAME, NAME))
#define nullable_omittable_field_3(TYPE, KEY, NAME) ML99_JUST(JSON_FROM(KEY, NAME))
    friend void from_json(const nlohmann::json &nlohmann_json_j,
                          Name &nlohmann_json_t) {
        const auto &j = nlohmann_json_j;
        auto &t = nlohmann_json_t;
#ifdef FromJsonExtra
        FromJsonExtra;
#endif
        ML99_LIST_EVAL(ML99_listMap(v(ML99_maybeUnwrap), ML99_listFilter(v(ML99_isJust), ML99_list(v(Fields)))))
    }
#undef nullable_omittable_field_3
#undef nullable_omittable_field_2
#undef nullable_omittable_field
#undef omittable_field_3
#undef omittable_field_2
#undef omittable_field
#undef nullable_field_3
#undef nullable_field_2
#undef nullable_field
#undef field_3
#undef field_2
#undef field
#undef JSON_FROM
#endif
