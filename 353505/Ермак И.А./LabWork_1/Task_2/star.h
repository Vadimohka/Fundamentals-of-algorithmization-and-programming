#ifndef STAR_H
#define STAR_H

#include "form.h"
#include <QPainter>
#include <QGraphicsItem>
#include <QColor>
#include <QPainterPath>
class Star : public form
{
    Q_OBJECT;
public:
    Star(int x, int y, int s, QColor bColor, QColor pColor);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    double perimetr();
    double square();
    void setScale(int sideScale);
public slots:
    void Scale();
protected:
    int side;
    int sideScal;
};

#endif // STAR_H
