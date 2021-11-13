//
// Created by Aidan on 8/27/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class StageInstance {
  public:
    AUTO_CONSTRUCTORS(StageInstance)

    field<Snowflake> id;
    field<Snowflake> guild_id;
    field<Snowflake> channel_id;
    field<std::string> topic;
    field<int> privacy_level;
    field<bool> discoverable_disabled;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(StageInstance, {}, {}, id, guild_id,
                                         channel_id, topic, privacy_level,
                                         discoverable_disabled)
};
