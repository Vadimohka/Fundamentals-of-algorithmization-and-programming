#ifndef ROMB_H
#define ROMB_H


#include <figure.h>
#include <QPainter>

class Romb1 : public Figure
{
    Q_OBJECT
public:
    explicit Romb1(QPointF point, QObject *parent = nullptr) : Figure(point, parent) {}
    ~Romb1() override = default;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ROMB_H
