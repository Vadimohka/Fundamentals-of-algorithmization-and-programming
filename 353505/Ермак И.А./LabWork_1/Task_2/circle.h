#ifndef CIRCLE_H
#define CIRCLE_H

#include "form.h"
#include <QPainter>
#include <QGraphicsObject>
#include <QColor>

class Circle : public form
{
    Q_OBJECT;
public:
    Circle(int x, int y, int r, QColor bColor, QColor pColor);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    double perimetr();
    double square();
    void SetScale(int radiusScale);
public slots:
    void Scale();
protected:
    int radius;
    int radiusScal;
};

#endif // CIRCLE_H

