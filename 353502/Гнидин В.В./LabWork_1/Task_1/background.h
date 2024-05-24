//
// Created by volodya-petarda on 3/3/24.
//

#ifndef GALAVA_BACKGROUND_H
#define GALAVA_BACKGROUND_H


#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsObject>

class background : public QGraphicsObject {
public:
    [[nodiscard]] QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};


#endif //GALAVA_BACKGROUND_H
