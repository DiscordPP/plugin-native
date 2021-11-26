//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

#define Name ApplicationCommand
#define Fields                                                                 \
    field(Snowflake, id), omittable_field(ApplicationCommandType, type),       \
        field(Snowflake, application_id),                                      \
        omittable_field(Snowflake, guild_id), field(std::string, name),        \
        field(std::string, description),                                       \
        omittable_field(std::vector<ApplicationCommandOption>, options),       \
        omittable_field(bool, default_permission), field(Snowflake, version)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name ApplicationCommandOption
#define Fields                                                                 \
    field(ApplicationCommandOptionType, type), field(std::string, name),       \
        field(std::string, description), omittable_field(bool, required),      \
        omittable_field(std::vector<ApplicationCommandOptionChoice>, choices), \
        omittable_field(std::vector<ApplicationCommandOption>, options),       \
        omittable_field(MessageType, channel_types)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

using ApplicationCommandOptionChoiceValue =
    std::variant<int, double, std::string>;
#define Name ApplicationCommandOptionChoice
#define Fields                                                                 \
    field(std::string, name), field(ApplicationCommandOptionChoiceValue, value)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name ApplicationCommandInteractionDataOption
#define Fields                                                                 \
    field(std::string, name), field(ApplicationCommandOptionType, type),       \
        omittable_field(json, value),                                          \
        omittable_field(std::vector<ApplicationCommandInteractionDataOption>,  \
                        options)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name GuildApplicationCommandPermissions
#define Fields                                                                 \
    field(Snowflake, id), field(Snowflake, application_id),                    \
        field(Snowflake, guild_id),                                            \
        field(std::vector<ApplicationCommandPermission>, permissions)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name ApplicationCommandPermission
#define Fields                                                                 \
    field(Snowflake, id), field(ApplicationCommandPermissionType, type),       \
        field(bool, permission)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
