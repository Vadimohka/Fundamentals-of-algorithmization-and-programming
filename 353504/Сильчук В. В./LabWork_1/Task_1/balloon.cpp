#include "balloon.h"

Balloon::Balloon(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) : Movingellipse(x, y, width, height, parent) {
    geometry = rect();
    balloonHeight = rect().height();
}

void Balloon::burst(){
    if(geometry.width() / 2 * scale > 10){
        scale*=0.9;
        isBursted = true;
    }
    else{
        emit stopTimer2();
    }
}

void Balloon::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(Qt::red);
    painter->drawEllipse(geometry.center(), geometry.width() / 2 * scale, geometry.height() / 2 * scale);

    if(!isBursted){
        int side = 10;

        int HighYVertex = rect().center().y() + (balloonHeight/2);
        int HighXVertex = rect().center().x();

        int LowYVertex = rect().center().y() + (balloonHeight/2) + side;
        int LowXVertexLeft  = rect().center().x() - (side / 2);
        int LowXVertexRight = rect().center().x() + (side / 2);

        QPolygonF triangle;
        triangle << QPointF(HighXVertex, HighYVertex) << QPointF(LowXVertexLeft, LowYVertex) << QPointF(LowXVertexRight, LowYVertex);
        painter->drawPolygon(triangle);

        // Рисование ниточки (линии)
        QPointF center = rect().center();
        painter->setPen(Qt::white);
        painter->drawLine(center.x(), LowYVertex, center.x(), LowYVertex + 90);
        painter->setRenderHint(QPainter::Antialiasing);
    }
}
