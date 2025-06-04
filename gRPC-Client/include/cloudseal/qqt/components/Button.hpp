#pragma once

// CloudSeal includes
#include <cloudseal/qqt/Object.hpp>

// Third-party includes (before namespace)
#include <nlohmann/json.hpp>

namespace cloudseal::qqt
{
    namespace builders
    {
        class ButtonBuilder;
        template <typename TObject>
        class ObjectBuilder;
    }
    class Button : public Object
    {
    public:
        friend class builders::ButtonBuilder;
        friend class builders::ObjectBuilder<Button>;
        friend class builders::ObjectBuilder<Object>;

        Button() : Object("Button") {}
        virtual ~Button() = default;

        // NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE_WITH_DEFAULT(
        //     Button, Object,
        //     text, icon
        // )

        virtual void serialize(nlohmann::json& j) const override
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
