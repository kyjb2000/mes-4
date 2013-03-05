#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>

using namespace std;

namespace Ui {
    class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow {

    Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();

protected:
    void closeEvent(QCloseEvent *event);

private:

    Ui::VentanaPrincipal *ui;

private slots:
    ///##############################
    ///### Funciones de las acciones desde el Qt Designer
    ///##############################
    void on_accionSalir_triggered();
    void on_accionImportarArchivoConFormatoCSV_triggered();
<<<<<<< HEAD
    void cambioEnCheckBoxVariablesEnLaPrimeraFila();
=======
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9

    ///##############################
    ///### Funciones relativas al proceso de manejo de archivos csv
    ///##############################
<<<<<<< HEAD
    bool conexionCorrectaALaBdTemporal();
    void botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido();
    void botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido();
    void cerrarConexionALaBdTemporal();
=======
    bool insertarPrimeros99CasosOMenosDelArchivoCSV();
    void botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido();
    void botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido();
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9

    ///##############################
    ///### Funciones de la base de datos funcional
    ///##############################
<<<<<<< HEAD
    bool conexionCorrectaALaBdFuncional();
    void actualizarVistasDeLaBdFuncional();
    bool crearBaseDeDatosFuncional(bool variablesEstanEnLaPrimeraFila);
=======

>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
};

#endif // VENTANAPRINCIPAL_H
