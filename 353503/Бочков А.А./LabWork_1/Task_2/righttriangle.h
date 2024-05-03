#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include <shape.h>

class rightTriangle : public shape
{
    Q_OBJECT
public:
    explicit rightTriangle(QPointF point, QObject *parent = 0);
private:
    double getSquare();
    double getPerim();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RIGHTTRIANGLE_H
