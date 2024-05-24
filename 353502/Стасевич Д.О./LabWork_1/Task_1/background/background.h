//
// Created by darina on 3/3/24.
//

#ifndef LAB_BACKGROUND_H
#define LAB_BACKGROUND_H

#include <QGraphicsObject>

class Background: public QGraphicsObject{
public:
    Background();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};



#endif //LAB_BACKGROUND_H
