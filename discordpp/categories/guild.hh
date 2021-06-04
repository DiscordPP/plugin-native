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

/*// https://discord.com/developers/docs/resources/guild#list-guild-members
// TODO unverified
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
    std::string out = fmt::format("/guilds/{}/members", *_guild_id, *_user_id);
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
#include <discordpp/macros/defineCallClose.hh>*/
