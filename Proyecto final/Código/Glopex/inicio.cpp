#include "inicio.h"
#include "ui_inicio.h"
#include "mainwindow.h"

inicio::inicio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);
}

inicio::~inicio()
{
    delete ui;
}

void inicio::on_iniciarsesion_button_clicked()
{

}

void inicio::on_registrarse_button_clicked()
{

}

void inicio::on_sinregistro_button_clicked()
{
    MainWindow *w = new MainWindow;
    w->show();
    this->close();
}
