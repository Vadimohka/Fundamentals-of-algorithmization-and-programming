#include "paintscene.h"

paintScene::paintScene(QObject *parent)
    : QGraphicsScene{parent}
{

}

paintScene::~paintScene()
{

}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse(event -> scenePos().x() - 5,
               event -> scenePos().y() - 5,
               1,
               1,
               QPen(Qt::NoPen),
               QBrush(Qt::black));
    previouspoint = event -> scenePos();
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPen pen(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    addLine(previouspoint.x(),
            previouspoint.y(),
            event -> scenePos().x(),
            event -> scenePos().y(),
            pen);
    previouspoint = event -> scenePos();
}
