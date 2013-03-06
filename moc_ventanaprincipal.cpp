/****************************************************************************
** Meta object code from reading C++ file 'ventanaprincipal.h'
**
<<<<<<< HEAD
** Created: Wed Mar 6 16:48:17 2013
=======
<<<<<<< HEAD
** Created: Tue Feb 26 11:34:03 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
=======
** Created: Tue Mar 5 11:49:46 2013
>>>>>>> f969703cb223799254a551f2fe16dfc250f0d13f
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ventanaprincipal.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaprincipal.h' doesn't include <QObject>."
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
static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
<<<<<<< HEAD
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
=======
       5,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< HEAD
       7,   14, // methods
=======
       5,   14, // methods
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
>>>>>>> f969703cb223799254a551f2fe16dfc250f0d13f
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      45,   17,   17,   17, 0x08,
<<<<<<< HEAD
      95,   17,   17,   17, 0x08,
     143,   17,  138,   17, 0x08,
     175,   17,   17,   17, 0x08,
     233,   17,   17,   17, 0x08,
     290,   17,   17,   17, 0x08,
     320,   17,  138,   17, 0x08,
     353,   17,   17,   17, 0x08,
     417,  387,  138,   17, 0x08,
=======
     100,   17,   95,   17, 0x08,
     145,   17,   17,   17, 0x08,
     203,   17,   17,   17, 0x08,
<<<<<<< HEAD
     260,   17,   95,   17, 0x08,
     284,   17,   17,   17, 0x08,
=======
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
>>>>>>> f969703cb223799254a551f2fe16dfc250f0d13f

       0        // eod
};

static const char qt_meta_stringdata_VentanaPrincipal[] = {
    "VentanaPrincipal\0\0on_accionSalir_triggered()\0"
    "on_accionImportarArchivoConFormatoCSV_triggered()\0"
<<<<<<< HEAD
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
=======
    "bool\0insertarPrimeros99CasosOMenosDelArchivoCSV()\0"
    "botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()\0"
    "botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido()\0"
<<<<<<< HEAD
    "conexionCorrectaALaBd()\0cerrarConexionALaBd()\0"
=======
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
>>>>>>> f969703cb223799254a551f2fe16dfc250f0d13f
};

const QMetaObject VentanaPrincipal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VentanaPrincipal,
<<<<<<< HEAD
      qt_meta_data_VentanaPrincipal, &staticMetaObjectExtraData }
=======
      qt_meta_data_VentanaPrincipal, 0 }
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
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
<<<<<<< HEAD
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
=======
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
<<<<<<< HEAD
        _id -= 7;
=======
        _id -= 5;
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
>>>>>>> f969703cb223799254a551f2fe16dfc250f0d13f
    }
    return _id;
}
QT_END_MOC_NAMESPACE
