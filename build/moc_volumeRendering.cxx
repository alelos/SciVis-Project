/****************************************************************************
** Meta object code from reading C++ file 'volumeRendering.h'
**
** Created: Thu Oct 27 11:34:56 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../volumeRendering.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'volumeRendering.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VolumeRendering[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      74,   34,   16,   16, 0x0a,
     114,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VolumeRendering[] = {
    "VolumeRendering\0\0startRendering()\0"
    "startPoint,startValue,endPoint,endValue\0"
    "setOpacityFunction(int,float,int,float)\0"
    "clearAllPoints()\0"
};

const QMetaObject VolumeRendering::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VolumeRendering,
      qt_meta_data_VolumeRendering, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VolumeRendering::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VolumeRendering::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VolumeRendering::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VolumeRendering))
        return static_cast<void*>(const_cast< VolumeRendering*>(this));
    return QObject::qt_metacast(_clname);
}

int VolumeRendering::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startRendering(); break;
        case 1: setOpacityFunction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 2: clearAllPoints(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
