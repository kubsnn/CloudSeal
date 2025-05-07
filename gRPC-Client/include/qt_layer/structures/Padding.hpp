#pragma once
#include <string>
#include <nlohmann/json.hpp>

namespace cloudseal::qt_layer
{
    struct Padding
    {
        int left = 0;
        int right = 0;
        int top = 0;
        int bottom = 0;
    };

    // Use NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE for automatic JSON serialization/deserialization
    MY_JSON_INTRUSIVE(Padding, left, right, top, bottom);
}