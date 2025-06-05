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

		template <typename TObject, typename TBuilder>
        class ObjectBuilder;
    }

    class Loader;

    class Pane : public Object
    {
    public:
		template <typename, typename>
        friend class builders::ObjectBuilder;
        friend class builders::PaneBuilder;
		friend class Loader;

        inline Pane() : Object("Pane") {}

        virtual ~Pane() noexcept = default;

        inline virtual void serialize(nlohmann::json& j) const override
        {
            Object::serialize(j);
            j["background"] = background.has_value() ? nlohmann::json(*background) : nullptr;
        }

	private:
        std::optional<Rectangle> background;
    };
}
