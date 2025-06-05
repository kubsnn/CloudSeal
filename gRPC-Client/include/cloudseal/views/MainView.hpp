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

            auto pane = builders::PaneBuilder()
                .background(
                    builders::RectangleBuilder()
                        .color("#ecf0f1") // Light gray color
                        .build())
                .anchors({.left = "parent.left", .right = "parent.right", .bottom = "parent.bottom"})
                .size({.height = 32})
                .build();

            auto input = builders::InputBuilder()
                .placeholder("Enter text here")
                .size({.width = 200, .height = 32})
                .anchors({.centerIn = "parent"})
                .callback(Callbacks::TextChanged, [id = pane->uuid()](QVariant value)
                {
                    auto background = Application::components().find(id)->second->property("background").value<QObject*>();
                    if (background)
                    {
                        background->setProperty("color", value.toString());
                    }
                })
                .build();
            objects_.push_back(input);
            objects_.push_back(pane);
        }

        std::vector<std::shared_ptr<Object>> getObjects() const override
        {
            return objects_;
        }
    private:
        std::vector<std::shared_ptr<Object>> objects_;
    };
} // namespace cloudseal::qqt::views