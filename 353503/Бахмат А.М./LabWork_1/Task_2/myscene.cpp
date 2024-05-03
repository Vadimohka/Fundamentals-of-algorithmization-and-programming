#include "myscene.h"

MyScene::MyScene(QObject* parent) : QGraphicsScene(parent) {}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    if(mouse -> button() == Qt::LeftButton)
    {
        _isMouseHelding = true;
        /*emit*/ mousePressed(mouse -> scenePos());
    }
    QGraphicsScene::mousePressEvent(mouse);
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    if(mouse -> button() == Qt::LeftButton)
    {
        _isMouseHelding = false;
    }
    QGraphicsScene::mouseReleaseEvent(mouse);
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    if(_isMouseHelding)
    {
        mousePressed(mouse -> scenePos());
    }
    QGraphicsScene::mouseMoveEvent(mouse);
}


