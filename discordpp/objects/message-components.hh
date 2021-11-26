//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

#define Name Component
#define Fields                                                                 \
    field(ComponentType, type), omittable_field(std::string, custom_id),       \
        omittable_field(bool, disabled), omittable_field(ButtonStyle, style),  \
        omittable_field(std::string, label), omittable_field(Emoji, emoji),    \
        omittable_field(std::string, url),                                     \
        omittable_field(std::vector<SelectOption>, options),                   \
        omittable_field(std::string, placeholder),                             \
        omittable_field(int, min_values), omittable_field(int, max_values),    \
        omittable_field(std::vector<Component>, components)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name Button
#define Parent Component
#define Fields                                                                 \
    static_field(ComponentType, type, ComponentType::BUTTON),                  \
        forward_omittable_field(std::string, custom_id),                       \
        forward_omittable_field(bool, disabled),                               \
        forward_omittable_field(ButtonStyle, style),                           \
        forward_omittable_field(std::string, label),                           \
        forward_omittable_field(Emoji, emoji),                                 \
        forward_omittable_field(std::string, url), exclude_field(options),     \
        exclude_field(placeholder), exclude_field(min_values),                 \
        exclude_field(max_values), exclude_field(components)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name SelectMenu
#define Parent Component
#define Fields                                                                 \
    static_field(ComponentType, type, ComponentType::SELECTMENU),              \
        forward_omittable_field(std::string, custom_id),                       \
        forward_omittable_field(bool, disabled), exclude_field(style),         \
        exclude_field(label), exclude_field(emoji), exclude_field(url),        \
        forward_omittable_field(std::vector<SelectOption>, options),           \
        forward_omittable_field(std::string, placeholder),                     \
        forward_omittable_field(int, min_values),                              \
        forward_omittable_field(int, max_values), exclude_field(components)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name ActionRow
#define Parent Component
#define Fields                                                                 \
    static_field(ComponentType, type, ComponentType::ACTIONROW),               \
        exclude_field(custom_id), exclude_field(disabled),                     \
        exclude_field(style), exclude_field(label), exclude_field(emoji),      \
        exclude_field(url), exclude_field(options),                            \
        exclude_field(placeholder), exclude_field(min_values),                 \
        exclude_field(max_values),                                             \
        forward_omittable_field(std::vector<Component>, components)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

#define Name SelectOption
#define Fields                                                                 \
    field(std::string, label), field(std::string, value),                      \
        omittable_field(std::string, description),                             \
        omittable_field(Emoji, emoji),                                         \
        omittable_field(bool, "default", default_selection)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
