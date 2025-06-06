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
        virtual ~ObjectBuilder() noexcept = default;

        [[nodiscard]] inline std::shared_ptr<TObject> build() const {

            object_->qmlString = jinja::QMLJinja().process(object_->type(), object_);
            object_->setCallbacks(std::move(callbacks_));
            log.debug() << "ObjectBuilder::build() - QML String: " << object_->qmlString;

            return object_;
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
            Point position;
            position.x = x;
            position.y = y;
            object_->position = position;

            return self();
        }

        [[nodiscard]] inline TBuilder& anchors(const Anchors& anchors)
        {
            if (!object_->layout.has_value()) {
                object_->layout.emplace();
            }

            object_->layout.value().anchors = anchors;

            return self();
        }

		template <std::convertible_to<int>... TArgs>
        [[nodiscard]] inline TBuilder& anchors(TArgs&&... args)
        {
            if (!object_->layout.has_value()) {
                object_->layout.emplace();
            }

            object_->layout.value().anchors = Anchors{ args... };

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

        [[nodiscard]] inline TBuilder& callbacks(std::shared_ptr<callbacks::Callbacks> callbacks)
        {
            callbacks_ = std::move(callbacks);
            return self();
        }

        template <typename F>
        [[nodiscard]] inline TBuilder& callback(std::string_view signal, F&& f)
        {
            callbacks_->addCallback(signal, std::forward<F>(f));

            return self();
        }

    protected:
        std::shared_ptr<TObject> object_ = std::make_shared<TObject>();
        std::shared_ptr<callbacks::Callbacks> callbacks_ = std::make_shared<callbacks::Callbacks>();

    private:
        [[nodiscard]] constexpr TBuilder& self() noexcept
        {
            return static_cast<TBuilder&>(*this);
        }
    };
} // namespace cloudseal::qqt