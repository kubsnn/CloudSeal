#include <cloudseal/qqt/GUI.hpp>

namespace cloudseal
{
    GUI::GUI(const std::shared_ptr<QQmlApplicationEngine> &engine, int argc, char *argv[])
        : engine_(engine), loader_(engine_)
    {
        engine_->load(QUrl::fromLocalFile("main.qml"));
        if (engine_->rootObjects().isEmpty())
            return;
    }

    bool GUI::makeView(std::shared_ptr<views::IView> &view)
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

    bool GUI::addObject(std::shared_ptr<qqt::Object> object, const std::string &parentId)
    {
        return loader_.createObjects(object, parentId);
    }
}