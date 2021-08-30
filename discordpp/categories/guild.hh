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

// https://discord.com/developers/docs/resources/guild#create-guild
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class CreateGuildCall
#define function createGuild
#define Fields                                                                 \
    NEW_FIELD(std::string, name, USEDBY(payload))                              \
    NEW_FIELD(std::string, region, USEDBY(payload))                            \
    NEW_FIELD(std::string, icon, USEDBY(payload))                              \
    NEW_FIELD(int, verification_level, USEDBY(payload))                        \
    NEW_FIELD(int, default_message_notifications, USEDBY(payload))             \
    NEW_FIELD(int, explicit_content_filter, USEDBY(payload))                   \
    NEW_FIELD(std::vector<json>, roles, USEDBY(payload))                       \
    NEW_FIELD(std::vector<json>, channels, USEDBY(payload))                    \
    NEW_FIELD(snowflake, afk_channel_id, USEDBY(payload))                      \
    NEW_FIELD(int, afk_timeout, USEDBY(payload))                               \
    NEW_FIELD(snowflake, system_channel_id, USEDBY(payload))                   \
    NEW_FIELD(int, system_channel_flags, USEDBY(payload))                      \
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
    if (!_name) {
        throw std::logic_error("Create Guild needs a Name");
    }
    json out({{"name", *_name}});
    if (_region) {
        out["region"] = *_region;
    }
    if (_icon) {
        out["icon"] = *_icon;
    }
    if (_verification_level) {
        out["verification_level"] = *_verification_level;
    }
    if (_default_message_notifications) {
        out["default_message_notifications"] = *_default_message_notifications;
    }
    if (_explicit_content_filter) {
        out["explicit_content_filter"] = *_explicit_content_filter;
    }
    return std::make_shared<const json>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildCall
