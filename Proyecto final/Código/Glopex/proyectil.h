#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>

class Proyectil:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Proyectil(QGraphicsItem * parent=0);
    int tipo;
    float g;
    float posx, posy, velx, vely,dt;
    float fric;
    int maxvel;
    int minvel;

public slots:
    void move();

};

#endif // PROYECTIL_H
