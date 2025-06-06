#pragma once
#include <cloudseal/views/IView.hpp>
#include <cloudseal/qqt/callbacks/Callbacks.hpp>
#include <cloudseal/qqt.hpp>

#include <cloudseal/views/TopBar.hpp>
#include <cloudseal/qqt/builders/InputBuilder.hpp>
#include <cloudseal/logger.hpp>

using namespace cloudseal::qqt;

namespace cloudseal::views
{
    class MainView : public IView
    {
    public:
        MainView()
        {
            auto topBar = std::make_shared<TopBar>();
			useView(topBar);

            auto pane = builders::PaneBuilder()
                .anchors({.left = "parent.left", .right = "parent.right", .bottom = "parent.bottom"})
                .size({.height = 32})
                .background(
                    builders::RectangleBuilder()
                        .color("#ecf0f1") // Light gray color
                        .build())
                .build();

            auto input = builders::InputBuilder()
                .size({.width = 200, .height = 32})
                .placeholder("Enter text here")
                .anchors({.centerIn = "parent"})
                .callback(callbacks::Callbacks::TextChanged, [id = pane->uuid()](QVariant value)
                {
                    auto background = Application::components().find(id)->second->property("background").value<QObject*>();
                    if (background)
                    {
                        background->setProperty("color", value.toString());
                    }
                })
                .build();
            objects_.push_back(input);
            objects_.push_back(pane);
        }

		inline void useView(std::shared_ptr<IView> view)
		{
			if (!view)
			{
				log.error() << "View is null. (" << view->name() << ")";
				return;
			}

			if (view->objects().empty())
			{
				log.warning() << "View has no objects to add. (" << view->name() << ")";
				return;
			}

			for (const auto& object : view->objects())
			{
				objects_.push_back(object);
			}
		}

		constexpr std::string_view name() const noexcept override
		{
			return "MainView";
		}

        inline const std::vector<std::shared_ptr<Object>>& objects() const noexcept override
        {
            return objects_;
        }
    private:
        std::vector<std::shared_ptr<Object>> objects_;
    };
} // namespace cloudseal::qqt::views