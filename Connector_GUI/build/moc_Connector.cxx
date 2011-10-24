/****************************************************************************
** Meta object code from reading C++ file 'Connector.h'
**
** Created: Mon Oct 24 15:10:47 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Connector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Connector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Connector[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   11,   10,   10, 0x0a,
      41,   10,   10,   10, 0x0a,
      81,   59,   55,   10, 0x0a,
     133,  119,   55,   10, 0x2a,
     170,  164,   55,   10, 0x2a,
     194,   10,   55,   10, 0x2a,
     221,  212,   10,   10, 0x0a,
     250,  242,   10,   10, 0x0a,
     274,  164,   10,   10, 0x0a,
     304,  296,   10,   10, 0x0a,
     336,  328,   10,   10, 0x0a,
     371,   10,  360,   10, 0x0a,
     383,   10,   10,   10, 0x0a,
     404,  399,   10,   10, 0x0a,
     428,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Connector[] = {
    "Connector\0\0username\0setUsername(QString)\0"
    "libsshLogin()\0int\0hours,minutes,seconds\0"
    "startVNCSession(string,string,string)\0"
    "hours,minutes\0startVNCSession(string,string)\0"
    "hours\0startVNCSession(string)\0"
    "startVNCSession()\0passSara\0"
    "setPassword(QString)\0passvnc\0"
    "setVNCPassword(QString)\0setTimeHours(QString)\0"
    "minutes\0setTimeMinutes(QString)\0seconds\0"
    "setTimeSeconds(QString)\0QTextEdit*\0"
    "getOutput()\0writeToOutput()\0node\0"
    "connectToVNCServer(int)\0logout()\0"
};

const QMetaObject Connector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Connector,
      qt_meta_data_Connector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Connector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Connector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Connector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Connector))
        return static_cast<void*>(const_cast< Connector*>(this));
    return QObject::qt_metacast(_clname);
}

int Connector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setUsername((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: libsshLogin(); break;
        case 2: { int _r = startVNCSession((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])),(*reinterpret_cast< string(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = startVNCSession((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = startVNCSession((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = startVNCSession();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: setPassword((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: setVNCPassword((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: setTimeHours((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: setTimeMinutes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: setTimeSeconds((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: { QTextEdit* _r = getOutput();
            if (_a[0]) *reinterpret_cast< QTextEdit**>(_a[0]) = _r; }  break;
        case 12: writeToOutput(); break;
        case 13: connectToVNCServer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: logout(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
