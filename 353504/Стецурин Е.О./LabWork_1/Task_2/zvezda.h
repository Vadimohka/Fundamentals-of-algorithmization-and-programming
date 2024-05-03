#ifndef ZVEZDA_H
#define ZVEZDA_H

#include "figure.h"
#include <QBrush>

class Zvezda5 : public Figure
{
public:
    Zvezda5(int radius1,int radius2, QGraphicsPolygonItem* parent = nullptr);
};

class Zvezda6 : public Figure
{
public:
    Zvezda6(int radius1,int radius2, QGraphicsPolygonItem* parent = nullptr);
};

class Zvezda8 : public Figure
{
public:
    Zvezda8(int radius1,int radius2, QGraphicsPolygonItem* parent = nullptr);
};

class ZvezdaDraw : public FigureDraw
{
    Q_OBJECT

public:
    explicit ZvezdaDraw(QPointF point, QGraphicsObject *parent = 0);
    ~ZvezdaDraw();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


#endif // ZVEZDA_H
