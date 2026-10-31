/****************************************************************************
** Meta object code from reading C++ file 'imagecachemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../imagecachemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagecachemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageCacheManager_t {
    QByteArrayData data[12];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageCacheManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageCacheManager_t qt_meta_stringdata_ImageCacheManager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ImageCacheManager"
QT_MOC_LITERAL(1, 18, 15), // "imageDownloaded"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 4), // "path"
QT_MOC_LITERAL(4, 40, 6), // "songId"
QT_MOC_LITERAL(5, 47, 8), // "download"
QT_MOC_LITERAL(6, 56, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 71, 5), // "reply"
QT_MOC_LITERAL(8, 77, 4), // "save"
QT_MOC_LITERAL(9, 82, 3), // "url"
QT_MOC_LITERAL(10, 86, 5), // "clear"
QT_MOC_LITERAL(11, 92, 8) // "isCached"

    },
    "ImageCacheManager\0imageDownloaded\0\0"
    "path\0songId\0download\0QNetworkReply*\0"
    "reply\0save\0url\0clear\0isCached"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageCacheManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   44,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       8,    2,   47,    2, 0x02 /* Public */,
      10,    1,   52,    2, 0x02 /* Public */,
      11,    1,   55,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    9,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QString,    3,

       0        // eod
};

void ImageCacheManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageCacheManager *_t = static_cast<ImageCacheManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageDownloaded((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->download((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->save((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->clear((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { bool _r = _t->isCached((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            typedef void (ImageCacheManager::*_t)(const QString & , const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageCacheManager::imageDownloaded)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ImageCacheManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageCacheManager.data,
      qt_meta_data_ImageCacheManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImageCacheManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageCacheManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImageCacheManager.stringdata0))
        return static_cast<void*>(const_cast< ImageCacheManager*>(this));
    return QObject::qt_metacast(_clname);
}

int ImageCacheManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ImageCacheManager::imageDownloaded(const QString & _t1, const int & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
