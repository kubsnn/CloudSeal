#pragma once
#include <cloudseal/qqt/builders/ObjectBuilder.hpp>
#include <cloudseal/qqt/builders/RectangleBuilder.hpp>
#include <memory>

namespace cloudseal::qqt::builders
{
    class PaneBuilder : public ObjectBuilder<Pane, PaneBuilder>
    {
    public:
        virtual ~PaneBuilder() noexcept = default;

        inline PaneBuilder& background(const Rectangle& background)
        {
            object_->background = background;
            return *this;
        }

        inline PaneBuilder& background(const std::shared_ptr<Rectangle>& background)
        {
            object_->background = *background;
            return *this;
        }

        inline PaneBuilder& backgroundColor(const std::string& color)
        {
            auto rect = builders::RectangleBuilder()
                .color(color)
                .build();
            object_->background = *rect;
            return *this;
        }
    };
} // namespace cloudseal::qqt::builders