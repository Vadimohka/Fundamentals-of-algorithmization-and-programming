#include "rectanleitem.h"
#include <QPainter>

RectangleItem::RectangleItem(int value, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsItem(parent), m_value(value), m_width(width), m_height(height) {}

QRectF RectangleItem::boundingRect() const {
    return QRectF(0, 0, m_width, m_height);
}

void RectangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Calculate the height based on the value
    qreal height = m_height * m_value / 10.0; // Assuming the maximum value is 10

    // Drawing a rectangle with adjusted height
    painter->drawRect(0, m_height - height, m_width, height);

    // Drawing the value inside the rectangle
    QString text = QString::number(m_value);
    painter->drawText(boundingRect(), Qt::AlignCenter, text);
}
