#pragma once
#include <qt_layer/builders/ObjectBuilder.hpp>

namespace cloudseal::qt_layer::builders
{
    class ButtonBuilder : public ObjectBuilder<Button>
    {
    public:

        ButtonBuilder() = default;
        virtual ~ButtonBuilder() = default;
        
        inline virtual ButtonBuilder& text(const std::string& text) final
        {
            object_.text_ = text;
            return *this;
        }
        inline virtual ButtonBuilder& icon(const std::string& icon) final
        {
            object_.icon_ = icon;
            return *this;
        }
    };
} // namespace cloudseal::qt_layer::builders