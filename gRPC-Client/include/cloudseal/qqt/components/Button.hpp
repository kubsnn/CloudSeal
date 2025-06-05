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
