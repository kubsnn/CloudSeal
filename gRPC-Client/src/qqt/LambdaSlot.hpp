#pragma once
#include <QtCore/QObject>
#include <functional>
#include <QtCore/QVariant>
#include <cloudseal/logger.hpp>
#include <stdexcept>

namespace cloudseal
{
    class LambdaSlot0 : public QObject
    {
        Q_OBJECT

    public:
        explicit LambdaSlot0(QObject *parent = nullptr) : QObject(parent) {}
        virtual ~LambdaSlot0() = default;

        std::function<void()> func;

    public slots:
        void call()
        {
            if (func)
            {
                try
                {
                    func();
                }
                catch (const std::exception &e)
                {
                    log.error() << "Exception in LambdaSlot::call: " << e.what();
                }
            }
            else
            {
                log.error() << "LambdaSlot::call called but func is not set.";
            }
        }
    };

    class LambdaSlot1 : public QObject
    {
        Q_OBJECT

    public:
        explicit LambdaSlot1(QObject *parent = nullptr) : QObject(parent) {}
        virtual ~LambdaSlot1() = default;

        std::function<void(QVariant)> func;

    public slots:
        void call(QVariant arg)
        {
            if (func)
            {
                try
                {
                    func(std::move(arg));
                }
                catch (const std::exception &e)
                {
                    log.error() << "Exception in LambdaSlot::call: " << e.what();
                }
            }
            else
            {
                log.error() << "LambdaSlot::call called but func is not set.";
            }
        }
    };

    class LambdaSlot2 : public QObject
    {
        Q_OBJECT

    public:
        explicit LambdaSlot2(QObject *parent = nullptr) : QObject(parent) {}
        virtual ~LambdaSlot2() = default;

        std::function<void(QVariant, QVariant)> func;
    public slots:
        void call(QVariant arg1, QVariant arg2)
        {
            if (func)
            {
                try
                {
                    func(arg1, arg2);
                }
                catch (const std::exception &e)
                {
                    log.error() << "Exception in LambdaSlot::call: " << e.what();
                }
            }
            else
            {
                log.error() << "LambdaSlot::call called but func is not set.";
            }
        }
    };

    class LambdaSlot3 : public QObject
    {
        Q_OBJECT
    public:
        explicit LambdaSlot3(QObject *parent = nullptr) : QObject(parent) {}
        virtual ~LambdaSlot3() = default;

        std::function<void(QVariant, QVariant, QVariant)> func;
    public slots:
        void call(QVariant arg1, QVariant arg2, QVariant arg3)
        {
            if (func)
            {
                try
                {
                    func(arg1, arg2, arg3);
                }
                catch (const std::exception &e)
                {
                    log.error() << "Exception in LambdaSlot::call: " << e.what();
                }
            }
            else
            {
                log.error() << "LambdaSlot::call called but func is not set.";
            }
        }
    };
    class LambdaSlot4 : public QObject
    {
        Q_OBJECT
    public:
        explicit LambdaSlot4(QObject *parent = nullptr) : QObject(parent) {}
        virtual ~LambdaSlot4() = default;

        std::function<void(QVariant, QVariant, QVariant, QVariant)> func;
    public slots:
        void call(QVariant arg1, QVariant arg2, QVariant arg3, QVariant arg4)
        {
            if (func)
            {
                try
                {
                    func(arg1, arg2, arg3, arg4);
                }
                catch (const std::exception &e)
                {
                    log.error() << "Exception in LambdaSlot::call: " << e.what();
                }
            }
            else
            {
                log.error() << "LambdaSlot::call called but func is not set.";
            }
        }
    };

}
