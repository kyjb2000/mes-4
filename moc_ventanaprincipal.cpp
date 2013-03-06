/****************************************************************************
** Meta object code from reading C++ file 'ventanaprincipal.h'
**
** Created: Wed Mar 6 16:48:17 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ventanaprincipal.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaprincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      45,   17,   17,   17, 0x08,
     100,   17,   95,   17, 0x08,
     145,   17,   17,   17, 0x08,
     203,   17,   17,   17, 0x08,
     260,   17,   95,   17, 0x08,
     284,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VentanaPrincipal[] = {
    "VentanaPrincipal\0\0on_accionSalir_triggered()\0"
    "on_accionImportarArchivoConFormatoCSV_triggered()\0"
    "bool\0insertarPrimeros99CasosOMenosDelArchivoCSV()\0"
    "botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()\0"
    "botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()\0"
    "conexionCorrectaALaBd()\0cerrarConexionALaBd()\0"
};

const QMetaObject VentanaPrincipal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VentanaPrincipal,
      qt_meta_data_VentanaPrincipal, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VentanaPrincipal::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VentanaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VentanaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaPrincipal))
        return static_cast<void*>(const_cast< VentanaPrincipal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VentanaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_accionSalir_triggered(); break;
        case 1: on_accionImportarArchivoConFormatoCSV_triggered(); break;
        case 2: { bool _r = insertarPrimeros99CasosOMenosDelArchivoCSV();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido(); break;
        case 4: botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido(); break;
        case 5: { bool _r = conexionCorrectaALaBd();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: cerrarConexionALaBd(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
