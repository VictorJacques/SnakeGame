#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QVector2D>

class Ball : public QGraphicsRectItem
{
public:
    Ball(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    void advance(int phase) override;

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QVector2D position;
    QVector2D velocity;
    QVector2D acceleration;

};

#endif // BALL_H
