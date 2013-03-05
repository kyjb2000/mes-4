/****************************************************************************
** Meta object code from reading C++ file 'dialogoparaguardararchivodedatossiono.h'
**
** Created: Mon Mar 4 12:46:08 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogoparaguardararchivodedatossiono.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogoparaguardararchivodedatossiono.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogoParaGuardarArchivoDeDatosSiONo[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      39,   38,   38,   38, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogoParaGuardarArchivoDeDatosSiONo[] = {
    "DialogoParaGuardarArchivoDeDatosSiONo\0"
    "\0on_botonNo_clicked()\0"
};

const QMetaObject DialogoParaGuardarArchivoDeDatosSiONo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogoParaGuardarArchivoDeDatosSiONo,
      qt_meta_data_DialogoParaGuardarArchivoDeDatosSiONo, 0 }
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
        switch (_id) {
        case 0: on_botonNo_clicked(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
