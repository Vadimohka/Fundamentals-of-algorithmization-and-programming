#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"
#include <QPainter>
class Circle : public figure
{
public:
    Circle();
    ~Circle();
    void initialization();
    int R, G, B;       // Цвет круга
    int PenSize;

private:
      // Толщина пера
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CIRCLE_H
