#include "snakescene.h"
#include <QKeyEvent>

SnakeScene::SnakeScene(QObject *parent)
    : QGraphicsScene{parent}
{
    _ball = new Ball(-10,-10,20,20);
    _ball->setBrush(QColor(43,51,24,255));
    addItem(_ball);

    _ball->setScale(2);

    _ball->setFlag(QGraphicsItem::ItemIsMovable);
    _ball->setFlag(QGraphicsItem::ItemIsFocusable);
    _ball->setFocus();

}

void SnakeScene::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key Press Event in SnakeScene";

    if( event->key() == Qt::Key_Left){
        _ball->setVelocity(QVector2D(-40,0));
    }
    if( event->key() == Qt::Key_Right){
        _ball->setVelocity(QVector2D(+40,0));
    }
    if( event->key() == Qt::Key_Up){
        _ball->setVelocity(QVector2D(0,-40));
    }
    if( event->key() == Qt::Key_Down){
        _ball->setVelocity(QVector2D(0,40));
    }
    if( event->key() == Qt::Key_R){
        //_ball->position.setX(0);
        //_ball->position.setY(0);
    }

    QGraphicsScene::keyPressEvent(event);
}
