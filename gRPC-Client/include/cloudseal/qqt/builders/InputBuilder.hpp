#pragma once
#include <cloudseal/qqt/builders/ObjectBuilder.hpp>
#include <cloudseal/qqt/components/Input.hpp>
#include <string>

namespace cloudseal::qqt::builders
{   
    class InputBuilder : public ObjectBuilder<Input>
    {
    public:
        InputBuilder() = default;

        virtual ~InputBuilder() noexcept = default;
        
        InputBuilder& text(const std::string& text);

        InputBuilder& icon(const std::string& icon);

        InputBuilder& placeholder(const std::string& placeholder);
    };
    
} // namespace cloudseal::qqt::builders
