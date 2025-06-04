#pragma once

// CloudSeal includes
#include <cloudseal/qqt/Object.hpp>
#include <cloudseal/qqt/components/Rectangle.hpp>

// Third-party includes (before namespace)
#include <nlohmann/json.hpp>
#include <optional>

namespace cloudseal::qqt
{
    namespace builders
    {
        class PaneBuilder;
        template <typename TObject>
        class ObjectBuilder;
    }
    class Pane : public Object
    {
    public:
        friend class builders::PaneBuilder;
        friend class builders::ObjectBuilder<Pane>;
        friend class builders::ObjectBuilder<Object>;

        Pane() : Object("Pane") {}
        virtual ~Pane() = default;

        // NLOHMANN_DEFINE_DERIVED_TYPE_INTRUSIVE_WITH_DEFAULT(
        //     Pane, Object,
        //     text, icon
        // )

        virtual void serialize(nlohmann::json& j) const override
        {
            Object::serialize(j);
            j["background"] = background.has_value() ? nlohmann::json(*background) : nullptr;
        }

        std::optional<Rectangle> background;
    };
}
