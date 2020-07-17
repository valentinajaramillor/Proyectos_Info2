#ifndef GLOBO_H
#define GLOBO_H

#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Globo:public QGraphicsPixmapItem
{

public:
    Globo(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
    void setDirection(int dir);
    QPixmap imagen;
    int direccion; // 1 derecha, 2 izquierda, 3 arriba
    int X,Y,height,width, posx, posy;

    void move();

};

#endif // GLOBO_H
