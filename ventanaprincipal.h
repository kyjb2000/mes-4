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

    ///##############################
    ///### Funciones relativas al proceso de manejo de archivos csv
    ///##############################
    bool insertarPrimeros99CasosOMenosDelArchivoCSV();
    void cambioEnCheckBoxVariablesEnLaPrimeraFila();
    void botonCancelarDeLaVentanaDeAnalisisDelArchivoCSVOprimido();
    void botonAceptarDeLaVentanaDeAnalisisDelArchivoCSVOprimido();

    ///##############################
    ///### Funciones de la base de datos funcional
    ///##############################

};

#endif // VENTANAPRINCIPAL_H
