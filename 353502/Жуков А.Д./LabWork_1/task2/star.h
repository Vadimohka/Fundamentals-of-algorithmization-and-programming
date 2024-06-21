#ifndef STAR_H
#define STAR_H

#include <figure.h>
#include <QPainter>

class Star : public Figure
{
    Q_OBJECT
public:
    explicit Star(int corners, QPointF point, QObject *parent = nullptr) : Figure(point, parent), crns(corners) {}
    ~Star() override = default;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    double crns;
};

#endif // STAR_H
