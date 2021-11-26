//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

#define Name AuditLog
#define Fields                                                                 \
    field(std::vector<AuditLogEntry>, audit_log_entries),                      \
        field(std::vector<Integration>, integrations),                         \
        field(std::vector<Channel>, threads), field(std::vector<User>, users), \
        field(std::vector<Webhook>, webhooks)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name AuditLogEntry
#define Fields                                                                 \
    nullable_field(Snowflake, target_id),                                      \
        omittable_field(std::vector<AuditLogChange>, changes),                 \
        nullable_field(Snowflake, user_id), field(Snowflake, id),              \
        field(AuditLogEvent, action_type),                                     \
        omittable_field(OptionalAuditEntryInfo, options),                      \
        omittable_field(std::string, reason)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name OptionalAuditEntryInfo
#define Fields                                                                 \
    omittable_field(Snowflake, channel_id),                                    \
        omittable_field(std::string, count),                                   \
        omittable_field(std::string, delete_member_days),                      \
        omittable_field(Snowflake, id),                                        \
        omittable_field(std::string, members_removed),                         \
        omittable_field(Snowflake, message_id),                                \
        omittable_field(std::string, role_name), field(std::string, type)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name AuditLogChange
#define Fields                                                                 \
    omittable_field(json, new_value), omittable_field(json, old_value),        \
        field(std::string, key)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
