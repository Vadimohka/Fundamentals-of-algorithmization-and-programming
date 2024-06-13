#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QPropertyAnimation>
#include <QDebug>


class Rectangle : public QGraphicsItem, public QObject
{

public:
    int x_;
    int y_;
    int width_;
    int height_;
    int xspeed = 1;
    Rectangle(int x = 240, int y = 200, int width = 160, int height = 100);
    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

public slots:
    virtual void move();
    virtual void moveBack();
};
#endif // RECTANGLE_H
