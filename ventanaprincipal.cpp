#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include <variablesglobales.h>
#include <manejodearchivoscsv.h>

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    ///##############################
<<<<<<< HEAD
    ///### Variable de control de la base de datos funcional en uso
    ///##############################
    baseDeDatosFuncionalEnUso = false;
=======
    ///### Incialización de variables necesarias al abrir la aplicación
    ///##############################
    baseDeDatosEnUso = false;
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

//##############################
///### Procedimiento reimplementado para salir de la aplicación cuando se oprime la [X] de la ventana principal
///##############################
void VentanaPrincipal::closeEvent(QCloseEvent *event)
 {
    event->ignore();
    ///##############################
    ///### Verificar si hay una base de datos funcional activa antes de salir
    ///##############################
<<<<<<< HEAD
    if (baseDeDatosFuncionalEnUso)
=======
    if (baseDeDatosEnUso)
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
    {
        guardarBaseDeDatosFuncional = new DialogoParaGuardarArchivoDeDatosSiONo(0, true);
        guardarBaseDeDatosFuncional->show();
    }
    ///##############################
    ///### Salir de la aplicación
    ///##############################
    else
    {
<<<<<<< HEAD
        cerrarConexionALaBdFuncional();
        eliminarArchivoDeLaBdFuncional();
=======
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
        exit(0);
    }
 }

///##############################
///### Procedimiento para salir de la aplicación desde el menú y la barra de herramientas
///##############################
void VentanaPrincipal::on_accionSalir_triggered()
{
    close();
}
