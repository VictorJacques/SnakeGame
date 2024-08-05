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

    ttl = 48;
}

void Ball::advance(int phase)
{
    if(phase == 0)
        return;

    //position.setX(pos().x());
    //position.setY(pos().y());

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


    //this->scene()->addItem(new Ball());

    setPos(position.toPointF());

    //if()
    //if(ttl-- == 0){
        // delete from scene
    //}
}
