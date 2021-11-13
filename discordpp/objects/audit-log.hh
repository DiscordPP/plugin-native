//
// Created by Aidan on 8/27/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class AuditLog {
  public:
    AUTO_CONSTRUCTORS(AuditLog)

    field<std::vector<AuditLogEntry>> audit_log_entries;
    field<std::vector<Integration>> integrations;
    field<std::vector<Channel>> threads;
    field<std::vector<User>> users;
    field<std::vector<Webhook>> webhooks;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(AuditLog, {}, {}, audit_log_entries,
                                         integrations, threads, users,
                                         webhooks);
};

class AuditLogEntry {
  public:
    AUTO_CONSTRUCTORS(AuditLogEntry)

    nullable_field<Snowflake> target_id;
    omittable_field<std::vector<AuditLogChange>> changes;
    nullable_field<Snowflake> user_id;
    field<Snowflake> id;
    field<AuditLogEvent> action_type;
    omittable_field<OptionalAuditEntryInfo> options;
    omittable_field<std::string> reason;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(AuditLogEntry, {}, {}, target_id,
                                         changes, user_id, id, action_type,
                                         options, reason);
};

class OptionalAuditEntryInfo {
  public:
    AUTO_CONSTRUCTORS(OptionalAuditEntryInfo)

    omittable_field<Snowflake> channel_id;
    omittable_field<std::string> count;
    omittable_field<std::string> delete_member_days;
    omittable_field<Snowflake> id;
    omittable_field<std::string> members_removed;
    omittable_field<Snowflake> message_id;
    omittable_field<std::string> role_name;
    field<std::string> type;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(OptionalAuditEntryInfo, {}, {},
                                         channel_id, count, delete_member_days,
                                         id, members_removed, message_id,
                                         role_name, type);
};

class AuditLogChange {
  public:
    AUTO_CONSTRUCTORS(AuditLogChange)

    omittable_field<json> new_value;
    omittable_field<json> old_value;
    field<std::string> key;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(AuditLogChange, {}, {}, new_value,
                                         old_value, key);
};
