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
#error This header should only be included in plugin-endpoints.hh
#endif

// https://discord.com/developers/docs/interactions/application-commands#get-global-application-commands
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGlobalApplicationCommands
#define function getGlobalApplicationCommands, getGlobalCommands
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    STATIC_FIELD(std::string, method, "GET")                                   \
    AUTO_TARGET("/applications/{}/commands", application_id)                   \
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
#define Class CreateGlobalApplicationCommand
#define function createGlobalApplicationCommand, createGlobalCommand
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(std::string, name, USEDBY(payload))                              \
    NEW_FIELD(std::string, description, USEDBY(payload))                       \
    NEW_FIELD(std::vector<json>, options, USEDBY(payload))                     \
    NEW_FIELD(bool, default_permission, USEDBY(payload))                       \
    NEW_FIELD(json, command_type, USEDBY(payload))                             \
    STATIC_FIELD(std::string, method, "GET")                                   \
    AUTO_TARGET("/applications/{}/commands", application_id)                   \
    AUTO_PAYLOAD(PFR(name) PFR(description) PFO(options)                       \
                     PFO(default_permission) PFO("type", command_type))        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>
