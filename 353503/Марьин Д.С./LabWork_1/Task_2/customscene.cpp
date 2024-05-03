#include "customscene.h"
#include "QtGui/qevent.h"
#include "QtWidgets/qgraphicsitem.h"

CustomScene::CustomScene(QObject *parent)
    : QGraphicsScene{parent}
{
    mousePos.setX(0);
    mousePos.setY(0);
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & (Qt::AllButtons))
    {
        mousePos.setX(event->scenePos().toPoint().x());
        mousePos.setY(event->scenePos().toPoint().y());
       qDebug()<<(QString("Mouse moving .... X :%1. Y:%2").arg(mousePos.x()).arg(mousePos.y()));
        emit signalMove(mousePos);
    }
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   mousePos.setX(event->scenePos().x());
   mousePos.setY(event->scenePos().y());
   qDebug()<<(QString("Mouse Pressed .... X :%1. Y:%2").arg(mousePos.x()).arg(mousePos.y()));
   if(event->button() == Qt::LeftButton)
        emit signalPressLeft(mousePos);
   if(event->button() == Qt::RightButton)
       emit signalPressRight(mousePos);
}

void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    mousePos.setX(event->scenePos().toPoint().x());
    mousePos.setY(event->scenePos().toPoint().y());
    emit signalRelease(mousePos);
}
void CustomScene::keyPressEvent(QKeyEvent *event)
{

    int key = event->key();
    QChar ch = event->text().at(0);
    qDebug() << "Key" << ch << "(" << key << ") was pressed";

    if (event->key() == 16777219 || event->key() == Qt::Key_Delete) //Delete button pressed
    {
        emit signalDelete();
    }
}
