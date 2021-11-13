//
// Created by Aidan on 8/27/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class Ready {
  public:
    AUTO_CONSTRUCTORS(Ready)

    field<int> v;
    field<User> user;
    field<std::vector<UnavailableGuild>> guilds;
    field<std::string> session_id;
    omittable_field<std::array<int, 2>> shard;
    field<Application> application;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Ready, {}, {}, v, user, guilds,
                                         session_id, shard, application)
};
