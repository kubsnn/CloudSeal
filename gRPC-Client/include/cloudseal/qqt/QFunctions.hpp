#pragma once

#include <cloudseal/qqt/LambdaSlot.hpp>
#include <memory>
#include <vector>
#include <functional>
#include <cloudseal/logger.hpp>
#include <string_view>

namespace cloudseal::qqt
{

    class QFunctions final
    {
    public:
        explicit QFunctions(QObject *object)
            : object(object) {}

        void addCallback0(const char *signalName, std::function<void()>&& callback)
        {
            const QMetaObject *meta = object->metaObject();
            int index = meta->indexOfSignal(signalName);
            if (index != -1)
            {
                QMetaMethod signal = meta->method(index);
                log.debug() << "Signal found:" << signal.methodSignature();

                // Tworzymy obiekt-pośrednik z metodą członkowską jako slot
                auto slotObj = std::make_shared<LambdaSlot0>();
                // slotObj->setObjectName(QString::fromStdString(signalName));

                slotObj->func = std::move(callback);

                auto slotMetaMethod = slotObj->metaObject()->method(slotObj->metaObject()->indexOfSlot("call()"));

                QObject::connect(object, signal, slotObj.get(), slotMetaMethod);
                lambdas.emplace_back(slotObj);
                log.debug() << "Connected signal " << signalName << " to slot " << slotMetaMethod.methodSignature();
                log.debug() << slotObj->metaObject()->className() << " in list:";
            }
            else
            {
                log.error() << "Signal not found: " << signalName;
            }
        }

        void addCallback1(const char *signalName, std::function<void(QVariant)>&& callback)
        {
            const QMetaObject *meta = object->metaObject();
            int index = meta->indexOfSignal(signalName);
            if (index != -1)
            {
                QMetaMethod signal = meta->method(index);
                log.debug() << "Signal found:" << signal.methodSignature();

                // Tworzymy obiekt-pośrednik z metodą członkowską jako slot
                auto slotObj = std::make_shared<LambdaSlot1>();
                slotObj->setObjectName(QString::fromStdString(signalName));

                slotObj->func = std::move(callback);

                auto slotMetaMethod = slotObj->metaObject()->method(slotObj->metaObject()->indexOfSlot("call(QVariant)"));

                QObject::connect(object, signal, slotObj.get(), slotMetaMethod);

                lambdas.emplace_back(slotObj);
                log.debug() << "Connected signal" << signalName << "to slot" << slotMetaMethod.methodSignature();
                for (const auto &lambda : lambdas)
                {
                    log.debug() << "LambdaSlot1 in list:" << lambda->metaObject()->className();
                }
            }
            else
            {
                log.error() << "Signal not found: " << signalName;
            }
        }


        template <typename F>
        void addCallback(const char* signal, F &&f)
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

        std::vector<std::shared_ptr<QObject>> lambdas;
        QObject *object;
    };
}