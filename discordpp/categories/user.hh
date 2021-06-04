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

// https://discord.com/developers/docs/resources/user#get-current-user
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetCurrentUserCall
#define function getCurrentUser, getSelf
#define Fields                                                                 \
    STATIC_FIELD(std::string, method, "GET")                                   \
    STATIC_FIELD(std::string, target, "/users/@me")                            \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#get-user
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetUserCall
#define function getUser
#define Fields                                                                 \
    NEW_FIELD(snowflake, user_id, USEDBY(target))                              \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_user_id)
        throw std::logic_error("Get User needs an ID");
    return std::make_shared<const std::string>("/users/" +
                                               std::to_string(*_user_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#modify-current-user
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyCurrentUserCall
#define function modifyCurrentUser, modifySelf
#define Fields                                                                 \
    NEW_FIELD(std::string, username, USEDBY(payload))                          \
    NEW_FIELD(std::string, avatar, USEDBY(payload))                            \
    STATIC_FIELD(std::string, method, "PATCH")                                 \
    STATIC_FIELD(std::string, target, "/users/@me")                            \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    HIDE_FIELD(payload)                                                        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const json> render_payload() override {
    json out;

    if (_username) {
        out["username"] = *_username;
    }

    if (_avatar) {
        out["avatar"] = *_avatar;
    }

    return std::make_shared<const json>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#get-current-user-guilds
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetCurrentUserGuildsCall
#define function getCurrentUserGuilds, getOwnGuilds
#define Fields                                                                 \
    NEW_FIELD(snowflake, before, USEDBY(target))                               \
    NEW_FIELD(snowflake, after, USEDBY(target))                                \
    NEW_FIELD(int, limit, USEDBY(target))                                      \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    std::string out = "/users/@me/guilds";
    bool first = true;
    if (_before) {
        out += fmt::format("{}before={}", first ? "?" : "&", *_before);
        first = false;
    }
    if (_after) {
        out += fmt::format("{}after={}", first ? "?" : "&", *_after);
        first = false;
    }
    if (_limit) {
        out += fmt::format("{}limit={}", first ? "?" : "&", *_limit);
        first = false;
    }
    return std::make_shared<const std::string>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#leave-guild
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class LeaveGuildCall
#define function leaveGuild
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "DELETE")                                \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Get Reactions needs a Guild ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/users/@me/guilds/{}", *_guild_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#create-dm
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class CreateDMCall
#define function createDM
#define Fields                                                                 \
    NEW_FIELD(snowflake, recipient_id, USEDBY(payload))                        \
    STATIC_FIELD(std::string, method, "POST")                                  \
    STATIC_FIELD(std::string, target, "/users/@me/channels")                   \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    HIDE_FIELD(payload)                                                        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const json> render_payload() override {
    if (!_recipient_id) {
        throw std::logic_error("Create DM needs a Recipient ID");
    }
    json out({{"recipient_id", std::to_string(*_recipient_id)}});
    return std::make_shared<const json>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#create-group-dm
// Broken payload identified by Westlanderz/SenpaiR6#1717
// Verified by UndarkAido/Aido#8614
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class CreateGroupDMCall
#define function createGroupDM
#define COMMA ,
#define Fields                                                                 \
    NEW_FIELD(std::vector<std::string>, access_tokens, USEDBY(payload))        \
    NEW_FIELD(std::map<snowflake COMMA std::string>, nicks, USEDBY(payload))   \
    STATIC_FIELD(std::string, method, "POST")                                  \
    STATIC_FIELD(std::string, target, "/users/@me/channels")                   \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    HIDE_FIELD(payload)                                                        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const json> render_payload() override {
    if (!_access_tokens) {
        throw std::logic_error("Create Group DM needs Access Tokens");
    }
    json out({{"access_tokens", *_access_tokens}});

    if (_nicks) {
        out["nicks"] = {};
        for (auto nick : *_nicks) {
            out["nicks"][std::to_string(nick.first)] = nick.second;
        }
    }
    return std::make_shared<const json>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>
#undef COMMA

// https://discord.com/developers/docs/resources/user#get-user-connections
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetUserConnectionsCall
#define function                                                               \
    getUserConnections, getCurrentUserConnections, getOwnConnections
#define Fields                                                                 \
    STATIC_FIELD(std::string, method, "GET")                                   \
    STATIC_FIELD(std::string, target, "/users/@me/connections")                \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>
