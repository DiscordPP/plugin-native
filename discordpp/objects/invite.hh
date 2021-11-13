//
// Created by Aidan on 8/27/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class Invite {
  public:
    AUTO_CONSTRUCTORS(Invite)

    field<std::string> code;
    omittable_field<Guild> guild;
    field<Channel> channel;
    omittable_field<User> inviter;
    omittable_field<InviteTargetType> target_type;
    omittable_field<User> target_user;
    omittable_field<Application> target_application;
    omittable_field<int> approximate_presence_count;
    omittable_field<int> approximate_member_count;
    nullable_omittable_field<Timestamp> expires_at;
    omittable_field<InviteStageInstance> stage_instance;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Invite, {}, {}, code, guild, channel,
                                         inviter, target_type, target_user,
                                         target_application,
                                         approximate_presence_count,
                                         approximate_member_count, expires_at,
                                         stage_instance)
};

class InviteMetadata {
  public:
    AUTO_CONSTRUCTORS(InviteMetadata)

    field<int> uses;
    field<int> max_uses;
    field<int> max_age;
    field<bool> temporary;
    field<Timestamp> created_at;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(InviteMetadata, {}, {}, uses, max_uses,
                                         max_age, temporary, created_at)
};

class InviteStageInstance {
  public:
    AUTO_CONSTRUCTORS(InviteStageInstance)

    field<std::vector<GuildMember>> members;
    field<int> participant_count;
    field<int> speaker_count;
    field<std::string> topic;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(InviteStageInstance, {}, {}, members,
                                         participant_count, speaker_count,
                                         topic)
};
