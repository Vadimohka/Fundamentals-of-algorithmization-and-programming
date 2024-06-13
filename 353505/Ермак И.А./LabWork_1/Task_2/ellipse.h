#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <form.h>
#include <QPainter>
#include <QGraphicsObject>
#include <QColor>

class Ellipse : public form
{
    Q_OBJECT;
public:
    Ellipse(int x, int y, int rH, int rV, QColor bColor, QColor pColor);
    void paint(QPainter *paiter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    double perimetr();
    double square();
    void setScale(int radiusHScale, int radius2Vcale);
public slots:
    void Scale();
protected:
    int radiusHorisontal;
    int radiusVertical;
    int radiusHScal;
    int radiusVScal;
};

#endif // ELLIPSE_H
