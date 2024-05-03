#ifndef STAR8_H
#define STAR8_H

#include <shape.h>

class star8 : public shape
{
    Q_OBJECT
public:
    explicit star8(QPointF point, QObject *parent = 0);
    QRectF boundingRect() const override;
private:
    double getSquare();
    double getPerim();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // STAR8_H
