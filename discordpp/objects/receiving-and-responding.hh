//
// Created by Aidan on 8/28/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// TODO unverified
#define Name Interaction
#define Fields                                                                 \
    field(Snowflake, id), field(Snowflake, application_id),                    \
        field(InteractionType, type), omittable_field(InteractionData, data),  \
        omittable_field(Snowflake, guild_id),                                  \
        omittable_field(Snowflake, channel_id),                                \
        omittable_field(GuildMember, member), omittable_field(User, user),     \
        field(std::string, token), field(int, version),                        \
        omittable_field(Message, message)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

// TODO unverified
#define Name InteractionData
#define Fields                                                                 \
    field(Snowflake, id), field(std::string, name), field(int, type),          \
        omittable_field(ResolvedData, resolved),                               \
        omittable_field(std::vector<ApplicationCommandInteractionDataOption>,  \
                        options),                                              \
        omittable_field(std::string, custom_id),                               \
        omittable_field(int, component_type),                                  \
        omittable_field(std::vector<SelectOption>, values),                    \
        omittable_field(Snowflake, target_id)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

using ResolvedDataUsers = std::map<Snowflake, User>;
using ResolvedDataMembers = std::map<Snowflake, User>;
using ResolvedDataRoles = std::map<Snowflake, User>;
using ResolvedDataChannels = std::map<Snowflake, User>;
using ResolvedDataMessages = std::map<Snowflake, User>;
// TODO unverified
#define Name ResolvedData
#define Fields                                                                 \
    omittable_field(ResolvedDataUsers, users),                                 \
        omittable_field(ResolvedDataMembers, members),                         \
        omittable_field(ResolvedDataRoles, roles),                             \
        omittable_field(ResolvedDataChannels, channels),                       \
        omittable_field(ResolvedDataMessages, messages)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

// TODO unverified
#define Name MessageInteraction
#define Fields                                                                 \
    field(Snowflake, id), field(InteractionType, type),                        \
        field(std::string, name), field(User, user)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

// TODO unverified
#define Name InteractionResponse
#define Fields                                                                 \
    field(InteractionType, type), omittable_field(InteractionCallbackData, data)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

// TODO unverified
#define Name InteractionCallbackData
#define Fields                                                                 \
    omittable_field(bool, tts), omittable_field(std::string, content),         \
        omittable_field(std::vector<Embed>, embeds),                           \
        omittable_field(AllowedMentions, allowed_mentions),                    \
        omittable_field(InteractionCallbackDataFlags, flags),                  \
        omittable_field(std::vector<Component>, components)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
