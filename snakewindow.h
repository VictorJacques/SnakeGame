#ifndef SNAKEWINDOW_H
#define SNAKEWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>
#include "ball.h"

class SnakeWindow : public QWidget
{
    Q_OBJECT

public:
    SnakeWindow(QWidget *parent = nullptr);
    ~SnakeWindow();

private:
    QGraphicsScene * _scene;
    QGraphicsView  * _view;

    Ball           * _ball;

    QTimer         * _timer;

    QVBoxLayout    * _layout;

};
#endif // SNAKEWINDOW_H