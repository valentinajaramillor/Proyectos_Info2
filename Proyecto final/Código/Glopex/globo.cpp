#include "globo.h"
#include "proyectil.h"
#include "gloyectil.h"

Globo::Globo()
{
    X=40;
    Y=40;
    height = 80;
    width = 80;

}

QRectF Globo::boundingRect() const
{
    return QRect(-1*X,-1*Y, height, width);


}
void Globo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-1*X,-1*Y, height, width, QPixmap(":/imagenes glopex/globo rojo.png"));
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


        gloyectil->setPosx(x());
        gloyectil->setPosy(y());
        gloyectil->setPos(x(),y());


        scene()->addItem(gloyectil);

    }
    else if (event->key() == Qt::Key_X){      //bala derecha
        Gloyectil * gloyectil = new Gloyectil();
        gloyectil->setdireccion(2);

        gloyectil->calcular();


        gloyectil->setPosx(x());
        gloyectil->setPosy(y()-20);
        gloyectil->setPos(x(),y()-20);


        scene()->addItem(gloyectil);

    }
    else if (event->key() == Qt::Key_Z){         //bala izquierda
        Gloyectil * gloyectil = new Gloyectil();
        gloyectil->setdireccion(3);

        gloyectil->calcular();

        gloyectil->setPosx(x());
        gloyectil->setPosy(y()-20);
        gloyectil->setPos(x(),y()-20);


        scene()->addItem(gloyectil);

    }
}


