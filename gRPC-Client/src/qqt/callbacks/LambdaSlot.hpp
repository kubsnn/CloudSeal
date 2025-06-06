#pragma once
#include <QtCore/QObject>
#include <functional>
#include <QtCore/QVariant>
#include <cloudseal/logger.hpp>
#include <stdexcept>

namespace cloudseal::qqt::callbacks
{
    template <typename... Args>
    class LambdaSlotBase {
    public:
        virtual ~LambdaSlotBase() = default;

        inline void call(Args... args)
        {
            if (func) {
                try {
                    func(std::move(args)...);
                }
                catch (const std::exception& e) {
                    log.error() << "Exception in LambdaSlot::call: " << e.what();
                }
            }
            else {
                log.error() << "LambdaSlot::call called but func is not set.";
            }
        }

        std::function<void(Args...)> func;
    };

    // Callback slot void()
    class LambdaSlot0 : public QObject, public LambdaSlotBase<>
    {
        Q_OBJECT;

        using Base = LambdaSlotBase<>;

    public:
        explicit LambdaSlot0(QObject* parent = nullptr) : QObject(parent) {}
        virtual ~LambdaSlot0() = default;

    public slots:
        void call();
    };


    // Callback slot void(QVariant)
    class LambdaSlot1 : public QObject, public LambdaSlotBase<QVariant>
    {
        Q_OBJECT;

        using Base = LambdaSlotBase<QVariant>;
    public:
        explicit LambdaSlot1(QObject* parent = nullptr) : QObject(parent) {}
        virtual ~LambdaSlot1() = default;

    public slots:
        void call(QVariant);
    };


    // Callback slot void(QVariant, QVariant)
    class LambdaSlot2 : public QObject, public LambdaSlotBase<QVariant, QVariant>
    {
        Q_OBJECT;

        using Base = LambdaSlotBase<QVariant, QVariant>;
    public:
        explicit LambdaSlot2(QObject* parent = nullptr) : QObject(parent) {}
        virtual ~LambdaSlot2() = default;

    public slots:
        void call(QVariant, QVariant);
    };


    // Callback slot void(QVariant, QVariant, QVariant)
    class LambdaSlot3 : public QObject, public LambdaSlotBase<QVariant, QVariant, QVariant>
    {
        Q_OBJECT;

        using Base = LambdaSlotBase<QVariant, QVariant, QVariant>;
    public:
        explicit LambdaSlot3(QObject* parent = nullptr) : QObject(parent) {}
        virtual ~LambdaSlot3() = default;

    public slots:
        void call(QVariant, QVariant, QVariant);
    };


    // Callback slot void(QVariant, QVariant, QVariant, QVariant)
    class LambdaSlot4 : public QObject, public LambdaSlotBase<QVariant, QVariant, QVariant, QVariant>
    {
        Q_OBJECT;

        using Base = LambdaSlotBase<QVariant, QVariant, QVariant, QVariant>;
    public:
        explicit LambdaSlot4(QObject* parent = nullptr) : QObject(parent) {}
        virtual ~LambdaSlot4() = default;

    public slots:
        void call(QVariant, QVariant, QVariant, QVariant);
    };
}