#define function getGuild
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(bool, with_counts, USEDBY(target))                               \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Get Guild needs a Guild ID");
    }
    std::string out = fmt::format("/guilds/{}", *_guild_id);
    bool first = true;
    if (_with_counts) {
        out += fmt::format("{}with_counts={}", first ? "?" : "&",
                           *_with_counts ? "true" : "false");
        first = false;
    }
    return std::make_shared<const std::string>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#modify-guild
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class GetGuildPreviewCall
#define function getGuildPreview
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(std::string, name, USEDBY(payload))                              \
    NEW_FIELD(std::string, region, USEDBY(payload))                            \
    NEW_FIELD(int, verification_level, USEDBY(payload))                        \
    NEW_FIELD(int, default_message_notifications, USEDBY(payload))             \
    NEW_FIELD(int, explicit_content_filter, USEDBY(payload))                   \
    NEW_FIELD(snowflake, afk_channel_id, USEDBY(payload))                      \
    NEW_FIELD(int, afk_timeout, USEDBY(payload))                               \
    NEW_FIELD(std::string, icon, USEDBY(payload))                              \
    NEW_FIELD(snowflake, owner_id, USEDBY(payload))                            \
    NEW_FIELD(std::string, splash, USEDBY(payload))                            \
    NEW_FIELD(std::string, discovery_splash, USEDBY(payload))                  \
    NEW_FIELD(std::string, banner, USEDBY(payload))                            \
    NEW_FIELD(snowflake, system_channel_id, USEDBY(payload))                   \
    NEW_FIELD(int, system_channel_flags, USEDBY(payload))                      \
    NEW_FIELD(snowflake, rules_channel_id, USEDBY(payload))                    \
    NEW_FIELD(snowflake, public_updates_channel_id, USEDBY(payload))           \
    NEW_FIELD(std::string, preferred_locale, USEDBY(payload))                  \
    NEW_FIELD(std::vector<std::string>, features, USEDBY(payload))             \
    NEW_FIELD(std::string, description, USEDBY(payload))                       \
    STATIC_FIELD(std::string, method, "PATCH")                                 \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    HIDE_FIELD(payload)                                                        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Modify Guild needs a Guild ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}", *_guild_id));
}
sptr<const json> render_payload() override {
    if (!_name) {
        throw std::logic_error("Modify Guild needs a Name");
    }
    json out({"name", *_name});
    if (_region) {
        out["region"] = *_region;
    }
    if (_verification_level) {
        out["verification_level"] = *_verification_level;
    }
    if (_default_message_notifications) {
        out["default_message_notifications"] = *_default_message_notifications;
    }
    if (_explicit_content_filter) {
        out["explicit_content_filter"] = *_explicit_content_filter;
    }
    if (_afk_channel_id) {
        out["afk_channel_id"] = std::to_string(*_afk_channel_id);
    }
    if (_afk_timeout) {
        out["afk_timeout"] = *_afk_timeout;
    }
    if (_icon) {
        out["icon"] = *_icon;
    }
    if (_owner_id) {
        out["owner_id"] = std::to_string(*_owner_id);
    }
    if (_splash) {
        out["splash"] = *_splash;
    }
    if (_discovery_splash) {
        out["discovery_splash"] = *_discovery_splash;
    }
    if (_banner) {
        out["banner"] = *_banner;
    }
    if (_system_channel_id) {
        out["system_channel_id"] = std::to_string(*_system_channel_id);
    }
    if (_system_channel_flags) {
        out["system_channel_flags"] = *_system_channel_flags;
    }
    if (_rules_channel_id) {
        out["rules_channel_id"] = std::to_string(*_rules_channel_id);
    }
    if (_public_updates_channel_id) {
        out["public_updates_channel_id"] =
            std::to_string(*_public_updates_channel_id);
    }
    if (_preferred_locale) {
        out["preferred_locale"] = *_preferred_locale;
    }
    if (_features) {
        out["features"] = *_features;
    }
    if (_description) {
        out["description"] = *_description;
    }
    return std::make_shared<const json>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#delete-guild
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class DeleteGuildCall
#define function deleteGuild
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
        throw std::logic_error("Delete Guild needs a Guild ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}", *_guild_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-channels
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildChannelsCall
#define function getGuildChannels
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Get Guild Channels needs a Guild ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/channels", *_guild_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#create-guild-channels
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class CreateGuildChannelsCall
#define function createGuildChannels
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(std::string, name, USEDBY(payload))                              \
    NEW_FIELD(int, type, USEDBY(payload))                                      \
    NEW_FIELD(std::string, topic, USEDBY(payload))                             \
    NEW_FIELD(int, bitrate, USEDBY(payload))                                   \
    NEW_FIELD(int, user_limit, USEDBY(payload))                                \
    NEW_FIELD(int, rate_limit_per_user, USEDBY(payload))                       \
    NEW_FIELD(int, position, USEDBY(payload))                                  \
    NEW_FIELD(std::vector<json>, permission_overwrites, USEDBY(payload))       \
    NEW_FIELD(snowflake, parent_id, USEDBY(payload))                           \
    NEW_FIELD(bool, nsfw, USEDBY(payload))                                     \
    STATIC_FIELD(std::string, method, "POST")                                  \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    HIDE_FIELD(payload)                                                        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Create Guild Channel needs a Guild ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/channels", *_guild_id));
}
sptr<const json> render_payload() override {
    if (!_name) {
        throw std::logic_error("Create Guild Channel needs a name");
    }
    if (!_type) {
        throw std::logic_error("Create Guild Channel needs a type");
    }
    if (*_type == 2 || *_type == 13) {
        if (!_bitrate) {
            throw std::logic_error("Create Guild Channel needs a bitrate");
        }
        if (!_user_limit) {
            throw std::logic_error("Create Guild Channel needs a user limit");
        }
    } else {
        if (!_topic) {
            throw std::logic_error("Create Guild Channel needs a topic");
        }
        if (!_rate_limit_per_user) {
            throw std::logic_error(
                "Create Guild Channel needs a rate limit per user");
        }
    }
    if (!_position) {
        throw std::logic_error("Create Guild Channel needs a position");
    }
    if (!_permission_overwrites) {
        throw std::logic_error(
            "Create Guild Channel needs a permission overwrites array");
    }
    if (!_parent_id) {
        throw std::logic_error("Create Guild Channel needs a parent id");
    }
    if (!_nsfw) {
        throw std::logic_error(
            "Create Guild Channel needs a nsfw classification");
    }
    json out{{"name", *_name},
             {"type", *_type},
             {"position", *_position},
             {"permission_overwrites", *_permission_overwrites},
             {"parent_id", std::to_string(*_parent_id)},
             {"nsfw", *_nsfw}};

    if (*_type == 2 || *_type == 13) {
        out["bitrate"] = *_bitrate;
        out["user_limit"] = *_user_limit;
    } else {
        out["topic"] = *_topic;
        out["rate_limit_per_user"] = *_rate_limit_per_user;
    }

    return std::make_shared<const json>(out);
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#create-guild-channels
// TODO unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyGuildChannelPositionsCall
#define function modifyGuildChannelPositions
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(snowflake, id, USEDBY(payload))                                  \
    NEW_FIELD(int, position, USEDBY(payload))                                  \
    NEW_FIELD(bool, lock_permissions, USEDBY(payload))                         \
    NEW_FIELD(snowflake, parent_id, USEDBY(payload))                           \
    STATIC_FIELD(std::string, method, "PATCH")                                 \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    HIDE_FIELD(payload)                                                        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Create Guild Channel needs a Guild ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/channels", *_guild_id));
}
sptr<const json> render_payload() override {
    if (!_id) {
        throw std::logic_error("Create Guild Channel needs a channel id");
    }
    json out{{"id", *_id}};

    if (_position) {
        out["position"] = *_position;
    }
    if (_lock_permissions) {
        out["lock_permissions"] = *_lock_permissions;
    }
    if (_parent_id) {
        out["parent_id"] = std::to_string(*_parent_id);
    }

    return std::make_shared<const json>(out);
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#list-active-threads
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class ListActiveThreadsCall
#define function listActiveThreads
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "GET")                                   \
    AUTO_TARGET("/guilds/{guild.id}/threads/active", ARR(guild_id), )          \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-member
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildMemberCall
#define function getGuildMember
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
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
    if (!_guild_id) {
        throw std::logic_error("Get Guild Member needs a Guild ID");
    }
    if (!_user_id) {
        throw std::logic_error("Get Guild Member needs a User ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/members/{}", *_guild_id, *_user_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#list-guild-members
// Verified by Westlanderz/SenpaiR6#1717
#define Bot PluginEndpoints
#define Parent Call
#define Class ListGuildMembersCall
#define function listGuildMembers
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(int, limit, USEDBY(target))                                      \
    NEW_FIELD(snowflake, after, USEDBY(target))                                \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("List Guild Members needs a Guild ID");
    }
    std::string out = fmt::format("/guilds/{}/members", *_guild_id);
    bool first = true;
    if (_limit) {
        out += fmt::format("{}limit={}", first ? "?" : "&", *_limit);
        first = false;
    }
    if (_after) {
        out += fmt::format("{}after={}", first ? "?" : "&", *_after);
        first = false;
    }
    return std::make_shared<const std::string>(out);
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#search-guild-members
// Verified by Westlanderz/SenpaiR6#1717
#define Bot PluginEndpoints
#define Parent Call
#define Class SearchGuildMembersCall
#define function searchGuildMembers
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(std::string, query, USEDBY(target))                              \
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
    if (!_guild_id) {
        throw std::logic_error("Search Guild Members needs a Guild ID");
    }
    if (!_query) {
        throw std::logic_error("Search Guild Members needs a Query");
    }
    std::string out =
        fmt::format("/guilds/{}/members/search?query={}", *_guild_id, *_query);
    if (_limit) {
        out += fmt::format("&limit={}", *_limit);
    }
    return std::make_shared<const std::string>(out);
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#add-guild-member
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class AddGuildMemberCall
#define function addGuildMember
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(snowflake, user_id, USEDBY(target))                              \
    NEW_FIELD(std::string, access_token, USEDBY(payload))                      \
    NEW_FIELD(std::string, nick, USEDBY(payload))                              \
    NEW_FIELD(std::vector<snowflake>, roles, USEDBY(payload))                  \
    NEW_FIELD(bool, mute, USEDBY(payload))                                     \
    NEW_FIELD(bool, deaf, USEDBY(payload))                                     \
    STATIC_FIELD(std::string, method, "PUT")                                   \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    HIDE_FIELD(payload)                                                        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Add Guild Member needs a Guild ID");
    }
    if (!_user_id) {
        throw std::logic_error("Add Guild Member needs a User ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/members/{}", *_guild_id, *_user_id));
}
sptr<const json> render_payload() override {
    if (!_access_token) {
        throw std::logic_error("Add Guild Member needs an Access Token");
    }
    json out({{"access_token", *_access_token}});
    if (_nick) {
        out["nick"] = *_nick;
    }
    if (_roles) {
        out["roles"] = json::array();
        std::transform(std::begin(*_roles), std::end(*_roles),
                       std::back_inserter(out["roles"]),
                       [](double d) { return std::to_string(d); });
    }
    if (_mute) {
        out["mute"] = *_mute;
    }
    if (_deaf) {
        out["deaf"] = *_deaf;
    }
    return std::make_shared<const json>(out);
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#modify-guild-member
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyGuildMemberCall
#define function modifyGuildMember
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(snowflake, user_id, USEDBY(target))                              \
    NEW_FIELD(std::string, nick, USEDBY(payload))                              \
    NEW_FIELD(std::vector<snowflake>, roles, USEDBY(payload))                  \
    NEW_FIELD(bool, mute, USEDBY(payload))                                     \
    NEW_FIELD(bool, deaf, USEDBY(payload))                                     \
    NEW_FIELD(snowflake, channel_id, USEDBY(payload))                          \
    STATIC_FIELD(std::string, method, "PATCH")                                 \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    HIDE_FIELD(payload)                                                        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Modify Guild Member needs a Guild ID");
    }
    if (!_user_id) {
        throw std::logic_error("Modify Guild Member needs a User ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/members/{}", *_guild_id, *_user_id));
}
sptr<const json> render_payload() override {
    json out;
    if (_nick) {
        out["nick"] = *_nick;
    }
    if (_roles) {
        out["roles"] = json::array();
        std::transform(std::begin(*_roles), std::end(*_roles),
                       std::back_inserter(out["roles"]),
                       [](double d) { return std::to_string(d); });
    }
    if (_mute) {
        out["mute"] = *_mute;
    }
    if (_deaf) {
        out["deaf"] = *_deaf;
    }
    if (_channel_id) {
        out["channel_id"] = std::to_string(*_channel_id);
    }
    return std::make_shared<const json>(out);
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#add-guild-member-role
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class AddGuildMemberRoleCall
#define function addGuildMemberRole
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(snowflake, user_id, USEDBY(target))                              \
    NEW_FIELD(snowflake, role_id, USEDBY(target))                              \
    STATIC_FIELD(std::string, method, "PUT")                                   \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Add Guild Member Role needs a Guild ID");
    }
    if (!_user_id) {
        throw std::logic_error("Add Guild Member Role needs a User ID");
    }
    if (!_role_id) {
        throw std::logic_error("Add Guild Member Role needs a Role ID");
    }
    return std::make_shared<const std::string>(fmt::format(
        "/guilds/{}/members/{}/roles/{}", *_guild_id, *_user_id, *_role_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#remove-guild-member-role
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class RemoveGuildMemberRoleCall
#define function removeGuildMemberRole
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(snowflake, user_id, USEDBY(target))                              \
    NEW_FIELD(snowflake, role_id, USEDBY(target))                              \
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
        throw std::logic_error("Remove Guild Member Role needs a Guild ID");
    }
    if (!_user_id) {
        throw std::logic_error("Remove Guild Member Role needs a User ID");
    }
    if (!_role_id) {
        throw std::logic_error("Remove Guild Member Role needs a Role ID");
    }
    return std::make_shared<const std::string>(fmt::format(
        "/guilds/{}/members/{}/roles/{}", *_guild_id, *_user_id, *_role_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#remove-guild-member
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class RemoveGuildMemberCall
#define function removeGuildMember, kickGuildMember
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(snowflake, user_id, USEDBY(target))                              \
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
        throw std::logic_error("Remove Guild Member Role needs a Guild ID");
    }
    if (!_user_id) {
        throw std::logic_error("Remove Guild Member Role needs a User ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/members/{}", *_guild_id, *_user_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-bans
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildBansCall
#define function getGuildBans, listGuildBans
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Get Guild Bans needs a Guild ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/bans", *_guild_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-ban
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildBanCall
#define function getGuildBan
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
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
    if (!_guild_id) {
        throw std::logic_error("Get Guild Ban needs a Guild ID");
    }
    if (!_user_id) {
        throw std::logic_error("Get Guild Ban needs a User ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/bans/{}", *_guild_id, *_user_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-ban
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class CreateGuildBanCall
#define function createGuildBan, banGuildUser
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(snowflake, user_id, USEDBY(target))                              \
    NEW_FIELD(int, delete_message_days, USEDBY(payload))                       \
    NEW_FIELD(std::string, reason, USEDBY(payload))                            \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    HIDE_FIELD(payload)                                                        \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Create Guild Ban needs a Guild ID");
    }
    if (!_user_id) {
        throw std::logic_error("Create Guild Ban needs a User ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/bans/{}", *_guild_id, *_user_id));
}
sptr<const json> render_payload() override {
    json out;
    if (_delete_message_days) {
        out["delete_message_days"] = *_delete_message_days;
    }
    if (_reason) {
        out["reason"] = *_reason;
    }
    return std::make_shared<const json>(out);
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#remove-guild-ban
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class RemoveGuildBanCall
#define function removeGuildBan, unbanGuildMember
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    NEW_FIELD(snowflake, user_id, USEDBY(target))                              \
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
        throw std::logic_error("Remove Guild Ban needs a Guild ID");
    }
    if (!_user_id) {
        throw std::logic_error("Remove Guild Ban needs a User ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/bans/{}", *_guild_id, *_user_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-roles
// Verified by Westlanderz/SenpaiR6#1717
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildRolesCall
#define function getGuildRoles
#define Fields                                                                 \
    NEW_FIELD(snowflake, guild_id, USEDBY(target))                             \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(target)                                                         \
    HIDE_FIELD(type)                                                           \
    HIDE_FIELD(body)                                                           \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_guild_id) {
        throw std::logic_error("Get Guild Roles needs a Guild ID");
    }
    return std::make_shared<const std::string>(
        fmt::format("/guilds/{}/roles", *_guild_id));
}
#include <discordpp/macros/defineCallClose.hh>
