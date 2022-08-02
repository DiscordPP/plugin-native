//
// Created by Aidan on 3/11/2021.
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

// https://discord.com/developers/docs/resources/emoji#list-guild-emojis
// TODO unverified
#define Parent Call
#define Class ListGuildEmojisCall
#define function listGuildEmojis
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/emojis", ARR(guild_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/emoji#get-guild-emoji
// TODO unverified
#define Parent Call
#define Class GetGuildEmojiCall
#define function getGuildEmoji
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, emoji_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/emojis/{}", ARR(guild_id, emoji_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/emoji#create-guild-emoji
// TODO unverified
#define Parent JsonCall
#define Class CreateGuildEmojiCall
#define function createGuildEmoji
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::string, image, USEDBY(payload))
NEW_FIELD(std::vector<Snowflake>, roles, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/guilds/{}/emojis", ARR(guild_id), )
AUTO_PAYLOAD(PFR(name) PFR(image) PFO(roles))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/emoji#modify-guild-emoji
// TODO unverified
#define Parent JsonCall
#define Class ModifyGuildEmojiCall
#define function modifyGuildEmoji
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, emoji_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::vector<Snowflake>, roles, USEDBY(payload))
STATIC_FIELD(std::string, method, "PATCH")
AUTO_TARGET("/guilds/{}/emojis/{}", ARR(guild_id, emoji_id), )
AUTO_PAYLOAD(PFR(name) PFO(roles))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/emoji#delete-guild-emoji
// TODO unverified
#define Parent Call
#define Class DeleteGuildEmojiCall
#define function deleteGuildEmoji
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, emoji_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/guilds/{}/emojis/{}", ARR(guild_id, emoji_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
