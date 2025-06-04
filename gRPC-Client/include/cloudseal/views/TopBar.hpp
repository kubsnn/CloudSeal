#pragma once
#include <cloudseal/qqt.hpp>
#include <cloudseal/qqt/Callbacks.hpp>
#include <cloudseal/views/IView.hpp>

using namespace cloudseal::qqt;

namespace cloudseal::views
{
    class TopBar : public IView
    {
    public:
        TopBar()
        {
            auto pane = builders::PaneBuilder()
                            .background(
                                builders::RectangleBuilder()
                                    .color("#2c3e50") // Dark blue color
                                    .build())
                            .anchors({.left = "parent.left", .right = "parent.right", .top = "parent.top"})
                            .size({.height = 32})
                            .build();

            auto button = builders::ButtonBuilder()
                              .text("Menu")
                              .size({.width = 100, .height = 32})
                              .padding({.left = 10, .right = 10, .top = 0, .bottom = 0})
                              .anchors({.left = "parent.left", .verticalCenter = "parent.verticalCenter"})
                              .callback(Callbacks::Clicked, []()
                                        { std::cout << "Menu button clicked" << std::endl; })
                              .build();

            pane->addChild(button);
            objects_.push_back(pane);
        }

        std::vector<std::shared_ptr<Object>> getObjects() const override
        {
            return objects_;
        }

    private:
        std::vector<std::shared_ptr<cloudseal::qqt::Object>> objects_;
    };
} // namespace cloudseal::views
