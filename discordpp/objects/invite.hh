//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

#define Name Invite
#define Fields                                                                 \
    field(std::string, code), omittable_field(Guild, guild),                   \
        field(Channel, channel), omittable_field(User, inviter),               \
        omittable_field(InviteTargetType, target_type),                        \
        omittable_field(User, target_user),                                    \
        omittable_field(Application, target_application),                      \
        omittable_field(int, approximate_presence_count),                      \
        omittable_field(int, approximate_member_count),                        \
        nullable_omittable_field(Timestamp, expires_at),                       \
        omittable_field(InviteStageInstance, stage_instance)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name InviteMetadata
#define Fields                                                                 \
    field(int, uses), field(int, max_uses), field(int, max_age),               \
        field(bool, temporary), field(Timestamp, created_at)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name InviteStageInstance
#define Fields                                                                 \
    field(std::vector<GuildMember>, members), field(int, participant_count),   \
        field(int, speaker_count), field(std::string, topic)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
