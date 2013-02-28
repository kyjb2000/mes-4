/********************************************************************************
** Form generated from reading UI file 'dialogodevaciadodelarchivocsv.ui'
**
** Created: Mon Nov 5 11:40:46 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGODEVACIADODELARCHIVOCSV_H
#define UI_DIALOGODEVACIADODELARCHIVOCSV_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogoDeVaciadoDelArchivoCSV
{
public:
    QPushButton *botonCancelar;
    QLabel *etiquetaImportandoArchivoCSV;
    QProgressBar *progresoDeVaciadoDelArchivoCSV;

    void setupUi(QDialog *DialogoDeVaciadoDelArchivoCSV)
    {
        if (DialogoDeVaciadoDelArchivoCSV->objectName().isEmpty())
            DialogoDeVaciadoDelArchivoCSV->setObjectName(QString::fromUtf8("DialogoDeVaciadoDelArchivoCSV"));
        DialogoDeVaciadoDelArchivoCSV->setWindowModality(Qt::ApplicationModal);
        DialogoDeVaciadoDelArchivoCSV->resize(300, 90);
        botonCancelar = new QPushButton(DialogoDeVaciadoDelArchivoCSV);
        botonCancelar->setObjectName(QString::fromUtf8("botonCancelar"));
        botonCancelar->setGeometry(QRect(111, 60, 84, 24));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        botonCancelar->setFont(font);
        etiquetaImportandoArchivoCSV = new QLabel(DialogoDeVaciadoDelArchivoCSV);
        etiquetaImportandoArchivoCSV->setObjectName(QString::fromUtf8("etiquetaImportandoArchivoCSV"));
        etiquetaImportandoArchivoCSV->setGeometry(QRect(69, 9, 180, 18));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        etiquetaImportandoArchivoCSV->setFont(font1);
        progresoDeVaciadoDelArchivoCSV = new QProgressBar(DialogoDeVaciadoDelArchivoCSV);
        progresoDeVaciadoDelArchivoCSV->setObjectName(QString::fromUtf8("progresoDeVaciadoDelArchivoCSV"));
        progresoDeVaciadoDelArchivoCSV->setGeometry(QRect(30, 30, 246, 24));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(9);
        progresoDeVaciadoDelArchivoCSV->setFont(font2);
        progresoDeVaciadoDelArchivoCSV->setMaximum(10000);
        progresoDeVaciadoDelArchivoCSV->setValue(0);

        retranslateUi(DialogoDeVaciadoDelArchivoCSV);

        QMetaObject::connectSlotsByName(DialogoDeVaciadoDelArchivoCSV);
    } // setupUi

    void retranslateUi(QDialog *DialogoDeVaciadoDelArchivoCSV)
    {
        DialogoDeVaciadoDelArchivoCSV->setWindowTitle(QString());
        botonCancelar->setText(QApplication::translate("DialogoDeVaciadoDelArchivoCSV", "Cancelar", 0, QApplication::UnicodeUTF8));
        etiquetaImportandoArchivoCSV->setText(QApplication::translate("DialogoDeVaciadoDelArchivoCSV", "Importando archivo CSV", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogoDeVaciadoDelArchivoCSV: public Ui_DialogoDeVaciadoDelArchivoCSV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGODEVACIADODELARCHIVOCSV_H
