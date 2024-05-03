#ifndef ELLIPS_H
#define ELLIPS_H

#include <shape.h>

class ellips : public shape
{
    Q_OBJECT
public:
    explicit ellips(QPointF point, QObject *parent = 0);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ELLIPS_H
