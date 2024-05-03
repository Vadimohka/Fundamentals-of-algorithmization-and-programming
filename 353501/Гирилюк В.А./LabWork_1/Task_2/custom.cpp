#include "custom.h"

Custom::Custom(QGraphicsItem *parent)
{
    setAcceptHoverEvents(true);
}

Custom::~Custom()
{

}

void Custom::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QColor::fromRgb(140, 0, 255), 5*current_Scale, Qt::SolidLine, Qt::RoundCap));
    for(int i = 0; i< points.size(); ++i){
        for(int j = 1; j< points[i].size(); ++j){
            painter->drawLine(current_Scale*points[i][j-1], current_Scale*points[i][j]);
        }
    }
    area = 0;
    perimeter = 0;
}

void Custom::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QVector<QPointF> newline;
    points.push_back(newline);
    points[currentline].push_back(QPointF(((event->scenePos().x()-pos().x())*cos(rotate/180*M_PI) + (event->scenePos().y()-pos().y())*sin(rotate/180*M_PI))/current_Scale, ((event->scenePos().y()-pos().y())*cos(rotate/180*M_PI) - (event->scenePos().x()-pos().x())*sin(rotate/180*M_PI))/current_Scale));
    update();
}

void Custom::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    points[currentline].push_back(QPointF(((event->scenePos().x()-pos().x())*cos(rotate/180*M_PI) + (event->scenePos().y()-pos().y())*sin(rotate/180*M_PI))/current_Scale, ((event->scenePos().y()-pos().y())*cos(rotate/180*M_PI) - (event->scenePos().x()-pos().x())*sin(rotate/180*M_PI))/current_Scale));
    update();
}

void Custom::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    currentline++;
}
