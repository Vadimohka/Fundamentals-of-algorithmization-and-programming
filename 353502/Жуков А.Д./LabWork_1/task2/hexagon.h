#ifndef HEXAGON_H
#define HEXAGON_H

#include <figure.h>
#include <QPainter>

class Hexagon : public Figure
{
    Q_OBJECT
public:
    explicit Hexagon(QPointF point, QObject *parent = nullptr) : Figure(point, parent) {}
    ~Hexagon() override = default;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // HEXAGON_H
