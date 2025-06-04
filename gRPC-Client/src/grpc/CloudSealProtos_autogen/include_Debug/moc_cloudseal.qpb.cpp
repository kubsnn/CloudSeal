/****************************************************************************
** Meta object code from reading C++ file 'cloudseal.qpb.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cloudseal/grpc/cloudseal.qpb.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cloudseal.qpb.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9cloudseal4grpc9CloudFileE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::CloudFile::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc9CloudFileE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::CloudFile",
        "id_proto",
        "name",
        "mimeType",
        "size",
        "QtProtobuf::int64",
        "createdTime",
        "source"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'id_proto'
        QtMocHelpers::PropertyData<QString>(1, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(2, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'mimeType'
        QtMocHelpers::PropertyData<QString>(3, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'size'
        QtMocHelpers::PropertyData<QtProtobuf::int64>(4, 0x80000000 | 5, QMC::Readable | QMC::Writable | QMC::Designable | QMC::Stored | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'createdTime'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'source'
        QtMocHelpers::PropertyData<QString>(7, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<CloudFile, qt_meta_tag_ZN9cloudseal4grpc9CloudFileE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN9cloudseal4grpc9CloudFileE[] = {
    QMetaObject::SuperData::link<QtProtobuf::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject cloudseal::grpc::CloudFile::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QProtobufMessage>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc9CloudFileE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc9CloudFileE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN9cloudseal4grpc9CloudFileE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal4grpc9CloudFileE_t>.metaTypes,
    nullptr
} };

void cloudseal::grpc::CloudFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<CloudFile *>(_o);
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QtProtobuf::int64 >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->id_proto(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->mimeType(); break;
        case 3: *reinterpret_cast<QtProtobuf::int64*>(_v) = _t->size(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->createdTime(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->source(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setId_proto(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setName(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setMimeType(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setSize(*reinterpret_cast<QtProtobuf::int64*>(_v)); break;
        case 4: _t->setCreatedTime(*reinterpret_cast<QString*>(_v)); break;
        case 5: _t->setSource(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN9cloudseal4grpc8FileListE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::FileList::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc8FileListE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::FileList",
        "filesData",
        "QList<cloudseal::grpc::CloudFile>"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'filesData'
        QtMocHelpers::PropertyData<QList<cloudseal::grpc::CloudFile>>(1, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<FileList, qt_meta_tag_ZN9cloudseal4grpc8FileListE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::grpc::FileList::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QProtobufMessage>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc8FileListE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc8FileListE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal4grpc8FileListE_t>.metaTypes,
    nullptr
} };

void cloudseal::grpc::FileList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<FileList *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QList<cloudseal::grpc::CloudFile>*>(_v) = _t->files(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFiles(*reinterpret_cast<QList<cloudseal::grpc::CloudFile>*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN9cloudseal4grpc11AuthRequestE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::AuthRequest::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc11AuthRequestE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::AuthRequest",
        "username",
        "password"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'username'
        QtMocHelpers::PropertyData<QString>(1, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'password'
        QtMocHelpers::PropertyData<QString>(2, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AuthRequest, qt_meta_tag_ZN9cloudseal4grpc11AuthRequestE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::grpc::AuthRequest::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QProtobufMessage>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc11AuthRequestE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc11AuthRequestE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal4grpc11AuthRequestE_t>.metaTypes,
    nullptr
} };

void cloudseal::grpc::AuthRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<AuthRequest *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->username(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->password(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setUsername(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setPassword(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN9cloudseal4grpc12AuthResponseE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::AuthResponse::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc12AuthResponseE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::AuthResponse",
        "success",
        "message",
        "token"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'success'
        QtMocHelpers::PropertyData<bool>(1, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'message'
        QtMocHelpers::PropertyData<QString>(2, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'token'
        QtMocHelpers::PropertyData<QString>(3, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AuthResponse, qt_meta_tag_ZN9cloudseal4grpc12AuthResponseE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::grpc::AuthResponse::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QProtobufMessage>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc12AuthResponseE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc12AuthResponseE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal4grpc12AuthResponseE_t>.metaTypes,
    nullptr
} };

void cloudseal::grpc::AuthResponse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<AuthResponse *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->success(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->message(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->token(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSuccess(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setMessage(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setToken(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN9cloudseal4grpc9AuthTokenE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::AuthToken::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc9AuthTokenE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::AuthToken",
        "token"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'token'
        QtMocHelpers::PropertyData<QString>(1, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AuthToken, qt_meta_tag_ZN9cloudseal4grpc9AuthTokenE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::grpc::AuthToken::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QProtobufMessage>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc9AuthTokenE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc9AuthTokenE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal4grpc9AuthTokenE_t>.metaTypes,
    nullptr
} };

void cloudseal::grpc::AuthToken::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<AuthToken *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->token(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setToken(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN9cloudseal4grpc12VaultRequestE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::VaultRequest::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc12VaultRequestE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::VaultRequest",
        "token",
        "localPath"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'token'
        QtMocHelpers::PropertyData<QString>(1, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'localPath'
        QtMocHelpers::PropertyData<QString>(2, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VaultRequest, qt_meta_tag_ZN9cloudseal4grpc12VaultRequestE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::grpc::VaultRequest::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QProtobufMessage>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc12VaultRequestE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc12VaultRequestE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal4grpc12VaultRequestE_t>.metaTypes,
    nullptr
} };

void cloudseal::grpc::VaultRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<VaultRequest *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->token(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->localPath(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setToken(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setLocalPath(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN9cloudseal4grpc10VaultQueryE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::VaultQuery::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc10VaultQueryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::VaultQuery",
        "token"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'token'
        QtMocHelpers::PropertyData<QString>(1, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VaultQuery, qt_meta_tag_ZN9cloudseal4grpc10VaultQueryE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::grpc::VaultQuery::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QProtobufMessage>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc10VaultQueryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc10VaultQueryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal4grpc10VaultQueryE_t>.metaTypes,
    nullptr
} };

void cloudseal::grpc::VaultQuery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<VaultQuery *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->token(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setToken(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN9cloudseal4grpc13VaultResponseE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::VaultResponse::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc13VaultResponseE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::VaultResponse",
        "localPath"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'localPath'
        QtMocHelpers::PropertyData<QString>(1, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VaultResponse, qt_meta_tag_ZN9cloudseal4grpc13VaultResponseE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::grpc::VaultResponse::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QProtobufMessage>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc13VaultResponseE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc13VaultResponseE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal4grpc13VaultResponseE_t>.metaTypes,
    nullptr
} };

void cloudseal::grpc::VaultResponse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<VaultResponse *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->localPath(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLocalPath(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN9cloudseal4grpc16FileTransferPathE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::FileTransferPath::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc16FileTransferPathE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::FileTransferPath",
        "token",
        "remoteName",
        "localPath"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'token'
        QtMocHelpers::PropertyData<QString>(1, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'remoteName'
        QtMocHelpers::PropertyData<QString>(2, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'localPath'
        QtMocHelpers::PropertyData<QString>(3, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<FileTransferPath, qt_meta_tag_ZN9cloudseal4grpc16FileTransferPathE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::grpc::FileTransferPath::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QProtobufMessage>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc16FileTransferPathE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc16FileTransferPathE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal4grpc16FileTransferPathE_t>.metaTypes,
    nullptr
} };

void cloudseal::grpc::FileTransferPath::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<FileTransferPath *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->token(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->remoteName(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->localPath(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setToken(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setRemoteName(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setLocalPath(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN9cloudseal4grpc11GlobalStatsE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::GlobalStats::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc11GlobalStatsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::GlobalStats",
        "total",
        "QtProtobuf::int64",
        "free"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'total'
        QtMocHelpers::PropertyData<QtProtobuf::int64>(1, 0x80000000 | 2, QMC::Readable | QMC::Writable | QMC::Designable | QMC::Stored | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'free'
        QtMocHelpers::PropertyData<QtProtobuf::int64>(3, 0x80000000 | 2, QMC::Readable | QMC::Writable | QMC::Designable | QMC::Stored | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<GlobalStats, qt_meta_tag_ZN9cloudseal4grpc11GlobalStatsE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN9cloudseal4grpc11GlobalStatsE[] = {
    QMetaObject::SuperData::link<QtProtobuf::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject cloudseal::grpc::GlobalStats::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QProtobufMessage>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc11GlobalStatsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc11GlobalStatsE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN9cloudseal4grpc11GlobalStatsE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal4grpc11GlobalStatsE_t>.metaTypes,
    nullptr
} };

void cloudseal::grpc::GlobalStats::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<GlobalStats *>(_o);
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QtProtobuf::int64 >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QtProtobuf::int64*>(_v) = _t->total(); break;
        case 1: *reinterpret_cast<QtProtobuf::int64*>(_v) = _t->free(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTotal(*reinterpret_cast<QtProtobuf::int64*>(_v)); break;
        case 1: _t->setFree(*reinterpret_cast<QtProtobuf::int64*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN9cloudseal4grpc6StatusE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::Status::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc6StatusE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::Status",
        "success",
        "message"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'success'
        QtMocHelpers::PropertyData<bool>(1, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'message'
        QtMocHelpers::PropertyData<QString>(2, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Status, qt_meta_tag_ZN9cloudseal4grpc6StatusE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject cloudseal::grpc::Status::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QProtobufMessage>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc6StatusE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9cloudseal4grpc6StatusE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9cloudseal4grpc6StatusE_t>.metaTypes,
    nullptr
} };

void cloudseal::grpc::Status::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<Status *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->success(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->message(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSuccess(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setMessage(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::CloudFile_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::CloudFile_QtProtobufNested",
        "QtProtobufFieldEnum",
        "Id_protoProtoFieldNumber",
        "NameProtoFieldNumber",
        "MimeTypeProtoFieldNumber",
        "SizeProtoFieldNumber",
        "CreatedTimeProtoFieldNumber",
        "SourceProtoFieldNumber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QtProtobufFieldEnum'
        QtMocHelpers::EnumData<QtProtobufFieldEnum>(1, 1, QMC::EnumIsScoped).add({
            {    2, QtProtobufFieldEnum::Id_protoProtoFieldNumber },
            {    3, QtProtobufFieldEnum::NameProtoFieldNumber },
            {    4, QtProtobufFieldEnum::MimeTypeProtoFieldNumber },
            {    5, QtProtobufFieldEnum::SizeProtoFieldNumber },
            {    6, QtProtobufFieldEnum::CreatedTimeProtoFieldNumber },
            {    7, QtProtobufFieldEnum::SourceProtoFieldNumber },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE =
    cloudseal::grpc::CloudFile_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE.relocatingData;

Q_CONSTINIT const QMetaObject cloudseal::grpc::CloudFile_QtProtobufNested::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc26CloudFile_QtProtobufNestedE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN9cloudseal4grpc25FileList_QtProtobufNestedE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::FileList_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc25FileList_QtProtobufNestedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::FileList_QtProtobufNested",
        "QtProtobufFieldEnum",
        "FilesProtoFieldNumber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QtProtobufFieldEnum'
        QtMocHelpers::EnumData<QtProtobufFieldEnum>(1, 1, QMC::EnumIsScoped).add({
            {    2, QtProtobufFieldEnum::FilesProtoFieldNumber },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9cloudseal4grpc25FileList_QtProtobufNestedE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9cloudseal4grpc25FileList_QtProtobufNestedE =
    cloudseal::grpc::FileList_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc25FileList_QtProtobufNestedE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc25FileList_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc25FileList_QtProtobufNestedE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc25FileList_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc25FileList_QtProtobufNestedE.relocatingData;

Q_CONSTINIT const QMetaObject cloudseal::grpc::FileList_QtProtobufNested::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc25FileList_QtProtobufNestedE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc25FileList_QtProtobufNestedE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc25FileList_QtProtobufNestedE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::AuthRequest_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::AuthRequest_QtProtobufNested",
        "QtProtobufFieldEnum",
        "UsernameProtoFieldNumber",
        "PasswordProtoFieldNumber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QtProtobufFieldEnum'
        QtMocHelpers::EnumData<QtProtobufFieldEnum>(1, 1, QMC::EnumIsScoped).add({
            {    2, QtProtobufFieldEnum::UsernameProtoFieldNumber },
            {    3, QtProtobufFieldEnum::PasswordProtoFieldNumber },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE =
    cloudseal::grpc::AuthRequest_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE.relocatingData;

Q_CONSTINIT const QMetaObject cloudseal::grpc::AuthRequest_QtProtobufNested::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc28AuthRequest_QtProtobufNestedE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::AuthResponse_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::AuthResponse_QtProtobufNested",
        "QtProtobufFieldEnum",
        "SuccessProtoFieldNumber",
        "MessageProtoFieldNumber",
        "TokenProtoFieldNumber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QtProtobufFieldEnum'
        QtMocHelpers::EnumData<QtProtobufFieldEnum>(1, 1, QMC::EnumIsScoped).add({
            {    2, QtProtobufFieldEnum::SuccessProtoFieldNumber },
            {    3, QtProtobufFieldEnum::MessageProtoFieldNumber },
            {    4, QtProtobufFieldEnum::TokenProtoFieldNumber },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE =
    cloudseal::grpc::AuthResponse_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE.relocatingData;

Q_CONSTINIT const QMetaObject cloudseal::grpc::AuthResponse_QtProtobufNested::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc29AuthResponse_QtProtobufNestedE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::AuthToken_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::AuthToken_QtProtobufNested",
        "QtProtobufFieldEnum",
        "TokenProtoFieldNumber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QtProtobufFieldEnum'
        QtMocHelpers::EnumData<QtProtobufFieldEnum>(1, 1, QMC::EnumIsScoped).add({
            {    2, QtProtobufFieldEnum::TokenProtoFieldNumber },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE =
    cloudseal::grpc::AuthToken_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE.relocatingData;

Q_CONSTINIT const QMetaObject cloudseal::grpc::AuthToken_QtProtobufNested::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc26AuthToken_QtProtobufNestedE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::VaultRequest_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::VaultRequest_QtProtobufNested",
        "QtProtobufFieldEnum",
        "TokenProtoFieldNumber",
        "LocalPathProtoFieldNumber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QtProtobufFieldEnum'
        QtMocHelpers::EnumData<QtProtobufFieldEnum>(1, 1, QMC::EnumIsScoped).add({
            {    2, QtProtobufFieldEnum::TokenProtoFieldNumber },
            {    3, QtProtobufFieldEnum::LocalPathProtoFieldNumber },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE =
    cloudseal::grpc::VaultRequest_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE.relocatingData;

Q_CONSTINIT const QMetaObject cloudseal::grpc::VaultRequest_QtProtobufNested::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc29VaultRequest_QtProtobufNestedE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::VaultQuery_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::VaultQuery_QtProtobufNested",
        "QtProtobufFieldEnum",
        "TokenProtoFieldNumber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QtProtobufFieldEnum'
        QtMocHelpers::EnumData<QtProtobufFieldEnum>(1, 1, QMC::EnumIsScoped).add({
            {    2, QtProtobufFieldEnum::TokenProtoFieldNumber },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE =
    cloudseal::grpc::VaultQuery_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE.relocatingData;

Q_CONSTINIT const QMetaObject cloudseal::grpc::VaultQuery_QtProtobufNested::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc27VaultQuery_QtProtobufNestedE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::VaultResponse_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::VaultResponse_QtProtobufNested",
        "QtProtobufFieldEnum",
        "LocalPathProtoFieldNumber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QtProtobufFieldEnum'
        QtMocHelpers::EnumData<QtProtobufFieldEnum>(1, 1, QMC::EnumIsScoped).add({
            {    2, QtProtobufFieldEnum::LocalPathProtoFieldNumber },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE =
    cloudseal::grpc::VaultResponse_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE.relocatingData;

Q_CONSTINIT const QMetaObject cloudseal::grpc::VaultResponse_QtProtobufNested::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc30VaultResponse_QtProtobufNestedE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::FileTransferPath_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::FileTransferPath_QtProtobufNested",
        "QtProtobufFieldEnum",
        "TokenProtoFieldNumber",
        "RemoteNameProtoFieldNumber",
        "LocalPathProtoFieldNumber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QtProtobufFieldEnum'
        QtMocHelpers::EnumData<QtProtobufFieldEnum>(1, 1, QMC::EnumIsScoped).add({
            {    2, QtProtobufFieldEnum::TokenProtoFieldNumber },
            {    3, QtProtobufFieldEnum::RemoteNameProtoFieldNumber },
            {    4, QtProtobufFieldEnum::LocalPathProtoFieldNumber },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE =
    cloudseal::grpc::FileTransferPath_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE.relocatingData;

Q_CONSTINIT const QMetaObject cloudseal::grpc::FileTransferPath_QtProtobufNested::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc33FileTransferPath_QtProtobufNestedE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::GlobalStats_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::GlobalStats_QtProtobufNested",
        "QtProtobufFieldEnum",
        "TotalProtoFieldNumber",
        "FreeProtoFieldNumber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QtProtobufFieldEnum'
        QtMocHelpers::EnumData<QtProtobufFieldEnum>(1, 1, QMC::EnumIsScoped).add({
            {    2, QtProtobufFieldEnum::TotalProtoFieldNumber },
            {    3, QtProtobufFieldEnum::FreeProtoFieldNumber },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE =
    cloudseal::grpc::GlobalStats_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE.relocatingData;

Q_CONSTINIT const QMetaObject cloudseal::grpc::GlobalStats_QtProtobufNested::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc28GlobalStats_QtProtobufNestedE.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN9cloudseal4grpc23Status_QtProtobufNestedE_t {};
} // unnamed namespace

template <> constexpr inline auto cloudseal::grpc::Status_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc23Status_QtProtobufNestedE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "cloudseal::grpc::Status_QtProtobufNested",
        "QtProtobufFieldEnum",
        "SuccessProtoFieldNumber",
        "MessageProtoFieldNumber"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QtProtobufFieldEnum'
        QtMocHelpers::EnumData<QtProtobufFieldEnum>(1, 1, QMC::EnumIsScoped).add({
            {    2, QtProtobufFieldEnum::SuccessProtoFieldNumber },
            {    3, QtProtobufFieldEnum::MessageProtoFieldNumber },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN9cloudseal4grpc23Status_QtProtobufNestedE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN9cloudseal4grpc23Status_QtProtobufNestedE =
    cloudseal::grpc::Status_QtProtobufNested::qt_create_metaobjectdata<qt_meta_tag_ZN9cloudseal4grpc23Status_QtProtobufNestedE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc23Status_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc23Status_QtProtobufNestedE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc23Status_QtProtobufNestedE =
    qt_staticMetaObjectContent_ZN9cloudseal4grpc23Status_QtProtobufNestedE.relocatingData;

Q_CONSTINIT const QMetaObject cloudseal::grpc::Status_QtProtobufNested::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc23Status_QtProtobufNestedE.stringdata,
    qt_staticMetaObjectStaticContent_ZN9cloudseal4grpc23Status_QtProtobufNestedE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN9cloudseal4grpc23Status_QtProtobufNestedE.metaTypes,
    nullptr
} };

QT_WARNING_POP
