//
// Created by Aidan on 8/27/2021.
//

// Howdy! This file contains unverified endpoints so they may need touching up.
// Sorry for the mess, I just don't have the time to verify everything by hand,
// especially with the volatile nature of a live service like Discord. If
// something doesn't work come swing by #🔚endpoints on the Discord++ server and
// someone'll help you out! If the endpoints work fine swing by that same
// channel with proof of credit for the @Endpoint Verifier role!

#ifndef ENDPOINT_BREAKOUTS
#error This header should only be included in plugin-endpoints.hh
#endif

// https://discord.com/developers/docs/interactions/application-commands#get-global-application-commands
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGlobalApplicationCommandsCall
#define function getGlobalApplicationCommands, getGlobalCommands
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    STATIC_FIELD(std::string, method, "GET")                                   \
    AUTO_TARGET("/applications/{}/commands", ARR(application_id), )            \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#create-global-application-command
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class CreateGlobalApplicationCommandCall
#define function createGlobalApplicationCommand, createGlobalCommand
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(std::string, name, USEDBY(payload))                              \
    NEW_FIELD(std::string, description, USEDBY(payload))                       \
    NEW_FIELD(std::vector<json>, options, USEDBY(payload))                     \
    NEW_FIELD(bool, default_permission, USEDBY(payload))                       \
    NEW_FIELD(json, command_type, USEDBY(payload))                             \
    STATIC_FIELD(std::string, method, "POST")                                  \
    AUTO_TARGET("/applications/{}/commands", ARR(application_id), )            \
    AUTO_PAYLOAD(PFR(name) PFR(description) PFO(options)                       \
                     PFO(default_permission) PFO("type", command_type))        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#get-global-application-command
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGlobalApplicationCommandCall
#define function getGlobalApplicationCommand, getGlobalCommand
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, command_id, USEDBY(target))                           \
    STATIC_FIELD(std::string, method, "GET")                                   \
    AUTO_TARGET("/applications/{}/command/{}",                                 \
                ARR(application_id, command_id), )                             \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#edit-global-application-command
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class EditGlobalApplicationCommandCall
#define function editGlobalApplicationCommand, editGlobalCommand
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, command_id, USEDBY(target))                           \
    NEW_FIELD(std::string, name, USEDBY(payload))                              \
    NEW_FIELD(std::string, description, USEDBY(payload))                       \
    NEW_FIELD(std::vector<json>, options, USEDBY(payload))                     \
    NEW_FIELD(bool, default_permission, USEDBY(payload))                       \
    STATIC_FIELD(std::string, method, "PATCH")                                 \
    AUTO_TARGET("/applications/{}/command/{}",                                 \
                ARR(application_id, command_id), )                             \
    AUTO_PAYLOAD(PFO(name) PFO(description) PFO(options)                       \
                     PFO(default_permission))                                  \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#delete-global-application-command
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class DeleteGlobalApplicationCommandCall
#define function deleteGlobalApplicationCommand, deleteGlobalCommand
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, command_id, USEDBY(target))                           \
    STATIC_FIELD(std::string, method, "DELETE")                                \
    AUTO_TARGET("/applications/{}/command/{}",                                 \
                ARR(application_id, command_id), )                             \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#bulk-overwrite-global-application-commands
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class BulkOverwriteGlobalApplicationCommandsCall
#define function                                                               \
    bulkOverwriteGlobalApplicationCommands, bulkOverwriteGlobalCommands
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    STATIC_FIELD(std::string, method, "PUT")                                   \
    AUTO_TARGET("/applications/{}/commands", ARR(application_id), )            \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#get-guild-application-commands
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildApplicationCommandsCall
#define function getGuildApplicationCommands, getGuildCommands
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "GET")                                   \
    AUTO_TARGET("/applications/{}/guilds/{}/commands",                         \
                ARR(application_id, guild_id), )                               \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

enum ApplicationCommandType { CHAT_INPUT = 1, USER = 2, MESSAGE = 3 };

