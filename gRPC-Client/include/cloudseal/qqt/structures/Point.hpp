#pragma once
#include <nlohmann/json.hpp>
#include <optional>

namespace cloudseal::qqt
{
    struct Point
    {
        std::optional<int> x;
        std::optional<int> y;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Point, x, y)
}