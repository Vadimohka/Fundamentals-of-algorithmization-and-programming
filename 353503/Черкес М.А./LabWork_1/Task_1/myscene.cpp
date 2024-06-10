#include "myscene.h"
#include "rectfigure.h"
#include<QGraphicsRotation>
MyScene::MyScene(QObject *parent)
    : QGraphicsScene{parent}
{

}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(!m_movingItem){
    tempfigure->setEndPoint(event->scenePos());
    this->update(QRectF(0,0,this->width(), this->height()));
    } else
    {
    m_movingItem->setTransformOriginPoint(m_movingItem->boundingRect().center());
    if(event->buttons() & Qt::LeftButton && rKeyPressed)
        {
        QPointF center = m_movingItem->boundingRect().center();
        QPointF diff = event->scenePos() - center;
        qreal angle = std::atan2(diff.y(), diff.x()) * 180 / M_PI;
        m_movingItem->setRotation(angle);
        }
       else
        {
        QPointF newPosInScene = event->scenePos();
        QPointF lastPosInScene = event->lastScenePos();
        QPointF diff = newPosInScene - lastPosInScene;

        m_movingItem->setPos(m_movingItem->pos() + diff);
        }
    }

}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_movingItem = nullptr;
}

void MyScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_R)
    {
        rKeyPressed = true;
    }
}

void MyScene::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_R)
    {
        rKeyPressed = false;
    }
}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    item = (abstractFigure*)itemAt(event->scenePos(),{});
    if(!item){
        RectFigure *item = new RectFigure(event->scenePos());
        item->setPos(event->pos());
        tempfigure = item;
        this->addItem(tempfigure);
    } else {
        if(event->button() == Qt::LeftButton && rKeyPressed)
        {
          m_movingItem = item;
            lastMousePos = event->scenePos();
        } else
        {
        m_movingItem = item;
        m_lastPos = item->pos();
        }
    }


}
