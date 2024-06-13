#ifndef HANOIBRICK_H
#define HANOIBRICK_H

#include <QGraphicsRectItem>
#include <QPainter>

class HanoiBrick : public QGraphicsRectItem
{
    int _x, _y, _w, _h;
public:
    HanoiBrick();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void setParams(const int x, const int y, int width, int height);
    void setParams(int i);
    float scale = 1.0;
};

#endif // HANOIBRICK_H
