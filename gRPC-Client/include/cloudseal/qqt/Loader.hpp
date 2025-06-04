#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>
#include <QtCore/QMetaObject>
#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <cloudseal/logger.hpp>
#include <cloudseal/qqt/jinja/QMLJinja.hpp>
#include <cloudseal/qqt/Object.hpp>
#include <cloudseal/qqt/components/Pane.hpp>
#include <cloudseal/qqt/components/Rectangle.hpp>
#include <cloudseal/qqt/Callbacks.hpp>
#include <cloudseal/qqt/CallbacksStorage.hpp>

namespace cloudseal::qqt
{
    class Loader
    {
    public:
        Loader(const std::shared_ptr<QQmlApplicationEngine> &engine)
            : engine_(engine)
        {
            if (engine_->rootObjects().isEmpty())
            {
                log.error() << "No root objects found in the QML engine.";
                return;
            }
        }

        virtual ~Loader() = default;

        template<typename T>
        QObject* get(const T& object) const
        {
            auto id = object->uuid();
            auto it = components_.find(id);
            if (it != components_.end())
            {
                return it->second;
            }
            log.error() << "Component with ID " << id << " not found.";
            return nullptr;
        }

        bool createObjects(std::shared_ptr<Object> object, const std::string &parentId = "")
        {
            auto children = object->releaseChildren();

            if (auto pane = std::dynamic_pointer_cast<Pane>(object))
            {
                auto rect = std::move(pane->background);
                pane->background.reset();
                createObject(*object, parentId);
                if (rect)
                {
                    createObject(rect.value(), object->uuid());
                }
            }
            else
            {
                createObject(*object, parentId);
            }

            if (children.empty())
            {
                return true;
            }

            for (auto &child : children)
            {
                if (!createObjects(child, object->uuid()))
                {
                    log.error() << "Failed to create child object with ID: " << child->uuid();
                    return false;
                }
            }
            return true;
        }

        bool createObject(Object &object, const std::string &parentId = "")
        {
            if (engine_->rootObjects().isEmpty())
            {
                log.error() << "No root objects found in the QML engine.";
                return false;
            }

            auto rootObject = engine_->rootObjects().first();

            QVariant result;
            bool res = QMetaObject::invokeMethod(engine_->rootObjects().first(),
                                                 "createDynamicComponentFromString",
                                                 Qt::DirectConnection,
                                                 Q_RETURN_ARG(QVariant, result),
                                                 Q_ARG(QVariant, QString::fromStdString(object.getQMLString()))
                                            );

            if (res && result.isValid())
            {
                QObject *obj = result.value<QObject *>();
                if (obj)
                {
                    components_[object.uuid()] = obj;
                    auto parent = getParent(parentId);
                    if (parent)
                    {
                        qobject_cast<QQuickItem*>(obj)->setParentItem(qobject_cast<QQuickItem *>(parent));
                    }
                    else
                    {
                        obj->setParent(rootObject);
                        obj->setProperty("visible", true);
                    }
                    if (dynamic_cast<const Rectangle *>(&object))
                    {
                        auto &pane = components_[parentId];
                        pane->setProperty("background", QVariant::fromValue(obj));
                    }

                    auto callbacks = object.releaseCallbacks();

                    if (callbacks) {
                        auto callbacksStorage = callbacks->build(obj);

                        QObject::connect(obj, &QObject::destroyed, obj, [callbacksStorage, type = object.type()]() {
                            delete callbacksStorage; // Clean up callbacksStorage when the object is destroyed
                            log.debug() << "callbacksStorage for " << type << " destroyed.";
                        });
                    }
                }
                else
                {
                    log.error() << "Returned object is null.";
                }
            }
            else
            {
                log.error() << "Failed to create component from QML string";
            }

            return res && result.isValid();
        }

        
        QObject *getParent(const std::string &parentId) const
        {
            auto it = components_.find(parentId);
            if (it != components_.end())
            {
                return it->second;
            }
            log.error() << "Parent with ID " << parentId << " not found.";
            return nullptr;
        }

        // Dodaj getter dla komponentów
        const std::unordered_map<std::string, QObject *> &getComponents() const
        {
            return components_;
        }

        // Dodaj getter dla engine
        std::shared_ptr<QQmlApplicationEngine> getEngine() const
        {
            return engine_;
        }

    private:
        std::shared_ptr<QQmlApplicationEngine> engine_;
        std::unordered_map<std::string, QObject *> components_;
    };
}