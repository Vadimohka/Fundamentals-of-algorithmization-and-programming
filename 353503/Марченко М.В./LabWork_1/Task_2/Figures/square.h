#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include <Figures/rectangle.h>

class Square : public Figure
{
    Q_OBJECT

public:
    explicit Square(QPointF point, QObject *parent = 0);
    ~Square();
    long double GetArea();
    long double GetPerimeter();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SQUARE_H
