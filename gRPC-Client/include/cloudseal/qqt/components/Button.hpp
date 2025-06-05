#pragma once

// CloudSeal includes
#include <cloudseal/qqt/Object.hpp>

// Third-party includes (before namespace)
#include <nlohmann/json.hpp>

namespace cloudseal::qqt
{
    namespace builders
    {
        template <typename TObject, typename TBuilder>
        class ObjectBuilder;

        class ButtonBuilder;
    }
    class Button : public Object
    {
    public:
        template <typename, typename>
        friend class cloudseal::qqt::builders::ObjectBuilder;
        friend class builders::ButtonBuilder;

        inline Button() : Object("Button") {}

        virtual ~Button() noexcept = default;

        inline virtual void serialize(nlohmann::json& j) const override
        {
            Object::serialize(j);
            j["text"] = text;
            j["icon"] = icon;
        }
        
    private:
        std::optional<std::string> text;

        std::optional<std::string> icon;
    };
}
