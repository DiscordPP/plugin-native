//
// Created by Aidan on 4/20/2021.
//

// Howdy! This file contains unverified endpoints so they may need touching up.
// Sorry for the mess, I just don't have the time to verify everything by hand,
// especially with the volatile nature of a live service like Discord. If
// something doesn't work come swing by #🔚endpoints on the Discord++ server and
// someone'll help you out! If the endpoints work fine swing by that same
// channel with proof of credit for the @Endpoint Verifier role!

#ifndef ENDPOINT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

// https://discord.com/developers/docs/resources/guild-scheduled-event#create-guild-scheduled-event
// TODO unverified
#define Parent JsonCall
#define Class CreateGuildScheduledEventCall
#define function createGuildScheduledEvent
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, channel_id, USEDBY(payload))
NEW_FIELD(GuildScheduledEventEntityMetadata, entity_metadata, USEDBY(payload))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(GuildScheduledEventPrivacyLevel, privacy_level, USEDBY(payload))
NEW_FIELD(Timestamp, scheduled_start_time, USEDBY(payload))
NEW_FIELD(Timestamp, scheduled_end_time, USEDBY(payload))
NEW_FIELD(std::string, description, USEDBY(payload))
NEW_FIELD(GuildScheduledEventEntityType, entity_type, USEDBY(payload))
NEW_FIELD(ImageData, image, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/guilds/{}/scheduled-events", ARR(guild_id),)
HIDE_FIELD(type)
HIDE_FIELD(body)
AUTO_PAYLOAD(
    PFO(channel_id)
    PFO(entity_metadata)
    PFR(name)
    PFR(privacy_level)
    PFR(scheduled_start_time)
    PFO(scheduled_end_time)
    PFO(description)
    PFR(entity_type)
    PFO(image)
)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild-scheduled-event#get-guild-scheduled-event
// TODO unverified
#define Parent Call
#define Class GetGuildScheduledEventCall
#define function getGuildScheduledEvent
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_scheduled_event_id, USEDBY(target))
NEW_FIELD(bool, with_user_count, USEDBY(target))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/guilds/{}/scheduled-events/{}", ARR(guild_id, guild_scheduled_event_id), QSO(with_user_count))
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
