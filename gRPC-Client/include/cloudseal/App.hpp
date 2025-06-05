#pragma once

#include <memory>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <cloudseal/logger.hpp>
#include <cloudseal/qqt/GUI.hpp>
#include <cloudseal/views/MainView.hpp>

namespace cloudseal
{
    class App {
    public:
        friend class GUI;
        App(int argc, char* argv[]) : app_(std::make_unique<QGuiApplication>(argc, argv))
        {
            engine_ = std::make_unique<QQmlApplicationEngine>();

            gui_ = std::make_unique<GUI>(engine_, argc, argv);

            mainView_ = std::make_shared<views::MainView>();

            gui_->makeView(mainView_);

            log.info() << exec();
        }

        int exec()
        {
            app_->setQuitOnLastWindowClosed(true);
            return app_->exec();
        }

        virtual ~App() noexcept = default;
 
    protected:
        std::unique_ptr<QGuiApplication> app_;
        std::shared_ptr<QQmlApplicationEngine> engine_;

    private:
        std::unique_ptr<GUI> gui_;
        std::shared_ptr<views::IView> mainView_;
    };
}
