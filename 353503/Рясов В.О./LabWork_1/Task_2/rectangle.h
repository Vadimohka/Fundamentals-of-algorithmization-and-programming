#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QGraphicsItem>
#include <QObject>

#include "figure.h"

class Rectangle : public Figure
{
    Q_OBJECT

public:
    explicit Rectangle(QPointF point, QObject *parent = nullptr);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RECTANGLE_H
