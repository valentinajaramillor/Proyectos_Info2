#ifndef GLOYECTIL_H
#define GLOYECTIL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>

class Gloyectil:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Gloyectil(QGraphicsItem * parent=0);
    void calcular();
    void setPosx(int posx_);
    void setPosy(int posy_);
    void setdireccion(int dir);

private:
    float g;
    float posx, posy, velx, vely,dt;
    float fric;
    int direccion;
    QTimer * timer;

public slots:
    void move();
};

#endif // GLOYECTIL_H
