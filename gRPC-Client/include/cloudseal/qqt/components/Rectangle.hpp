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

        Rectangle() : Object("Rectangle") {}
        virtual ~Rectangle() = default;

        // NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE_WITH_DEFAULT(
        //     Rectangle, Object,
        //     text, icon
        // )

        virtual void serialize(nlohmann::json& j) const override
        {
            Object::serialize(j);
            j["color"] = color;
        }
    private:
        std::optional<std::string> color;
    };
}
