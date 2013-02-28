#include <QtGui/QApplication>
#include "ventanaprincipal.h"

int main(int argc, char *argv[])
{
    QApplication aplicacion(argc, argv);
    VentanaPrincipal ventanaPrincipal;
    ventanaPrincipal.showMaximized();
    return aplicacion.exec();
}