// https://discord.com/developers/docs/interactions/application-commands#create-guild-application-command
// UndarkAido/Aido#8614 verified application_id, guild_id, name, description,
// options, command_type
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class CreateGuildApplicationCommandCall
#define function createGuildApplicationCommand, createGuildCommand
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(std::string, name, USEDBY(payload))                              \
    NEW_FIELD(std::string, description, USEDBY(payload))                       \
    NEW_FIELD(std::vector<json>, options, USEDBY(payload))                     \
    NEW_FIELD(bool, default_permission, USEDBY(payload))                       \
    NEW_FIELD(ApplicationCommandType, command_type, USEDBY(payload))           \
    STATIC_FIELD(std::string, method, "POST")                                  \
    AUTO_TARGET("/applications/{}/guilds/{}/commands",                         \
                ARR(application_id, guild_id), )                               \
    AUTO_PAYLOAD(PFR(name) PFR(description) PFO(options)                       \
                     PFO(default_permission) PFO("type", command_type))        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#get-guild-application-command
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildApplicationCommandCall
#define function getGuildApplicationCommand, getGuildCommand
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, command_id, USEDBY(target))                           \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "GET")                                   \
    AUTO_TARGET("/applications/{}/guilds/{}/command/{}",                       \
                ARR(application_id, guild_id, command_id), )                   \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#edit-guild-application-command
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class EditGuildApplicationCommandCall
#define function editGuildApplicationCommand, editGuildCommand
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, command_id, USEDBY(target))                           \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(std::string, name, USEDBY(payload))                              \
    NEW_FIELD(std::string, description, USEDBY(payload))                       \
    NEW_FIELD(std::vector<json>, options, USEDBY(payload))                     \
    NEW_FIELD(bool, default_permission, USEDBY(payload))                       \
    STATIC_FIELD(std::string, method, "PATCH")                                 \
    AUTO_TARGET("/applications/{}/guilds/{}/command/{}",                       \
                ARR(application_id, guild_id, command_id), )                   \
    AUTO_PAYLOAD(PFO(name) PFO(description) PFO(options)                       \
                     PFO(default_permission))                                  \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#delete-guild-application-command
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class DeleteGuildApplicationCommandCall
#define function deleteGuildApplicationCommand, deleteGuildCommand
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, command_id, USEDBY(target))                           \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "DELETE")                                \
    AUTO_TARGET("/applications/{}/guilds/{}/command/{}",                       \
                ARR(application_id, guild_id, command_id), )                   \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#bulk-overwrite-guild-application-commands
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class BulkOverwriteGuildApplicationCommandsCall
#define function                                                               \
    bulkOverwriteGuildApplicationCommands, bulkOverwriteGuildCommands
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "PUT")                                   \
    AUTO_TARGET("/applications/{}/guilds/{}/commands",                         \
                ARR(application_id, guild_id), )                               \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#get-guild-application-command-permissions
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildApplicationCommandPermissionsCall
#define function                                                               \
    getGuildApplicationCommandPermissions, getGuildCommandPermissions,         \
        getGuildCommandPerms
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "GET")                                   \
    AUTO_TARGET("/applications/{}/guilds/{}/commands/permissions",             \
                ARR(application_id, guild_id), )                               \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#get-application-command-permissions
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetApplicationCommandPermissionsCall
#define function                                                               \
    getApplicationCommandPermissions, getCommandPermissions, getCommandPerms
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, command_id, USEDBY(target))                           \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "GET")                                   \
    AUTO_TARGET("/applications/{}/guilds/{}/command/{}/permissions",           \
                ARR(application_id, guild_id, command_id), )                   \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#edit-application-command-permissions
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class EditApplicationCommandPermissionsCall
#define function                                                               \
    editApplicationCommandPermissions, editCommandPermissions, editCommandPerms
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, command_id, USEDBY(target))                           \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(std::vector<json>, permissions, USEDBY(target))                  \
    STATIC_FIELD(std::string, method, "PUT")                                   \
    AUTO_TARGET("/applications/{}/guilds/{}/command/{}/permissions",           \
                ARR(application_id, guild_id, command_id), )                   \
    AUTO_PAYLOAD(PFR(permissions))                                             \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#batch-edit-application-command-permissions
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class BatchEditApplicationCommandPermissionsCall
#define function                                                               \
    batchEditApplicationCommandPermissions, batchEditCommandPermissions,       \
        batchEditCommandPerms
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "PUT")                                   \
    AUTO_TARGET("/applications/{}/guilds/{}/commands/permissions",             \
                ARR(application_id, guild_id), )                               \
    FORWARD_FIELD(json, payload, )                                             \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>
