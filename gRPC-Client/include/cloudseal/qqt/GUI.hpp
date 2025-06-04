#pragma once
#include <cloudseal/qqt.hpp>
#include <memory>
#include <unordered_map>
#include <iostream>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>
#include <QtCore/QMetaObject>
#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <QtQuick/QQuickItem>

#include <cloudseal/qqt/jinja/QMLJinja.hpp>
#include <cloudseal/logger.hpp>
#include <cloudseal/qqt/Loader.hpp>
#include <cloudseal/qqt/QFunctions.hpp>
#include <cloudseal/qqt/LambdaSlot.hpp>

#include <cloudseal/views/IView.hpp>

namespace cloudseal
{
    class GUI
    {
    public:
        GUI(const std::shared_ptr<QQmlApplicationEngine> &engine, int argc, char *argv[]) : engine_(engine), loader_(engine_)
        {
            engine_->load(QUrl::fromLocalFile("main.qml"));
            if (engine_->rootObjects().isEmpty())
                return;
        }

        bool makeView(std::shared_ptr<cloudseal::views::IView> &view)
        {
            if (!view)
            {
                log.error() << "View is null.";
                return false;
            }

            if (view->getObjects().empty())
            {
                log.error() << "View has no objects to add.";
                return false;
            }

            for (auto &object : view->getObjects())
            {
                if (!addObject(object))
                {
                    log.error() << "Failed to add object with ID: " << object->uuid();
                    return false;
                }

                
            }

            return true;
        }

        bool addObject(std::shared_ptr<cloudseal::qqt::Object> object, const std::string &parentId = "")
        {
            return loader_.createObjects(object, parentId);
        }

    private:
        std::shared_ptr<QQmlApplicationEngine> engine_;
        cloudseal::qqt::Loader loader_;
    };
} // namespace cloudseal