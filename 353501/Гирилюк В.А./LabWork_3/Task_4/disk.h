#ifndef DISK_H
#define DISK_H

#include <QGraphicsObject>
#include <QPainter>
#include <QTimer>

class Disk : public QGraphicsObject
{
public:
    int order;
    QTimer *timer;
    Disk();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setParams(int height, int width);
    void moveTo(int x, int y);
    void move();
private:
    int moveToX = 0;
    int moveToY = 0;
    int height;
    int width;
};

#endif // DISK_H
