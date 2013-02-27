#include "dialogoparaimportararchivoscsv.h"
#include "ui_dialogoparaimportararchivoscsv.h"
#include <QDesktopWidget>

DialogoParaImportarArchivosCSV::DialogoParaImportarArchivosCSV(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoParaImportarArchivosCSV)
{
    ui->setupUi(this);
    ///##############################
    ///### Procedimiento para centrar el díalogo relativo a la pantalla completa
    ///##############################
    const QRect pantalla = QApplication::desktop()->screenGeometry();
    this->move(pantalla.center() - this->rect().center());
}

DialogoParaImportarArchivosCSV::~DialogoParaImportarArchivosCSV()
{
    delete ui;
}
