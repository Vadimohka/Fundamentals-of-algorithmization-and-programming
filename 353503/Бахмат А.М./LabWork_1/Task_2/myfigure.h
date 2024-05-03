#ifndef MYFIGURE_H
#define MYFIGURE_H

#include <QGraphicsItem>
#include <QPainter>

class MyFigure : public QGraphicsItem
{
public:
    MyFigure();
    virtual qreal Area();
    virtual qreal Perimeter();
    void changeCenterX(int centerX);
    void changeCenterY(int centerY);
    QPoint getCenter();
    void changeHeight(int newHeight);
    void changeWidth(int newWidth);
    void changeSize(int newSize);
    void changeRadius(int newRadius);
    void changeRadius1(int newRadius1);
    void changeRadius2(int newRadius2);
    void changeScale(int newScale);
    auto getScale() -> qreal;
    void makeFlagTrue();
    QPoint center;
    bool flag = true;
    const qreal _boundRectValue = 500;
    const qreal _value = 50;
    qreal radius1 = _value , radius2 = _value;
    qreal radius = 2 * _value;
    qreal height = 4 * _value;
    qreal width = 2 * _value;
    qreal size = _value;
    qreal scale = 1;
protected:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // MYFIGURE_H
