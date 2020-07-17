#include "inicio.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    inicio o;
    o.show();
    return a.exec();
}
