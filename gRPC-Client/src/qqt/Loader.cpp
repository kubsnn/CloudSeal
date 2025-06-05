#include <cloudseal/qqt/Loader.hpp>
#include <QtQuick/QQuickItem>
#include <QtCore/QMetaObject>
#include <QtCore/QVariant>
#include <cloudseal/logger.hpp>

namespace cloudseal::qqt {

    Loader::Loader(std::shared_ptr<QQmlApplicationEngine> engine)
        : engine_(std::move(engine))
    {
        if (engine_->rootObjects().isEmpty())
        {
            log.error() << "No root objects found in the QML engine.";
            return;
        }
    }

    QObject* Loader::get(std::shared_ptr<const Object> object) const
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

    bool Loader::createObjects(std::shared_ptr<Object> object, const std::string& parentId)
    {
        auto children = object->releaseChildren();

        if (auto pane = std::dynamic_pointer_cast<Pane>(object))
        {
            auto rect = std::move(pane->background);
            pane->background.reset();
            createObject(object.get(), parentId);
            if (rect)
            {
                createObject(&rect.value(), object->uuid());
            }
        }
        else
        {
            createObject(object.get(), parentId);
        }

        if (children.empty())
        {
            return true;
        }

        for (auto& child : children)
        {
            if (!createObjects(child, object->uuid()))
            {
                log.error() << "Failed to create child object with ID: " << child->uuid();
                return false;
            }
        }
        return true;
    }

    bool Loader::createObject(Object* object, const std::string& parentId)
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
            Q_ARG(QVariant, QString::fromStdString(object->getQMLString()))
        );

        if (!(res && result.isValid()))
        {
            log.error() << "Failed to create component from QML string";
            return false;
        }

        auto qobj = result.value<QObject*>();

        if (qobj == nullptr)
        {
            log.error() << "Returned object is null.";
            return false;
        }

        components_[object->uuid()] = qobj;

        updateQObjectParent(object, qobj, parentId);

		updatePaneIfRectangle(object, qobj, parentId);

		addCallbacks(object, qobj);

		return true;
    }

    void Loader::addCallbacks(Object* object, QObject* qobj) const
    {
        auto callbacks = object->releaseCallbacks();

        if (!callbacks) return;

        auto callbacksStorage = callbacks->build(qobj);

        QObject::connect(qobj, &QObject::destroyed, qobj, [callbacksStorage, type = object->type()]() {
            delete callbacksStorage; // Clean up callbacksStorage when the object is destroyed
            log.debug() << "callbacksStorage for " << type << " destroyed.";
        });
    }

    void Loader::updateQObjectParent(Object* object, QObject* obj, const std::string& parentId) const
    {
        auto parent = getParent(parentId);
        if (parent)
        {
            qobject_cast<QQuickItem*>(obj)->setParentItem(qobject_cast<QQuickItem*>(parent));
            return;
        }

        auto rootObject = engine_->rootObjects().first();

        obj->setParent(rootObject);
        obj->setProperty("visible", true);
    }

    void Loader::updatePaneIfRectangle(Object* object, QObject* qobj, const std::string& parentId)
    {
        if (dynamic_cast<const Rectangle*>(object))
        {
            const auto& pane = components_[parentId];
            pane->setProperty("background", QVariant::fromValue(qobj));
        }
    }


    QObject* Loader::getParent(const std::string& parentId) const
    {
        auto it = components_.find(parentId);
        if (it != components_.end())
        {
            return it->second;
        }
        log.error() << "Parent with ID " << parentId << " not found.";
        return nullptr;
    }


    // Dodaj getter dla komponent�w
    const std::unordered_map<std::string, QObject*>& Loader::getComponents() const
    {
        return components_;
    }

    // Dodaj getter dla engine
    std::shared_ptr<QQmlApplicationEngine> Loader::getEngine() const
    {
        return engine_;
    }
}