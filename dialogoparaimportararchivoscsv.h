#ifndef DIALOGOPARAIMPORTARARCHIVOSCSV_H
#define DIALOGOPARAIMPORTARARCHIVOSCSV_H

#include <QDialog>

namespace Ui {
    class DialogoParaImportarArchivosCSV;
}

class DialogoParaImportarArchivosCSV : public QDialog
{
    Q_OBJECT

public:
    DialogoParaImportarArchivosCSV(QWidget *parent = 0);
    Ui::DialogoParaImportarArchivosCSV *ui;
    ~DialogoParaImportarArchivosCSV();

protected:

private:
    ///##############################
    ///### Se pasó a la sección "public" para tener acceso a los elementos desde la clase VentanaPrincipal
    ///##############################
    //Ui::DialogoParaImportarArchivosCSV *ui;

private slots:
};

#endif // DIALOGOPARAIMPORTARARCHIVOSCSV_H
