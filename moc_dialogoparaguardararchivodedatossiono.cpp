/****************************************************************************
** Meta object code from reading C++ file 'dialogoparaguardararchivodedatossiono.h'
**
<<<<<<< HEAD
** Created: Tue Feb 26 11:34:05 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
=======
** Created: Mon Mar 4 12:46:08 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogoparaguardararchivodedatossiono.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogoparaguardararchivodedatossiono.h' doesn't include <QObject>."
<<<<<<< HEAD
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
=======
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogoParaGuardarArchivoDeDatosSiONo[] = {

 // content:
<<<<<<< HEAD
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
=======
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      39,   38,   38,   38, 0x08,
<<<<<<< HEAD
      60,   38,   38,   38, 0x08,
=======
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9

       0        // eod
};

static const char qt_meta_stringdata_DialogoParaGuardarArchivoDeDatosSiONo[] = {
    "DialogoParaGuardarArchivoDeDatosSiONo\0"
<<<<<<< HEAD
    "\0on_botonNo_clicked()\0on_botonSi_clicked()\0"
};

void DialogoParaGuardarArchivoDeDatosSiONo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DialogoParaGuardarArchivoDeDatosSiONo *_t = static_cast<DialogoParaGuardarArchivoDeDatosSiONo *>(_o);
        switch (_id) {
        case 0: _t->on_botonNo_clicked(); break;
        case 1: _t->on_botonSi_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DialogoParaGuardarArchivoDeDatosSiONo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
=======
    "\0on_botonNo_clicked()\0"
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
};

const QMetaObject DialogoParaGuardarArchivoDeDatosSiONo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogoParaGuardarArchivoDeDatosSiONo,
<<<<<<< HEAD
      qt_meta_data_DialogoParaGuardarArchivoDeDatosSiONo, &staticMetaObjectExtraData }
=======
      qt_meta_data_DialogoParaGuardarArchivoDeDatosSiONo, 0 }
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogoParaGuardarArchivoDeDatosSiONo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogoParaGuardarArchivoDeDatosSiONo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogoParaGuardarArchivoDeDatosSiONo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogoParaGuardarArchivoDeDatosSiONo))
        return static_cast<void*>(const_cast< DialogoParaGuardarArchivoDeDatosSiONo*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogoParaGuardarArchivoDeDatosSiONo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
<<<<<<< HEAD
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
=======
        switch (_id) {
        case 0: on_botonNo_clicked(); break;
        default: ;
        }
        _id -= 1;
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
    }
    return _id;
}
QT_END_MOC_NAMESPACE
