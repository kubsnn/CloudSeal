#pragma once
#include <cloudseal/qqt/Object.hpp>
#include <cloudseal/logger.hpp>
#include <cloudseal/qqt/Loader.hpp>
#include <cloudseal/views/IView.hpp>
#include <QtQml/QQmlApplicationEngine>
#include <memory>

namespace cloudseal
{
    class GUI
    {
    public:
        GUI(std::shared_ptr<QQmlApplicationEngine> engine);

        bool makeView(std::shared_ptr<views::IView> view);

        bool addObject(std::shared_ptr<qqt::Object> object, const std::string &parentId = "");

    private:
        std::shared_ptr<QQmlApplicationEngine> engine_;

        std::shared_ptr<qqt::Loader> loader_;
    };
} // namespace cloudseal