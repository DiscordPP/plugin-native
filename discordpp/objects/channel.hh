//
// Created by Aidan on 3/11/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class Channel {
  public:
    AUTO_CONSTRUCTORS(Channel)

    field<Snowflake> id;
    field<int> type;
    omittable_field<Snowflake> guild_id;
    omittable_field<int> position;
    omittable_field<std::vector<Overwrite>> permission_overwrites;
    omittable_field<std::string> name;
    nullable_omittable_field<std::string> topic;
    omittable_field<bool> nsfw;
    nullable_omittable_field<Snowflake> last_message_id;
    omittable_field<int> bitrate;
    omittable_field<int> user_limit;
    omittable_field<int> rate_limit_per_user;
    omittable_field<std::vector<User>> recipients;
    nullable_omittable_field<std::string> icon;
    omittable_field<Snowflake> owner_id;
    omittable_field<Snowflake> application_id;
    nullable_omittable_field<Snowflake> parent_id;
    nullable_omittable_field<Timestamp> last_pin_timestamp;
    nullable_omittable_field<std::string> rtc_region;
    omittable_field<int> video_quality_mode;
    omittable_field<int> message_count;
    omittable_field<int> member_count;
    omittable_field<ThreadMetadata> thread_metadata;
    omittable_field<ThreadMember> member;
    omittable_field<int> default_auto_archive_duration;
    omittable_field<std::string> permissions;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(
        Channel, {}, {}, id, type, guild_id, position, permission_overwrites,
        name, topic, nsfw, last_message_id, bitrate, user_limit,
        rate_limit_per_user, recipients, icon, owner_id, application_id,
        parent_id, last_pin_timestamp, rtc_region, video_quality_mode,
        message_count, member_count, thread_metadata, member,
        default_auto_archive_duration, permissions)
};

class Message {
  public:
    AUTO_CONSTRUCTORS(Message)

    field<Snowflake> id;
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;
    field<User> author;
    omittable_field<GuildMember> member;
    field<std::string> content;
    field<Timestamp> timestamp;
    field<Timestamp> edited_timestamp;
    field<bool> tts;
    field<bool> mention_everyone;
    field<std::vector<User>> mentions;
    field<std::vector<Snowflake>> mention_roles;
    omittable_field<std::vector<ChannelMention>> mention_channels;
    field<std::vector<Attachment>> attachments;
    field<std::vector<Embed>> embeds;
    omittable_field<std::vector<Reaction>> reactions;
    omittable_field<std::variant<int, std::string>> nonce;
    field<bool> pinned;
    omittable_field<Snowflake> webhook_id;
    field<MessageType> type;
    omittable_field<MessageActivity> activity;
    omittable_field<Application> application;
    omittable_field<Snowflake> application_id;
    nullable_omittable_field<MessageReference> message_reference;
    omittable_field<MessageFlags> flags;
    omittable_field<MessageReference> referenced_message;
    omittable_field<MessageInteraction> interaction;
    omittable_field<Channel> thread;
    omittable_field<std::vector<Component>> components;
    omittable_field<std::vector<StickerItem>> sticker_items;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(
        Message, {}, {}, id, channel_id, guild_id, author, member, content,
        timestamp, edited_timestamp, tts, mention_everyone, mentions,
        mention_roles, mention_channels, attachments, embeds, reactions, nonce,
        pinned, webhook_id, type, activity, application, application_id,
        message_reference, flags, referenced_message, interaction, thread,
        components, sticker_items)
};

class MessageActivity {
  public:
    AUTO_CONSTRUCTORS(MessageActivity)

    field<MessageActivityType> type;
    omittable_field<std::string> party_id;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(MessageActivity, {}, {}, type,
                                         party_id)
};

class MessageReference {
  public:
    AUTO_CONSTRUCTORS(MessageReference)

    omittable_field<Snowflake> message_id;
    omittable_field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;
    omittable_field<bool> fail_if_not_exists;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(MessageReference, {}, {}, message_id,
                                         channel_id, guild_id,
                                         fail_if_not_exists)
};

class FollowedChannel {
  public:
    AUTO_CONSTRUCTORS(FollowedChannel)

    field<Snowflake> channel_id;
    field<Snowflake> webhook_id;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(FollowedChannel, {}, {}, channel_id,
                                         webhook_id)
};

class Reaction {
  public:
    AUTO_CONSTRUCTORS(Reaction)

    field<int> count;
    field<bool> me;
    field<Emoji> emoji;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Reaction, {}, {}, count, me, emoji)
};

class Overwrite {
  public:
    AUTO_CONSTRUCTORS(Overwrite)

    field<Snowflake> id;
    field<int> type;
    field<std::string> allow;
    field<std::string> deny;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Overwrite, {}, {}, id, type, allow,
                                         deny)
};

class ThreadMetadata {
  public:
    AUTO_CONSTRUCTORS(ThreadMetadata)

