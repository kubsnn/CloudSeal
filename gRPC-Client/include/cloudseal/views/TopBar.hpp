#pragma once
#include <cloudseal/qqt.hpp>
#include <cloudseal/qqt/Callbacks.hpp>
#include <cloudseal/views/IView.hpp>
#include <QApplication>
#include <QtCore/QMetaMethod>

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
                              .text("✕")
                              .size({.width = 32, .height = 32})
                              .padding({.left = 0, .right = 0, .top = 0, .bottom = 0})
                              .margin({.left = 0, .right = 0, .top = 0, .bottom = 0})
                              .anchors({.right = "parent.right", .verticalCenter = "parent.verticalCenter"})
                              .color("#333") // Dark gray color
                              .colorOnHover("red") // red
                              .colorOnPress("#c0392b")
                              .callback(Callbacks::Clicked, []()
                                    { 
                                        QMetaObject::invokeMethod(QApplication::instance(), "quit", Qt::QueuedConnection);
                                        QCoreApplication::exit(0); 
                                    })
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
