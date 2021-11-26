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

// https://discord.com/developers/docs/resources/sticker#get-sticker
// TODO unverified
#define Parent Call
#define Class GetStickerCall
#define function getSticker
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, sticker_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/stickers/{}", ARR(sticker_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/sticker#list-nitro-sticker-packs
//  TODO unverified
#define Parent Call
#define Class ListNitroStickerPacksCall
#define function listNitroStickerPacks, getNitroStickerPacks
#include <discordpp/macros/defineCallOpen.hh>
STATIC_FIELD(std::string, method, "GET")
STATIC_FIELD(std::string, target, "/sticker-packs")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/sticker#list-guild-stickers
//  TODO unverified
#define Parent Call
#define Class ListGuildStickerCall
#define function listGuildStickers, getGuildStickers
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, sticker_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/stickers", ARR(guild_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/sticker#get-guild-sticker
//  TODO unverified
#define Parent Call
#define Class GetGuildStickerCall
#define function getGuildSticker
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, sticker_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/stickers/{}", ARR(guild_id, sticker_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/sticker#create-guild-sticker
//  TODO unverified
#define Parent FileCall
#define Class CreateGuildStickerCall
#define function createGuildStickers
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/stickers", ARR(guild_id), )
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::string, description, USEDBY(payload))
NEW_FIELD(std::string, tags, USEDBY(payload))
AUTO_PAYLOAD(PFR(name) PFR(description) PFR(tags))
FORWARD_FIELD(std::string, filename, )
FORWARD_FIELD(std::string, filetype, )
FORWARD_FIELD(std::string, file, )
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/sticker#modify-guild-sticker
//  TODO unverified
#define Parent JsonCall
#define Class ModifyGuildStickerCall
#define function modifyGuildStickers
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/stickers", ARR(guild_id), )
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::optional<std::string>, description, USEDBY(payload))
NEW_FIELD(std::string, tags, USEDBY(payload))
AUTO_PAYLOAD(PFO(name) PFO(description) PFO(tags))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/sticker#delete-guild-sticker
//  TODO unverified
#define Parent Call
#define Class DeleteGuildStickerCall
#define function deleteGuildSticker
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, sticker_id, USEDBY(target))
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/stickers/{}", ARR(guild_id, sticker_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
