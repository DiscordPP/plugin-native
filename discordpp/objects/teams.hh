//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// TODO unverified
#define Name Team
#define Fields                                                                 \
    nullable_field(std::string, icon), field(Snowflake, id),                   \
        field(std::vector<GuildMember>, members), field(std::string, name),    \
        field(Snowflake, owner_user_id)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

// TODO unverified
#define Name TeamMember
#define Fields                                                                 \
    field(int, membership_state),                                              \
        field(std::vector<std::string>, permissions),                          \
        field(Snowflake, team_id), field(User, user)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
