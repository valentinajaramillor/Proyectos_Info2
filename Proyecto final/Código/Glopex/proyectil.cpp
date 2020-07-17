#include "proyectil.h"

Proyectil::Proyectil(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    g=-9.8;
    dt=0.1;
    maxvel=100;
    minvel=10;

    int random_number1;
    random_number1 = rand() % 650;
    tipo = rand() % 4;
    if (tipo==1){
        posx=random_number1;
        posy=650;
        setPos(posx,-posy);
    }
    else if (tipo==2){
        posx=0;
        posy=random_number1;
        setPos(posx,-posy);
    }
    else if (tipo==3){
        posx=650;
        posy=random_number1;
        setPos(posx,-posy);
    }


    if (tipo==1){
        velx=0;
        vely= -1*(rand() % maxvel +minvel);
    }
    else if (tipo==2){
        velx= (rand() % maxvel +minvel);
        vely=0;
    }
    else if (tipo==3){
        velx= -1*(rand() % maxvel +minvel);
        vely=0;
    }


    //draw the bullet
    setPixmap(QPixmap("://imagenes glopex/triangulo.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}

void Proyectil::move()
{
    vely=vely+g*dt;
    posx=posx+velx*dt;
    posy=posy+vely*dt+(0.5)*g*dt*dt;
    setPos(posx,-posy);
}
