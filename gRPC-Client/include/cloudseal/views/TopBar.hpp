#pragma once
#include <cloudseal/qqt.hpp>
#include <cloudseal/qqt/callbacks/Callbacks.hpp>
#include <cloudseal/views/IView.hpp>
#include <QApplication>
#include <QtCore/QMetaMethod>

namespace cloudseal::views
{
    class TopBar : public IView
    {
    public:
        TopBar()
        {
            auto pane = qqt::builders::PaneBuilder()
                            .background(
                                qqt::builders::RectangleBuilder()
                                    .color("#2c3e50") // Dark blue color
                                    .build())
                            .anchors({.left = "parent.left", .right = "parent.right", .top = "parent.top"})
                            .size({.height = 32})
                            .build();

            auto button = qqt::builders::ButtonBuilder()
                              .text("✕")
                              .size({.width = 32, .height = 32})
                              .anchors({.right = "parent.right", .verticalCenter = "parent.verticalCenter"})
                              .color("#dcdcdc") // Dark gray color
                              .colorOnHover("red") // red
                              .colorOnPress("#c0392b")
                              .callback(qqt::callbacks::Callbacks::Clicked, []()
                                    {
                                      Application::exit(0);
                                    })
                              .build();

            pane->addChild(button);
            objects_.push_back(pane);
        }

		constexpr std::string_view name() const noexcept override
		{
			return "TopBar";
		}

        const std::vector<std::shared_ptr<qqt::Object>>& objects() const noexcept override
        {
            return objects_;
        }

    private:
        std::vector<std::shared_ptr<qqt::Object>> objects_;
    };
} // namespace cloudseal::views
