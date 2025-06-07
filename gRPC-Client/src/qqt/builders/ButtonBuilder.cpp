#include <cloudseal/qqt/builders/ButtonBuilder.hpp>

namespace cloudseal::qqt::builders
{
    ButtonBuilder& ButtonBuilder::text(const std::string& text)
    {
        object_->text = text;

        return *this;
    }

    ButtonBuilder& ButtonBuilder::icon(const std::string& icon)
    {
        object_->icon = icon;

        return *this;
    }
} // namespace cloudseal::qqt::builders