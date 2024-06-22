#ifndef RECTANGLEITEM_H
#define RECTANGLEITEM_H

#include <QGraphicsItem>

class RectangleItem : public QGraphicsItem
{
public:
    RectangleItem(int value, qreal width, qreal height, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int m_value;
    qreal m_width;
    qreal m_height;
};

#endif // RECTANGLEITEM_H
