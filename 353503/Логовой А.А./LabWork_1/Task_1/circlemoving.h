#ifndef CIRCLEMOVING_H
#define CIRCLEMOVING_H

#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QPainter>

class CircleMoving : public QGraphicsObject
{
    Q_OBJECT
protected:
    QRectF circle_;
    bool is_move = true;
    int rotate_angle{};

public:

    CircleMoving();
    QRectF boundingRect() const override ;
    virtual void paint(QPainter *paintert,const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void move();
    void turnOn();

};

#endif // CIRCLEMOVING_H
