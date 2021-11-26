//
// Created by Aidan on 4/20/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

#define Name User
#define Fields                                                                 \
    field(Snowflake, id), field(std::string, username),                        \
        field(std::string, discriminator),                                     \
        nullable_field(std::string, avatar), omittable_field(bool, bot),       \
        omittable_field(bool, system), omittable_field(bool, mfa_enabled),     \
        nullable_omittable_field(std::string, banner),                         \
        nullable_omittable_field(int, accent_color),                           \
        omittable_field(std::string, locale), omittable_field(bool, verified), \
        nullable_omittable_field(std::string, email),                          \
        omittable_field(int, flags), omittable_field(int, premium_type),       \
        omittable_field(int, public_flags)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name Connection
#define Fields                                                                 \
    field(std::string, id), field(std::string, name),                          \
        field(std::string, type), omittable_field(bool, revoked),              \
        omittable_field(std::vector<Integration>, integrations),               \
        field(bool, verified), field(bool, friend_sync),                       \
        field(bool, show_activity), field(int, visibility)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
