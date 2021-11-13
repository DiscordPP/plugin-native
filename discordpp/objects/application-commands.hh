//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

#define Name ApplicationCommand
#define Fields                                                                 \
    field(Snowflake, id), omittable_field(ApplicationCommandType, type),       \
        field(Snowflake, application_id),                                      \
        omittable_field(Snowflake, guild_id), field(std::string, name),        \
        field(std::string, description),                                       \
        omittable_field(std::vector<ApplicationCommandOption>, options),       \
        omittable_field(bool, default_permission), field(Snowflake, version)
#include "../macros/defineObjectOpen.hh"
// This space intentionally left blank
#include "../macros/defineObjectClose.hh"

#define Name ApplicationCommandOption
#define Fields                                                                 \
    field(ApplicationCommandOptionType, type), field(std::string, name),       \
        field(std::string, description), omittable_field(bool, required),      \
        omittable_field(std::vector<ApplicationCommandOptionChoice>, choices), \
        omittable_field(std::vector<ApplicationCommandOption>, options),       \
        omittable_field(MessageType, channel_types)
#include "../macros/defineObjectOpen.hh"
// This space intentionally left blank
#include "../macros/defineObjectClose.hh"

class ApplicationCommandOptionChoice {
  public:
    AUTO_CONSTRUCTORS(ApplicationCommandOptionChoice)

    field<std::string> name;
    field<std::variant<int, double, std::string>> value;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(ApplicationCommandOptionChoice, {}, {},
                                         name, value);
};

class ApplicationCommandInteractionDataOption {
  public:
    AUTO_CONSTRUCTORS(ApplicationCommandInteractionDataOption)

    field<std::string> name;
    field<ApplicationCommandOptionType> type;
    omittable_field<json> value;
    omittable_field<std::vector<ApplicationCommandInteractionDataOption>>
        options;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(
        ApplicationCommandInteractionDataOption,
        {
            if (t.value.is_omitted() && t.options.is_omitted()) {
                throw std::logic_error(
                    "Either \"value\" or \"options\" must be present to "
                    "serialize an ApplicationCommandInteractionDataOption");
            }
        },
        {}, name, type, value, options);
};

class GuildApplicationCommandPermissions {
  public:
    AUTO_CONSTRUCTORS(GuildApplicationCommandPermissions)

    field<Snowflake> id;
    field<Snowflake> application_id;
    field<Snowflake> guild_id;
    field<std::vector<ApplicationCommandPermission>> permissions;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(GuildApplicationCommandPermissions, {},
                                         {}, id, application_id, guild_id,
                                         permissions);
};

class ApplicationCommandPermission {
  public:
    AUTO_CONSTRUCTORS(ApplicationCommandPermission)

    field<Snowflake> id;
    field<ApplicationCommandPermissionType> type;
    field<bool> permission;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(ApplicationCommandPermission, {}, {},
                                         id, type, permission);
};
