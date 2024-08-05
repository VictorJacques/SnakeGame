#include "ball.h"
#include <QDebug>
#include <QKeyEvent>

Ball::Ball(qreal x, qreal y,
           qreal width, qreal height,
           QGraphicsItem *parent): QGraphicsRectItem(x,y,width,height,parent)
{
    qDebug() << "Ball constructed!";
    acceleration.setX(0);
    acceleration.setY(0);
}

void Ball::advance(int phase)
{
    if(phase == 0)
        return;

    position.setX(pos().x());
    position.setY(pos().y());

    position += velocity;
    velocity += acceleration;

    if(position.y() > 300)
        position.setY(-300);
    if(position.x() > 300)
        position.setX(-300);
    if(position.y() < -300)
        position.setY(300);
    if(position.x() < -300)
        position.setX(300);


    setPos(position.toPointF());
}

void Ball::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key Press Event in Ball";

    if( event->key() == Qt::Key_Left){
        position.setX(position.x()-40);
    }
    if( event->key() == Qt::Key_Right){
        position.setX(position.x()+40);
    }
    if( event->key() == Qt::Key_Up){
        position.setY(position.y()-40);
    }
    if( event->key() == Qt::Key_Down){
        position.setY(position.y()+40);
    }
    if( event->key() == Qt::Key_R){
        position.setX(0);
        position.setY(0);
    }

    setPos(position.toPointF());

}
