//
// Created by Aidan on 8/27/2021.
//

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

#include "../field.hh"

// TODO unverified
#define Name Device
#define Fields                                                                 \
    field(DeviceType, type), field(std::string, id), field(Vendor, vendor),    \
        field(Model, model), field(std::vector<std::string>, related),         \
        omittable_field(bool, echo_cancellation),                              \
        omittable_field(bool, noise_suppression),                              \
        omittable_field(bool, automatic_gain_control),                         \
        omittable_field(bool, hardware_mute)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

// TODO unverified
#define Name Vendor
#define Fields field(std::string, name), field(std::string, url)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"

// TODO unverified
#define Name Model
#define Fields field(std::string, name), field(std::string, url)
#include "../util/defineObjectOpen.hh"
// This space intentionally left blank
#include "../util/defineObjectClose.hh"
