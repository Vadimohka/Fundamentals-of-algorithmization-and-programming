#ifndef CLEAR_SCENE_H
#define CLEAR_SCENE_H
#include "shape.h"
#include <QPainter>
#include <QGraphicsItem>

class Clear_scene : public Shape
{

public:
    Clear_scene();
    qreal calculateArea() override;
    qreal calculatePerimeter() override;
    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
};

#endif // CLEAR_SCENE_H
