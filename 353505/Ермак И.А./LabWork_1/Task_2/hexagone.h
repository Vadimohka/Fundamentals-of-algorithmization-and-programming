#ifndef HEXAGONE_H
#define HEXAGONE_H

#include "form.h"
#include <QColor>
#include <QPainter>
#include <QGraphicsItem>
#include <QPainterPath>

class Hexagone : public form
{
    Q_OBJECT;
public:
    Hexagone(int x, int y, int s, QColor bColor, QColor pColor);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    double square();
    double perimetr();
    void setScale(int sideScale);
public slots:
    void Scale();
protected:
    int side;
    int sideScal;
};

#endif // HEXAGONE_H

