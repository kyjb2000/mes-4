/********************************************************************************
** Form generated from reading UI file 'dialogoparaguardararchivodedatossiono.ui'
**
<<<<<<< HEAD
** Created: Tue Mar 5 12:47:21 2013
=======
<<<<<<< HEAD
** Created: Tue Feb 26 11:33:57 2013
**      by: Qt User Interface Compiler version 4.8.2
=======
** Created: Mon Mar 4 12:45:49 2013
>>>>>>> f969703cb223799254a551f2fe16dfc250f0d13f
**      by: Qt User Interface Compiler version 4.7.4
>>>>>>> ab210070f27e857d96696d3b2896d8ab005b9ff9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOPARAGUARDARARCHIVODEDATOSSIONO_H
#define UI_DIALOGOPARAGUARDARARCHIVODEDATOSSIONO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogoParaGuardarArchivoDeDatosSiONo
{
public:
    QLabel *etiquetaDeseaGuardarElARchivoDeDatosActual;
    QPushButton *botonNo;
    QPushButton *botonSi;
    QLabel *etiquetaDeseaGuardarElARchivoDeDatosActual_2;

    void setupUi(QDialog *DialogoParaGuardarArchivoDeDatosSiONo)
    {
        if (DialogoParaGuardarArchivoDeDatosSiONo->objectName().isEmpty())
            DialogoParaGuardarArchivoDeDatosSiONo->setObjectName(QString::fromUtf8("DialogoParaGuardarArchivoDeDatosSiONo"));
        DialogoParaGuardarArchivoDeDatosSiONo->setWindowModality(Qt::ApplicationModal);
        DialogoParaGuardarArchivoDeDatosSiONo->resize(291, 99);
        etiquetaDeseaGuardarElARchivoDeDatosActual = new QLabel(DialogoParaGuardarArchivoDeDatosSiONo);
        etiquetaDeseaGuardarElARchivoDeDatosActual->setObjectName(QString::fromUtf8("etiquetaDeseaGuardarElARchivoDeDatosActual"));
        etiquetaDeseaGuardarElARchivoDeDatosActual->setGeometry(QRect(39, 18, 219, 15));
        botonNo = new QPushButton(DialogoParaGuardarArchivoDeDatosSiONo);
        botonNo->setObjectName(QString::fromUtf8("botonNo"));
        botonNo->setGeometry(QRect(51, 60, 84, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setItalic(false);
        botonNo->setFont(font);
        botonSi = new QPushButton(DialogoParaGuardarArchivoDeDatosSiONo);
        botonSi->setObjectName(QString::fromUtf8("botonSi"));
        botonSi->setGeometry(QRect(150, 60, 84, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setBold(false);
        font1.setWeight(50);
        botonSi->setFont(font1);
        etiquetaDeseaGuardarElARchivoDeDatosActual_2 = new QLabel(DialogoParaGuardarArchivoDeDatosSiONo);
        etiquetaDeseaGuardarElARchivoDeDatosActual_2->setObjectName(QString::fromUtf8("etiquetaDeseaGuardarElARchivoDeDatosActual_2"));
        etiquetaDeseaGuardarElARchivoDeDatosActual_2->setGeometry(QRect(40, 39, 101, 16));
        botonNo->raise();
        etiquetaDeseaGuardarElARchivoDeDatosActual->raise();
        botonSi->raise();
        etiquetaDeseaGuardarElARchivoDeDatosActual_2->raise();

        retranslateUi(DialogoParaGuardarArchivoDeDatosSiONo);

        QMetaObject::connectSlotsByName(DialogoParaGuardarArchivoDeDatosSiONo);
    } // setupUi

    void retranslateUi(QDialog *DialogoParaGuardarArchivoDeDatosSiONo)
    {
        DialogoParaGuardarArchivoDeDatosSiONo->setWindowTitle(QApplication::translate("DialogoParaGuardarArchivoDeDatosSiONo", "Guardar archivo de datos actual", 0, QApplication::UnicodeUTF8));
        etiquetaDeseaGuardarElARchivoDeDatosActual->setText(QApplication::translate("DialogoParaGuardarArchivoDeDatosSiONo", "\302\277Desea guardar el archivo de", 0, QApplication::UnicodeUTF8));
        botonNo->setText(QApplication::translate("DialogoParaGuardarArchivoDeDatosSiONo", "No", 0, QApplication::UnicodeUTF8));
        botonSi->setText(QApplication::translate("DialogoParaGuardarArchivoDeDatosSiONo", "S\303\255", 0, QApplication::UnicodeUTF8));
        etiquetaDeseaGuardarElARchivoDeDatosActual_2->setText(QApplication::translate("DialogoParaGuardarArchivoDeDatosSiONo", "datos actual?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogoParaGuardarArchivoDeDatosSiONo: public Ui_DialogoParaGuardarArchivoDeDatosSiONo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOPARAGUARDARARCHIVODEDATOSSIONO_H
