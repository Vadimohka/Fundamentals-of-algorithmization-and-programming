//
// Created by darina on 4/10/24.
//

#ifndef TASK4_MOVINGRECTANGLE_H
#define TASK4_MOVINGRECTANGLE_H

#include <QGraphicsObject>
#include <QWidget>
#include <QPainter>

class MovingRectangle: public QGraphicsObject{

public:
    explicit MovingRectangle(double x0, double y0, double width);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void move(int x, int y);
    int getX();
    int getY();
    int getW();


private:
    double x, y, w;
    const double h = 10;

protected:


};

#endif //TASK4_MOVINGRECTANGLE_H
