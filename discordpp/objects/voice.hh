//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// TODO unverified
#define Name VoiceState
#define Fields                                                                 \
    omittable_field(Snowflake, guild_id),                                      \
        nullable_field(Snowflake, channel_id), field(Snowflake, user_id),      \
        omittable_field(GuildMember, member), field(std::string, session_id),  \
        field(bool, deaf), field(bool, mute), field(bool, self_deaf),          \
        field(bool, self_mute), omittable_field(bool, self_stream),            \
        field(bool, self_video), field(bool, suppress),                        \
        nullable_field(Timestamp, request_to_speak_timestamp)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

// TODO unverified
#define Name VoiceRegion
#define Fields                                                                 \
    field(std::string, id), field(std::string, name), field(bool, optimal),    \
        field(bool, deprecated), field(bool, custom)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
