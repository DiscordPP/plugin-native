//
// Created by Aidan on 4/20/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

#define Name Guild
#define Fields                                                                 \
    field(Snowflake, id), field(std::string, name),                            \
        nullable_field(std::string, icon),                                     \
        nullable_omittable_field(std::string, icon_hash),                      \
        nullable_field(std::string, splash),                                   \
        nullable_field(std::string, discovery_splash),                         \
        omittable_field(bool, owner), field(Snowflake, owner_id),              \
        omittable_field(std::string, permissions),                             \
        nullable_field(Snowflake, afk_channel_id), field(int, afk_timeout),    \
        omittable_field(bool, widget_enabled),                                 \
        nullable_omittable_field(Snowflake, widget_channel_id),                \
        field(VerificationLevel, verification_level),                          \
        field(DefaultMessageNotificationLevel, default_message_notifications), \
        field(ExplicitContentFilterLevel, explicit_content_filter),            \
        field(std::vector<Role>, roles), field(std::vector<Emoji>, emojis),    \
        field(std::vector<GuildFeature>, features),                            \
        field(MFALevel, mfa_level), nullable_field(Snowflake, application_id), \
        nullable_field(Snowflake, system_channel_id),                          \
        field(SystemChannelFlags, system_channel_flags),                       \
        nullable_field(Snowflake, rules_channel_id),                           \
        omittable_field(Timestamp, joined_at), omittable_field(bool, large),   \
        omittable_field(bool, unavailable),                                    \
        omittable_field(int, member_count),                                    \
        omittable_field(std::vector<VoiceState>, voice_states),                \
        omittable_field(std::vector<GuildMember>, members),                    \
        omittable_field(std::vector<Channel>, channels),                       \
        omittable_field(std::vector<Channel>, threads),                        \
        omittable_field(std::vector<PresenceUpdate>, presences),               \
        nullable_omittable_field(int, max_presences),                          \
        omittable_field(int, max_members),                                     \
        nullable_field(std::string, vanity_url_code),                          \
        nullable_field(std::string, description),                              \
        nullable_field(std::string, banner), field(PremiumTier, premium_tier), \
        omittable_field(int, premium_subscription_count),                      \
        field(std::string, preferred_locale),                                  \
        nullable_field(Snowflake, public_updates_channel_id),                  \
        omittable_field(int, max_video_channel_users),                         \
        omittable_field(int, approximate_member_count),                        \
        omittable_field(int, approximate_presence_count),                      \
        omittable_field(WelcomeScreen, welcome_screen),                        \
        field(GuildNSFWLevel, nsfw_level),                                     \
        omittable_field(std::vector<StageInstance>, stage_instances),          \
        omittable_field(std::vector<Sticker>, stickers)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name UnavailableGuild
#define Fields field(Snowflake, id), omittable_field(bool, unavailable)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name GuildPreview
#define Fields                                                                 \
    field(Snowflake, id), field(std::string, name),                            \
        nullable_field(std::string, icon),                                     \
        nullable_field(std::string, splash),                                   \
        nullable_field(std::string, discovery_splash),                         \
        field(std::vector<Emoji>, emojis),                                     \
        field(std::vector<GuildFeature>, features),                            \
        field(int, approximate_member_count),                                  \
        field(int, approximate_presence_count),                                \
        nullable_field(std::string, description)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name GuildWidget
#define Fields field(bool, enabled), nullable_field(Snowflake, channel_id)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name GuildMember
#define Fields                                                                 \
    omittable_field(User, user), nullable_omittable_field(std::string, nick),  \
        nullable_omittable_field(std::string, avatar),                         \
        field(std::vector<Snowflake>, roles), field(Timestamp, joined_at),     \
        nullable_omittable_field(Timestamp, premium_since), field(bool, deaf), \
        field(bool, mute), omittable_field(bool, pending),                     \
        omittable_field(std::string, permissions)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name Integration
#define Fields                                                                 \
    field(Snowflake, id), field(std::string, name), field(std::string, type),  \
        field(bool, enabled), omittable_field(bool, syncing),                  \
        omittable_field(Snowflake, role_id),                                   \
        omittable_field(bool, enable_emoticons),                               \
        omittable_field(IntegrationExpireBehavior, expire_behavior),           \
        omittable_field(int, expire_grace_period),                             \
        omittable_field(User, user), field(IntegrationAccount, account),       \
        omittable_field(Timestamp, synced_at),                                 \
        omittable_field(int, subscriber_count),                                \
        omittable_field(bool, revoked),                                        \
        omittable_field(Application, application)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name IntegrationAccount
#define Fields field(std::string, id), field(std::string, name)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name IntegrationApplication
#define Fields                                                                 \
    field(Snowflake, id), field(std::string, name),                            \
        nullable_field(std::string, icon), field(std::string, description),    \
        field(std::string, summary), omittable_field(User, bot)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name Ban
#define Fields nullable_field(std::string, reason), field(User, user)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name WelcomeScreen
#define Fields                                                                 \
    nullable_field(std::string, description),                                  \
        field(std::vector<WelcomeScreenChannel>, welcome_channels)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name WelcomeScreenChannel
#define Fields                                                                 \
    field(Snowflake, channel_id), field(std::string, description),             \
        nullable_field(Snowflake, emoji_id),                                   \
        nullable_field(std::string, emoji_name)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
