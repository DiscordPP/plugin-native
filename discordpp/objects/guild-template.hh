//
// Created by Aidan on 8/27/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class GuildTemplate {
  public:
    AUTO_CONSTRUCTORS(GuildTemplate)

    field<std::string> code;
    field<std::string> name;
    nullable_field<std::string> description;
    field<int> usage_count;
    field<Snowflake> creator_id;
    field<User> creator;
    field<Timestamp> created_at;
    field<Timestamp> updated_at;
    field<Snowflake> source_guild_id;
    field<Guild> serialized_source_guild;
    nullable_field<bool> is_dirty;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(GuildTemplate, {}, {}, code, name,
                                         description, usage_count, creator_id,
                                         creator, created_at, updated_at,
                                         source_guild_id,
                                         serialized_source_guild, is_dirty)
};
