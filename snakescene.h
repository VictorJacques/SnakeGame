#ifndef SNAKESCENE_H
#define SNAKESCENE_H

#include <QGraphicsScene>
#include <QDebug>
#include "ball.h"

class SnakeScene : public QGraphicsScene
{
public:
    explicit SnakeScene(QObject *parent = nullptr);

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ball * _ball;
};

#endif // SNAKESCENE_H
