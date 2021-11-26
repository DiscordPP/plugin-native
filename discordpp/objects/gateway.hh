//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

using ReadyShard = std::array<int, 2>;
#define Name Ready
#define Fields                                                                 \
    field(int, "v", version), field(User, user),                               \
        field(std::vector<UnavailableGuild>, guilds),                          \
        field(std::string, session_id), omittable_field(ReadyShard, shard),    \
        field(Application, application)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
