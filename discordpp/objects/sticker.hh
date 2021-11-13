//
// Created by Aidan on 8/27/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class Sticker {
  public:
    AUTO_CONSTRUCTORS(Sticker)

    field<Snowflake> id;
    omittable_field<Snowflake> pack_id;
    field<std::string> name;
    nullable_field<std::string> description;
    field<std::string> tags;
    field<int> type;
    field<int> format_type;
    omittable_field<bool> available;
    omittable_field<Snowflake> guild_id;
    omittable_field<User> user;
    omittable_field<int> sort_value;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Sticker, {}, {}, id, pack_id, name,
                                         description, tags, type, format_type,
                                         available, guild_id, user, sort_value)
};

class StickerItem {
  public:
    AUTO_CONSTRUCTORS(StickerItem)

    field<Snowflake> id;
    field<std::string> name;
    field<int> format_type;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(StickerItem, {}, {}, id, name,
                                         format_type)
};

class StickerPack {
  public:
    AUTO_CONSTRUCTORS(StickerPack)

    field<Snowflake> id;
    field<std::vector<Sticker>> stickers;
    field<std::string> name;
    field<Snowflake> sku_id;
    omittable_field<Snowflake> cover_sticker_id;
    field<std::string> description;
    field<Snowflake> banner_asset_id;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(StickerPack, {}, {}, id, stickers,
                                         name, sku_id, cover_sticker_id,
                                         description, banner_asset_id)
};
