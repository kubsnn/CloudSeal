#pragma once
#include <memory>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>

#include <qt_layer/jinja/QMLJinja.hpp>
#include <qt_layer/components/Button.hpp>

#include <App.hpp>

#include <qt_layer/builders/ButtonBuilder.hpp>
namespace cloudseal
{
    class GUI
    {
    public:
        GUI(const std::shared_ptr<QQmlApplicationEngine>& engine, int argc, char *argv[]) :
            engine_(engine){
               
            
            engine_->load(QUrl(QStringLiteral("qrc:/main.qml")));
            if (engine_->rootObjects().isEmpty())
                return;

            using namespace qt_layer;

            auto button = builders::ButtonBuilder()
                .text("Hello World")
                .size({100, 50})
                .position({100, 100})
                .anchors({.left = "parent.left", .top = "parent.top"})
                .padding({10, 10, 10, 10})
                .inset({5, 5, 5, 5})
                .margin({0, 0, 0, 0})
                .build();

            auto jinja = QMLJinja();
            auto qmlString = jinja.process("Button", button);
            loadComponentFromQMLString(qmlString);

        }
        virtual ~GUI() = default;

        void loadComponentFromQMLString(const std::string &qmlString)
        {
            QVariant newObjectVariant;
            
            QMetaObject::invokeMethod(engine_->rootObjects()[0], "createDynamicComponentFromString",
                                  Q_RETURN_ARG(QVariant, newObjectVariant),
                                  Q_ARG(QVariant, qmlString.c_str()));
        }

    private:
        std::shared_ptr<QQmlApplicationEngine> engine_;
    };
} // namespace cloudseal::qt_layer