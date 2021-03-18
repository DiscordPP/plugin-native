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
#error This header should only be included in plugin-endpoints.hh
#endif

// https://discord.com/developers/docs/resources/emoji#list-guild-emojis
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class ListGuildEmojisCall
#define function listGuildEmojis
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(std::string, target)                                            \
    HIDE_FIELD(std::string, type)                                              \
    HIDE_FIELD(std::string, body)                                              \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id)
        throw std::logic_error("List Guild Emojis needs an ID");
    return std::make_shared<const std::string>(
        "/guilds/" + std::to_string(*_guild_id) + "/emojis");
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/emoji#get-guild-emoji
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildEmojiCall
#define function getGuildEmoji
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(snowflake, emoji_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(std::string, target)                                            \
    HIDE_FIELD(std::string, type)                                              \
    HIDE_FIELD(std::string, body)                                              \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id)
        throw std::logic_error("Get Guild Emoji needs a Guild ID");
    if (!_emoji_id)
        throw std::logic_error("Get Guild Emoji needs an Emoji ID");
    return std::make_shared<const std::string>(
        "/guilds/" + std::to_string(*_guild_id) + "/emojis/" +
        std::to_string(*_emoji_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/emoji#create-guild-emoji
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class CreateGuildEmojiCall
#define function createGuildEmoji
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(std::string, name, USEDBY(payload))                              \
    NEW_FIELD(std::string, image, USEDBY(payload))                             \
    NEW_FIELD(std::vector<snowflake>, roles, USEDBY(payload))                  \
    STATIC_FIELD(std::string, method, "POST")                                  \
    HIDE_FIELD(std::string, target)                                            \
    HIDE_FIELD(std::string, type)                                              \
    HIDE_FIELD(std::string, body)                                              \
    HIDE_FIELD(json, payload)                                                  \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id)
        throw std::logic_error("Create Guild Emoji needs a Guild ID");
    return std::make_shared<const std::string>(
        "/guilds/" + std::to_string(*_guild_id) + "/emojis");
}
sptr<const json> render_payload() override {
    json out;

    if (!_name)
        throw std::logic_error("Create Guild Emoji needs a Name");
    out["name"] = *_name;

    if (!_image)
        throw std::logic_error("Create Guild Emoji need Image Data");
    out["image"] = *_image;

    if (_roles) {
        json roles = json::array();
        for (snowflake role : *_roles)
            roles.push_back(std::to_string(role));
        out["roles"] = roles;
    }

    return std::make_shared<const json>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/emoji#modify-guild-emoji
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyGuildEmojiCall
#define function modifyGuildEmoji
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(snowflake, emoji_id, USEDBY(target))                             \
    NEW_FIELD(std::string, name, USEDBY(payload))                              \
    NEW_FIELD(std::vector<snowflake>, roles, USEDBY(payload))                  \
    STATIC_FIELD(std::string, method, "PATCH")                                 \
    HIDE_FIELD(std::string, target)                                            \
    HIDE_FIELD(std::string, type)                                              \
    HIDE_FIELD(std::string, body)                                              \
    HIDE_FIELD(json, payload)                                                  \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id)
        throw std::logic_error("Modify  Guild Emoji needs a Guild ID");
    if (!_emoji_id)
        throw std::logic_error("Modify  Guild Emoji needs an Emoji ID");
    return std::make_shared<const std::string>(
        "/guilds/" + std::to_string(*_guild_id) + "/emojis/" +
        std::to_string(*_emoji_id));
}
sptr<const json> render_payload() override {
    json out;

    if (!_name)
        throw std::logic_error("Create Guild Emoji needs a Name");
    out["name"] = *_name;

    if (_roles) {
        json roles = json::array();
        for (snowflake role : *_roles)
            roles.push_back(std::to_string(role));
        out["roles"] = roles;
    }

    return std::make_shared<const json>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/emoji#delete-guild-emoji
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class DeleteGuildEmojiCall
#define function deleteGuildEmoji
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(snowflake, emoji_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "DELETE")                                \
    HIDE_FIELD(std::string, target)                                            \
    HIDE_FIELD(std::string, type)                                              \
    HIDE_FIELD(std::string, body)                                              \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id)
        throw std::logic_error("Delete Guild Emoji needs a Guild ID");
    if (!_emoji_id)
        throw std::logic_error("Delete Guild Emoji needs an Emoji ID");
    return std::make_shared<const std::string>(
        "/guilds/" + std::to_string(*_guild_id) + "/emojis/" +
        std::to_string(*_emoji_id));
}
#include <discordpp/macros/defineCallClose.hh>
