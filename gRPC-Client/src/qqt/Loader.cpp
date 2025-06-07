#include <cloudseal/qqt/Loader.hpp>
#include <QtQuick/QQuickItem>
#include <QtCore/QMetaObject>
#include <QtCore/QVariant>
#include <cloudseal/logger.hpp>
#include <QQmlContext>

namespace cloudseal::qqt {

    Loader::Loader(std::shared_ptr<QQmlApplicationEngine> engine)
        : engine_(std::move(engine))
    {
        if (engine_->rootObjects().isEmpty()) [[unlikely]]
        {
            log.error() << "No root objects found in the QML engine.";
        }
    }

    QObject* Loader::get(std::shared_ptr<const Object> object) const
    {
        auto id = object->uuid();

        auto it = components_.find(id);
        if (it == components_.end()) [[unlikely]]
        {
            log.error() << "Component with ID " << id << " not found.";
            return nullptr;
        }

		return it->second;
    }

    bool Loader::createObjects(const std::shared_ptr<Object>& object, const std::string& parentId)
    {
        auto children = object->releaseChildren();

        if (auto pane = std::dynamic_pointer_cast<Pane>(object))
        {
            auto rect = std::move(pane->background);
            pane->background.reset();
            createObject(object.get(), parentId);

            if (rect) [[likely]]
            {
                createObject(&rect.value(), object->uuid());
            }
        }
        else
        {
            createObject(object.get(), parentId);
        }

        if (children.empty()) return true;

        for (auto& child : children)
        {
            if (!createObjects(child, object->uuid())) [[unlikely]]
            {
                log.error() << "Failed to create child object with ID: " << child->uuid();
                return false;
            }
        }

        return true;
    }

    bool Loader::createObject(Object* object, const std::string& parentId)
    {
        if (engine_->rootObjects().isEmpty()) [[unlikely]]
        {
            log.error() << "No root objects found in the QML engine.";
            return false;
        }

        auto qobj = createQObject(object, parentId);

        if (qobj == nullptr) [[unlikely]]
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

    QObject* Loader::createQObject(Object* object, const std::string& parentId)
    {
  //      QVariant result;
  //      bool res = QMetaObject::invokeMethod(engine_->rootObjects().first(),
  //          "createDynamicComponentFromString",
  //          Qt::DirectConnection,
  //          Q_RETURN_ARG(QVariant, result),
  //          Q_ARG(QVariant, QString::fromStdString(object->getQMLString()))
  //      );

		//if (!(res && result.isValid())) [[unlikely]]
  //      {
  //          log.error() << "Failed to create component from QML string";

  //          return nullptr;
  //      }

  //      return result.value<QObject*>();
        QQmlContext* context = new QQmlContext(engine_->rootContext());
        context->setContextProperty("parent", getParent(parentId));

        QQmlComponent component(engine_.get());
        component.setData(QString::fromStdString(object->getQMLString()).toUtf8(), QUrl(QString::fromStdString(object->type())));

        if (component.status() != QQmlComponent::Ready) {
            qWarning() << "Component error:" << component.errors();
            return nullptr;
        }

        QObject* qobj = component.create(context);

		if (!qobj) [[unlikely]]
		{
			log.error() << "Failed to create object from component.";
			return nullptr;
		}

		return qobj;
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

        obj->setParent(parent);
        qobject_cast<QQuickItem*>(obj)->setParentItem(qobject_cast<QQuickItem*>(parent));

        //obj->setProperty("visible", true);
    }

    void Loader::updatePaneIfRectangle(Object* object, QObject* qobj, const std::string& parentId)
    {
        if (!dynamic_cast<const Rectangle*>(object)) [[likely]] return;

        const auto& pane = components_[parentId];
        pane->setProperty("background", QVariant::fromValue(qobj));
    }

    QObject* Loader::getParent(const std::string& parentId) const
    {
        auto it = components_.find(parentId);
        if (it == components_.end()) [[unlikely]] {
            return qobject_cast<QObject*>(engine_->rootObjects().first()->findChild<QQuickItem*>("root"));
        }

        return it->second;
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