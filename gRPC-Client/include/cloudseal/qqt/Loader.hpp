#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include <QtQml/QQmlApplicationEngine>

#include <QtCore/QObject>

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
        Loader(std::shared_ptr<QQmlApplicationEngine> engine);

        virtual ~Loader() noexcept = default;

        QObject* get(std::shared_ptr<const Object> object) const;

        bool createObjects(std::shared_ptr<Object> object, const std::string& parentId = "");

        QObject* getParent(const std::string& parentId) const;

        // Dodaj getter dla komponentów
        const std::unordered_map<std::string, QObject*>& getComponents() const;

        // Dodaj getter dla engine
        std::shared_ptr<QQmlApplicationEngine> getEngine() const;

    private:
        bool createObject(Object* object, const std::string& parentId = "");

		QObject* createQObject(Object* object);

        void addCallbacks(Object* object, QObject* obj) const;

        void updateQObjectParent(Object* object, QObject* obj, const std::string& parentId) const;

        void updatePaneIfRectangle(Object* object, QObject* obj, const std::string& parentId);



        std::shared_ptr<QQmlApplicationEngine> engine_;

        std::unordered_map<std::string, QObject*> components_;
    };
}