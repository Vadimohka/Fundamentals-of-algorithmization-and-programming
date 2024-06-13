#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "figure.h"

#include <QGraphicsItem>
#include <QObject>

#include "figure.h"

class Ellipse : public Figure
{
    Q_OBJECT

public:
    explicit Ellipse(QPointF point, QObject *parent = nullptr);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ELLIPSE_H
