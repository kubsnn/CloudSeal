/****************************************************************************
** Meta object code from reading C++ file 'LambdaSlot.hpp'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../LambdaSlot.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LambdaSlot.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN9cloudseal11LambdaSlot0E_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::LambdaSlot0::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal11LambdaSlot0E_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::LambdaSlot0",
        "call",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'call'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<LambdaSlot0, qt_meta_tag_ZN9cloudseal11LambdaSlot0E_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::LambdaSlot0::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot0E_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot0E_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal11LambdaSlot0E_t>.metaTypes,
    nullptr
} };

void cloudseal::LambdaSlot0::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LambdaSlot0 *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->call(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *cloudseal::LambdaSlot0::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cloudseal::LambdaSlot0::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot0E_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cloudseal::LambdaSlot0::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN9cloudseal11LambdaSlot1E_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::LambdaSlot1::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal11LambdaSlot1E_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::LambdaSlot1",
        "call",
        "",
        "QVariant",
        "arg"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'call'
        QtMocHelpers::SlotData<void(QVariant)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<LambdaSlot1, qt_meta_tag_ZN9cloudseal11LambdaSlot1E_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::LambdaSlot1::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot1E_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot1E_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal11LambdaSlot1E_t>.metaTypes,
    nullptr
} };

void cloudseal::LambdaSlot1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LambdaSlot1 *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->call((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *cloudseal::LambdaSlot1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cloudseal::LambdaSlot1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot1E_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cloudseal::LambdaSlot1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN9cloudseal11LambdaSlot2E_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::LambdaSlot2::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal11LambdaSlot2E_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::LambdaSlot2",
        "call",
        "",
        "QVariant",
        "arg1",
        "arg2"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'call'
        QtMocHelpers::SlotData<void(QVariant, QVariant)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<LambdaSlot2, qt_meta_tag_ZN9cloudseal11LambdaSlot2E_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::LambdaSlot2::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot2E_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot2E_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal11LambdaSlot2E_t>.metaTypes,
    nullptr
} };

void cloudseal::LambdaSlot2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LambdaSlot2 *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->call((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *cloudseal::LambdaSlot2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cloudseal::LambdaSlot2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot2E_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cloudseal::LambdaSlot2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN9cloudseal11LambdaSlot3E_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::LambdaSlot3::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal11LambdaSlot3E_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::LambdaSlot3",
        "call",
        "",
        "QVariant",
        "arg1",
        "arg2",
        "arg3"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'call'
        QtMocHelpers::SlotData<void(QVariant, QVariant, QVariant)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 }, { 0x80000000 | 3, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<LambdaSlot3, qt_meta_tag_ZN9cloudseal11LambdaSlot3E_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::LambdaSlot3::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot3E_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot3E_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal11LambdaSlot3E_t>.metaTypes,
    nullptr
} };

void cloudseal::LambdaSlot3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LambdaSlot3 *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->call((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject *cloudseal::LambdaSlot3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cloudseal::LambdaSlot3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot3E_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cloudseal::LambdaSlot3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN9cloudseal11LambdaSlot4E_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::LambdaSlot4::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal11LambdaSlot4E_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::LambdaSlot4",
        "call",
        "",
        "QVariant",
        "arg1",
        "arg2",
        "arg3",
        "arg4"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'call'
        QtMocHelpers::SlotData<void(QVariant, QVariant, QVariant, QVariant)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 }, { 0x80000000 | 3, 6 }, { 0x80000000 | 3, 7 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<LambdaSlot4, qt_meta_tag_ZN9cloudseal11LambdaSlot4E_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::LambdaSlot4::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot4E_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot4E_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal11LambdaSlot4E_t>.metaTypes,
    nullptr
} };

void cloudseal::LambdaSlot4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<LambdaSlot4 *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->call((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject *cloudseal::LambdaSlot4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cloudseal::LambdaSlot4::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal11LambdaSlot4E_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int cloudseal::LambdaSlot4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
