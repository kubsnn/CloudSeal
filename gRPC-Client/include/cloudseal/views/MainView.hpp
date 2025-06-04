#pragma once
#include <cloudseal/views/IView.hpp>
#include <cloudseal/qqt/Callbacks.hpp>
#include <cloudseal/qqt.hpp>

#include <cloudseal/views/TopBar.hpp>

using namespace cloudseal::qqt;

namespace cloudseal::views
{
    class MainView : public IView
    {
    public:
        MainView()
        {
            auto topBar = std::make_shared<TopBar>();
            for (const auto &obj : topBar->getObjects())
            {
                objects_.push_back(obj);
            }
        }

        std::vector<std::shared_ptr<Object>> getObjects() const override
        {
            return objects_;
        }
    private:
        std::vector<std::shared_ptr<Object>> objects_;
    };
} // namespace cloudseal::qqt::views