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

        virtual const std::vector<std::shared_ptr<cloudseal::qqt::Object>>& getObjects() const noexcept = 0;
    };
} // namespace cloudseal::views