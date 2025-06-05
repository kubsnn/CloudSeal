#pragma once

// CloudSeal includes
#include <cloudseal/qqt/Object.hpp>

// Third-party includes (before namespace)
#include <nlohmann/json.hpp>

namespace cloudseal::qqt
{
    namespace builders
    {
        class InputBuilder;
        template <typename TObject>
        class ObjectBuilder;
    }
    class Input : public Object
    {
    public:
        friend class builders::InputBuilder;
        friend class builders::ObjectBuilder<Input>;
        friend class builders::ObjectBuilder<Object>;

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
