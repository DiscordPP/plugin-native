//
// Created by Aidan on 3/11/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

#define Name Channel
#define Fields                                                                 \
    field(Snowflake, id), field(int, type),                                    \
        omittable_field(Snowflake, guild_id), omittable_field(int, position),  \
        omittable_field(std::vector<Overwrite>, permission_overwrites),        \
        omittable_field(std::string, name),                                    \
        nullable_omittable_field(std::string, topic),                          \
        omittable_field(bool, nsfw),                                           \
        nullable_omittable_field(Snowflake, last_message_id),                  \
        omittable_field(int, bitrate), omittable_field(int, user_limit),       \
        omittable_field(int, rate_limit_per_user),                             \
        omittable_field(std::vector<User>, recipients),                        \
        nullable_omittable_field(std::string, icon),                           \
        omittable_field(Snowflake, owner_id),                                  \
        omittable_field(Snowflake, application_id),                            \
        nullable_omittable_field(Snowflake, parent_id),                        \
        nullable_omittable_field(Timestamp, last_pin_timestamp),               \
        nullable_omittable_field(std::string, rtc_region),                     \
        omittable_field(int, video_quality_mode),                              \
        omittable_field(int, message_count),                                   \
        omittable_field(int, member_count),                                    \
        omittable_field(ThreadMetadata, thread_metadata),                      \
        omittable_field(ThreadMember, member),                                 \
        omittable_field(int, default_auto_archive_duration),                   \
        omittable_field(std::string, permissions)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name Message
#define Fields                                                                 \
    field(Snowflake, id), field(Snowflake, channel_id),                        \
        omittable_field(Snowflake, guild_id), field(User, author),             \
        omittable_field(GuildMember, member), field(std::string, content),     \
        field(Timestamp, timestamp), field(Timestamp, edited_timestamp),       \
        field(bool, tts), field(bool, mention_everyone),                       \
        field(std::vector<User>, mentions),                                    \
        field(std::vector<Snowflake>, mention_roles),                          \
        omittable_field(std::vector<ChannelMention>, mention_channels),        \
        field(std::vector<Attachment>, attachments),                           \
        field(std::vector<Embed>, embeds),                                     \
        omittable_field(std::vector<Reaction>, reactions),                     \
        omittable_field(Nonce, nonce), field(bool, pinned),                    \
        omittable_field(Snowflake, webhook_id), field(MessageType, type),      \
        omittable_field(MessageActivity, activity),                            \
        omittable_field(Application, application),                             \
        omittable_field(Snowflake, application_id),                            \
        nullable_omittable_field(MessageReference, message_reference),         \
        omittable_field(MessageFlags, flags),                                  \
        omittable_field(MessageReference, referenced_message),                 \
        omittable_field(MessageInteraction, interaction),                      \
        omittable_field(Channel, thread),                                      \
        omittable_field(std::vector<Component>, components),                   \
        omittable_field(std::vector<StickerItem>, sticker_items)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name MessageActivity
#define Fields                                                                 \
    field(MessageActivityType, type), omittable_field(std::string, party_id)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name MessageReference
#define Fields                                                                 \
    omittable_field(Snowflake, message_id),                                    \
        omittable_field(Snowflake, channel_id),                                \
        omittable_field(Snowflake, guild_id),                                  \
        omittable_field(bool, fail_if_not_exists)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name FollowedChannel
#define Fields field(Snowflake, channel_id), field(Snowflake, webhook_id)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name Reaction
#define Fields field(int, count), field(bool, me), field(Emoji, emoji)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name Overwrite
#define Fields                                                                 \
    field(Snowflake, id), field(int, type), field(std::string, allow),         \
        field(std::string, deny)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name ThreadMetadata
#define Fields                                                                 \
    field(bool, archived), field(int, auto_archive_duration),                  \
        field(Timestamp, archive_timestamp), field(bool, locked),              \
        omittable_field(bool, invitable)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name ThreadMember
#define Fields                                                                 \
    omittable_field(Snowflake, id), omittable_field(Snowflake, user_id),       \
        field(Timestamp, join_timestamp), field(int, flags)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name Embed
#define Fields                                                                 \
    omittable_field(std::string, title), omittable_field(EmbedType, type),     \
        omittable_field(std::string, description),                             \
        omittable_field(std::string, url),                                     \
        omittable_field(Timestamp, timestamp), omittable_field(int, color),    \
        omittable_field(EmbedFooter, footer),                                  \
        omittable_field(EmbedImage, image),                                    \
        omittable_field(EmbedThumbnail, thumbnail),                            \
        omittable_field(EmbedVideo, video),                                    \
        omittable_field(EmbedProvider, provider),                              \
        omittable_field(EmbedAuthor, author),                                  \
        omittable_field(std::vector<EmbedField>, fields)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name EmbedThumbnail
#define Fields                                                                 \
    field(std::string, url), omittable_field(std::string, proxy_url),          \
        omittable_field(int, height), omittable_field(int, width)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name EmbedVideo
#define Fields                                                                 \
    omittable_field(std::string, url),                                         \
        omittable_field(std::string, proxy_url), omittable_field(int, height), \
        omittable_field(int, width)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name EmbedImage
#define Fields                                                                 \
    field(std::string, url), omittable_field(std::string, proxy_url),          \
        omittable_field(int, height), omittable_field(int, width)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name EmbedProvider
#define Fields                                                                 \
    omittable_field(std::string, name), omittable_field(std::string, url)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name EmbedAuthor
#define Fields                                                                 \
    field(std::string, name), omittable_field(std::string, url),               \
        omittable_field(std::string, icon_url),                                \
        omittable_field(std::string, proxy_icon_url)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name EmbedFooter
#define Fields                                                                 \
    field(std::string, text), omittable_field(std::string, icon_url),          \
        omittable_field(std::string, proxy_icon_url)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name EmbedField
#define Fields                                                                 \
    field(std::string, name), field(std::string, value),                       \
        omittable_field(bool, display_inline)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name Attachment
#define Fields                                                                 \
    field(Snowflake, id), field(std::string, filename),                        \
        omittable_field(std::string, content_type), field(int, size),          \
        field(std::string, url), field(std::string, proxy_url),                \
        nullable_omittable_field(int, height),                                 \
        nullable_omittable_field(int, width), omittable_field(bool, ephemeral)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name ChannelMention
#define Fields                                                                 \
    field(Snowflake, id), field(Snowflake, guild_id),                          \
        field(ChannelType, type), field(std::string, name)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name AllowedMentions
#define Fields                                                                 \
    field(std::vector<AllowedMentionType>, parse),                             \
        field(std::vector<Snowflake>, roles),                                  \
        field(std::vector<Snowflake>, users), field(bool, replied_user)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
