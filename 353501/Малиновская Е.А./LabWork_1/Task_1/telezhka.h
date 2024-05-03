#ifndef TELEZHKA_H
#define TELEZHKA_H
#include "moving_rectangle.h"
#include <QPainter>
#include <QGraphicsItem>

class telezhka : public moving_rectangle {
public:
    telezhka(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
protected:
    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // TELEZHKA_H
