#pragma once

#include <GUI.hpp>

namespace cloudseal
{
    class App {
    public:
        friend class GUI;
        App(int argc, char* argv[]) : app_(std::make_unique<QGuiApplication>(argc, argv))
        {
            engine_ = std::make_unique<QQmlApplicationEngine>();

            gui_ = std::make_unique<GUI>(engine_, argc, argv);

            log.info() << exec();
        }

        int exec()
        {
            return app_->exec();
        }

        virtual ~App() = default;
 
    protected:
        std::unique_ptr<QGuiApplication> app_;
        std::shared_ptr<QQmlApplicationEngine> engine_;
    private:
        std::unique_ptr<GUI> gui_;
    };
}
