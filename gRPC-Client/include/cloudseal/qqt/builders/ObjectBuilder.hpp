#pragma once
#include <cloudseal/qqt/Layout.hpp>
#include <cloudseal/qqt/Object.hpp>
#include <cloudseal/qqt/structures/Size.hpp>
#include <cloudseal/qqt/structures/Point.hpp>
#include <cloudseal/qqt/CallbacksStorage.hpp>
#include <cloudseal/qqt/jinja/QMLJinja.hpp>
#include <memory>
#include <unordered_map>
#include <functional>
#include <cloudseal/qqt/Callbacks.hpp>

namespace cloudseal::qqt::builders
{
    template <typename TObject>
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

        inline ObjectBuilder& visible(bool visible)
        {
            object_->visible = visible;
            return *this;
        }
        inline ObjectBuilder& size(const Size& size)
        {
            object_->size = size;
            return *this;
        }
        inline ObjectBuilder& size(int width, int height)
        {
            Size size;
            size.width = width;
            size.height = height;
            object_->size = size;
            return *this;
        }
        inline ObjectBuilder& position(const Point& position)
        {
            object_->position = position;
            return *this;
        }
        inline ObjectBuilder& position(int x, int y)
        {
            Point position;
            position.x = x;
            position.y = y;
            object_->position = position;
            return *this;
        }
        inline ObjectBuilder& anchors(const Anchors& anchors)
        {
            if (!object_->layout.has_value()) {
                object_->layout = Layout();
            }
            object_->layout.value().anchors = anchors;
            return *this;
        }
        template <typename... TArgs>
        inline ObjectBuilder& anchors(TArgs&&... args)
        {
            if (!object_->layout.has_value()) {
                object_->layout = Layout();
            }
            object_->layout.value().anchors = Anchors{args...};
            return *this;
        }
        inline ObjectBuilder& padding(const Padding& padding)
        {
            if (!object_->layout.has_value()) {
                object_->layout = Layout();
            }
            object_->layout.value().padding = padding;
            return *this;
        }
        template <typename... TArgs>
        inline ObjectBuilder& padding(TArgs&&... args)
        {
            if (!object_->layout.has_value()) {
                object_->layout = Layout();
            }
            object_->layout.value().padding = Padding{args...};
            return *this;
        }
        inline ObjectBuilder& inset(const Inset& inset)
        {
            if (!object_->layout.has_value()) {
                object_->layout = Layout();
            }
            object_->layout.value().inset = inset;
            return *this;
        }
        template <typename... TArgs>
        inline ObjectBuilder& inset(TArgs&&... args)
        {
            if (!object_->layout.has_value()) {
                object_->layout = Layout();
            }
            object_->layout.value().inset = Inset{args...};
            return *this;
        }
        inline ObjectBuilder& margin(const Margin& margin)
        {
            if (!object_->layout.has_value()) {
                object_->layout = Layout();
            }
            object_->layout.value().margin = margin;
            return *this;
        }        template <typename... TArgs>
        inline ObjectBuilder& margin(TArgs&&... args)
        {
            if (!object_->layout.has_value()) {
                object_->layout = Layout();
            }
            object_->layout.value().margin = Margin{args...};
            return *this;
        }
        inline ObjectBuilder& color(const std::string &color)
        {
            object_->color = color;
            return *this;
        }
        inline ObjectBuilder& colorOnHover(const std::string &color)
        {
            object_->colorOnHover = color;
            return *this;
        }
        inline ObjectBuilder& colorOnPress(const std::string &color)
        {
            object_->colorOnPress = color;
            return *this;
        }

        inline ObjectBuilder& callbacks(std::shared_ptr<Callbacks> callbacks)
        {
            callbacks_ = std::move(callbacks);
            return *this;
        }

        template <typename F>
        inline ObjectBuilder& callback(std::string_view signal, F &&f)
        {
            callbacks_->addCallback(signal, std::forward<F>(f));

            return *this;
        }

    protected:
        std::shared_ptr<TObject> object_ = std::make_shared<TObject>();
        std::shared_ptr<Callbacks> callbacks_ = std::make_shared<Callbacks>();
    };
} // namespace cloudseal::qqt