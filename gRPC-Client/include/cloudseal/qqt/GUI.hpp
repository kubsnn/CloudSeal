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
        GUI(const std::shared_ptr<QQmlApplicationEngine> &engine, int argc, char *argv[]);

        bool makeView(std::shared_ptr<::cloudseal::views::IView> &view);

        bool addObject(std::shared_ptr<::cloudseal::qqt::Object> object, const std::string &parentId = "");

    private:
        std::shared_ptr<QQmlApplicationEngine> engine_;
        ::cloudseal::qqt::Loader loader_;
    };
} // namespace cloudseal