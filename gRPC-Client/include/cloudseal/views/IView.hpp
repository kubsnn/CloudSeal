#pragma once
#include <cloudseal/qqt/Object.hpp>
#include <memory>
#include <vector>
#include <string_view>

namespace cloudseal::views
{
    class IView
    {
    public:
        virtual ~IView() noexcept = default;

		virtual std::string_view name() const noexcept = 0;

        virtual const std::vector<std::shared_ptr<cloudseal::qqt::Object>>& objects() const noexcept = 0;
    };
} // namespace cloudseal::views