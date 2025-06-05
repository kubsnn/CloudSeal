#pragma once
#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace cloudseal::qqt
{
    struct Padding
    {
        std::optional<int> left;

        std::optional<int> right;

        std::optional<int> top;

        std::optional<int> bottom;
    };

    // Use NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE for automatic JSON serialization/deserialization
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Padding, left, right, top, bottom);
}