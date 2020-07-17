#include "gloyectil.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

Gloyectil::Gloyectil(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    g=9.8;
    dt=0.1;

    setPos(posx,posy);

    //draw the bullet
    setPixmap(QPixmap("://imagenes glopex/gloyectil rojo.png"));

    //connect
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

}

void Gloyectil::calcular()
{
    if (direccion==1){
        velx=0;
        vely=-80;
    }
    else if (direccion==2){
        velx=150;
        vely=0;
    }
    else if (direccion==3){
        velx=-150;
        vely=0;
    }

    timer->start(50);
}

void Gloyectil::setPosx(int posx_)
{
    posx=posx_;
}

void Gloyectil::setPosy(int posy_)
{
    posy=posy_;
}

void Gloyectil::setdireccion(int dir)
{
    direccion=dir;
}

void Gloyectil::move()
{

    vely=vely+g*dt;
    posx=posx+velx*dt;
    posy=posy+vely*dt+(0.5)*g*dt*dt;

    if (direccion==1){

        setPos(posx,posy);
    }
    else if (direccion==2){
        setPos(posx,posy);
    }
    else if (direccion==3){
        setPos(posx,posy);
    }

}
