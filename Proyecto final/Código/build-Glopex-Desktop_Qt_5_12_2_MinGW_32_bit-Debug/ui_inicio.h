/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inicio
{
public:
    QLabel *logo;
    QLabel *decision_label;
    QPushButton *iniciarsesion_button;
    QPushButton *registrarse_button;
    QPushButton *sinregistro_button;

    void setupUi(QWidget *inicio)
    {
        if (inicio->objectName().isEmpty())
            inicio->setObjectName(QString::fromUtf8("inicio"));
        inicio->resize(693, 480);
        logo = new QLabel(inicio);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(170, 50, 341, 151));
        QFont font;
        font.setPointSize(79);
        logo->setFont(font);
        decision_label = new QLabel(inicio);
        decision_label->setObjectName(QString::fromUtf8("decision_label"));
        decision_label->setGeometry(QRect(270, 200, 151, 21));
        QFont font1;
        font1.setPointSize(13);
        decision_label->setFont(font1);
        iniciarsesion_button = new QPushButton(inicio);
        iniciarsesion_button->setObjectName(QString::fromUtf8("iniciarsesion_button"));
        iniciarsesion_button->setGeometry(QRect(270, 240, 131, 23));
        registrarse_button = new QPushButton(inicio);
        registrarse_button->setObjectName(QString::fromUtf8("registrarse_button"));
        registrarse_button->setGeometry(QRect(270, 280, 131, 23));
        sinregistro_button = new QPushButton(inicio);
        sinregistro_button->setObjectName(QString::fromUtf8("sinregistro_button"));
        sinregistro_button->setGeometry(QRect(270, 320, 131, 23));

        retranslateUi(inicio);

        QMetaObject::connectSlotsByName(inicio);
    } // setupUi

    void retranslateUi(QWidget *inicio)
    {
        inicio->setWindowTitle(QApplication::translate("inicio", "Form", nullptr));
        logo->setText(QApplication::translate("inicio", "Glopex", nullptr));
        decision_label->setText(QApplication::translate("inicio", "\302\277Qu\303\251 desea hacer?", nullptr));
        iniciarsesion_button->setText(QApplication::translate("inicio", "Iniciar sesi\303\263n", nullptr));
        registrarse_button->setText(QApplication::translate("inicio", "Registrarse", nullptr));
        sinregistro_button->setText(QApplication::translate("inicio", "Jugar sin registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inicio: public Ui_inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
