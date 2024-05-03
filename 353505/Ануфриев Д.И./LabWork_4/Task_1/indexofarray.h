#ifndef INDEXOFARRAY_H
#define INDEXOFARRAY_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QGraphicsItem>

class IndexOfArray : public QGraphicsItem
{
public:
    IndexOfArray(qreal pos_x, qreal pos_y, qreal width, qreal height, QColor color);

    void setColor(QColor color);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:
    qreal width, height;
    QColor color;

    qreal pos_x, pos_y;
};

#endif // INDEXOFARRAY_H
