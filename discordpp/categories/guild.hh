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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::string, region, USEDBY(payload))
NEW_FIELD(std::string, icon, USEDBY(payload))
NEW_FIELD(int, verification_level, USEDBY(payload))
NEW_FIELD(int, default_message_notifications, USEDBY(payload))
NEW_FIELD(int, explicit_content_filter, USEDBY(payload))
NEW_FIELD(std::vector<json>, roles, USEDBY(payload))
NEW_FIELD(std::vector<json>, channels, USEDBY(payload))
NEW_FIELD(Snowflake, afk_channel_id, USEDBY(payload))
NEW_FIELD(int, afk_timeout, USEDBY(payload))
NEW_FIELD(Snowflake, system_channel_id, USEDBY(payload))
NEW_FIELD(int, system_channel_flags, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
STATIC_FIELD(std::string, target, "/users/@me/channels")
HIDE_FIELD(type)
HIDE_FIELD(body)
HIDE_FIELD(payload)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(bool, with_counts, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::string, region, USEDBY(payload))
NEW_FIELD(int, verification_level, USEDBY(payload))
NEW_FIELD(int, default_message_notifications, USEDBY(payload))
NEW_FIELD(int, explicit_content_filter, USEDBY(payload))
NEW_FIELD(Snowflake, afk_channel_id, USEDBY(payload))
NEW_FIELD(int, afk_timeout, USEDBY(payload))
NEW_FIELD(std::string, icon, USEDBY(payload))
NEW_FIELD(Snowflake, owner_id, USEDBY(payload))
NEW_FIELD(std::string, splash, USEDBY(payload))
NEW_FIELD(std::string, discovery_splash, USEDBY(payload))
NEW_FIELD(std::string, banner, USEDBY(payload))
NEW_FIELD(Snowflake, system_channel_id, USEDBY(payload))
NEW_FIELD(int, system_channel_flags, USEDBY(payload))
NEW_FIELD(Snowflake, rules_channel_id, USEDBY(payload))
NEW_FIELD(Snowflake, public_updates_channel_id, USEDBY(payload))
NEW_FIELD(std::string, preferred_locale, USEDBY(payload))
NEW_FIELD(std::vector<std::string>, features, USEDBY(payload))
NEW_FIELD(std::string, description, USEDBY(payload))
STATIC_FIELD(std::string, method, "PATCH")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
HIDE_FIELD(payload)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(int, type, USEDBY(payload))
NEW_FIELD(std::string, topic, USEDBY(payload))
NEW_FIELD(int, bitrate, USEDBY(payload))
NEW_FIELD(int, user_limit, USEDBY(payload))
NEW_FIELD(int, rate_limit_per_user, USEDBY(payload))
NEW_FIELD(int, position, USEDBY(payload))
NEW_FIELD(std::vector<json>, permission_overwrites, USEDBY(payload))
NEW_FIELD(Snowflake, parent_id, USEDBY(payload))
NEW_FIELD(bool, nsfw, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
HIDE_FIELD(payload)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, id, USEDBY(payload))
NEW_FIELD(int, position, USEDBY(payload))
NEW_FIELD(bool, lock_permissions, USEDBY(payload))
NEW_FIELD(Snowflake, parent_id, USEDBY(payload))
STATIC_FIELD(std::string, method, "PATCH")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
HIDE_FIELD(payload)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{guild.id}/threads/active", ARR(guild_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-member
// TODO unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildMemberCall
#define function getGuildMember
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(int, limit, USEDBY(target))
NEW_FIELD(Snowflake, after, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::string, query, USEDBY(target))
NEW_FIELD(int, limit, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/members/search", ARR(guild_id), QSR(query) QSO(limit))
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#add-guild-member
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class AddGuildMemberCall
#define function addGuildMember
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
NEW_FIELD(std::string, access_token, USEDBY(payload))
NEW_FIELD(std::string, nick, USEDBY(payload))
NEW_FIELD(std::vector<Snowflake>, roles, USEDBY(payload))
NEW_FIELD(bool, mute, USEDBY(payload))
NEW_FIELD(bool, deaf, USEDBY(payload))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/guilds/{}/members/{}", ARR(guild_id, user_id), )
AUTO_PAYLOAD(PFR(access_token) PFO(nick) PFO(roles) PFO(mute) PFO(deaf))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#modify-guild-member
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyGuildMemberCall
#define function modifyGuildMember
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
NEW_FIELD(std::string, nick, USEDBY(payload))
NEW_FIELD(std::vector<Snowflake>, roles, USEDBY(payload))
NEW_FIELD(bool, mute, USEDBY(payload))
NEW_FIELD(bool, deaf, USEDBY(payload))
NEW_FIELD(Snowflake, channel_id, USEDBY(payload))
STATIC_FIELD(std::string, method, "PATCH")
AUTO_TARGET("/guilds/{}/members/{}", ARR(guild_id, user_id),)
AUTO_PAYLOAD(PFO(nick) PFO(roles) PFO(mute) PFO(deaf) PFO(channel_id))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#modify-current-user-nick
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyCurrentUserNickCall
#define function modifyCurrentUserNick
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::optional<std::string>, nick, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/guilds/{}/members/@me/nick", ARR(guild_id), )
AUTO_PAYLOAD(PFO(nick))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#add-guild-member-role
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class AddGuildMemberRoleCall
#define function addGuildMemberRole
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
NEW_FIELD(Snowflake, role_id, USEDBY(target))
STATIC_FIELD(std::string, method, "PUT")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
NEW_FIELD(Snowflake, role_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
NEW_FIELD(int, delete_message_days, USEDBY(payload))
NEW_FIELD(std::string, reason, USEDBY(payload))
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
HIDE_FIELD(payload)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
HIDE_FIELD(target)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
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
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/roles", ARR(guild_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#create-guild-role
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class CreateGuildRoleCall
#define function createGuildRole
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(std::string, permissions, USEDBY(payload))
NEW_FIELD(int, color, USEDBY(payload))
NEW_FIELD(bool, hoist, USEDBY(payload))
NEW_FIELD(bool, mentionable, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/guilds/{}/roles", ARR(guild_id), )
AUTO_PAYLOAD(PFR(name) PFR(permissions) PFR(color) PFR(hoist) PFR(mentionable))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#modify-guild-role-positions
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyGuildRolePositionsCall
#define function modifyGuildRolePositions
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, id, USEDBY(payload))
NEW_FIELD(int, position, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/guilds/{}/roles", ARR(guild_id), )
HIDE_FIELD(payload)
protected:
sptr<const json> render_payload() override {
    json out;
    REQUIRE_VAR(id);
    out["id"] = *_id;
    PFO(position);
    return std::make_shared<const json>(out);
}
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#modify-guild-role
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyGuildRoleCall
#define function modifyGuildRole
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, role_id, USEDBY(target))
NEW_FIELD(std::optional<std::string>, name, USEDBY(payload))
NEW_FIELD(std::optional<std::string>, permissions, USEDBY(payload))
NEW_FIELD(std::optional<int>, color, USEDBY(payload))
NEW_FIELD(std::optional<bool>, hoist, USEDBY(payload))
NEW_FIELD(std::optional<bool>, mentionable, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/guilds/{}/roles/{}", ARR(guild_id, role_id), )
AUTO_PAYLOAD(PFO(name) PFO(permissions) PFO(color) PFO(hoist) PFO(mentionable))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#delete-guild-role
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class DeleteGuildRoleCall
#define function deleteGuildRole
#include <discordpp/macros/defineCallOpen.hh>
STATIC_FIELD(std::string, method, "DELETE")
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, role_id, USEDBY(target))
AUTO_TARGET("/guilds/{}/roles/{}", ARR(guild_id, role_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-prune-count
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildPruneCountCall
#define function getGuildPruneCount
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(int, days, USEDBY(target))
NEW_FIELD(std::vector<Snowflake>, include_roles, USEDBY(target))
HIDE_FIELD(target)
protected:
sptr<const std::string> render_target() override {
    REQUIRE_VAR(guild_id)
    std::string out = fmt::format("/guilds/{}/roles", to_string(*_guild_id));
    bool first = true;
    if (_days) {
        out += fmt::format("{}days={}", first ? "?" : "&", *_days);
        first = false;
    }
    if (_include_roles) {
        out += fmt::format("{}include_roles={}", first ? "?" : "&", [this]() {
            std::string out;
            bool first = true;
            std::for_each(_include_roles->begin(), _include_roles->end(),
                          [&first, &out](Snowflake &sf) {
                              out += fmt::format("{}{}", first ? "" : ",",
                                                 to_string(sf));
                              first = false;
                          });
            return std::move(out);
        });
        first = false;
    };
    return std::make_shared<const std::string>(out);
}
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#begin-guild-prune
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class BeginGuildPruneCall
#define function beginGuildPrune
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(int, days, USEDBY(payload))
NEW_FIELD(bool, compute_prune_count, USEDBY(payload))
NEW_FIELD(std::vector<Snowflake>, include_roles, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/guilds/{}/prune", ARR(guild_id), )
AUTO_PAYLOAD(PFO(guild_id) PFO(days) PFO(include_roles))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-voice-regions
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildVoiceRegionsCall
#define function getGuildVoiceRegions
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
AUTO_TARGET("/guilds/{}/regions", ARR(guild_id), )
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-invites
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildInvitesCall
#define function getGuildInvites
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
AUTO_TARGET("/guilds/{}/invites", ARR(guild_id), )
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-integrations
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildIntegrationsCall
#define function getGuildIntegrations
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
AUTO_TARGET("/guilds/{}/integrations", ARR(guild_id), )
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#delete-guild-integration
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class DeleteGuildIntegrationsCall
#define function deleteGuildIntegrations
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, interaction_id, USEDBY(target))
AUTO_TARGET("/guilds/{}/integrations/{}", ARR(guild_id, interaction_id), )
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-widget-settings
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildWidgetSettingsCall
#define function getGuildWidgetSettings
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
AUTO_TARGET("/guilds/{}/widget", ARR(guild_id), )
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#modify-guild-widget
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyGuildWidgetCall
#define function modifyGuildWidget
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(bool, enabled, USEDBY(payload))
NEW_FIELD(std::optional<Snowflake>, channel_id, USEDBY(payload))
AUTO_TARGET("/guilds/{}/widget", ARR(guild_id), )
AUTO_PAYLOAD(PFO(enabled) PFO(channel_id))
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-widget
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildWidgetCall
#define function getGuildWidget
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
AUTO_TARGET("/guilds/{}/widget.json", ARR(guild_id), )
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-vanity-url
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetVanityURLCall
#define function getVanityURL
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
AUTO_TARGET("/guilds/{}/vanity-url", ARR(guild_id), )
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-widget-image
// TODO Unverified
#define Bot PluginEndpoints
#define Parent Call
#define Class GetGuildWidgetImageCall
#define function getGuildWidgetImage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::string, style, USEDBY(target))
auto style(const WidgetStyleOptions &styleIn) {
    static const char *strs[] = {"shield", "banner1", "banner2", "banner3",
                                 "banner4"};
    return style(std::make_shared<std::string>(strs[styleIn]));
}
AUTO_TARGET("/guilds/{}/widget.png", ARR(guild_id), QSO(style))
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#get-guild-welcome-screen
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class GetGuildWelcomeScreenCall
#define function getGuildWelcomeScreen
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
AUTO_TARGET("/guilds/{}/welcome-screen", ARR(guild_id), )
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#modify-guild-welcome-screen
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyGuildWelcomeScreenCall
#define function modifyGuildWelcomeScreen
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::optional<bool>, enabled, USEDBY(payload))
NEW_FIELD(std::optional<std::vector<json>>, welcome_channels, USEDBY(payload))
NEW_FIELD(std::optional<std::string>, description, USEDBY(payload))
AUTO_TARGET("/guilds/{}/welcome-screen", ARR(guild_id), )
STATIC_FIELD(std::string, method, "PATCH")
AUTO_PAYLOAD(PFO(enabled) PFO(welcome_channels) PFO(description))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#modify-current-user-voice-state
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyCurrentUserVoiceStateCall
#define function modifyCurrentUserVoiceState
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, channel_id, USEDBY(payload))
NEW_FIELD(bool, suppress, USEDBY(payload))
NEW_FIELD(std::optional<std::string>, request_to_speak_timestamp,
          USEDBY(payload))
AUTO_TARGET("/guilds/{}/voice-states/@me", ARR(guild_id), )
STATIC_FIELD(std::string, method, "PATCH")
HIDE_FIELD(payload)
protected:
sptr<const json> render_payload() override {
    json out;
    if (_channel_id) {
        out["channel_id"] = to_string(*_channel_id);
    }
    PFO(suppress)
    PFO(request_to_speak_timestamp)
    return std::make_shared<const json>(std::move(out));
}
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild#modify-user-voice-state
// TODO Unverified
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyUserVoiceStateCall
#define function modifyUserVoiceState
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
NEW_FIELD(Snowflake, channel_id, USEDBY(payload))
NEW_FIELD(bool, suppress, USEDBY(payload))
AUTO_TARGET("/guilds/{}/voice-states/{}}", ARR(guild_id, user_id), )
STATIC_FIELD(std::string, method, "PATCH")
HIDE_FIELD(payload)
protected:
sptr<const json> render_payload() override {
    json out;
    if (_channel_id) {
        out["channel_id"] = to_string(*_channel_id);
    }
    PFO(suppress)
    return std::make_shared<const json>(std::move(out));
}
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
