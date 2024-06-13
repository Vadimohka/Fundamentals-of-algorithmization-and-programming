#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <shape.h>

class rectangle : public shape
{
    Q_OBJECT
public:
    explicit rectangle(QPointF point, QObject *parent = 0);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RECTANGLE_H