    field<bool> archived;
    field<int> auto_archive_duration;
    field<Timestamp> archive_timestamp;
    field<bool> locked;
    omittable_field<bool> invitable;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(ThreadMetadata, {}, {}, archived,
                                         auto_archive_duration,
                                         archive_timestamp, locked, invitable)
};

class ThreadMember {
  public:
    AUTO_CONSTRUCTORS(ThreadMember)

    omittable_field<Snowflake> id;
    omittable_field<Snowflake> user_id;
    field<Timestamp> join_timestamp;
    field<int> flags;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(ThreadMember, {}, {}, id, user_id,
                                         join_timestamp, flags)
};

class Embed {
  public:
    AUTO_CONSTRUCTORS(Embed)

    omittable_field<std::string> title;
    omittable_field<EmbedType> type;
    omittable_field<std::string> description;
    omittable_field<std::string> url;
    omittable_field<Timestamp> timestamp;
    omittable_field<int> color;
    omittable_field<EmbedFooter> footer;
    omittable_field<EmbedImage> image;
    omittable_field<EmbedThumbnail> thumbnail;
    omittable_field<EmbedVideo> video;
    omittable_field<EmbedProvider> provider;
    omittable_field<EmbedAuthor> author;
    omittable_field<std::vector<EmbedField>> fields;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Embed, {}, {}, title, type,
                                         description, url, timestamp, color,
                                         footer, image, thumbnail, video,
                                         provider, author, fields)
};

class EmbedThumbnail {
  public:
    AUTO_CONSTRUCTORS(EmbedThumbnail)

    field<std::string> url;
    omittable_field<std::string> proxy_url;
    omittable_field<int> height;
    omittable_field<int> width;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(EmbedThumbnail, {}, {}, url, proxy_url,
                                         height, width)
};

class EmbedVideo {
  public:
    AUTO_CONSTRUCTORS(EmbedVideo)

    omittable_field<std::string> url;
    omittable_field<std::string> proxy_url;
    omittable_field<int> height;
    omittable_field<int> width;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(EmbedVideo, {}, {}, url, proxy_url,
                                         height, width)
};

class EmbedImage {
  public:
    AUTO_CONSTRUCTORS(EmbedImage)

    field<std::string> url;
    omittable_field<std::string> proxy_url;
    omittable_field<int> height;
    omittable_field<int> width;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(EmbedImage, {}, {}, url, proxy_url,
                                         height, width)
};

class EmbedProvider {
  public:
    AUTO_CONSTRUCTORS(EmbedProvider)

    omittable_field<std::string> name;
    omittable_field<std::string> url;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(EmbedProvider, {}, {}, name, url)
};
class EmbedAuthor {
  public:
    AUTO_CONSTRUCTORS(EmbedAuthor)

    field<std::string> name;
    omittable_field<std::string> url;
    omittable_field<std::string> icon_url;
    omittable_field<std::string> proxy_icon_url;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(EmbedAuthor, {}, {}, name, url,
                                         icon_url, proxy_icon_url)
};

class EmbedFooter {
  public:
    AUTO_CONSTRUCTORS(EmbedFooter)

    field<std::string> text;
    omittable_field<std::string> icon_url;
    omittable_field<std::string> proxy_icon_url;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(EmbedFooter, {}, {}, text, icon_url,
                                         proxy_icon_url)
};

class EmbedField {
  public:
    AUTO_CONSTRUCTORS(EmbedField)

    field<std::string> name;
    field<std::string> value;
    omittable_field<bool> display_inline;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(
        EmbedField,
        {
            if (!t.display_inline.is_omitted()) {
                j["inline"] = t.display_inline;
            }
        },
        { j.at("inline").get_to(t.display_inline); }, name, value)
};

class Attachment {
  public:
    AUTO_CONSTRUCTORS(Attachment)

    field<Snowflake> id;
    field<std::string> filename;
    omittable_field<std::string> content_type;
    field<int> size;
    field<std::string> url;
    field<std::string> proxy_url;
    nullable_omittable_field<int> height;
    nullable_omittable_field<int> width;
    omittable_field<bool> ephemeral;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Attachment, {}, {}, id, filename,
                                         content_type, size, url, proxy_url,
                                         height, width, ephemeral)
};

class ChannelMention {
  public:
    AUTO_CONSTRUCTORS(ChannelMention)

    field<Snowflake> id;
    field<Snowflake> guild_id;
    field<ChannelType> type;
    field<std::string> name;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(ChannelMention, {}, {}, id, guild_id,
                                         type, name)
};

class AllowedMentions {
  public:
    AUTO_CONSTRUCTORS(AllowedMentions)

    field<std::vector<AllowedMentionType>> parse;
    field<std::vector<Snowflake>> roles;
    field<std::vector<Snowflake>> users;
    field<bool> replied_user;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(AllowedMentions, {}, {}, parse, roles,
                                         users, replied_user)
};
