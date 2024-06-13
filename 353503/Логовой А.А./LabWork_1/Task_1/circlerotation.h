#ifndef CIRCLEROTATION_H
#define CIRCLEROTATION_H

#include "circlemoving.h"
#include <QPainter>
#include <QGraphicsView>
class CircleRotation : public CircleMoving
{
public:
    CircleRotation();
    void rotation(QPainter* painter, QGraphicsScene* scene) ;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    QGraphicsView*view;
    QGraphicsScene* scene;
    QTransform * transfrom;
    QGraphicsScene cinema;
    QPainter* painter;
    CircleRotation* circleRotate;
    QStyleOptionGraphicsItem *item;
    QWidget *widget;
    int change_angle{};
    bool is_push_button;
    void pushOn();


protected:
    int angle_rotation =0 ;
};

#endif  CIRCLEROTATION_H
