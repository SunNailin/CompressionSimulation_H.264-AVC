/****************************************************************************
** Meta object code from reading C++ file 'cameramgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../H264Server/cameramgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameramgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CameraMgr_t {
    QByteArrayData data[13];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraMgr_t qt_meta_stringdata_CameraMgr = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CameraMgr"
QT_MOC_LITERAL(1, 10, 13), // "updatePreview"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "image"
QT_MOC_LITERAL(4, 31, 13), // "imageCaptured"
QT_MOC_LITERAL(5, 45, 9), // "IplImage*"
QT_MOC_LITERAL(6, 55, 4), // "time"
QT_MOC_LITERAL(7, 60, 12), // "changeDevice"
QT_MOC_LITERAL(8, 73, 8), // "QAction*"
QT_MOC_LITERAL(9, 82, 6), // "action"
QT_MOC_LITERAL(10, 89, 12), // "setFrameRate"
QT_MOC_LITERAL(11, 102, 9), // "frameRate"
QT_MOC_LITERAL(12, 112, 12) // "imageCapture"

    },
    "CameraMgr\0updatePreview\0\0image\0"
    "imageCaptured\0IplImage*\0time\0changeDevice\0"
    "QAction*\0action\0setFrameRate\0frameRate\0"
    "imageCapture"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    2,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   47,    2, 0x0a /* Public */,
      10,    1,   50,    2, 0x0a /* Public */,
      12,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::UInt,    3,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::UInt,   11,
    QMetaType::Void,

       0        // eod
};

void CameraMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraMgr *_t = static_cast<CameraMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatePreview((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->imageCaptured((*reinterpret_cast< IplImage*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 2: _t->changeDevice((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->setFrameRate((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->imageCapture(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraMgr::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraMgr::updatePreview)) {
                *result = 0;
            }
        }
        {
            typedef void (CameraMgr::*_t)(IplImage * , unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraMgr::imageCaptured)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CameraMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CameraMgr.data,
      qt_meta_data_CameraMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CameraMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CameraMgr.stringdata0))
        return static_cast<void*>(const_cast< CameraMgr*>(this));
    return QObject::qt_metacast(_clname);
}

int CameraMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CameraMgr::updatePreview(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CameraMgr::imageCaptured(IplImage * _t1, unsigned int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
