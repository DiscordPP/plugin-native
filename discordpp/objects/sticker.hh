//
// Created by Aidan on 8/27/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// TODO unverified
#define Name Sticker
#define Fields                                                                 \
field(Snowflake, id),\
omittable_field(Snowflake, pack_id),\
field(std::string, name),\
nullable_field(std::string, description),\
field(std::string, tags),\
field(int, type),\
field(int, format_type),\
omittable_field(bool, available),\
omittable_field(Snowflake, guild_id),\
omittable_field(User, user),\
omittable_field(int, sort_value)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

// TODO unverified
#define Name StickerItem
#define Fields                                                                 \
field(Snowflake, id),\
field(std::string, name),\
field(int, format_type)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

// TODO unverified
#define Name StickerPack
#define Fields                                                                 \
field(Snowflake, id),\
field(std::vector<Sticker>, stickers),\
field(std::string, name),\
field(Snowflake, sku_id),\
omittable_field(Snowflake, cover_sticker_id),\
field(std::string, description),\
field(Snowflake, banner_asset_id)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
