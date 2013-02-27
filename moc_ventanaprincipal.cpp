/****************************************************************************
** Meta object code from reading C++ file 'ventanaprincipal.h'
**
** Created: Tue Feb 26 11:34:03 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ventanaprincipal.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaprincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      45,   17,   17,   17, 0x08,
      95,   17,   17,   17, 0x08,
     143,   17,  138,   17, 0x08,
     175,   17,   17,   17, 0x08,
     233,   17,   17,   17, 0x08,
     290,   17,   17,   17, 0x08,
     320,   17,  138,   17, 0x08,
     353,   17,   17,   17, 0x08,
     417,  387,  138,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VentanaPrincipal[] = {
    "VentanaPrincipal\0\0on_accionSalir_triggered()\0"
    "on_accionImportarArchivoConFormatoCSV_triggered()\0"
    "cambioEnCheckBoxVariablesEnLaPrimeraFila()\0"
    "bool\0conexionCorrectaALaBdTemporal()\0"
    "botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()\0"
    "botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()\0"
    "cerrarConexionALaBdTemporal()\0"
    "conexionCorrectaALaBdFuncional()\0"
    "actualizarVistasDeLaBdFuncional()\0"
    "variablesEstanEnLaPrimeraFila\0"
    "crearBaseDeDatosFuncional(bool)\0"
};

void VentanaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VentanaPrincipal *_t = static_cast<VentanaPrincipal *>(_o);
        switch (_id) {
        case 0: _t->on_accionSalir_triggered(); break;
        case 1: _t->on_accionImportarArchivoConFormatoCSV_triggered(); break;
        case 2: _t->cambioEnCheckBoxVariablesEnLaPrimeraFila(); break;
        case 3: { bool _r = _t->conexionCorrectaALaBdTemporal();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido(); break;
        case 5: _t->botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido(); break;
        case 6: _t->cerrarConexionALaBdTemporal(); break;
        case 7: { bool _r = _t->conexionCorrectaALaBdFuncional();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->actualizarVistasDeLaBdFuncional(); break;
        case 9: { bool _r = _t->crearBaseDeDatosFuncional((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VentanaPrincipal::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VentanaPrincipal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VentanaPrincipal,
      qt_meta_data_VentanaPrincipal, &staticMetaObjectExtraData }
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
