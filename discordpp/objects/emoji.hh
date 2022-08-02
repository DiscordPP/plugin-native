//
// Created by Aidan on 3/11/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

class User;

// TODO unverified
#define Name Emoji
#define Fields                                                                 \
    nullable_field(Snowflake, id), nullable_field(std::string, name),          \
        omittable_field(std::vector<Snowflake>, roles),                        \
        omittable_field(User, user), omittable_field(bool, require_colons),    \
        omittable_field(bool, managed), omittable_field(bool, animated),       \
        omittable_field(bool, available)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
