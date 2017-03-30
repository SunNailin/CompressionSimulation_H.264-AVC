/****************************************************************************
** Meta object code from reading C++ file 'codecsetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../H264Server/codecsetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codecsetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CodecSetting_t {
    QByteArrayData data[8];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CodecSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CodecSetting_t qt_meta_stringdata_CodecSetting = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CodecSetting"
QT_MOC_LITERAL(1, 13, 8), // "setParam"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "x264_param_t"
QT_MOC_LITERAL(4, 36, 5), // "param"
QT_MOC_LITERAL(5, 42, 12), // "setFrameRate"
QT_MOC_LITERAL(6, 55, 8), // "framRate"
QT_MOC_LITERAL(7, 64, 12) // "paramSetting"

    },
    "CodecSetting\0setParam\0\0x264_param_t\0"
    "param\0setFrameRate\0framRate\0paramSetting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CodecSetting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::UInt,    6,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CodecSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CodecSetting *_t = static_cast<CodecSetting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setParam((*reinterpret_cast< x264_param_t(*)>(_a[1]))); break;
        case 1: _t->setFrameRate((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->paramSetting(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CodecSetting::*_t)(x264_param_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CodecSetting::setParam)) {
                *result = 0;
            }
        }
        {
            typedef void (CodecSetting::*_t)(unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CodecSetting::setFrameRate)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CodecSetting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CodecSetting.data,
      qt_meta_data_CodecSetting,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CodecSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CodecSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CodecSetting.stringdata0))
        return static_cast<void*>(const_cast< CodecSetting*>(this));
    return QDialog::qt_metacast(_clname);
}

int CodecSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CodecSetting::setParam(x264_param_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CodecSetting::setFrameRate(unsigned int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
