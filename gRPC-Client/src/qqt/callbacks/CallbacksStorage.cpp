#include <cloudseal/qqt/callbacks/CallbacksStorage.hpp>
#include <QMetaObject>
#include <QMetaMethod>
#include <cloudseal/logger.hpp>
#include <cloudseal/qqt/callbacks/LambdaSlot.hpp>
#include <string_view>

namespace cloudseal::qqt::callbacks
{
    void CallbacksStorage::addCallback0(const char* signalName, std::function<void()>&& callback)
    {
        const QMetaObject* meta = object->metaObject();

        int index = meta->indexOfSignal(signalName);
        if (index == -1) [[unlikely]]
        {
            log.error() << "Signal not found: " << signalName;
			return;
        }

        QMetaMethod signal = meta->method(index);

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

    void CallbacksStorage::addCallback1(const char* signalName, std::function<void(QVariant)>&& callback)
    {
        const QMetaObject* meta = object->metaObject();
        int index = meta->indexOfSignal(signalName);
        if (index == -1) [[unlikely]]
        {
            log.error() << "Signal not found: " << signalName;
            return;
        }

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
        for (const auto& lambda : lambdas)
        {
            log.debug() << "LambdaSlot1 in list:" << lambda->metaObject()->className();
        }
    }

} // namespace cloudseal::qqt