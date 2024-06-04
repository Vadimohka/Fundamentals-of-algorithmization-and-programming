//
// Created by darina on 4/10/24.
//

#ifndef TASK4_MOVINGRECTANGLE_H
#define TASK4_MOVINGRECTANGLE_H

#include <QGraphicsObject>
#include <QWidget>
#include <QPainter>

class Rectangle: public QGraphicsObject{

public:
    explicit Rectangle(double x0, double y0, double width);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getX() const;
    int getY() const;
    int getH() const;

private:
    int x, y, h;
    const int w = 10;

protected:


};

#endif //TASK4_MOVINGRECTANGLE_H
