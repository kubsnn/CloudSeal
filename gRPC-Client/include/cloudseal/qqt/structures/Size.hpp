#pragma once
#include <nlohmann/json.hpp>
#include <optional>

namespace cloudseal::qqt
{
    struct Size
    {
        std::optional<int> width;
        std::optional<int> height;
    };
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Size, width, height)
}