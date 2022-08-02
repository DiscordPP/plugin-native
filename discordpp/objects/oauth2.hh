//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// TODO unverified
#define Name CurrentAuthorizationInformation
#define Fields                                                                 \
    field(Application, application), field(std::vector<std::string>, scopes),  \
        field(Timestamp, expires), omittable_field(User, user)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
