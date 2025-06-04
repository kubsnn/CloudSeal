#pragma once
#include <cloudseal/qqt/builders/ObjectBuilder.hpp>
#include <cloudseal/qqt/components/Button.hpp>
#include <functional>
#include <memory>

namespace cloudseal::qqt::builders
{   
    class ButtonBuilder : public ObjectBuilder<Button>
    {
    public:
        ButtonBuilder() = default;
        virtual ~ButtonBuilder() = default;
        
        constexpr ButtonBuilder& text(const std::string& text) { object_->text = text; return *this; }
        constexpr ButtonBuilder& icon(const std::string& icon) { object_->icon = icon; return *this; }

       
    };
    
} // namespace cloudseal::qqt::builders
