/****************************************************************************
** Meta object code from reading C++ file 'h264coder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../H264Server/h264coder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'h264coder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_H264Coder_t {
    QByteArrayData data[11];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_H264Coder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_H264Coder_t qt_meta_stringdata_H264Coder = {
    {
QT_MOC_LITERAL(0, 0, 9), // "H264Coder"
QT_MOC_LITERAL(1, 10, 7), // "iniX264"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "paramSetting"
QT_MOC_LITERAL(4, 32, 12), // "x264_param_t"
QT_MOC_LITERAL(5, 45, 5), // "param"
QT_MOC_LITERAL(6, 51, 13), // "imageCaptured"
QT_MOC_LITERAL(7, 65, 9), // "IplImage*"
QT_MOC_LITERAL(8, 75, 5), // "image"
QT_MOC_LITERAL(9, 81, 4), // "time"
QT_MOC_LITERAL(10, 86, 10) // "stopCoding"

    },
    "H264Coder\0iniX264\0\0paramSetting\0"
    "x264_param_t\0param\0imageCaptured\0"
    "IplImage*\0image\0time\0stopCoding"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_H264Coder[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       6,    2,   38,    2, 0x0a /* Public */,
      10,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::UInt,    8,    9,
    QMetaType::Void,

       0        // eod
};

void H264Coder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        H264Coder *_t = static_cast<H264Coder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->iniX264(); break;
        case 1: _t->paramSetting((*reinterpret_cast< x264_param_t(*)>(_a[1]))); break;
        case 2: _t->imageCaptured((*reinterpret_cast< IplImage*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 3: _t->stopCoding(); break;
        default: ;
        }
    }
}

const QMetaObject H264Coder::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_H264Coder.data,
      qt_meta_data_H264Coder,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *H264Coder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *H264Coder::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_H264Coder.stringdata0))
        return static_cast<void*>(const_cast< H264Coder*>(this));
    return QObject::qt_metacast(_clname);
}

int H264Coder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
