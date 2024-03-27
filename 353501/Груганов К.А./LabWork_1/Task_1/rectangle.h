#ifndef RECTANGLE_H
#define RECTANGLE_H

#include<QGraphicsRectItem>
#include<QPainter>
#include<QTimer>
#include<QGraphicsScene>
#include <QPushButton>
class Rectangle:public QGraphicsRectItem,public QObject
{

public:
    Rectangle();
    ~Rectangle();
    void moveLeft();
    void moveRight();
    void Stop();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
    QTimer* timer1;
    QTimer*timer2;

};

#endif // RECTANGLE_H
