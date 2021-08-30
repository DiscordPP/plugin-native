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

// https://discord.com/developers/docs/interactions/receiving-and-responding#create-interaction-response
// UndarkAido/Aido#8614 verified interaction_id, interaction_token,
// interaction_type, data
// Note: interaction_id is the ID of the interaction *event*
// TODO unverified
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
    AUTO_TARGET("/interactions/{}/{}/callback",                                \
                ARR(interaction_id, interaction_token), )                      \
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
    AUTO_TARGET("/webhooks/{}/{}/messages/@original",                          \
                ARR(application_id, interaction_token), )                      \
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
    AUTO_TARGET("/webhooks/{}/{}/messages/@original",                          \
                ARR(application_id, interaction_token), )                      \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/receiving-and-responding#create-followup-message
//  TODO unverified
#define Bot PluginEndpoints
#define Parent FileCall
#define Class CreateFollowupMessageCall
#define function createFollowupMessage
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(std::string, interaction_token, USEDBY(target))                  \
    NEW_FIELD(std::string, content, USEDBY(payload))                           \
    NEW_FIELD(std::string, username, USEDBY(payload))                          \
    NEW_FIELD(std::string, avatar_url, USEDBY(payload))                        \
    NEW_FIELD(bool, tts, USEDBY(payload))                                      \
    NEW_FIELD(std::vector<json>, embeds, USEDBY(payload))                      \
    NEW_FIELD(json, allowed_mentions, USEDBY(payload))                         \
    NEW_FIELD(std::vector<json>, components, USEDBY(payload))                  \
    NEW_FIELD(int, flags, USEDBY(payload))                                     \
    FORWARD_FIELD(std::string, filename, )                                     \
    FORWARD_FIELD(std::string, filetype, )                                     \
    FORWARD_FIELD(std::string, file, )                                         \
    STATIC_FIELD(std::string, method, "POST")                                  \
    AUTO_TARGET("/webhooks/{}/{}", ARR(application_id, interaction_token), )   \
    AUTO_PAYLOAD(PFO(content) PFO(username) PFO(avatar_url) PFO(tts) PFO(      \
        embeds) PFO(allowed_mentions) PFO(components) PFO(flags))              \
    FORWARD_FIELD(handleWrite, onWrite, ) FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/receiving-and-responding#get-followup-message
//  TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetFollowupMessageCall
#define function getFollowupMessage
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(std::string, interaction_token, USEDBY(target))                  \
    NEW_FIELD(snowflake, message_id, USEDBY(target))                           \
    STATIC_FIELD(std::string, method, "GET")                                   \
    AUTO_TARGET("/webhooks/{}/{}/messages/{}",                                 \
                ARR(application_id, interaction_token, message_id), )          \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/receiving-and-responding#edit-followup-message
//  TODO unverified
#define Bot PluginEndpoints
#define Parent FileCall
#define Class editFollowupMessageCall
#define function editFollowupMessage
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(std::string, interaction_token, USEDBY(target))                  \
    NEW_FIELD(snowflake, message_id, USEDBY(target))                           \
    NEW_FIELD(std::string, content, USEDBY(payload))                           \
    NEW_FIELD(std::vector<json>, embeds, USEDBY(payload))                      \
    NEW_FIELD(json, allowed_mentions, USEDBY(payload))                         \
    NEW_FIELD(std::vector<json>, components, USEDBY(payload))                  \
    FORWARD_FIELD(std::string, filename, )                                     \
    FORWARD_FIELD(std::string, filetype, )                                     \
    FORWARD_FIELD(std::string, file, )                                         \
    STATIC_FIELD(std::string, method, "PATCH")                                 \
    AUTO_TARGET("/webhooks/{}/{}/messages/{}",                                 \
                ARR(application_id, interaction_token, message_id), )          \
    AUTO_PAYLOAD(PFO(content) PFO(embeds) PFO(allowed_mentions)                \
                     PFO(components))                                          \
    FORWARD_FIELD(handleWrite, onWrite, ) FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/interactions/receiving-and-responding#delete-followup-message
//  TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class DeleteFollowupMessageCall
#define function deleteFollowupMessage
#define Fields                                                                 \
    NEW_FIELD(snowflake, application_id, USEDBY(target))                       \
    NEW_FIELD(std::string, interaction_token, USEDBY(target))                  \
    NEW_FIELD(snowflake, message_id, USEDBY(target))                           \
    STATIC_FIELD(std::string, method, "DELETE")                                \
    AUTO_TARGET("/webhooks/{}/{}/messages/{}",                                 \
                ARR(application_id, interaction_token, message_id), )          \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>
