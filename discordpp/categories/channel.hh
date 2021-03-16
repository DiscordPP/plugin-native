//
// Created by Aidan on 3/11/2021.
//

#ifndef ENDPOINT_BREAKOUTS
#error This header should only be included in plugin-endpoints.hh
#endif

// https://discord.com/developers/docs/resources/channel#get-channel
#define Bot PluginEndpoints
#define Parent Call
#define Class GetChannelCall
#define function getChannel
#define Fields                                                                 \
    NEW_FIELD(snowflake, channel_id, USEDBY(target))                           \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(std::string, target)                                            \
    HIDE_FIELD(std::string, type)                                              \
    HIDE_FIELD(std::string, body)                                              \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_channel_id)
        throw std::logic_error("Get Channel needs an ID");
    return std::make_shared<const std::string>("/channels/" +
                                               std::to_string(*_channel_id));
}
#include <discordpp/macros/defineCallClose.hh>

enum ChannelType {
    // a text channel within a server
    GUILD_TEXT = 0,
    // a direct message between users
    DM = 1,
    // a voice channel within a server
    GUILD_VOICE = 2,
    // a direct message between multiple users
    GROUP_DM = 3,
    // an organizational category that contains up to 50 channels
    GUILD_CATEGORY = 4,
    // a channel that users can follow and crosspost into their own server
    GUILD_NEWS = 5,
    // a channel in which game developers can sell their game on Discord
    GUILD_STORE = 6
};

// https://discord.com/developers/docs/resources/channel#modify-channel
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class ModifyChannelCall
#define function modifyChannel
#define Fields                                                                 \
    NEW_FIELD(snowflake, channel_id, USEDBY(target))                           \
    NEW_FIELD(std::string, name, USEDBY(payload))                              \
    NEW_FIELD(int, channel_type, USEDBY(payload))                              \
    NEW_FIELD(int, position, USEDBY(payload))                                  \
    NEW_FIELD(std::string, topic, USEDBY(payload))                             \
    NEW_FIELD(bool, nsfw, USEDBY(payload))                                     \
    NEW_FIELD(int, rate_limit_per_user, USEDBY(payload))                       \
    NEW_FIELD(int, bitrate, USEDBY(payload))                                   \
    NEW_FIELD(int, user_limit, USEDBY(payload))                                \
    NEW_FIELD(std::vector<json>, permission_overwrites, USEDBY(payload))       \
    NEW_FIELD(snowflake, parent_id, USEDBY(payload))                           \
    HIDE_FIELD(json, payload)                                                  \
    STATIC_FIELD(std::string, method, "PATCH")                                 \
    HIDE_FIELD(std::string, target)                                            \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_channel_id) {
        throw std::logic_error("Modify Channel needs an ID");
    }
    return std::make_shared<const std::string>("/channels/" +
                                               std::to_string(*_channel_id));
}
sptr<const json> render_payload() override {
    json out;

    out["name"] = *_name;

    if (_channel_type)
        out["type"] = *_channel_type;

    if (_position)
        out["position"] = *_position;

    if (_topic)
        out["topic"] = *_topic;

    if (_nsfw)
        out["nsfw"] = *_nsfw;

    if (_rate_limit_per_user)
        out["rate_limit_per_user"] = *_rate_limit_per_user;

    if (_bitrate)
        out["bitrate"] = *_bitrate;

    if (_user_limit)
        out["user_limit"] = *_user_limit;

    if (_permission_overwrites)
        out["permission_overwrites"] = *_permission_overwrites;

    if (_parent_id)
        out["parent_id"] = std::to_string(*_parent_id);

    return std::make_shared<const json>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#deleteclose-channel
#define Bot PluginEndpoints
#define Parent Call
#define Class DeleteChannelCall
#define function deleteChannel, closeChannel
#define Fields                                                                 \
    NEW_FIELD(snowflake, channel_id, USEDBY(target))                           \
    STATIC_FIELD(std::string, method, "DELETE")                                \
    HIDE_FIELD(std::string, target)                                            \
    HIDE_FIELD(std::string, type)                                              \
    HIDE_FIELD(std::string, body)                                              \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_channel_id)
        throw std::logic_error("Delete/Close Channel needs an ID");
    return std::make_shared<const std::string>("/channels/" +
                                               std::to_string(*_channel_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#get-channel-messages
#define Bot PluginEndpoints
#define Parent JsonCall
#define Class GetChannelMessagesCall
#define function getChannelMessages
#define Fields                                                                 \
    NEW_FIELD(snowflake, channel_id, USEDBY(target))                           \
    NEW_FIELD(snowflake, around, USEDBY(payload))                              \
    NEW_FIELD(snowflake, before, USEDBY(payload))                              \
    NEW_FIELD(snowflake, after, USEDBY(payload))                               \
    NEW_FIELD(int, limit, USEDBY(payload))                                     \
    HIDE_FIELD(json, payload)                                                  \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(std::string, target)                                            \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_channel_id) {
        throw std::logic_error("Get Channel Messages needs an ID");
    }
    return std::make_shared<const std::string>(
        "/channels/" + std::to_string(*_channel_id) + "/messages");
}
sptr<const json> render_payload() override {
    json out;

    if (_around)
        out["around"] = *_around;

    if (_before)
        out["before"] = *_before;

    if (_after)
        out["after"] = *_after;

    if (_limit)
        out["limit"] = *_limit;

    return std::make_shared<const json>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#get-channel
#define Bot PluginEndpoints
#define Parent Call
#define Class GetChannelMessageCall
#define function getChannelMessage
#define Fields                                                                 \
    NEW_FIELD(snowflake, channel_id, USEDBY(target))                           \
    NEW_FIELD(snowflake, message_id, USEDBY(target))                           \
    STATIC_FIELD(std::string, method, "GET")                                   \
    HIDE_FIELD(std::string, target)                                            \
    HIDE_FIELD(std::string, type)                                              \
    HIDE_FIELD(std::string, body)                                              \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_channel_id)
        throw std::logic_error("Get Channel Message needs a Channel ID");
    if (!_message_id)
        throw std::logic_error("Get Channel Message needs a Message ID");
    return std::make_shared<const std::string>(
        "/channels/" + std::to_string(*_channel_id) + "/messages/" +
        std::to_string(*_message_id));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#create-message
