/****************************************************************************
** Meta object code from reading C++ file 'download_files.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../web-crawler/download_files.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'download_files.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_download_files_t {
    QByteArrayData data[8];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_download_files_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_download_files_t qt_meta_stringdata_download_files = {
    {
QT_MOC_LITERAL(0, 0, 14), // "download_files"
QT_MOC_LITERAL(1, 15, 15), // "finsh_all_files"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 10), // "disconnect"
QT_MOC_LITERAL(4, 43, 23), // "finish_download_process"
QT_MOC_LITERAL(5, 67, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 82, 12), // "change_stats"
QT_MOC_LITERAL(7, 95, 43) // "QNetworkAccessManager::Networ..."

    },
    "download_files\0finsh_all_files\0\0"
    "disconnect\0finish_download_process\0"
    "QNetworkReply*\0change_stats\0"
    "QNetworkAccessManager::NetworkAccessibility"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_download_files[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   36,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void download_files::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        download_files *_t = static_cast<download_files *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finsh_all_files(); break;
        case 1: _t->disconnect(); break;
        case 2: _t->finish_download_process((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->change_stats((*reinterpret_cast< QNetworkAccessManager::NetworkAccessibility(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (download_files::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&download_files::finsh_all_files)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (download_files::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&download_files::disconnect)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject download_files::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_download_files.data,
      qt_meta_data_download_files,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *download_files::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *download_files::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_download_files.stringdata0))
        return static_cast<void*>(const_cast< download_files*>(this));
    return QObject::qt_metacast(_clname);
}

int download_files::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void download_files::finsh_all_files()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void download_files::disconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
