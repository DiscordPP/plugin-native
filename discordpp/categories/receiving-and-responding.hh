//
// Created by Aidan on 8/28/2021.
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

enum InteractionCallbackType {
    PONG = 1,
    CHANNEL_MESSAGE_WITH_SOURCE = 4,
    DEFERRED_CHANNEL_MESSAGE_WITH_SOURCE = 5,
    DEFERRED_UPDATE_MESSAGE = 6,
    UPDATE_MESSAGE = 7
};

// https://discord.com/developers/docs/interactions/receiving-and-responding#create-interaction-response
//  TODO unverified
#define Bot PluginEndpoints
#define Parent FileCall
#define Class CreateInteractionResponseCall
#define function createInteractionResponse, createResponse
#define Fields                                                                 \
    NEW_FIELD(snowflake, interaction_id, USEDBY(target))                       \
    NEW_FIELD(std::string, interaction_token, USEDBY(target))                  \
    NEW_FIELD(InteractionCallbackType, interaction_type, USEDBY(payload))      \
    NEW_FIELD(json, data, USEDBY(payload))                                     \
    FORWARD_FIELD(std::string, filename, )                                     \
    FORWARD_FIELD(std::string, filetype, )                                     \
    FORWARD_FIELD(std::string, file, )                                         \
    STATIC_FIELD(std::string, method, "POST")                                  \
    AUTO_TARGET("/interactions/{}/{}/callback", interaction_id,                \
                interaction_token)                                             \
    AUTO_PAYLOAD(PFR("type", interaction_type) PFO(data))                      \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/receiving-and-responding#get-original-interaction-response
//  TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetOriginalInteractionResponseCall
#define function getOriginalInteractionResponse, getOriginalResponse
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(std::string, interaction_token, USEDBY(target))                  \
    STATIC_FIELD(std::string, method, "GET")                                   \
    AUTO_TARGET("/webhooks/{}/{}/messages/@original", application_id,          \
                interaction_token)                                             \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/receiving-and-responding#edit-original-interaction-response
//  TODO unverified

// https://discord.com/developers/docs/interactions/receiving-and-responding#delete-original-interaction-response
//  TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class deleteOriginalInteractionResponseCall
#define function deleteOriginalInteractionResponse, deleteOriginalResponse
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(std::string, interaction_token, USEDBY(target))                  \
    STATIC_FIELD(std::string, method, "DELETE")                                \
    AUTO_TARGET("/webhooks/{}/{}/messages/@original", application_id,          \
                interaction_token)                                             \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/receiving-and-responding#create-followup-message
//  TODO unverified

// https://discord.com/developers/docs/interactions/receiving-and-responding#get-followup-message
//  TODO unverified

// https://discord.com/developers/docs/interactions/receiving-and-responding#edit-followup-message
//  TODO unverified

// https://discord.com/developers/docs/interactions/receiving-and-responding#delete-followup-message
//  TODO unverified
