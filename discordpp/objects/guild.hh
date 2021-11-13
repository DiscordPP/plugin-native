//
// Created by Aidan on 4/20/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class Guild {
  public:
    AUTO_CONSTRUCTORS(Guild)

    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> icon;
    nullable_omittable_field<std::string> icon_hash;
    nullable_field<std::string> splash;
    nullable_field<std::string> discovery_splash;
    omittable_field<bool> owner;
    field<Snowflake> owner_id;
    omittable_field<std::string> permissions;
    nullable_field<Snowflake> afk_channel_id;
    field<int> afk_timeout;
    omittable_field<bool> widget_enabled;
    nullable_omittable_field<Snowflake> widget_channel_id;
    field<VerificationLevel> verification_level;
    field<DefaultMessageNotificationLevel> default_message_notifications;
    field<ExplicitContentFilterLevel> explicit_content_filter;
    field<std::vector<Role>> roles;
    field<std::vector<Emoji>> emojis;
    field<std::vector<GuildFeature>> features;
    field<MFALevel> mfa_level;
    nullable_field<Snowflake> application_id;
    nullable_field<Snowflake> system_channel_id;
    field<SystemChannelFlags> system_channel_flags;
    nullable_field<Snowflake> rules_channel_id;
    omittable_field<Timestamp> joined_at;
    omittable_field<bool> large;
    omittable_field<bool> unavailable;
    omittable_field<int> member_count;
    omittable_field<std::vector<VoiceState>> voice_states;
    omittable_field<std::vector<GuildMember>> members;
    omittable_field<std::vector<Channel>> channels;
    omittable_field<std::vector<Channel>> threads;
    omittable_field<std::vector<PresenceUpdate>> presences;
    nullable_omittable_field<int> max_presences;
    omittable_field<int> max_members;
    nullable_field<std::string> vanity_url_code;
    nullable_field<std::string> description;
    nullable_field<std::string> banner;
    field<PremiumTier> premium_tier;
    omittable_field<int> premium_subscription_count;
    field<std::string> preferred_locale;
    nullable_field<Snowflake> public_updates_channel_id;
    omittable_field<int> max_video_channel_users;
    omittable_field<int> approximate_member_count;
    omittable_field<int> approximate_presence_count;
    omittable_field<WelcomeScreen> welcome_screen;
    field<GuildNSFWLevel> nsfw_level;
    omittable_field<std::vector<StageInstance>> stage_instances;
    omittable_field<std::vector<Sticker>> stickers;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(
        Guild, {}, {}, id, name, icon, icon_hash, splash, discovery_splash,
        owner, owner_id, permissions, afk_channel_id, afk_timeout,
        widget_enabled, widget_channel_id, verification_level,
        default_message_notifications, explicit_content_filter, roles, emojis,
        features, mfa_level, application_id, system_channel_id,
        system_channel_flags, rules_channel_id, joined_at, large, unavailable,
        member_count, voice_states, members, channels, threads, presences,
        max_presences, max_members, vanity_url_code, description, banner,
        premium_tier, premium_subscription_count, preferred_locale,
        public_updates_channel_id, max_video_channel_users,
        approximate_member_count, approximate_presence_count, welcome_screen,
        nsfw_level, stage_instances, stickers)
};

class UnavailableGuild {
  public:
    AUTO_CONSTRUCTORS(UnavailableGuild)

    field<Snowflake> id;
    omittable_field<bool> unavailable;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(UnavailableGuild, {}, {}, id,
                                         unavailable)
};

class GuildPreview {
  public:
    AUTO_CONSTRUCTORS(GuildPreview)

    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> icon;
    nullable_field<std::string> splash;
    nullable_field<std::string> discovery_splash;
    field<std::vector<Emoji>> emojis;
    field<std::vector<GuildFeature>> features;
    field<int> approximate_member_count;
    field<int> approximate_presence_count;
    nullable_field<std::string> description;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(GuildPreview, {}, {}, id, name, icon,
                                         splash, discovery_splash, emojis,
                                         features, approximate_member_count,
                                         approximate_presence_count,
                                         description)
};

class GuildWidget {
  public:
    AUTO_CONSTRUCTORS(GuildWidget)

    field<bool> enabled;
    nullable_field<Snowflake> channel_id;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(GuildWidget, {}, {}, enabled,
                                         channel_id)
};

class GuildMember {
  public:
    AUTO_CONSTRUCTORS(GuildMember)

    omittable_field<User> user;
    nullable_omittable_field<std::string> nick;
    nullable_omittable_field<std::string> avatar;
    field<std::vector<Snowflake>> roles;
    field<Timestamp> joined_at;
    nullable_omittable_field<Timestamp> premium_since;
    field<bool> deaf;
    field<bool> mute;
    omittable_field<bool> pending;
    omittable_field<std::string> permissions;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(GuildMember, {}, {}, user, nick,
                                         avatar, roles, joined_at,
                                         premium_since, deaf, mute, pending,
                                         permissions)
};

class Integration {
  public:
    AUTO_CONSTRUCTORS(Integration)

    field<Snowflake> id;
    field<std::string> name;
    field<std::string> type;
    field<bool> enabled;
    omittable_field<bool> syncing;
    omittable_field<Snowflake> role_id;
    omittable_field<bool> enable_emoticons;
    omittable_field<IntegrationExpireBehavior> expire_behavior;
    omittable_field<int> expire_grace_period;
    omittable_field<User> user;
    field<IntegrationAccount> account;
    omittable_field<Timestamp> synced_at;
    omittable_field<int> subscriber_count;
    omittable_field<bool> revoked;
    omittable_field<Application> application;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Integration, {}, {}, id, name, type,
                                         enabled, syncing, role_id,
                                         enable_emoticons, expire_behavior,
                                         expire_grace_period, user, account,
                                         synced_at, subscriber_count, revoked,
                                         application)
};

class IntegrationAccount {
  public:
    AUTO_CONSTRUCTORS(IntegrationAccount)

    field<std::string> id;
    field<std::string> name;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(IntegrationAccount, {}, {}, id, name)
};

class IntegrationApplication {
  public:
    AUTO_CONSTRUCTORS(IntegrationApplication)

    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> icon;
    field<std::string> description;
    field<std::string> summary;
    omittable_field<User> bot;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(IntegrationApplication, {}, {}, id,
                                         name, icon, description, summary, bot)
};

class Ban {
  public:
    AUTO_CONSTRUCTORS(Ban)

    nullable_field<std::string> reason;
    field<User> user;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Ban, {}, {}, reason, user)
};

class WelcomeScreen {
  public:
    AUTO_CONSTRUCTORS(WelcomeScreen)

    nullable_field<std::string> description;
    field<std::vector<WelcomeScreenChannel>> welcome_channels;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(WelcomeScreen, {}, {}, description,
                                         welcome_channels)
};

class WelcomeScreenChannel {
  public:
    AUTO_CONSTRUCTORS(WelcomeScreenChannel)

    field<Snowflake> channel_id;
    field<std::string> description;
    nullable_field<Snowflake> emoji_id;
    nullable_field<std::string> emoji_name;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(WelcomeScreenChannel, {}, {},
                                         channel_id, description, emoji_id,
                                         emoji_name)
};
