#include <cloudseal/qqt/builders/InputBuilder.hpp>

namespace cloudseal::qqt::builders
{
    InputBuilder& InputBuilder::text(const std::string& text)
    {
        object_->text = text;
        return *this;
    }

    InputBuilder& InputBuilder::icon(const std::string& icon)
    {
        object_->icon = icon;
        return *this;
    }

    InputBuilder& InputBuilder::placeholder(const std::string& placeholder)
    {
        object_->placeholder = placeholder;
        return *this;
    }
} // namespace cloudseal::qqt::builders