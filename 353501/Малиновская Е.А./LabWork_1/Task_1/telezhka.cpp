#include "telezhka.h"
#include <QPainter>

telezhka::telezhka(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) :
    moving_rectangle(x,y,width,height, parent){
}

void telezhka :: paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter -> setBrush(Qt::blue);                     //drawing body
    int x{0}, y{0}, width{300}, height{200};
    painter -> drawRect(x,y,width,height);
    painter -> setBrush(Qt::black);                     //drawing wheels
    painter -> drawEllipse(x + 20, y + 180, 50,50);
    painter -> drawEllipse(x + 220, y + 180, 50,50);
}
