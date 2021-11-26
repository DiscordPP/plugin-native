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
#error This header should only be included in plugin-native.hh
#endif

// https://discord.com/developers/docs/resources/user#get-current-user
// TODO unverified
#define Parent Call
#define Class GetCurrentUserCall
#define function getCurrentUser, getSelf
#include <discordpp/macros/defineCallOpen.hh>
STATIC_FIELD(std::string, method, "GET")
STATIC_FIELD(std::string, target, "/users/@me")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#get-user
// TODO unverified
#define Parent Call
#define Class GetUserCall
#define function getUser
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, user_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/users/{}", ARR(user_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#modify-current-user
// TODO unverified
#define Parent JsonCall
#define Class ModifyCurrentUserCall
#define function modifyCurrentUser, modifySelf
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(std::string, username, USEDBY(payload))
NEW_FIELD(std::string, avatar, USEDBY(payload))
STATIC_FIELD(std::string, method, "PATCH")
STATIC_FIELD(std::string, target, "/users/@me")
HIDE_FIELD(type)
HIDE_FIELD(body)
AUTO_PAYLOAD(PFO(username) PFO(avatar))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#get-current-user-guilds
// TODO unverified
#define Parent Call
#define Class GetCurrentUserGuildsCall
#define function getCurrentUserGuilds, getOwnGuilds
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, before, USEDBY(target))
NEW_FIELD(Snowflake, after, USEDBY(target))
NEW_FIELD(int, limit, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(target)
protected:
sptr<const std::string> render_target() override {
    std::string out = "/users";
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
    };
    return std::make_shared<const std::string>(out);
}
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#leave-guild
// TODO unverified
#define Parent Call
#define Class LeaveGuildCall
#define function leaveGuild
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/users/{}", ARR(guild_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#create-dm
// TODO unverified
#define Parent JsonCall
#define Class CreateDMCall
#define function createDM
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, recipient_id, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
STATIC_FIELD(std::string, target, "/users/@me/channels")
AUTO_PAYLOAD(PFR(recipient_id))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#create-group-dm
// Broken payload identified by Westlanderz/SenpaiR6#1717
// Verified by UndarkAido/Aido#8614
#define Parent JsonCall
#define Class CreateGroupDMCall
#define function createGroupDM
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(std::vector<std::string>, access_tokens, USEDBY(payload))
#define COMMA ,
NEW_FIELD(std::map<Snowflake COMMA std::string>, nicks, USEDBY(payload))
#undef COMMA
STATIC_FIELD(std::string, method, "POST")
STATIC_FIELD(std::string, target, "/users/@me/channels")
HIDE_FIELD(type)
HIDE_FIELD(body)
AUTO_PAYLOAD(PFR(access_tokens) PFO(nicks))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/user#get-user-connections
// TODO unverified
#define Parent Call
#define Class GetUserConnectionsCall
#define function                                                               \
    getUserConnections, getCurrentUserConnections, getOwnConnections
#include <discordpp/macros/defineCallOpen.hh>
STATIC_FIELD(std::string, method, "GET")
STATIC_FIELD(std::string, target, "/users/@me/connections")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
