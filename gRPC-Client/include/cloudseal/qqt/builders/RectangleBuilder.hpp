#pragma once
#include <cloudseal/qqt/builders/ObjectBuilder.hpp>

namespace cloudseal::qqt::builders
{
    class RectangleBuilder : public ObjectBuilder<Rectangle>
    {
    public:
        RectangleBuilder() {
            this->anchors({.fill = "parent"});
        }
        virtual ~RectangleBuilder() = default;

        inline RectangleBuilder& color(const std::string& color)
        {
            object_->color = color;
            return *this;
        }
        
    };
} // namespace cloudseal::qqt::builders