#pragma once
#include <qt_layer/Object.hpp>
#include <nlohmann/json.hpp>

namespace cloudseal::qt_layer
{
    namespace builders
    {
        class ButtonBuilder;
    }
    class Button : public Object
    {
    public:
        friend class builders::ButtonBuilder;
        friend class builders::ObjectBuilder<Button>;

        virtual ~Button() = default;

    private:
        std::string text_;
        std::string icon_;
    };
}