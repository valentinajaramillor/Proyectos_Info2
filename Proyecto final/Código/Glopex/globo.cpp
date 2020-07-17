#include "globo.h"
#include "proyectil.h"
#include "gloyectil.h"

Globo::Globo(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    X=40;
    Y=40;
    height = 80;
    width = 80;

    setPixmap(QPixmap(":/imagenes glopex/globo rojo.png"));
}

void Globo::move()
{
    if (direccion==1){
        setPos(x()+10,y());

    }
    else if (direccion==2){
        setPos(x()-10,y());

    }
    else if (direccion==3){
        setPos(x(),y()-10);

    }
}

void Globo::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Right){
        //if(pos().x()+(width/2)<650)
            direccion=1;
            this->move();
    }
    else if (event->key() == Qt::Key_Left){
        //if(pos().x()-(width/2)>0)
            direccion=2;
            this->move();
    }
    else if (event->key() == Qt::Key_Up){
        direccion=3;
        this->move();
    }
    else if (event->key() == Qt::Key_S){    //bala arriba
        Gloyectil * gloyectil = new Gloyectil();
        gloyectil->setdireccion(1);

        gloyectil->calcular();


        gloyectil->setPosx(x()+35);
        gloyectil->setPosy(y());
        gloyectil->setPos(x()+35,y());


        scene()->addItem(gloyectil);

    }
    else if (event->key() == Qt::Key_X){      //bala derecha
        Gloyectil * gloyectil = new Gloyectil();
        gloyectil->setdireccion(2);

        gloyectil->calcular();


        gloyectil->setPosx(x()+70);
        gloyectil->setPosy(y()+20);
        gloyectil->setPos(x()+70,y()+20);


        scene()->addItem(gloyectil);

    }
    else if (event->key() == Qt::Key_Z){         //bala izquierda
        Gloyectil * gloyectil = new Gloyectil();
        gloyectil->setdireccion(3);

        gloyectil->calcular();

        gloyectil->setPosx(x());
        gloyectil->setPosy(y()+20);
        gloyectil->setPos(x(),y()+20);


        scene()->addItem(gloyectil);

    }
}


