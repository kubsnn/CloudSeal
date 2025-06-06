#pragma once
#include <memory>
#include <vector>
#include <functional>
#include <QObject>
#include <QVariant>

namespace cloudseal::qqt::callbacks
{

    class CallbacksStorage final
    {
    public:
        inline explicit CallbacksStorage(QObject *object)
            : object(object) {}

        void addCallback0(const char *signalName, std::function<void()> &&callback);

        void addCallback1(const char *signalName, std::function<void(QVariant)> &&callback);

        template <typename F>
        inline void addCallback(const char *signal, F &&f)
        {
            using Fn = std::decay_t<F>;

            if constexpr (std::is_invocable_v<Fn>)
            {
                addCallback0(signal, std::function<void()>(std::forward<F>(f)));
            }
            else if constexpr (std::is_invocable_v<Fn, QVariant>)
            {
                addCallback1(signal, std::function<void(QVariant)>(std::forward<F>(f)));
            }
        }

    private:
        std::vector<std::shared_ptr<QObject>> lambdas;
        QObject *object;
    };
}