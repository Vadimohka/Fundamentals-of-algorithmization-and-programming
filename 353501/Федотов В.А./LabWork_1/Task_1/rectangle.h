#ifndef RECTANGLE_H
#define RECTANGLE_H

// #include <QGraphicsItem>
#include <QGraphicsObject>
#include <QObject>
#include <QPainter>
#include <QTimer>

class Rectangle : public QGraphicsObject
{
    Q_OBJECT
public:
    Rectangle();

    int floor;
    int shiftY;
    int targetY;

    QTimer *timer;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

signals:
    void floorChanged(int newFloor);
    void incrementComplete();

public slots:
    void setFloor(int floor);

    void handleFloorChange(int newFloor);
    void incrementYPosition();

};

#endif // RECTANGLE_H
