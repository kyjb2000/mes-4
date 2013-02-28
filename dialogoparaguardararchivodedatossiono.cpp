#include "dialogoparaguardararchivodedatossiono.h"
#include "ui_dialogoparaguardararchivodedatossiono.h"
#include <QDesktopWidget>

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
///### Procedimiento para cerrar el diálogo que pregunta si se guarda la base de datos funcional en uso
///##############################
void DialogoParaGuardarArchivoDeDatosSiONo::on_botonNo_clicked()
{
    this->~DialogoParaGuardarArchivoDeDatosSiONo();
    if (cerrarLaAplicacionDespuesDeCerrarElDialogo)
    {
        exit(0);
    }

}
