//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// TODO unverified
#define Name StageInstance
#define Fields                                                                 \
    field(Snowflake, id), field(Snowflake, guild_id),                          \
        field(Snowflake, channel_id), field(std::string, topic),               \
        field(int, privacy_level), field(bool, discoverable_disabled)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
