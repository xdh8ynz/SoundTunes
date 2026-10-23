/****************************************************************************
** Meta object code from reading C++ file 'musicsearchcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/controllers/musicsearchcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicsearchcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MusicSearchController_t {
    QByteArrayData data[17];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicSearchController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicSearchController_t qt_meta_stringdata_MusicSearchController = {
    {
QT_MOC_LITERAL(0, 0, 21), // "MusicSearchController"
QT_MOC_LITERAL(1, 22, 16), // "songModelChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 18), // "songSearchFinished"
QT_MOC_LITERAL(4, 59, 16), // "songSearchFailed"
QT_MOC_LITERAL(5, 76, 11), // "serverError"
QT_MOC_LITERAL(6, 88, 12), // "networkError"
QT_MOC_LITERAL(7, 101, 16), // "onSearchFinished"
QT_MOC_LITERAL(8, 118, 11), // "QList<Song>"
QT_MOC_LITERAL(9, 130, 5), // "songs"
QT_MOC_LITERAL(10, 136, 14), // "onSearchFailed"
QT_MOC_LITERAL(11, 151, 13), // "onServerError"
QT_MOC_LITERAL(12, 165, 14), // "onNetworkError"
QT_MOC_LITERAL(13, 180, 12), // "searchSounds"
QT_MOC_LITERAL(14, 193, 5), // "query"
QT_MOC_LITERAL(15, 199, 9), // "songModel"
QT_MOC_LITERAL(16, 209, 10) // "SongModel*"

    },
    "MusicSearchController\0songModelChanged\0"
    "\0songSearchFinished\0songSearchFailed\0"
    "serverError\0networkError\0onSearchFinished\0"
    "QList<Song>\0songs\0onSearchFailed\0"
    "onServerError\0onNetworkError\0searchSounds\0"
    "query\0songModel\0SongModel*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicSearchController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       1,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   69,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      13,    1,   75,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   14,

 // properties: name, type, flags
      15, 0x80000000 | 16, 0x00495009,

 // properties: notify_signal_id
       0,

       0        // eod
};

void MusicSearchController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicSearchController *_t = static_cast<MusicSearchController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->songModelChanged(); break;
        case 1: _t->songSearchFinished(); break;
        case 2: _t->songSearchFailed(); break;
        case 3: _t->serverError(); break;
        case 4: _t->networkError(); break;
        case 5: _t->onSearchFinished((*reinterpret_cast< QList<Song>(*)>(_a[1]))); break;
        case 6: _t->onSearchFailed(); break;
        case 7: _t->onServerError(); break;
        case 8: _t->onNetworkError(); break;
        case 9: _t->searchSounds((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Song> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MusicSearchController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicSearchController::songModelChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MusicSearchController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicSearchController::songSearchFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MusicSearchController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicSearchController::songSearchFailed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MusicSearchController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicSearchController::serverError)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MusicSearchController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicSearchController::networkError)) {
                *result = 4;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SongModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        MusicSearchController *_t = static_cast<MusicSearchController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< SongModel**>(_v) = _t->songModel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject MusicSearchController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MusicSearchController.data,
      qt_meta_data_MusicSearchController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MusicSearchController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicSearchController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MusicSearchController.stringdata0))
        return static_cast<void*>(const_cast< MusicSearchController*>(this));
    return QObject::qt_metacast(_clname);
}

int MusicSearchController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MusicSearchController::songModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MusicSearchController::songSearchFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MusicSearchController::songSearchFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MusicSearchController::serverError()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MusicSearchController::networkError()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
