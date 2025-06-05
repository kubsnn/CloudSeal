#pragma once

// CloudSeal includes
#include <cloudseal/qqt/Object.hpp>

// Third-party includes (before namespace)
#include <nlohmann/json.hpp>
#include <optional>

namespace cloudseal::qqt
{
    namespace builders
    {
        class RectangleBuilder;
    }
    class Rectangle : public Object
    {
    public:
        friend class builders::RectangleBuilder;
        friend class builders::ObjectBuilder<Rectangle>;

        inline Rectangle() : Object("Rectangle") {}

        virtual ~Rectangle() noexcept = default;

        inline virtual void serialize(nlohmann::json& j) const override
        {
            Object::serialize(j);
            j["color"] = color;
        }

    private:
        std::optional<std::string> color;
    };
}
