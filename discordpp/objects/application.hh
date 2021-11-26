//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

#define Name Application
#define Fields                                                                 \
    field(Snowflake, id), field(std::string, name),                            \
        nullable_field(std::string, icon), field(std::string, description),    \
        omittable_field(std::vector<std::string>, rpc_origins),                \
        field(bool, bot_public), field(bool, bot_require_code_grant),          \
        omittable_field(std::string, terms_of_service_url),                    \
        omittable_field(std::string, privacy_policy_url),                      \
        omittable_field(User, owner), field(std::string, summary),             \
        field(std::string, verify_key), nullable_field(Team, team),            \
        omittable_field(Snowflake, guild_id),                                  \
        omittable_field(Snowflake, primary_sku_id),                            \
        omittable_field(std::string, slug),                                    \
        omittable_field(std::string, cover_image),                             \
        omittable_field(ApplicationFlags, flags)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
