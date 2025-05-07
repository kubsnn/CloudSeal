#pragma once
#include <utils/utils.hpp>
#include <qt_layer/structures/Anchors.hpp>
#include <qt_layer/structures/Padding.hpp>
#include <qt_layer/structures/Inset.hpp>
#include <qt_layer/structures/Margin.hpp>
#include <nlohmann/json.hpp>
#include <string>

namespace cloudseal::qt_layer {
    struct Layout {
        // Layout(Anchors anchors = {}, Padding padding = {}, Inset inset = {}, Margin margin = {})
        //     : anchors_(anchors), padding_(padding), inset_(inset), margin_(margin)
        // {}

        virtual ~Layout() = default;

        Anchors anchors_;
        Padding padding_;
        Inset inset_;
        Margin margin_;
    };

    
}