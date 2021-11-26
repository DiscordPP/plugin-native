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

// https://discord.com/developers/docs/resources/channel#get-channel
// TODO unverified
#define Parent Call
#define Class GetChannelCall
#define function getChannel
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/channels/{}", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#modify-channel
// TODO unverified
#define Parent JsonCall
#define Class ModifyChannelCall
#define function modifyChannel
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(int, channel_type, USEDBY(payload))
NEW_FIELD(int, position, USEDBY(payload))
NEW_FIELD(std::string, topic, USEDBY(payload))
NEW_FIELD(bool, nsfw, USEDBY(payload))
NEW_FIELD(int, rate_limit_per_user, USEDBY(payload))
NEW_FIELD(int, bitrate, USEDBY(payload))
NEW_FIELD(int, user_limit, USEDBY(payload))
NEW_FIELD(std::vector<Overwrite>, permission_overwrites, USEDBY(payload))
NEW_FIELD(Snowflake, parent_id, USEDBY(payload))
STATIC_FIELD(std::string, method, "PATCH")
AUTO_TARGET("/channels/{}", ARR(channel_id), )
AUTO_PAYLOAD(PFO(name) PFO(channel_type) PFO(position) PFO(topic) PFO(nsfw)
                 PFO(rate_limit_per_user) PFO(bitrate) PFO(user_limit)
                     PFO(permission_overwrites) PFO(parent_id))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#deleteclose-channel
// TODO unverified
#define Parent Call
#define Class DeleteChannelCall
#define function deleteChannel, closeChannel
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/channels/{}", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#get-channel-messages
// TODO unverified
#define Parent Call
#define Class GetChannelMessagesCall
#define function getChannelMessages
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, around, USEDBY(target))
NEW_FIELD(Snowflake, before, USEDBY(target))
NEW_FIELD(Snowflake, after, USEDBY(target))
NEW_FIELD(int, limit, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/channels/{}/messages", ARR(channel_id),
            QSO(around) QSO(before) QSO(after) QSO(limit))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#get-channel
// TODO unverified
#define Parent Call
#define Class GetChannelMessageCall
#define function getChannelMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/channels/{}/messages/{}", ARR(channel_id, message_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#create-message
// UndarkAido/Aido#8614 verified channel_id, content, filename, filetype, file
// vymishiscool/Vym#2162 verified embeds
// TODO nonce, tts, allowed_mentions, and message_reference are unverified
#define Parent FileCall
#define Class CreateMessageCall
#define function createMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(std::string, content, USEDBY(payload))
NEW_FIELD(Nonce, nonce, USEDBY(payload))
NEW_FIELD(bool, tts, USEDBY(payload))
NEW_FIELD(std::vector<json>, embeds, USEDBY(payload))
NEW_FIELD(json, allowed_mentions, USEDBY(payload))
NEW_FIELD(json, message_reference, USEDBY(payload))
FORWARD_FIELD(std::string, filename, )
FORWARD_FIELD(std::string, filetype, )
FORWARD_FIELD(std::string, file, )
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/channels/{}/messages", ARR(channel_id), )
AUTO_PAYLOAD(PFO(content) PFO(nonce) PFO(tts) PFO(embeds) PFO(allowed_mentions)
                 PFO(message_reference))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#crosspost-message
// TODO unverified
#define Parent Call
#define Class CrosspostMessageCall
#define function crosspostMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/channels/{}/messages/{}/crosspost", ARR(channel_id, message_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#create-reaction
// TODO unverified
#define Parent Call
#define Class CreateReactionCall
#define function createReaction
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
NEW_FIELD(std::string, emoji, USEDBY(target))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/channels/{}/messages/{}/reactions/{}/@me",
            ARR(channel_id, message_id, emoji), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#delete-own-reaction
