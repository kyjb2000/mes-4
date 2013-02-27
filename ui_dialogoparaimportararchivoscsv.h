/********************************************************************************
** Form generated from reading UI file 'dialogoparaimportararchivoscsv.ui'
**
** Created: Tue Feb 26 11:33:57 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOPARAIMPORTARARCHIVOSCSV_H
#define UI_DIALOGOPARAIMPORTARARCHIVOSCSV_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogoParaImportarArchivosCSV
{
public:
    QGroupBox *cajaDeDatos;
    QTableView *tablaDeDatosTemporal;
    QLabel *etiquetaNumeroDeCasos;
    QLineEdit *numeroDeCasos;
    QProgressBar *porcentajeDeVaciado;
    QLabel *etiquetaPorcentajeDeVaciado;
    QGroupBox *cajaDeVariables;
    QCheckBox *variablesEnPrimeraFila;
    QLineEdit *numeroDeVariables;
    QLabel *etiquetaNumeroDeVariables;
    QTableView *tablaDeVariablesTemporal;
    QGroupBox *cajaDeDatosDelArchivoCSV;
    QLabel *etiquetaNombre;
    QLineEdit *nombreDelArchivoCSVAImportar;
    QLabel *etiquetaPorcentajeDeAnalisis;
    QProgressBar *porcentajeDeAnalisis;
    QPushButton *botonCancelar;
    QPushButton *botonAceptar;

    void setupUi(QDialog *DialogoParaImportarArchivosCSV)
    {
        if (DialogoParaImportarArchivosCSV->objectName().isEmpty())
            DialogoParaImportarArchivosCSV->setObjectName(QString::fromUtf8("DialogoParaImportarArchivosCSV"));
        DialogoParaImportarArchivosCSV->setWindowModality(Qt::ApplicationModal);
        DialogoParaImportarArchivosCSV->resize(675, 477);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        DialogoParaImportarArchivosCSV->setFont(font);
        DialogoParaImportarArchivosCSV->setModal(true);
        cajaDeDatos = new QGroupBox(DialogoParaImportarArchivosCSV);
        cajaDeDatos->setObjectName(QString::fromUtf8("cajaDeDatos"));
        cajaDeDatos->setGeometry(QRect(9, 270, 654, 174));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(84, 171, 255, 33));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(212, 234, 255, 33));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(148, 202, 255, 33));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(42, 85, 127, 33));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(56, 114, 170, 33));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(169, 213, 255, 144));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        cajaDeDatos->setPalette(palette);
        cajaDeDatos->setFont(font);
        cajaDeDatos->setAutoFillBackground(true);
        tablaDeDatosTemporal = new QTableView(cajaDeDatos);
        tablaDeDatosTemporal->setObjectName(QString::fromUtf8("tablaDeDatosTemporal"));
        tablaDeDatosTemporal->setEnabled(true);
        tablaDeDatosTemporal->setGeometry(QRect(0, 39, 654, 120));
        QFont font1;
        font1.setPointSize(9);
        tablaDeDatosTemporal->setFont(font1);
        tablaDeDatosTemporal->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tablaDeDatosTemporal->setTabKeyNavigation(false);
        tablaDeDatosTemporal->setProperty("showDropIndicator", QVariant(false));
        tablaDeDatosTemporal->setDragDropOverwriteMode(false);
        etiquetaNumeroDeCasos = new QLabel(cajaDeDatos);
        etiquetaNumeroDeCasos->setObjectName(QString::fromUtf8("etiquetaNumeroDeCasos"));
        etiquetaNumeroDeCasos->setGeometry(QRect(474, 15, 51, 15));
        etiquetaNumeroDeCasos->setFont(font1);
        numeroDeCasos = new QLineEdit(cajaDeDatos);
        numeroDeCasos->setObjectName(QString::fromUtf8("numeroDeCasos"));
        numeroDeCasos->setGeometry(QRect(525, 9, 111, 24));
        numeroDeCasos->setReadOnly(true);
        porcentajeDeVaciado = new QProgressBar(cajaDeDatos);
        porcentajeDeVaciado->setObjectName(QString::fromUtf8("porcentajeDeVaciado"));
        porcentajeDeVaciado->setGeometry(QRect(411, 9, 45, 24));
        porcentajeDeVaciado->setValue(0);
        etiquetaPorcentajeDeVaciado = new QLabel(cajaDeDatos);
        etiquetaPorcentajeDeVaciado->setObjectName(QString::fromUtf8("etiquetaPorcentajeDeVaciado"));
        etiquetaPorcentajeDeVaciado->setGeometry(QRect(348, 15, 57, 15));
        etiquetaPorcentajeDeVaciado->setFont(font1);
        cajaDeVariables = new QGroupBox(DialogoParaImportarArchivosCSV);
        cajaDeVariables->setObjectName(QString::fromUtf8("cajaDeVariables"));
        cajaDeVariables->setGeometry(QRect(9, 81, 654, 177));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        cajaDeVariables->setPalette(palette1);
        cajaDeVariables->setFont(font);
        cajaDeVariables->setAutoFillBackground(true);
        variablesEnPrimeraFila = new QCheckBox(cajaDeVariables);
        variablesEnPrimeraFila->setObjectName(QString::fromUtf8("variablesEnPrimeraFila"));
        variablesEnPrimeraFila->setEnabled(false);
        variablesEnPrimeraFila->setGeometry(QRect(12, 21, 186, 21));
        variablesEnPrimeraFila->setFont(font1);
        numeroDeVariables = new QLineEdit(cajaDeVariables);
        numeroDeVariables->setObjectName(QString::fromUtf8("numeroDeVariables"));
        numeroDeVariables->setGeometry(QRect(576, 18, 60, 24));
        numeroDeVariables->setFont(font);
        numeroDeVariables->setReadOnly(true);
        etiquetaNumeroDeVariables = new QLabel(cajaDeVariables);
        etiquetaNumeroDeVariables->setObjectName(QString::fromUtf8("etiquetaNumeroDeVariables"));
        etiquetaNumeroDeVariables->setGeometry(QRect(507, 24, 60, 15));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(9);
        etiquetaNumeroDeVariables->setFont(font2);
        tablaDeVariablesTemporal = new QTableView(cajaDeVariables);
        tablaDeVariablesTemporal->setObjectName(QString::fromUtf8("tablaDeVariablesTemporal"));
        tablaDeVariablesTemporal->setGeometry(QRect(0, 51, 654, 111));
        tablaDeVariablesTemporal->setFont(font1);
        tablaDeVariablesTemporal->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tablaDeVariablesTemporal->setTabKeyNavigation(false);
        tablaDeVariablesTemporal->setProperty("showDropIndicator", QVariant(false));
        tablaDeVariablesTemporal->setDragDropOverwriteMode(false);
        cajaDeDatosDelArchivoCSV = new QGroupBox(DialogoParaImportarArchivosCSV);
        cajaDeDatosDelArchivoCSV->setObjectName(QString::fromUtf8("cajaDeDatosDelArchivoCSV"));
        cajaDeDatosDelArchivoCSV->setGeometry(QRect(9, 9, 654, 60));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        cajaDeDatosDelArchivoCSV->setPalette(palette2);
        cajaDeDatosDelArchivoCSV->setFont(font);
        cajaDeDatosDelArchivoCSV->setAutoFillBackground(true);
        etiquetaNombre = new QLabel(cajaDeDatosDelArchivoCSV);
        etiquetaNombre->setObjectName(QString::fromUtf8("etiquetaNombre"));
        etiquetaNombre->setGeometry(QRect(12, 27, 45, 15));
        etiquetaNombre->setFont(font1);
        nombreDelArchivoCSVAImportar = new QLineEdit(cajaDeDatosDelArchivoCSV);
        nombreDelArchivoCSVAImportar->setObjectName(QString::fromUtf8("nombreDelArchivoCSVAImportar"));
        nombreDelArchivoCSVAImportar->setGeometry(QRect(66, 21, 450, 24));
        nombreDelArchivoCSVAImportar->setMinimumSize(QSize(0, 0));
        nombreDelArchivoCSVAImportar->setReadOnly(true);
        etiquetaPorcentajeDeAnalisis = new QLabel(cajaDeDatosDelArchivoCSV);
        etiquetaPorcentajeDeAnalisis->setObjectName(QString::fromUtf8("etiquetaPorcentajeDeAnalisis"));
        etiquetaPorcentajeDeAnalisis->setGeometry(QRect(528, 27, 57, 15));
        etiquetaPorcentajeDeAnalisis->setFont(font1);
        porcentajeDeAnalisis = new QProgressBar(cajaDeDatosDelArchivoCSV);
        porcentajeDeAnalisis->setObjectName(QString::fromUtf8("porcentajeDeAnalisis"));
        porcentajeDeAnalisis->setGeometry(QRect(591, 21, 45, 24));
        porcentajeDeAnalisis->setValue(0);
        botonCancelar = new QPushButton(DialogoParaImportarArchivosCSV);
        botonCancelar->setObjectName(QString::fromUtf8("botonCancelar"));
        botonCancelar->setGeometry(QRect(468, 450, 84, 21));
        botonCancelar->setFont(font);
        botonAceptar = new QPushButton(DialogoParaImportarArchivosCSV);
        botonAceptar->setObjectName(QString::fromUtf8("botonAceptar"));
        botonAceptar->setEnabled(false);
        botonAceptar->setGeometry(QRect(561, 450, 84, 21));
        botonAceptar->setFont(font);
        botonAceptar->setDefault(true);

        retranslateUi(DialogoParaImportarArchivosCSV);

        QMetaObject::connectSlotsByName(DialogoParaImportarArchivosCSV);
    } // setupUi

    void retranslateUi(QDialog *DialogoParaImportarArchivosCSV)
    {
        DialogoParaImportarArchivosCSV->setWindowTitle(QApplication::translate("DialogoParaImportarArchivosCSV", "Importar archivo CSV", 0, QApplication::UnicodeUTF8));
        cajaDeDatos->setTitle(QApplication::translate("DialogoParaImportarArchivosCSV", "Datos", 0, QApplication::UnicodeUTF8));
        etiquetaNumeroDeCasos->setText(QApplication::translate("DialogoParaImportarArchivosCSV", "# casos", 0, QApplication::UnicodeUTF8));
        numeroDeCasos->setText(QString());
        etiquetaPorcentajeDeVaciado->setText(QApplication::translate("DialogoParaImportarArchivosCSV", "% vaciado", 0, QApplication::UnicodeUTF8));
        cajaDeVariables->setTitle(QApplication::translate("DialogoParaImportarArchivosCSV", "Variables", 0, QApplication::UnicodeUTF8));
        variablesEnPrimeraFila->setText(QApplication::translate("DialogoParaImportarArchivosCSV", "variables en la primera l\303\255nea", 0, QApplication::UnicodeUTF8));
        numeroDeVariables->setText(QString());
        etiquetaNumeroDeVariables->setText(QApplication::translate("DialogoParaImportarArchivosCSV", "# variables", 0, QApplication::UnicodeUTF8));
        cajaDeDatosDelArchivoCSV->setTitle(QApplication::translate("DialogoParaImportarArchivosCSV", "Datos del archivo CSV", 0, QApplication::UnicodeUTF8));
        etiquetaNombre->setText(QApplication::translate("DialogoParaImportarArchivosCSV", "Nombre", 0, QApplication::UnicodeUTF8));
        etiquetaPorcentajeDeAnalisis->setText(QApplication::translate("DialogoParaImportarArchivosCSV", "% an\303\241lisis", 0, QApplication::UnicodeUTF8));
        botonCancelar->setText(QApplication::translate("DialogoParaImportarArchivosCSV", "Cancelar", 0, QApplication::UnicodeUTF8));
        botonAceptar->setText(QApplication::translate("DialogoParaImportarArchivosCSV", "Aceptar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogoParaImportarArchivosCSV: public Ui_DialogoParaImportarArchivosCSV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOPARAIMPORTARARCHIVOSCSV_H
