/****************************************************************************
** Meta object code from reading C++ file 'ffmpegdecoder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../H264Server/ffmpegdecoder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ffmpegdecoder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FfmpegDecoder_t {
    QByteArrayData data[12];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FfmpegDecoder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FfmpegDecoder_t qt_meta_stringdata_FfmpegDecoder = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FfmpegDecoder"
QT_MOC_LITERAL(1, 14, 13), // "updatePreview"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "image"
QT_MOC_LITERAL(4, 35, 13), // "imageCaptured"
QT_MOC_LITERAL(5, 49, 9), // "IplImage*"
QT_MOC_LITERAL(6, 59, 4), // "time"
QT_MOC_LITERAL(7, 64, 10), // "fileClosed"
QT_MOC_LITERAL(8, 75, 8), // "openFile"
QT_MOC_LITERAL(9, 84, 8), // "fileName"
QT_MOC_LITERAL(10, 93, 9), // "closeFile"
QT_MOC_LITERAL(11, 103, 10) // "decodeFile"

    },
    "FfmpegDecoder\0updatePreview\0\0image\0"
    "imageCaptured\0IplImage*\0time\0fileClosed\0"
    "openFile\0fileName\0closeFile\0decodeFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FfmpegDecoder[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    2,   47,    2, 0x06 /* Public */,
       7,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   53,    2, 0x0a /* Public */,
      10,    0,   56,    2, 0x0a /* Public */,
      11,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::UInt,    3,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FfmpegDecoder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FfmpegDecoder *_t = static_cast<FfmpegDecoder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatePreview((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->imageCaptured((*reinterpret_cast< IplImage*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 2: _t->fileClosed(); break;
        case 3: _t->openFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->closeFile(); break;
        case 5: _t->decodeFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FfmpegDecoder::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FfmpegDecoder::updatePreview)) {
                *result = 0;
            }
        }
        {
            typedef void (FfmpegDecoder::*_t)(IplImage * , unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FfmpegDecoder::imageCaptured)) {
                *result = 1;
            }
        }
        {
            typedef void (FfmpegDecoder::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FfmpegDecoder::fileClosed)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject FfmpegDecoder::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FfmpegDecoder.data,
      qt_meta_data_FfmpegDecoder,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FfmpegDecoder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FfmpegDecoder::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FfmpegDecoder.stringdata0))
        return static_cast<void*>(const_cast< FfmpegDecoder*>(this));
    return QObject::qt_metacast(_clname);
}

int FfmpegDecoder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FfmpegDecoder::updatePreview(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FfmpegDecoder::imageCaptured(IplImage * _t1, unsigned int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FfmpegDecoder::fileClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
