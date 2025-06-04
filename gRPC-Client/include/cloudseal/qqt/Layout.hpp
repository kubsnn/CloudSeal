#pragma once
#include <cloudseal/utils/utils.hpp>
#include <cloudseal/qqt/structures/Anchors.hpp>
#include <cloudseal/qqt/structures/Padding.hpp>
#include <cloudseal/qqt/structures/Inset.hpp>
#include <cloudseal/qqt/structures/Margin.hpp>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>

namespace cloudseal::qqt {
    struct Layout {
        // Layout(Anchors anchors = {}, Padding padding = {}, Inset inset = {}, Margin margin = {})
        //     : anchors_(anchors), padding_(padding), inset_(inset), margin_(margin)
        // {}

        virtual ~Layout() = default;

        Anchors anchors;
        Padding padding;
        Inset inset;
        Margin margin;
    };

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Layout, anchors, padding, inset, margin)
}