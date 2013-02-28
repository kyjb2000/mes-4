#ifndef DIALOGOPARAGUARDARARCHIVODEDATOSSIONO_H
#define DIALOGOPARAGUARDARARCHIVODEDATOSSIONO_H

#include <QDialog>

namespace Ui {
class DialogoParaGuardarArchivoDeDatosSiONo;
}

class DialogoParaGuardarArchivoDeDatosSiONo : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogoParaGuardarArchivoDeDatosSiONo(QWidget *parent = 0, bool cerrarAplicacion=false);
    Ui::DialogoParaGuardarArchivoDeDatosSiONo *ui;
    ~DialogoParaGuardarArchivoDeDatosSiONo();
    bool cerrarLaAplicacionDespuesDeCerrarElDialogo;

private slots:
    void on_botonNo_clicked();

private:
    ///##############################
    ///### Se pasó a la sección "public" para tener acceso a los elementos desde la clase VentanaPrincipal
    ///##############################
    //Ui::DialogoParaGuardarArchivoDeDatosSiONo *ui;
};

#endif // DIALOGOPARAGUARDARARCHIVODEDATOSSIONO_H
