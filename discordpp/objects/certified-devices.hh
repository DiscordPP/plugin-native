//
// Created by Aidan on 8/27/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

#include "../field.hh"

class Device {
  public:
    AUTO_CONSTRUCTORS(Device)

    field<DeviceType> type;
    field<std::string> id;
    field<Vendor> vendor;
    field<Model> model;
    field<std::vector<std::string>> related;
    omittable_field<bool> echo_cancellation;
    omittable_field<bool> noise_suppression;
    omittable_field<bool> automatic_gain_control;
    omittable_field<bool> hardware_mute;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Device, {}, {}, type, id, vendor,
                                         model, related, echo_cancellation,
                                         noise_suppression,
                                         automatic_gain_control, hardware_mute)
};

class Vendor {
  public:
    AUTO_CONSTRUCTORS(Vendor)

    field<std::string> name;
    field<std::string> url;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Vendor, {}, {}, name, url)
};

class Model {
  public:
    AUTO_CONSTRUCTORS(Model)

    field<std::string> name;
    field<std::string> url;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Model, {}, {}, name, url)
};
