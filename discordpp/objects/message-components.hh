//
// Created by Aidan on 8/27/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class Component {
  public:
    AUTO_CONSTRUCTORS(Component)

    Component(field<ComponentType> type, omittable_field<std::string> customId,
              omittable_field<bool> disabled,
              omittable_field<ButtonStyle> style,
              omittable_field<std::string> label, omittable_field<Emoji> emoji,
              omittable_field<std::string> url,
              omittable_field<std::vector<SelectOption>> options,
              omittable_field<std::string> placeholder,
              omittable_field<int> minValues, omittable_field<int> maxValues,
              omittable_field<std::vector<Component>> components)
        : type(std::move(type)), custom_id(std::move(customId)),
          disabled(std::move(disabled)), style(std::move(style)),
          label(std::move(label)), emoji(std::move(emoji)), url(std::move(url)),
          options(std::move(options)), placeholder(std::move(placeholder)),
          min_values(std::move(minValues)), max_values(std::move(maxValues)),
          components(std::move(components)) {}

    field<ComponentType> type;
    omittable_field<std::string> custom_id;
    omittable_field<bool> disabled;
    omittable_field<ButtonStyle> style;
    omittable_field<std::string> label;
    omittable_field<Emoji> emoji;
    omittable_field<std::string> url;
    omittable_field<std::vector<SelectOption>> options;
    omittable_field<std::string> placeholder;
    omittable_field<int> min_values;
    omittable_field<int> max_values;
    omittable_field<std::vector<Component>> components;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Component, {}, {}, type, custom_id,
                                         disabled, style, label, emoji, url,
                                         options, placeholder, min_values,
                                         max_values, components)
};

class Button : public Component {
    using Component::components;
    using Component::max_values;
    using Component::min_values;
    using Component::options;
    using Component::placeholder;

  public:
    Button()
        : Component(ComponentType::BUTTON, uninitialized, uninitialized,
                    uninitialized, uninitialized, uninitialized, uninitialized,
                    omitted, omitted, omitted, omitted, omitted) {}

    Button(omittable_field<std::string> customId,
           omittable_field<bool> disabled, omittable_field<ButtonStyle> style,
           omittable_field<std::string> label, omittable_field<Emoji> emoji,
           omittable_field<std::string> url,
           omittable_field<std::vector<Component>> components)
        : Component(ComponentType::BUTTON, customId, disabled, style, label,
                    emoji, url, omitted, omitted, omitted, omitted, omitted) {}

    Button(const json &j) { from_json(j, *this); }

    const field<ComponentType> &type = Component::type;
};

class SelectMenu : public Component {
    using Component::emoji;
    using Component::label;
    using Component::style;
    using Component::url;

  public:
    SelectMenu()
        : Component(ComponentType::SELECTMENU, uninitialized, uninitialized,
                    omitted, omitted, omitted, omitted, uninitialized,
                    uninitialized, uninitialized, uninitialized, omitted) {}

    SelectMenu(omittable_field<std::string> customId,
               omittable_field<bool> disabled,
               std::vector<SelectOption> options,
               omittable_field<std::string> placeholder,
               omittable_field<int> minValues, omittable_field<int> maxValues)
        : Component(ComponentType::SELECTMENU, customId, disabled, omitted,
                    omitted, omitted, omitted, options, placeholder, minValues,
                    maxValues, omitted) {}

    SelectMenu(const json &j) { from_json(j, *this); }

    const field<ComponentType> &type = Component::type;
};

class ActionRow : public Component {
    using Component::custom_id;
    using Component::disabled;
    using Component::emoji;
    using Component::label;
    using Component::max_values;
    using Component::min_values;
    using Component::options;
    using Component::placeholder;
    using Component::style;
    using Component::url;

  public:
    ActionRow()
        : Component(ComponentType::ACTIONROW, omitted, omitted, omitted,
                    omitted, omitted, omitted, omitted, omitted, omitted,
                    omitted, uninitialized) {}

    ActionRow(omittable_field<std::vector<Component>> components)
        : Component(ComponentType::ACTIONROW, omitted, omitted, omitted,
                    omitted, omitted, omitted, omitted, omitted, omitted,
                    omitted, components) {}

    ActionRow(const json &j) { from_json(j, *this); }

    const field<ComponentType> &type = Component::type;
};

class SelectOption {
  public:
    AUTO_CONSTRUCTORS(SelectOption)

    field<std::string> label;
    field<std::string> value;
    omittable_field<std::string> description;
    omittable_field<Emoji> emoji;
    omittable_field<bool> default_selection;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(
        SelectOption,
        {
            if (!t.default_selection.is_omitted()) {
                j["default"] = t.default_selection;
            }
        },
        { j.at("default").get_to(t.default_selection); }, label, value,
        description, emoji)
};
