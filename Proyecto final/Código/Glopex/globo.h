#ifndef GLOBO_H
#define GLOBO_H

#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsItem>

class Globo:public QGraphicsItem
{

public:
    Globo();
    void keyPressEvent(QKeyEvent * event);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setDirection(int dir);
    QPixmap imagen;
    int direccion; // 1 derecha, 2 izquierda, 3 arriba
    int X,Y,height,width, posx, posy;

    void move();

};

#endif // GLOBO_H
