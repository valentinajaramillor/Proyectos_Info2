/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *nivel_label;
    QLCDNumber *nivel_lcd;
    QLabel *tiempo_label;
    QLCDNumber *tiempo_lcd;
    QPushButton *iniciar_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(896, 672);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(120, 0, 650, 650));
        nivel_label = new QLabel(centralwidget);
        nivel_label->setObjectName(QString::fromUtf8("nivel_label"));
        nivel_label->setGeometry(QRect(810, 40, 51, 31));
        QFont font;
        font.setPointSize(14);
        nivel_label->setFont(font);
        nivel_lcd = new QLCDNumber(centralwidget);
        nivel_lcd->setObjectName(QString::fromUtf8("nivel_lcd"));
        nivel_lcd->setGeometry(QRect(790, 70, 91, 51));
        nivel_lcd->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 25, 255);\n"
"font: 12pt \"Rockwell\";"));
        tiempo_label = new QLabel(centralwidget);
        tiempo_label->setObjectName(QString::fromUtf8("tiempo_label"));
        tiempo_label->setGeometry(QRect(800, 140, 71, 21));
        tiempo_label->setFont(font);
        tiempo_lcd = new QLCDNumber(centralwidget);
        tiempo_lcd->setObjectName(QString::fromUtf8("tiempo_lcd"));
        tiempo_lcd->setGeometry(QRect(790, 180, 91, 51));
        tiempo_lcd->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 25, 255);\n"
"font: 12pt \"Rockwell\";"));
        iniciar_button = new QPushButton(centralwidget);
        iniciar_button->setObjectName(QString::fromUtf8("iniciar_button"));
        iniciar_button->setGeometry(QRect(790, 300, 91, 51));
        QFont font1;
        font1.setPointSize(11);
        iniciar_button->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        nivel_label->setText(QApplication::translate("MainWindow", "Nivel", nullptr));
        tiempo_label->setText(QApplication::translate("MainWindow", "Tiempo", nullptr));
        iniciar_button->setText(QApplication::translate("MainWindow", "INICIAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
