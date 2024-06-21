#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <figure.h>
#include <QPainter>

class Rectangle : public Figure
{
    Q_OBJECT
public:
    explicit Rectangle(QPointF point, QObject *parent = nullptr) : Figure(point, parent) {}
    ~Rectangle() override = default;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RECTANGLE_H