// TODO unverified
#define Parent Call
#define Class DeleteOwnReactionCall
#define function deleteOwnReaction
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
NEW_FIELD(std::string, emoji, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
HIDE_FIELD(target)
protected:
sptr<const std::string> render_target() override {
    REQUIRE_VAR(channel_id)
    REQUIRE_VAR(message_id)
    REQUIRE_VAR(emoji)
    REQUIRE_VAR(user_id)
    return std::make_shared<const std::string>(
        fmt::format("/channels/{}/messages/{}/reactions/{}/@me",
                    std::to_string(*_channel_id), std::to_string(*_message_id),
                    util::url_encode(*_emoji)));
}
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#delete-user-reaction
// TODO unverified
#define Parent Call
#define Class DeleteUserReactionCall
#define function deleteUserReaction
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
NEW_FIELD(std::string, emoji, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
HIDE_FIELD(target)
protected:
sptr<const std::string> render_target() override {
    REQUIRE_VAR(channel_id)
    REQUIRE_VAR(message_id)
    REQUIRE_VAR(emoji)
    REQUIRE_VAR(user_id)
    return std::make_shared<const std::string>(
        fmt::format("/channels/{}/messages/{}/reactions/{}/{}",
                    std::to_string(*_channel_id), std::to_string(*_message_id),
                    util::url_encode(*_emoji), std::to_string(*_user_id)));
}
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#get-reactions
// TODO unverified
#define Parent Call
#define Class GetReactionsCall
#define function getReactions
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
NEW_FIELD(std::string, emoji, USEDBY(target))
NEW_FIELD(Snowflake, before, USEDBY(target))
NEW_FIELD(Snowflake, after, USEDBY(target))
NEW_FIELD(int, limit, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
HIDE_FIELD(target)
protected:
sptr<const std::string> render_target() override {
    REQUIRE_VAR(channel_id)
    REQUIRE_VAR(message_id)
    REQUIRE_VAR(emoji)
    std::string out = fmt::format(
        "/channels/{}/messages/{}/reactions/{}", std::to_string(*_channel_id),
        std::to_string(*_message_id), util::url_encode(*_emoji));
    bool first = true;
    QSO(after)
    QSO(limit)
    return std::make_shared<const std::string>(std::move(out));
}
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#delete-all-reactions
// TODO unverified
#define Parent Call
#define Class DeleteAllReactionsCall
#define function deleteAllReactions
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/channels/{}/messages/{}/reactions", ARR(channel_id, message_id),)
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#delete-all-reactions-for-emoji
// TODO unverified
#define Parent Call
#define Class DeleteAllReactionsForEmojiCall
#define function deleteAllReactionsForEmoji
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
NEW_FIELD(std::string, emoji, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
HIDE_FIELD(target)
protected:
sptr<const std::string> render_target() override {
    REQUIRE_VAR(channel_id)
    REQUIRE_VAR(message_id)
    REQUIRE_VAR(emoji)
    return std::make_shared<const std::string>(
        fmt::format("/channels/{}/messages/{}/reactions/{}", *_channel_id,
                    *_message_id, util::url_encode(*_emoji)));
}
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#edit-message
// Westlanderz/SenpaiR6#1717 verified channel_id, message_id, content, embed and
// flags
// TODO allowed_mentions is unverified
#define Parent JsonCall
#define Class EditMessageCall
#define function editMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
NEW_FIELD(std::string, content, USEDBY(payload))
NEW_FIELD(json, embed, USEDBY(payload))
NEW_FIELD(int, flags, USEDBY(payload))
NEW_FIELD(json, allowed_mentions, USEDBY(payload))
STATIC_FIELD(std::string, method, "PATCH")
AUTO_TARGET("/channels/{}/messages/{}", ARR(channel_id, message_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
AUTO_PAYLOAD(PFO(content) PFO(embed) PFO(flags) PFO(allowed_mentions))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#delete-message
// Verified by Westlanderz/SenpaiR6#1717
#define Parent Call
#define Class DeleteMessageCall
#define function deleteMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/channels/{}/messages/{}", ARR(channel_id, message_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#bulk-delete-messages
// TODO unverified
#define Parent JsonCall
#define Class BulkDeleteMessagesCall
#define function bulkDeleteMessages
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(std::vector<Snowflake>, messages, USEDBY(payload))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/channels/{}/messages/bulk-delete", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
AUTO_PAYLOAD(PFR(messages))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#edit-channel-permissions
// TODO unverified
#define Parent JsonCall
#define Class EditChannelPermissionsCall
#define function editChannelPermissions
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, overwrite_id, USEDBY(target))
NEW_FIELD(std::string, allow, USEDBY(payload))
NEW_FIELD(std::string, deny, USEDBY(payload))
NEW_FIELD(int, permission_type, USEDBY(payload))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/channels/{}/permissions/{}", ARR(channel_id, overwrite_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
AUTO_PAYLOAD(PFO(allow) PFO(deny) PFO("type", permission_type))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#get-channel-invites
// TODO unverified
#define Parent Call
#define Class GetChannelInvitesCall
#define function getChannelInvites
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/channels/{}/invites", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#create-channel-invite
// TODO unverified
#define Parent JsonCall
#define Class CreateChannelInviteCall
#define function createChannelInvite
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(int, max_age, USEDBY(payload))
NEW_FIELD(int, max_uses, USEDBY(payload))
NEW_FIELD(bool, temporary, USEDBY(payload))
NEW_FIELD(bool, unique, USEDBY(payload))
NEW_FIELD(std::string, target_user, USEDBY(payload))
NEW_FIELD(int, target_user_type, USEDBY(payload))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/channels/{}/invites", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
AUTO_PAYLOAD(PFO(max_age) PFO(max_uses) PFO(temporary) PFO(unique)
                 PFO(target_user) PFO(target_user_type))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#delete-channel-permission
// TODO unverified
#define Parent Call
#define Class DeleteChannelPermissionCall
#define function deleteChannelPermissions
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, overwrite_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/channels/{}/permissions/{}", ARR(channel_id, overwrite_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#follow-news-channel
// TODO unverified
#define Parent JsonCall
#define Class FollowNewsChannelCall
#define function followNewsChannel
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, webhook_channel_id, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/channels/{}/followers", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
AUTO_PAYLOAD(PFR(webhook_channel_id))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#trigger-typing-indicator
// TODO unverified
#define Parent Call
#define Class TriggerTypingIndicatorCall
#define function triggerTypingIndicator
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/channels/{}/typing", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#get-pinned-messages
// TODO unverified
#define Parent Call
#define Class GetPinnedMessagesCall
#define function getPinnedMessages
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/channels/{}/pins", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#add-pinned-channel-message
// TODO unverified
#define Parent Call
#define Class AddPinnedChannelMessageCall
#define function addPinnedChannelMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/channels/{}/pins/{}", ARR(channel_id, message_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#delete-pinned-channel-message
// TODO unverified
#define Parent Call
#define Class DeletePinnedChannelMessageCall
#define function deletePinnedChannelMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/channels/{}/pins/{}", ARR(channel_id, message_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#group-dm-add-recipient
// TODO unverified
#define Parent JsonCall
#define Class AddGroupDMRecipientCall
#define function addGroupDMRecipient
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
NEW_FIELD(std::string, access_token, USEDBY(payload))
NEW_FIELD(std::string, nick, USEDBY(payload))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/channels/{}/recipients/{}", ARR(channel_id, user_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
AUTO_PAYLOAD(PFR(access_token) PFO(nick))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#group-dm-remove-recipient
// TODO unverified
#define Parent Call
#define Class RemoveGroupDMRecipientCall
#define function removeGroupDMRecipient
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/channels/{}/recipients/{}", ARR(channel_id, user_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#start-thread-with-message
//  TODO unverified
#define Parent JsonCall
#define Class StartThreadWithMessageCall
#define function startThreadWithMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, message_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(int, auto_archive_duration, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/channels/{}/messages/{}/threads", ARR(channel_id, message_id), )
AUTO_PAYLOAD(PFR(name) PFR(auto_archive_duration))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#start-thread-without-message
//  TODO unverified
#define Parent JsonCall
#define Class StartThreadWithoutMessageCall
#define function startThreadWithoutMessage, startThreadWoutMessage
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(payload))
NEW_FIELD(int, auto_archive_duration, USEDBY(payload))
NEW_FIELD(ChannelType, thread_type, USEDBY(payload))
NEW_FIELD(bool, invitable, USEDBY(payload))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/channels/{}/threads", ARR(channel_id), )
AUTO_PAYLOAD(PFR(name) PFR(auto_archive_duration))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#join-thread
//  TODO unverified
#define Parent Call
#define Class JoinThreadCall
#define function joinThread
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/channels/{}/thread-members/@me", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#add-thread-member
//  TODO unverified
#define Parent Call
#define Class AddThreadMemberCall
#define function addThreadMember
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/channels/{}/thread-members/{}", ARR(channel_id, user_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#leave-thread
//  TODO unverified
#define Parent Call
#define Class LeaveThreadCall
#define function leaveThread
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/channels/{}/thread-members/@me", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#remove-thread-member
//  TODO unverified
#define Parent Call
#define Class RemoveThreadMemberCall
#define function removeThreadMember
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(Snowflake, user_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/channels/{}/thread-members/{}", ARR(channel_id, user_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#list-thread-members
//  TODO unverified
#define Parent Call
#define Class ListThreadMembersCall
#define function listThreadMembers
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/channels/{}/thread-members", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#list-public-archived-threads
//  TODO unverified
#define Parent Call
#define Class ListPublicArchivedThreadsCall
#define function listPublicArchivedThreads
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(std::string, before, USEDBY(target))
NEW_FIELD(int, limit, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/channels/{}/threads/archived/public", ARR(channel_id),
            QSO(before) QSO(limit))
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#list-private-archived-threads
//  TODO unverified
#define Parent Call
#define Class ListPrivateArchivedThreadsCall
#define function listPrivateArchivedThreads
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(std::string, before, USEDBY(target))
NEW_FIELD(int, limit, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/channels/{}/threads/archived/private", ARR(channel_id),
            QSO(before) QSO(limit))
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/channel#list-joined-private-archived-threads
//  TODO unverified
#define Parent Call
#define Class ListJoinedPrivateArchivedThreadsCall
#define function listJoinedPrivateArchivedThreads
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
NEW_FIELD(std::string, before, USEDBY(target))
NEW_FIELD(int, limit, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/channels/{}/users/@me/threads/archived/private", ARR(channel_id),
            QSO(before) QSO(limit))
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
