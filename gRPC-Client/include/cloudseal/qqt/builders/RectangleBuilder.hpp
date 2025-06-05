#pragma once
#include <cloudseal/qqt/builders/ObjectBuilder.hpp>

namespace cloudseal::qqt::builders
{
    class RectangleBuilder : public ObjectBuilder<Rectangle, RectangleBuilder>
    {
        using Base = ObjectBuilder<Rectangle, RectangleBuilder>;
    public:
        inline RectangleBuilder() {
            (void)Base::anchors({.fill = "parent"});
        }
        
        virtual ~RectangleBuilder() noexcept = default;

        inline RectangleBuilder& color(const std::string& color)
        {
            object_->color = color;
            return *this;
        }

        template<typename... Args>
        RectangleBuilder& anchors(Args&&...) = delete;
        
    };
} // namespace cloudseal::qqt::builders