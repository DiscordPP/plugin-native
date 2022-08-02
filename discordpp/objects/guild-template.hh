//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// TODO unverified
#define Name GuildTemplate
#define Fields                                                                 \
    field(std::string, code), field(std::string, name),                        \
        nullable_field(std::string, description), field(int, usage_count),     \
        field(Snowflake, creator_id), field(User, creator),                    \
        field(Timestamp, created_at), field(Timestamp, updated_at),            \
        field(Snowflake, source_guild_id),                                     \
        field(Guild, serialized_source_guild), nullable_field(bool, is_dirty)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
