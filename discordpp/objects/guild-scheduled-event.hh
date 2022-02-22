//
// Created by Aidan on 4/20/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

#define Name GuildScheduledEvent
#define Fields \
    field(Snowflake, id),\
    field(Snowflake, guild_id),\
    nullable_field(Snowflake, channel_id),\
    omittable_nullable_field(Snowflake, creator_id),\
    field(std::string, name),\
    field(std::string, description),\
    field(Timestamp, scheduled_start_time),\
    nullable_field(Timestamp, scheduled_end_time),\
    field(GuildScheduledEventPrivacyLevel, privacy_level),\
    field(GuildScheduledEventStatus, status),\
    field(GuildScheduledEventEntityType, entity_type),\
    nullable_field(Snowflake, entity_id),\
    nullable_field(GuildScheduledEventMetadata, entity_metadata),\
    omittable_field(User, creator),\
    omittable_field(int, user_count),\
    nullable_field(std::string, image)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name GuildScheduledEventMetadata
#define Fields omittable_field(std::string, location)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name GuildScheduledEventUser
#define Fields \
    field(Snowflake, guild_scheduled_event_id),\
    field(User, user),\
    nullable_field(GuildMember, member)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
