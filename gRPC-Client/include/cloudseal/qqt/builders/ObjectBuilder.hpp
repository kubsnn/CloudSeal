#pragma once
#include <cloudseal/qqt/Layout.hpp>
#include <cloudseal/qqt/Object.hpp>
#include <cloudseal/qqt/structures/Size.hpp>
#include <cloudseal/qqt/structures/Point.hpp>
#include <cloudseal/qqt/callbacks/CallbacksStorage.hpp>
#include <cloudseal/qqt/callbacks/Callbacks.hpp>
#include <cloudseal/qqt/jinja/QMLJinja.hpp>
#include <memory>
#include <unordered_map>
#include <functional>

namespace cloudseal::qqt::builders
{
	template <typename TObject, typename TBuilder>
    class ObjectBuilder
    {
    public:
		inline ObjectBuilder()
			: object_(std::make_shared<TObject>())
        { 
			object_->callbacks_ = std::make_shared<callbacks::Callbacks>();
        }

        inline ObjectBuilder(std::shared_ptr<TObject> object)
            : object_(std::move(object))
        { }

        virtual ~ObjectBuilder() noexcept = default;

        [[nodiscard]] inline std::shared_ptr<TObject> build() const {

            object_->qmlString = jinja::process(object_->type(), object_);

            log.debug() << "ObjectBuilder::build() - QML String: " << object_->qmlString;

            return object_;
        }

        [[nodiscard]] inline std::shared_ptr<TObject> rebuild() const {
			if (!object_) {
				log.error() << "ObjectBuilder::rebuild() - object_ is null";
				throw std::runtime_error("ObjectBuilder::rebuild() - object_ is null");
			}

			object_->qmlString = jinja::process(object_->type(), object_);

			log.debug() << "ObjectBuilder::rebuild() - QML String: " << object_->qmlString;

			return object_;
		}

        [[nodiscard]] inline TObject& get() noexcept
        {
            return *object_;
        }

        [[nodiscard]] inline TBuilder& visible(bool visible) noexcept
        {
            object_->visible = visible;

            return self();
        }

        [[nodiscard]] inline TBuilder& size(const Size& size) noexcept
        {
            object_->size = size;

            return self();
        }

        [[nodiscard]] inline TBuilder& size(int width, int height) noexcept
        {
			object_->size = Size{ .width = width, .height = height };

            return self();
        }

        [[nodiscard]] inline TBuilder& position(const Point& position) noexcept
        {
            object_->position = position;

            return self();
        }

        [[nodiscard]] inline TBuilder& position(int x, int y) noexcept
        {
			object_->position = Point{ .x = x, .y = y };

            return self();
        }

        [[nodiscard]] inline TBuilder& anchors(Anchors anchors) noexcept
        {
            if (!object_->layout.has_value()) {
                object_->layout.emplace();
            }

            object_->layout.value().anchors = std::move(anchors);

            return self();
        }

		template <std::convertible_to<std::string>... TArgs>
        [[nodiscard]] inline TBuilder& anchors(TArgs&&... args)
        {
            if (!object_->layout.has_value()) {
                object_->layout.emplace();
            }

            object_->layout.value().anchors = Anchors{ std::forward<TArgs>(args)... };

            return self();
        }

        [[nodiscard]] inline TBuilder& padding(const Padding& padding) noexcept
        {
            if (!object_->layout.has_value()) {
                object_->layout.emplace();
            }

            object_->layout.value().padding = padding;

            return self();
        }

		template <std::convertible_to<int>... TArgs>
        [[nodiscard]] inline TBuilder& padding(TArgs&&... args) noexcept
        {
            if (!object_->layout.has_value()) {
				object_->layout.emplace();
            }
            object_->layout.value().padding = Padding{ args... };
            return self();
        }

        [[nodiscard]] inline TBuilder& inset(const Inset& inset)
        {
            if (!object_->layout.has_value()) {
                object_->layout.emplace();
            }
            object_->layout.value().inset = inset;
            return self();
        }

        template <typename... TArgs>
        [[nodiscard]] inline TBuilder& inset(TArgs&&... args)
        {
            if (!object_->layout.has_value()) {
                object_->layout.emplace();
            }
            object_->layout.value().inset = Inset{ args... };
            return self();
        }

        [[nodiscard]] inline TBuilder& margin(const Margin& margin) noexcept
        {
            if (!object_->layout.has_value()) {
                object_->layout.emplace();
            }
            object_->layout.value().margin = margin;
            return self();
        }

		template <std::convertible_to<int>... TArgs>
        [[nodiscard]] inline TBuilder& margin(TArgs&&... args) noexcept
        {
            if (!object_->layout.has_value()) {
                object_->layout.emplace();
            }
            object_->layout.value().margin = Margin{ args... };
            return self();
        }

        [[nodiscard]] inline TBuilder& color(const std::string& color)
        {
            object_->color = color;
            return self();
        }

        [[nodiscard]] inline TBuilder& colorOnHover(const std::string& color)
        {
            object_->colorOnHover = color;
            return self();
        }

        [[nodiscard]] inline TBuilder& colorOnPress(const std::string& color)
        {
            object_->colorOnPress = color;
            return self();
        }

		// This method overrides the default callbacks storage with a custom one. Even if the object already has a callbacks storage, it will be replaced.
        [[nodiscard]] inline TBuilder& callbacks(std::shared_ptr<callbacks::Callbacks> callbacks)
        {
            object_->callbacks_ = std::move(callbacks);
            return self();
        }

		/*
            This method adds a callback to the existing callbacks storage.If the object does not have a callbacks storage, it will create one.
        
            Ones you 
        */ 
        template <typename F>
        [[nodiscard]] inline TBuilder& callback(std::string_view signal, F&& f)
        {
            object_->callbacks_->addCallback(signal, std::forward<F>(f));

            return self();
        }

    protected:
        std::shared_ptr<TObject> object_;
        std::shared_ptr<callbacks::Callbacks> callbacks_;

    private:
        [[nodiscard]] constexpr TBuilder& self() noexcept
        {
            return static_cast<TBuilder&>(*this);
        }
    };
} // namespace cloudseal::qqt