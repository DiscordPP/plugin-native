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

#ifndef Name
#error An object needs a name
#endif

class Name
#ifdef Parent
    : public Parent
#endif
{
  public:
#ifndef Parent
    //Name() = default;
    Name(const json &j) { from_json(j, *this); }
#define field(TYPE, NAME) field<TYPE> NAME = uninitialized
#define nullable_field(TYPE, NAME) nullable_field<TYPE> NAME = uninitialized
#define omittable_field(TYPE, NAME) omittable_field<TYPE> NAME = omitted
#define nullable_omittable_field(TYPE, NAME) nullable_omittable_field<TYPE> NAME = omitted
    Name(DPP_FOR_EACH_CS(RENDER, Fields)) :
#undef nullable_omittable_field
#undef omittable_field
#undef nullable_field
#undef field
#define field(TYPE, NAME) NAME(NAME)
#define nullable_field(TYPE, NAME) NAME(NAME)
#define omittable_field(TYPE, NAME) NAME(NAME)
#define nullable_omittable_field(TYPE, NAME) NAME(NAME)
    DPP_FOR_EACH_CS(RENDER, Fields) {}
#undef nullable_omittable_field
#undef omittable_field
#undef nullable_field
#undef field
#endif

#define field(TYPE, NAME) field<TYPE> NAME;
#define nullable_field(TYPE, NAME) nullable_field<TYPE> NAME;
#define omittable_field(TYPE, NAME) omittable_field<TYPE> NAME;
#define nullable_omittable_field(TYPE, NAME)                                   \
    nullable_omittable_field<TYPE> NAME;
    DPP_FOR_EACH(RENDER, Fields)
#undef nullable_omittable_field
#undef omittable_field
#undef nullable_field
#undef field

#define field(TYPE, NAME) NAME
#define nullable_field(TYPE, NAME) NAME
#define omittable_field(TYPE, NAME) NAME
#define nullable_omittable_field(TYPE, NAME) NAME
    friend void to_json(nlohmann::json &nlohmann_json_j,
                        const Name &nlohmann_json_t) {
        auto &j = nlohmann_json_j;
        const auto &t = nlohmann_json_t;
#ifdef ToJsonExtra
        ToJsonExtra;
#endif
        NLOHMANN_JSON_EXPAND(
            NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO_FIELD, Fields));
    }
    friend void from_json(const nlohmann::json &nlohmann_json_j,
                          Name &nlohmann_json_t) {
        const auto &j = nlohmann_json_j;
        auto &t = nlohmann_json_t;
#ifdef FromJsonExtra
        FromJsonExtra;
#endif
        NLOHMANN_JSON_EXPAND(
            NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM_FIELD, Fields));
    }
#undef nullable_omittable_field
#undef omittable_field
#undef nullable_field
#undef field
