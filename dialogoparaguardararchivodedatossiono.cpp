#include "dialogoparaguardararchivodedatossiono.h"
#include "ui_dialogoparaguardararchivodedatossiono.h"
#include <QDesktopWidget>
#include <QFileDialog>
#include <QString>

#include <iostream>
using namespace std;

extern void cerrarConexionALaBdFuncional();
extern void eliminarArchivoDeLaBdFuncional();

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
///### Procedimiento para cerrar el diálogo que pregunta si se guarda la base de datos funcional en uso (NO)
///##############################
void DialogoParaGuardarArchivoDeDatosSiONo::on_botonNo_clicked()
{
    this->~DialogoParaGuardarArchivoDeDatosSiONo();
    if (cerrarLaAplicacionDespuesDeCerrarElDialogo)
    {
        cerrarConexionALaBdFuncional();
        eliminarArchivoDeLaBdFuncional();
        exit(0);
    }

}

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
