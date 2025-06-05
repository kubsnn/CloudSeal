#pragma once

#include <cloudseal/qqt/LambdaSlot.hpp>
#include <QtCore/QVariant>
#include <QtCore/QObject>
#include <memory>
#include <vector>
#include <functional>
#include <cloudseal/logger.hpp>
#include <string_view>
#include <cloudseal/qqt/CallbacksStorage.hpp>

namespace cloudseal::qqt
{

    class Callbacks final
    {
    public:
        constexpr static std::string_view Clicked = "clicked()";
        constexpr static std::string_view Pressed = "pressed()";
        constexpr static std::string_view Released = "released()";
        constexpr static std::string_view TextChanged = "textModified(QVariant)";
        constexpr static std::string_view IconChanged = "iconChanged(QVariant)";
        constexpr static std::string_view ValueChanged = "valueChanged(QVariant)";
        
    public:
        Callbacks() = default;

        template <typename F>
        inline void addCallback(std::string_view signal, F &&f)
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

        inline CallbacksStorage* build(QObject *object)
        {
            auto storage = new CallbacksStorage(object);

            for (auto &&pair : pairs0)
            {
                storage->addCallback0(pair.first.c_str(), std::move(pair.second));
            }

            for (auto &&pair : pairs1)
            {
                storage->addCallback1(pair.first.c_str(), std::move(pair.second));
            }

            // clean up
            clear();

            return storage;
        }

    private:
        inline void addCallback0(std::string_view signalName, std::function<void()> &&callback)
        {
            pairs0.emplace_back(signalName, std::move(callback));
        }

        inline void addCallback1(std::string_view signalName, std::function<void(QVariant)> &&callback)
        {
            pairs1.emplace_back(signalName, std::move(callback));
        }

        inline void clear()
        {
            pairs0.clear();
            pairs1.clear();
            pairs2.clear();
            pairs3.clear();

            pairs0.shrink_to_fit();
            pairs1.shrink_to_fit();
            pairs2.shrink_to_fit();
            pairs3.shrink_to_fit();
        }

        std::vector<std::pair<std::string, std::function<void()>>> pairs0;
        std::vector<std::pair<std::string, std::function<void(QVariant)>>> pairs1;
        std::vector<std::pair<std::string, std::function<void(QVariant, QVariant)>>> pairs2;
        std::vector<std::pair<std::string, std::function<void(QVariant, QVariant, QVariant)>>> pairs3;
    };
}