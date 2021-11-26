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

// https://discord.com/developers/docs/resources/webhook#create-webhook
//  TODO unverified
#define Parent JsonCall
#define Class CreateWebhookCall
#define function createWebhook
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::string, avatar, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/channels/{}/webhooks", ARR(channel_id), )
AUTO_PAYLOAD(PFR(name) PFO(avatar))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#get-channel-webhooks
//  TODO unverified
#define Parent Call
#define Class GetChannelWebhooksCall
#define function getChannelWebhooks
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/channels/{}/webhooks", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#get-guild-webhooks
//  TODO unverified
#define Parent Call
#define Class GetGuildWebhooksCall
#define function getGuildWebhooks
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/webhooks", ARR(guild_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#get-webhook
//  TODO unverified
#define Parent Call
#define Class GetWebhookCall
#define function getWebhook
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, webhook_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/webhooks/{}", ARR(webhook_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#get-webhook-with-token
//  TODO unverified
#define Parent Call
#define Class GetWebhookWithTokenCall
#define function getWebhookWithToken
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, webhook_id, USEDBY(target))
NEW_FIELD(std::string, webhook_token, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/webhooks/{}/{}", ARR(webhook_id, webhook_token), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#modify-webhook
//  TODO unverified
#define Parent JsonCall
#define Class ModifyWebhookCall
#define function modifyWebhook
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, webhook_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::optional<std::string>, avatar, USEDBY(payload))
NEW_FIELD(Snowflake, channel_id, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/webhooks/{}", ARR(webhook_id), )
AUTO_PAYLOAD(PFR(name) PFO(avatar) PFO(channel_id))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#modify-webhook-with-token
//  TODO unverified
#define Parent JsonCall
#define Class ModifyWebhookWithTokenCall
#define function modifyWebhookWithToken
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, webhook_id, USEDBY(target))
NEW_FIELD(std::string, webhook_token, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::optional<std::string>, avatar, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/webhooks/{}/{}", ARR(webhook_id, webhook_token), )
AUTO_PAYLOAD(PFR(name) PFO(avatar))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#delete-webhook
//  TODO unverified
#define Parent Call
#define Class DeleteWebhookCall
#define function deleteWebhook
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, webhook_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/webhooks/{}", ARR(webhook_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#delete-webhook-with-token
//  TODO unverified
#define Parent Call
#define Class DeleteWebhookWithTokenCall
#define function deleteWebhookWithToken
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, webhook_id, USEDBY(target))
NEW_FIELD(std::string, webhook_token, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/webhooks/{}/{}", ARR(webhook_id, webhook_token), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#execute-webhook
//  TODO unverified
#define Parent FileCall
#define Class ExecuteWebhookCall
#define function executeWebhook
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, webhook_id, USEDBY(target))
NEW_FIELD(std::string, webhook_token, USEDBY(target))
NEW_FIELD(bool, wait, USEDBY(target))
NEW_FIELD(Snowflake, thread_id, USEDBY(target))
NEW_FIELD(std::string, content, USEDBY(payload))
NEW_FIELD(std::string, username, USEDBY(payload))
NEW_FIELD(std::string, avatar_url, USEDBY(payload))
NEW_FIELD(bool, tts, USEDBY(payload))
NEW_FIELD(std::vector<json>, embeds, USEDBY(payload))
NEW_FIELD(json, allowed_mentions, USEDBY(payload))
NEW_FIELD(std::vector<json>, components, USEDBY(payload))
FORWARD_FIELD(std::string, filename, )
FORWARD_FIELD(std::string, filetype, )
FORWARD_FIELD(std::string, file, )
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/webhooks/{}/{}", ARR(webhook_id, webhook_token),
            QSO(wait) QSO(thread_id))
AUTO_PAYLOAD(PFO(content) PFO(username) PFO(avatar_url) PFO(tts) PFO(embeds)
                 PFO(allowed_mentions) PFO(components))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#execute-slackcompatible-webhook
// TODO

// https://discord.com/developers/docs/resources/webhook#execute-githubcompatible-webhook
//  TODO

// https://discord.com/developers/docs/resources/webhook#get-webhook-message
//  TODO unverified
#define Parent Call
#define Class GetWebhookMessageCall
#define function getWebhookMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, webhook_id, USEDBY(target))
NEW_FIELD(std::string, webhook_token, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/webhooks/{}/{}/messages/{}",
            ARR(webhook_id, webhook_token, message_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#edit-webhook-message
//  TODO unverified
#define Parent FileCall
#define Class editWebhookMessageCall
#define function editWebhookMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, webhook_id, USEDBY(target))
NEW_FIELD(std::string, webhook_token, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
NEW_FIELD(std::string, content, USEDBY(payload))
NEW_FIELD(std::vector<json>, embeds, USEDBY(payload))
NEW_FIELD(json, allowed_mentions, USEDBY(payload))
NEW_FIELD(std::vector<json>, components, USEDBY(payload))
FORWARD_FIELD(std::string, filename, )
FORWARD_FIELD(std::string, filetype, )
FORWARD_FIELD(std::string, file, )
STATIC_FIELD(std::string, method, "PATCH")
AUTO_TARGET("/webhooks/{}/{}/messages/{}",
            ARR(webhook_id, webhook_token, message_id), )
AUTO_PAYLOAD(PFO(content) PFO(embeds) PFO(allowed_mentions) PFO(components))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/webhook#delete-webhook-message
//  TODO unverified
#define Parent Call
#define Class DeleteWebhookMessageCall
#define function deleteWebhookMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, webhook_id, USEDBY(target))
NEW_FIELD(std::string, webhook_token, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/webhooks/{}/{}/messages/{}",
            ARR(webhook_id, webhook_token, message_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
