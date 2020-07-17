#include "inicio.h"
#include "mainwindow.h"

#include <QApplication>

MainWindow *w;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    inicio o;
    o.show();
    return a.exec();
}
