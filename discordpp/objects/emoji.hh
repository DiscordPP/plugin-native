//
// Created by Aidan on 3/11/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class User;

class Emoji {
  public:
    AUTO_CONSTRUCTORS(Emoji)

    nullable_field<Snowflake> id;
    nullable_field<std::string> name;
    omittable_field<std::vector<Snowflake>> roles;
    omittable_field<User> user;
    omittable_field<bool> require_colons;
    omittable_field<bool> managed;
    omittable_field<bool> animated;
    omittable_field<bool> available;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Emoji, {}, {}, id, name, roles, user,
                                         require_colons, managed, animated,
                                         available)
};