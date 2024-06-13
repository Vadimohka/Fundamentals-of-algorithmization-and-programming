#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <form.h>
#include <QPainter>
#include <QColor>
#include <QPolygon>
#include <QPen>

class Triangle : public form
{
    Q_OBJECT;
public:
    Triangle(int x, int y, int b, int s, QColor bColor, QColor pColor);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    double square();
    double perimetr();
    void setScale(int baseScale,int sideScale);
public slots:
    void Scale();
protected:
    int base;
    int side;
    int baseScal;
    int sideScal;
};

#endif // TRIANGLE_H
