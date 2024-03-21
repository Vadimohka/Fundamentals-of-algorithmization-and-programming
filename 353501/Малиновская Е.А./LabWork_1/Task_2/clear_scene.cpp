#include "clear_scene.h"

Clear_scene::Clear_scene() {}

void Clear_scene::paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    int x{0}, y{0};
    QBrush brush(Qt::white);
    painter->setBrush(brush);
    painter->drawEllipse(x,y,1,1);
}

qreal Clear_scene::calculateArea(){
}

qreal Clear_scene::calculatePerimeter(){
}
