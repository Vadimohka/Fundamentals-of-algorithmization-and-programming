#ifndef CIRCLE_H
#define CIRCLE_H


#include <figure.h>
#include <QPainter>

class Circle : public Figure
{
    Q_OBJECT
public:
    explicit Circle(QPointF point, QObject *parent = nullptr) : Figure(point, parent) {}
    ~Circle() override = default;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // CIRCLE_H
