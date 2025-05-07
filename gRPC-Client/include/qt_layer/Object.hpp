#pragma once
#include <utils/utils.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <qt_layer/Layout.hpp>
#include <qt_layer/structures/Size.hpp>
#include <qt_layer/structures/Point.hpp>
#include <qt_layer/builders/ObjectBuilder.hpp>

namespace cloudseal::qt_layer {
    class Object {
    public:
        friend class builders::ObjectBuilder<Object>;

        Object()
            : uuid_(utils::generate_uuid()) {}
        virtual ~Object() = default;

    protected:
        const std::string& uuid() const {
            return uuid_;
        }
        bool visible_ = true;
        Size size_{};
        Point position_{};
        Layout layout_{};

    private:
        std::string uuid_;
    };
}