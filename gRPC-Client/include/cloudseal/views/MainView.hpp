#pragma once
#include <cloudseal/views/IView.hpp>
#include <cloudseal/qqt/Callbacks.hpp>
#include <cloudseal/qqt.hpp>

#include <cloudseal/views/TopBar.hpp>
#include <cloudseal/qqt/builders/InputBuilder.hpp>
#include <cloudseal/logger.hpp>

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
            auto input = builders::InputBuilder()
                .placeholder("Enter text here")
                .size({.width = 200, .height = 32})
                .anchors({.centerIn = "parent"})
                .callback(Callbacks::TextChanged, [](QVariant value)
                {
                    log.debug() << "Input text changed to: " << value.toString().toStdString();
                })
                .build();
            objects_.push_back(input);
        }

        std::vector<std::shared_ptr<Object>> getObjects() const override
        {
            return objects_;
        }
    private:
        std::vector<std::shared_ptr<Object>> objects_;
    };
} // namespace cloudseal::qqt::views