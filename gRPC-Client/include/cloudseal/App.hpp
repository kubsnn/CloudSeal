#pragma once

#include <memory>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <cloudseal/logger.hpp>
#include <cloudseal/qqt/GUI.hpp>
#include <chrono>

namespace cloudseal
{
    class App {
    public:
        friend class GUI;

        inline App(int argc, char* argv[], std::shared_ptr<views::IView> view) 
			: app_(std::make_unique<QGuiApplication>(argc, argv))
            , mainView_(std::move(view))
        {
            engine_ = std::make_unique<QQmlApplicationEngine>();

            gui_ = std::make_unique<GUI>(engine_);

			displayView();

            int code = exec();
            log.info() << "Application exited with code: " << code;
            if (code != 0) {
                log.error() << "Application encountered an error and exited with code: " << code;
            } else {
                log.info() << "Application exited successfully.";
            }
        }

        inline int exec()
        {
            app_->setQuitOnLastWindowClosed(true);
            return app_->exec();
        }

        inline void displayView()
        {
			if (!mainView_) {
				log.error() << "Main view is not set.";
				return;
			}

            auto start = std::chrono::high_resolution_clock::now();

            gui_->makeView(mainView_);

            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            log.info() << "View created and built in " << duration << " ms";
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