#define Bot PluginEndpoints
#define Parent FileCall
#define Class CreateMessageCall
#define function createMessage
#define Fields                                                                 \
    NEW_FIELD(snowflake, channel_id, USEDBY(target))                           \
    NEW_FIELD(std::string, content, USEDBY(payload))                           \
    NEW_FIELD(Nonce, nonce, USEDBY(payload))                                   \
    NEW_FIELD(bool, tts, USEDBY(payload))                                      \
    NEW_FIELD(json, embed, USEDBY(payload))                                    \
    NEW_FIELD(json, allowed_mentions, USEDBY(payload))                         \
    NEW_FIELD(json, message_reference, USEDBY(payload))                        \
    FORWARD_FIELD(std::string, filename, )                                     \
    FORWARD_FIELD(std::string, filetype, )                                     \
    FORWARD_FIELD(std::string, file, )                                         \
    FORWARD_FIELD(json, payload, )                                             \
    FORWARD_FIELD(std::string, target, )                                       \
    FORWARD_FIELD(handleWrite, onWrite, ) FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_channel_id) {
        throw std::logic_error("Create Message needs an ID");
    }
    return std::make_shared<const std::string>(
        "/channels/" + std::to_string(*_channel_id) + "/messages");
}
sptr<const json> render_payload() override {
    json out;

    if (_content)
        out["content"] = *_content;

    if (_nonce)
        out["nonce"] = *_nonce;

    if (_tts)
        out["tts"] = *_tts;

    if (_embed)
        out["embed"] = *_embed;

    if (_allowed_mentions)
        out["allowed_mentions"] = *_allowed_mentions;

    if (_message_reference)
        out["message_reference"] = *_message_reference;

    return std::make_shared<const json>(std::move(out));
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#crosspost-message
#define Bot PluginEndpoints
#define Parent Call
#define Class CrosspostMessageCall
#define function crosspostMessage
#define Fields                                                                 \
    NEW_FIELD(snowflake, channel_id, USEDBY(target))                           \
    NEW_FIELD(snowflake, message_id, USEDBY(target))                           \
    STATIC_FIELD(std::string, method, "POST")                                  \
    HIDE_FIELD(std::string, target)                                            \
    HIDE_FIELD(std::string, type)                                              \
    HIDE_FIELD(std::string, body)                                              \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_channel_id)
        throw std::logic_error("Crosspost Message needs a Channel ID");
    if (!_message_id)
        throw std::logic_error("Crosspost Message needs a Message ID");
    return std::make_shared<const std::string>(
        "/channels/" + std::to_string(*_channel_id) + "/messages/" +
        std::to_string(*_message_id) + "/crosspost");
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#create-reaction
#define Bot PluginEndpoints
#define Parent Call
#define Class CreateReactionCall
#define function createReaction
#define Fields                                                                 \
    NEW_FIELD(snowflake, channel_id, USEDBY(target))                           \
    NEW_FIELD(snowflake, message_id, USEDBY(target))                           \
    NEW_FIELD(std::string, emoji, USEDBY(target))                              \
    STATIC_FIELD(std::string, method, "PUT")                                   \
    HIDE_FIELD(std::string, target)                                            \
    HIDE_FIELD(std::string, type)                                              \
    HIDE_FIELD(std::string, body)                                              \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_channel_id)
        throw std::logic_error("Create Reaction needs a Channel ID");
    if (!_message_id)
        throw std::logic_error("Create Reaction needs a Message ID");
    if (!_emoji)
        throw std::logic_error("Create Reaction needs an emoji");
    return std::make_shared<const std::string>(
        "/channels/" + std::to_string(*_channel_id) + "/messages/" +
        std::to_string(*_message_id) + "/reactions/" +
        util::url_encode(*_emoji) + "/@me");
}
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#delete-own-reaction
// https://discord.com/developers/docs/resources/channel#delete-user-reaction
#define Bot PluginEndpoints
#define Parent Call
#define Class DeleteOwnReactionCall
#define function deleteOwnReaction
#define Fields                                                                 \
    NEW_FIELD(snowflake, channel_id, USEDBY(target))                           \
    NEW_FIELD(snowflake, message_id, USEDBY(target))                           \
    NEW_FIELD(std::string, emoji, USEDBY(target))                              \
    NEW_FIELD(snowflake, user_id, USEDBY(target))                              \
    STATIC_FIELD(std::string, method, "DELETE")                                \
    HIDE_FIELD(std::string, target)                                            \
    HIDE_FIELD(std::string, type)                                              \
    HIDE_FIELD(std::string, body)                                              \
    FORWARD_FIELD(handleWrite, onWrite, )                                      \
    FORWARD_FIELD(handleRead, onRead, )

#include <discordpp/macros/defineCallOpen.hh>
protected:
sptr<const std::string> render_target() override {
    if (!_channel_id)
        throw std::logic_error("Delete Own Reaction needs a Channel ID");
    if (!_message_id)
        throw std::logic_error("Delete Own Reaction needs a Message ID");
    if (!_emoji)
        throw std::logic_error("Delete Own Reaction needs an emoji");
    return std::make_shared<const std::string>(
        "/channels/" + std::to_string(*_channel_id) + "/messages/" +
        std::to_string(*_message_id) + "/reactions/" +
        util::url_encode(*_emoji) + "/" + (!_user_id ? "@me" : std::to_string(*_user_id)));
}
#include <discordpp/macros/defineCallClose.hh>
