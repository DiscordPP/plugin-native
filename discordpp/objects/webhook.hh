//
// Created by Aidan on 8/27/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class Webhook {
  public:
    AUTO_CONSTRUCTORS(Webhook)

    field<Snowflake> id;
    field<int> type;
    nullable_omittable_field<Snowflake> guild_id;
    nullable_field<Snowflake> channel_id;
    omittable_field<User> user;
    nullable_field<std::string> name;
    nullable_field<std::string> avatar;
    omittable_field<std::string> token;
    nullable_field<Snowflake> application_id;
    omittable_field<Guild> source_guild;
    omittable_field<Channel> source_channel;
    omittable_field<std::string> url;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Webhook, {}, {}, id, type, guild_id,
                                         channel_id, user, name, avatar, token,
                                         application_id, source_guild,
                                         source_channel, url)
};
