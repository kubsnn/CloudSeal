#pragma once
#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace cloudseal::qqt
{
    struct Anchors
    {
        std::optional<std::string> left;
        std::optional<std::string> right;
        std::optional<std::string> top;
        std::optional<std::string> bottom;

        std::optional<std::string> fill;
        std::optional<std::string> centerIn;
        std::optional<std::string> verticalCenter;
        std::optional<std::string> horizontalCenter;
    };

    // Use NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE for automatic JSON serialization/deserialization
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Anchors, left, right, top, bottom, fill, centerIn, verticalCenter, horizontalCenter)
}