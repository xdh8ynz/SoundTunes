/****************************************************************************
** Meta object code from reading C++ file 'yandexmusicclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/yandexmusicclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'yandexmusicclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_YandexMusicClient_t {
    QByteArrayData data[12];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_YandexMusicClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_YandexMusicClient_t qt_meta_stringdata_YandexMusicClient = {
    {
QT_MOC_LITERAL(0, 0, 17), // "YandexMusicClient"
QT_MOC_LITERAL(1, 18, 19), // "onSongsSearchFailed"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 20), // "onSongsSearchSuccess"
QT_MOC_LITERAL(4, 60, 11), // "QList<Song>"
QT_MOC_LITERAL(5, 72, 5), // "songs"
QT_MOC_LITERAL(6, 78, 14), // "onNetworkError"
QT_MOC_LITERAL(7, 93, 13), // "onServerError"
QT_MOC_LITERAL(8, 107, 15), // "onSongsReceived"
QT_MOC_LITERAL(9, 123, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 138, 5), // "reply"
QT_MOC_LITERAL(11, 144, 21) // "onSearchTimerFinished"

    },
    "YandexMusicClient\0onSongsSearchFailed\0"
    "\0onSongsSearchSuccess\0QList<Song>\0"
    "songs\0onNetworkError\0onServerError\0"
    "onSongsReceived\0QNetworkReply*\0reply\0"
    "onSearchTimerFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YandexMusicClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   50,    2, 0x0a /* Public */,
      11,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void YandexMusicClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        YandexMusicClient *_t = static_cast<YandexMusicClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSongsSearchFailed(); break;
        case 1: _t->onSongsSearchSuccess((*reinterpret_cast< QList<Song>(*)>(_a[1]))); break;
        case 2: _t->onNetworkError(); break;
        case 3: _t->onServerError(); break;
        case 4: _t->onSongsReceived((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->onSearchTimerFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Song> >(); break;
            }
            break;
        case 4:
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
            typedef void (YandexMusicClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YandexMusicClient::onSongsSearchFailed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (YandexMusicClient::*_t)(QList<Song> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YandexMusicClient::onSongsSearchSuccess)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (YandexMusicClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YandexMusicClient::onNetworkError)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (YandexMusicClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&YandexMusicClient::onServerError)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject YandexMusicClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_YandexMusicClient.data,
      qt_meta_data_YandexMusicClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *YandexMusicClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YandexMusicClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_YandexMusicClient.stringdata0))
        return static_cast<void*>(const_cast< YandexMusicClient*>(this));
    return QObject::qt_metacast(_clname);
}

int YandexMusicClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void YandexMusicClient::onSongsSearchFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void YandexMusicClient::onSongsSearchSuccess(QList<Song> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void YandexMusicClient::onNetworkError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void YandexMusicClient::onServerError()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
