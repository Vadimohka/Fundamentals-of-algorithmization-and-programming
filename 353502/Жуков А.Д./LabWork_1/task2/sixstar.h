#ifndef SIXSTAR_H
#define SIXSTAR_H

#include <figure.h>
#include <QPainter>

class SixStar : public Figure
{
public:
    explicit SixStar(QPointF point, QObject *parent = nullptr) : Figure(point, parent) {}
    ~SixStar() override = default;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SIXSTAR_H
