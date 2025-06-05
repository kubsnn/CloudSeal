#pragma once

#include <cloudseal/qqt/Loader.hpp>
#include <memory>   
#include <unordered_map>
#include <QtCore/QObject>

namespace cloudseal
{
    class Application
    {
    public:
        inline static void setLoader(std::shared_ptr<qqt::Loader> newLoader)
        {
            loader = std::move(newLoader);
        }

        inline static const std::unordered_map<std::string, QObject*>& components()
        {
            return loader->getComponents();
        }

        static void exit(int code);

		inline static void reset()
		{
			loader.reset();
		}

    private:
        Application() = default;

        inline static std::shared_ptr<qqt::Loader> loader{};
    };
}