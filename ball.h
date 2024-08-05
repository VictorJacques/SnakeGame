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

    void moveBy(QVector2D dir) { position += dir; }
    void setVelocity(QVector2D vel) { velocity = vel; }

private:
    QVector2D position;
    QVector2D velocity;
    QVector2D acceleration;

    unsigned int ttl;

};

#endif // BALL_H
