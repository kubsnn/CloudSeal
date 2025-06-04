#pragma once
#include <cloudseal/qqt/Object.hpp>

namespace cloudseal::views
{
    class IView
    {
    public:
        virtual ~IView() = default;

        virtual std::vector<std::shared_ptr<cloudseal::qqt::Object>> getObjects() const = 0;
    };
} // namespace cloudseal::views