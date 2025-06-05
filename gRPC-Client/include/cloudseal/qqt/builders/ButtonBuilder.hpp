#pragma once
#include <cloudseal/qqt/builders/ObjectBuilder.hpp>
#include <cloudseal/qqt/components/Button.hpp>
#include <string>

namespace cloudseal::qqt::builders
{   
	class ButtonBuilder : public ObjectBuilder<Button, ButtonBuilder>
    {
    public:
        ButtonBuilder() = default;

        virtual ~ButtonBuilder() noexcept = default;
        
        ButtonBuilder& text(const std::string& text);

        ButtonBuilder& icon(const std::string& icon);
    };
    
} // namespace cloudseal::qqt::builders
