#include "dialogoparaguardararchivodedatossiono.h"
#include "ui_dialogoparaguardararchivodedatossiono.h"
#include <QDesktopWidget>
<<<<<<< HEAD
#include <QFileDialog>
#include <QString>

#include <iostream>
using namespace std;

extern void cerrarConexionALaBdFuncional();
extern void eliminarArchivoDeLaBdFuncional();
=======
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9

DialogoParaGuardarArchivoDeDatosSiONo::DialogoParaGuardarArchivoDeDatosSiONo(QWidget *parent, bool cerrarAplicacion) :
    QDialog(parent),
    ui(new Ui::DialogoParaGuardarArchivoDeDatosSiONo)
{
    ui->setupUi(this);
    ///##############################
    ///### Procedimiento para centrar el díalogo relativo a la pantalla completa
    ///##############################
    const QRect pantalla = QApplication::desktop()->screenGeometry();
    this->move(pantalla.center() - this->rect().center());
    cerrarLaAplicacionDespuesDeCerrarElDialogo = cerrarAplicacion;
}

DialogoParaGuardarArchivoDeDatosSiONo::~DialogoParaGuardarArchivoDeDatosSiONo()
{
    delete ui;
}

///##############################
<<<<<<< HEAD
///### Procedimiento para cerrar el diálogo que pregunta si se guarda la base de datos funcional en uso (NO)
=======
///### Procedimiento para cerrar el diálogo que pregunta si se guarda la base de datos funcional en uso
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
///##############################
void DialogoParaGuardarArchivoDeDatosSiONo::on_botonNo_clicked()
{
    this->~DialogoParaGuardarArchivoDeDatosSiONo();
    if (cerrarLaAplicacionDespuesDeCerrarElDialogo)
    {
<<<<<<< HEAD
        cerrarConexionALaBdFuncional();
        eliminarArchivoDeLaBdFuncional();
=======
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
        exit(0);
    }

}
<<<<<<< HEAD

///##############################
///### Procedimiento para cerrar el diálogo que pregunta si se guarda la base de datos funcional en uso (SI)
///##############################
void DialogoParaGuardarArchivoDeDatosSiONo::on_botonSi_clicked()
{
    this->~DialogoParaGuardarArchivoDeDatosSiONo();
    QString nombreDelArchivoAGuardar = QFileDialog::getSaveFileName(0, tr("Guardar datos"), QDir::currentPath(), tr("Archivos de datos mes(*.mes)"));
    if( !nombreDelArchivoAGuardar.isNull() )
    {
        QFile nombreDeLaBaseDeDatosFuncional ("./baseDeDatosFuncional");
        nombreDeLaBaseDeDatosFuncional.rename(nombreDelArchivoAGuardar.toAscii().data());
    }
    if (cerrarLaAplicacionDespuesDeCerrarElDialogo)
    {
        cerrarConexionALaBdFuncional();
        eliminarArchivoDeLaBdFuncional();
        exit(0);
    }
}
=======
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
