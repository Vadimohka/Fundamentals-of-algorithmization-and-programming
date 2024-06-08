#ifndef PLANE_H
#define PLANE_H

#include <movingrect.h>

class Plane : public movingrect
{
    Q_OBJECT

public:
    Plane(QObject *parent = nullptr);
    void lowerGear();
    void unLowerGear();
    QTimer *timer;
private:
    QGraphicsRectItem *rect1;
    QGraphicsRectItem *rect2;
    QGraphicsEllipseItem *wheel1;
    QGraphicsEllipseItem *wheel2;
    QGraphicsRectItem *wing1;
    QGraphicsRectItem *wing2;
    QGraphicsEllipseItem *cabin;
    bool lowered;
    void paintp(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;
    qreal rotation;
private slots:
    void lower();
    void unlower();
};

#endif // PLANE_H
