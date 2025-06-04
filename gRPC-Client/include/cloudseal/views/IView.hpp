#pragma once
#include <cloudseal/qqt/Object.hpp>
#include <memory>
#include <vector>

namespace cloudseal::views
{
    class IView
    {
    public:
        virtual ~IView() noexcept = default;

        virtual std::vector<std::shared_ptr<cloudseal::qqt::Object>> getObjects() const = 0;
    };
} // namespace cloudseal::views