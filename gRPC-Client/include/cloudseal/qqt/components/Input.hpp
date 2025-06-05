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

        class InputBuilder;
    }
    class Input : public Object
    {
    public:
        template <typename, typename>
        friend class builders::ObjectBuilder;
        friend class builders::InputBuilder;

        inline Input() : Object("Input") {}

        virtual ~Input() noexcept = default;

        inline virtual void serialize(nlohmann::json& j) const override
        {
            Object::serialize(j);
            j["placeholder"] = placeholder;
            j["text"] = text;
            j["icon"] = icon;
        }
        
    private:
        std::optional<std::string> placeholder;
        std::optional<std::string> text;
        std::optional<std::string> icon;
    };
}
