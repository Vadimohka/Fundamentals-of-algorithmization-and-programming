//
// Created by u on 09.03.24.
//

#ifndef TELEGA_BACKGROUND_H
#define TELEGA_BACKGROUND_H


#include <QGraphicsObject>
#include <QPainter>

class background : public QGraphicsObject
{
public:
    [[nodiscard]] QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};


#endif //TELEGA_BACKGROUND_H
