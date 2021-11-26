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
#error This header should only be included in plugin-native.hh
#endif

// https://discord.com/developers/docs/interactions/application-commands#get-global-application-commands
// TODO unverified
#define Parent Call
#define Class GetGlobalApplicationCommandsCall
#define function getGlobalApplicationCommands, getGlobalCommands
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/applications/{}/commands", ARR(application_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#create-global-application-command
// TODO unverified
#define Parent JsonCall
#define Class CreateGlobalApplicationCommandCall
#define function createGlobalApplicationCommand, createGlobalCommand
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::string, description, USEDBY(payload))
NEW_FIELD(std::vector<ApplicationCommandOption>, options, USEDBY(payload))
NEW_FIELD(bool, default_permission, USEDBY(payload))
NEW_FIELD(ApplicationCommandType, command_type, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/applications/{}/commands", ARR(application_id), )
AUTO_PAYLOAD(PFR(name) PFR(description) PFO(options) PFO(default_permission)
                 PFO("type", command_type))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#get-global-application-command
// TODO unverified
#define Parent Call
#define Class GetGlobalApplicationCommandCall
#define function getGlobalApplicationCommand, getGlobalCommand
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, command_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/applications/{}/command/{}", ARR(application_id, command_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#edit-global-application-command
// TODO unverified
#define Parent JsonCall
#define Class EditGlobalApplicationCommandCall
#define function editGlobalApplicationCommand, editGlobalCommand
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, command_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::string, description, USEDBY(payload))
NEW_FIELD(std::vector<ApplicationCommandOption>, options, USEDBY(payload))
NEW_FIELD(bool, default_permission, USEDBY(payload))
STATIC_FIELD(std::string, method, "PATCH")
AUTO_TARGET("/applications/{}/command/{}", ARR(application_id, command_id), )
AUTO_PAYLOAD(PFO(name) PFO(description) PFO(options) PFO(default_permission))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#delete-global-application-command
// TODO unverified
#define Parent Call
#define Class DeleteGlobalApplicationCommandCall
#define function deleteGlobalApplicationCommand, deleteGlobalCommand
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, command_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/applications/{}/command/{}", ARR(application_id, command_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#bulk-overwrite-global-application-commands
// TODO unverified
#define Parent Call
#define Class BulkOverwriteGlobalApplicationCommandsCall
#define function                                                               \
    bulkOverwriteGlobalApplicationCommands, bulkOverwriteGlobalCommands
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/applications/{}/commands", ARR(application_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#get-guild-application-commands
// TODO unverified
#define Parent Call
#define Class GetGuildApplicationCommandsCall
#define function getGuildApplicationCommands, getGuildCommands
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/applications/{}/guilds/{}/commands",
            ARR(application_id, guild_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#create-guild-application-command
// UndarkAido/Aido#8614 verified application_id, guild_id, name, description,
// options, command_type
// TODO unverified
#define Parent JsonCall
#define Class CreateGuildApplicationCommandCall
#define function createGuildApplicationCommand, createGuildCommand
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::string, description, USEDBY(payload))
NEW_FIELD(std::vector<ApplicationCommandOption>, options, USEDBY(payload))
NEW_FIELD(bool, default_permission, USEDBY(payload))
NEW_FIELD(ApplicationCommandType, command_type, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/applications/{}/guilds/{}/commands",
            ARR(application_id, guild_id), )
AUTO_PAYLOAD(PFR(name) PFR(description) PFO(options) PFO(default_permission)
                 PFO("type", command_type))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#get-guild-application-command
// TODO unverified
#define Parent Call
#define Class GetGuildApplicationCommandCall
#define function getGuildApplicationCommand, getGuildCommand
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, command_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/applications/{}/guilds/{}/command/{}",
            ARR(application_id, guild_id, command_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#edit-guild-application-command
// TODO unverified
#define Parent JsonCall
#define Class EditGuildApplicationCommandCall
#define function editGuildApplicationCommand, editGuildCommand
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, command_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::string, description, USEDBY(payload))
NEW_FIELD(std::vector<ApplicationCommandOption>, options, USEDBY(payload))
NEW_FIELD(bool, default_permission, USEDBY(payload))
STATIC_FIELD(std::string, method, "PATCH")
AUTO_TARGET("/applications/{}/guilds/{}/command/{}",
            ARR(application_id, guild_id, command_id), )
AUTO_PAYLOAD(PFO(name) PFO(description) PFO(options) PFO(default_permission))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#delete-guild-application-command
// TODO unverified
#define Parent Call
#define Class DeleteGuildApplicationCommandCall
#define function deleteGuildApplicationCommand, deleteGuildCommand
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, command_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/applications/{}/guilds/{}/command/{}",
            ARR(application_id, guild_id, command_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#bulk-overwrite-guild-application-commands
// TODO unverified
#define Parent Call
#define Class BulkOverwriteGuildApplicationCommandsCall
#define function                                                               \
    bulkOverwriteGuildApplicationCommands, bulkOverwriteGuildCommands
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/applications/{}/guilds/{}/commands",
            ARR(application_id, guild_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#get-guild-application-command-permissions
// TODO unverified
#define Parent Call
#define Class GetGuildApplicationCommandPermissionsCall
#define function                                                               \
    getGuildApplicationCommandPermissions, getGuildCommandPermissions,         \
        getGuildCommandPerms
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/applications/{}/guilds/{}/commands/permissions",
            ARR(application_id, guild_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#get-application-command-permissions
// TODO unverified
#define Parent Call
#define Class GetApplicationCommandPermissionsCall
#define function                                                               \
    getApplicationCommandPermissions, getCommandPermissions, getCommandPerms
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, command_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/applications/{}/guilds/{}/command/{}/permissions",
            ARR(application_id, guild_id, command_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#edit-application-command-permissions
// TODO unverified
#define Parent JsonCall
#define Class EditApplicationCommandPermissionsCall
#define function                                                               \
    editApplicationCommandPermissions, editCommandPermissions, editCommandPerms
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, command_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::vector<ApplicationCommandPermission>, permissions,
          USEDBY(target))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/applications/{}/guilds/{}/command/{}/permissions",
            ARR(application_id, guild_id, command_id), )
AUTO_PAYLOAD(PFR(permissions))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/application-commands#batch-edit-application-command-permissions
// TODO unverified
#define Parent JsonCall
#define Class BatchEditApplicationCommandPermissionsCall
#define function                                                               \
    batchEditApplicationCommandPermissions, batchEditCommandPermissions,       \
        batchEditCommandPerms
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, application_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/applications/{}/guilds/{}/commands/permissions",
            ARR(application_id, guild_id), )
FORWARD_FIELD(json, payload, )
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
