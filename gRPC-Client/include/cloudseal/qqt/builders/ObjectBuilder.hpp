#pragma once
#include <cloudseal/qqt/Layout.hpp>
#include <cloudseal/qqt/Object.hpp>
#include <cloudseal/qqt/structures/Size.hpp>
#include <cloudseal/qqt/structures/Point.hpp>
#include <cloudseal/qqt/QFunctions.hpp>
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
        virtual ~ObjectBuilder() = default;

        template <typename T>
        std::string generateQMLString(const T &object) const
        {
            QMLJinja jinja;
            return jinja.process(object.type(), object);
        }

        [[nodiscard]] inline std::shared_ptr<TObject> build() const {
            
            object_->qmlString = generateQMLString(*object_);
            object_->setCallbacks(std::move(callbacks_));
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

        // // === SIGNAL HANDLING ===
        
        // /**
        //  * @brief Connect a signal to a callback function
        //  * @param signalName Name of the signal (e.g., "clicked", "valueChanged(int)")
        //  * @param callback Function to call when signal is triggered
        //  */
        // inline ObjecObjectBuilder& onSignal(const std::string& signalName, SignalCallback callback)
        // {
        //     object_->signalCallbacks_[signalName] = callback;
        //     return *this;
        // }

        // /**
        //  * @brief Connect a simple signal with no arguments
        //  * @param signalName Name of the signal
        //  * @param callback Function to call when signal is triggered
        //  */
        // inline ObjecObjectBuilder& onSignal(const std::string& signalName, std::function<void()> callback)
        // {
        //     object_->signalCallbacks_[signalName] = [callback](const QVariantList&) { callback(); };
        //     return *this;
        // }

        // /**
        //  * @brief Connect a signal with one argument
        //  * @param signalName Name of the signal
        //  * @param callback Function to call when signal is triggered
        //  */
        // template<typename T>
        // inline ObjecObjectBuilder& onSignal(const std::string& signalName, std::function<void(T)> callback)
        // {
        //     object_->signalCallbacks_[signalName] = [callback](const QVariantList& args) {
        //         if (!args.isEmpty()) {
        //             callback(args[0].value<T>());
        //         }
        //     };
        //     return *this;
        // }

        // /**
        //  * @brief Connect a signal with two arguments
        //  * @param signalName Name of the signal
        //  * @param callback Function to call when signal is triggered
        //  */
        // template<typename T1, typename T2>
        // inline ObjecObjectBuilder& onSignal(const std::string& signalName, std::function<void(T1, T2)> callback)
        // {
        //     object_->signalCallbacks_[signalName] = [callback](const QVariantList& args) {
        //         if (args.size() >= 2) {
        //             callback(args[0].value<T1>(), args[1].value<T2>());
        //         }
        //     };
        //     return *this;
        // }

        // /**
        //  * @brief Get the stored signal callbacks for connecting to actual QML object
        //  * @return Map of signal names to callbacks
        //  */
        // [[nodiscard]] const std::unordered_map<std::string, SignalCallback>& getSignalCallbacks() const
        // {
        //     return object_->signalCallbacks_;
        // }

        // /**
        //  * @brief Apply all signal connections to a QML object using QFunctions
        //  * @param qmlObject The QML object to connect signals to
        //  * @param qFunctions QFunctions instance for handling connections
        //  */
    protected:
        std::shared_ptr<TObject> object_ = std::make_shared<TObject>();
        std::shared_ptr<Callbacks> callbacks_ = std::make_shared<Callbacks>();
        
    };
} // namespace cloudseal::qqt