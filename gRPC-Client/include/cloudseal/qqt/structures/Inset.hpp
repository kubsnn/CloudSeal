#pragma once
#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace cloudseal::qqt
{
    struct Inset
    {
        std::optional<int> left;
        std::optional<int> right;
        std::optional<int> top;
        std::optional<int> bottom;
    };

    // Use NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE for automatic JSON serialization/deserialization
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Inset, left, right, top, bottom);
}