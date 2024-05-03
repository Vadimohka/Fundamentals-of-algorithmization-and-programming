#ifndef MOVINGRECT_H
#define MOVINGRECT_H

#include "QGraphicsObject"
#include "QPoint"

class MovingRect : public QGraphicsObject
{
    Q_OBJECT
protected:
    QRectF rect_;
    bool is_move;

public:
    explicit MovingRect(QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void move();
    void turnOnMove();

};

#endif // MOVINGRECT_H
