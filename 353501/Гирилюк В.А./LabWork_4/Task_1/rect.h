#ifndef RECT_H
#define RECT_H

#include <QGraphicsObject>
#include <QPainter>

class Rect: public QGraphicsItem
{
    int x = 0, y = 0, h = 0, w = 0;
public:
    Rect();
    Rect(Rect& other);
    ~Rect();
    bool aim = false;
    void setParam(int x, int y, int w, int h);
    Rect& operator=(Rect& other);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
#endif // RECT_H
