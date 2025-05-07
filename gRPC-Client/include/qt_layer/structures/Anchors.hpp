#pragma once
#include <string>
#include <nlohmann/json.hpp>

namespace cloudseal::qt_layer
{
    struct Anchors
    {
        std::string left{};
        std::string right{};
        std::string top{};
        std::string bottom{};

        std::string fill{};
        std::string centerIn{};
    };

    // Use NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE for automatic JSON serialization/deserialization
    MY_JSON_INTRUSIVE(Anchors, left, right, top, bottom, fill, centerIn)
}