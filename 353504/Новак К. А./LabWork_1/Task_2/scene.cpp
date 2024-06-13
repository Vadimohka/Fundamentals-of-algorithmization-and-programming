#include "scene.h"

Scene::Scene(QObject *parent) {
    Q_UNUSED(parent);
}

QPointF Scene::getCenter() const
{
    if (currItem) {
        return currItem->center+currItem->delta;
    }
    return QPointF(0,0);
}

double Scene::getSquare() const
{
    if (currItem) {
        return currItem->square;
    }
    return 0;
}

double Scene::getPerim() const
{
    if (currItem) {
        return currItem->perim;
    }
    return 0;
}

void Scene::setTypeFigure(int x)
{
    typeFigure = x;
}

void Scene::setTypeAct(int x)
{
    typeAct = x;
}

int Scene::getTypeFigure()
{
    return typeFigure;
}

int Scene::getTypeAct()
{
    return typeAct;
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    //qDebug () << typeAct;
    if (currItem) {
    if (typeAct==0) {
        //qDebug () << currItem->getStartPoint().x() << currItem->getStartPoint().y() << currItem->getFinalPoint().x() << currItem->getFinalPoint().y();
        currItem->setFinalPoint(event->scenePos());
    }
    if (typeAct==1) {
        currItem->moveBy(event->scenePos().x()-event->lastScenePos().x(),event->scenePos().y()-event->lastScenePos().y());
        currItem->delta+=QPointF(event->scenePos().x()-event->lastScenePos().x(),event->scenePos().y()-event->lastScenePos().y());
    }
    currItem->update(qMin(currItem->getStartPoint().x(),currItem->getFinalPoint().x()),
                     qMin(currItem->getStartPoint().y(),currItem->getFinalPoint().y()),
                     currItem->length, currItem->width);
    }
    if (typeAct==4 && deleteFlag) {
        selectedItem = this->items(QPolygonF()
                                   << QPointF(event->scenePos().x(), event->scenePos().y())
                                   << QPointF(event->scenePos().x(), event->scenePos().y() + 1)
                                   << QPointF(event->scenePos().x() + 1, event->scenePos().y() + 1)
                                   << QPointF(event->scenePos().x() + 1, event->scenePos().y()));
        if (!selectedItem.empty()){
            removeItem(selectedItem[0]);
            currItem=nullptr;
        }
    }
    this->QGraphicsScene::update(QRectF(0, 0, this->width(), this->height()));
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    //qDebug () << typeAct;
    selectedItem = this->items(QPolygonF()
                               << QPointF(event->scenePos().x(), event->scenePos().y())
                               << QPointF(event->scenePos().x(), event->scenePos().y() + 1)
                               << QPointF(event->scenePos().x() + 1, event->scenePos().y() + 1)
                               << QPointF(event->scenePos().x() + 1, event->scenePos().y()));
    //qDebug () << 1;
    if (currItem) {
        currItem->color = Qt::black;
    }
    if (!selectedItem.empty()) {
        currItem = (shape*)selectedItem[0];
        if (typeAct) {
            currItem->color = Qt::blue;
        }
        //center = selectedItem[0]->pos();
        perim = currItem->perim;
        square = currItem->square;
    } else {
        currItem = nullptr;
    }
    //qDebug () << 2;
    if (typeAct==0) {
        //qDebug () << typeFigure;
        switch (typeFigure) {
        case 0:{
            //qDebug () << event->scenePos().x() << event->scenePos().y();
            ellips *newitem = new ellips(event->scenePos());
            newitem->setPos(event->pos());
            currItem = newitem;
            this->addItem(currItem);
            break;
        }
        case 1:{
            rectangle *newitem = new rectangle(event->scenePos());
            newitem->setPos(event->pos());
            currItem = newitem;
            this->addItem(currItem);
            break;
        }
        case 2:{
            triangle *newitem = new triangle(event->scenePos());
            newitem->setPos(event->pos());
            currItem = newitem;
            this->addItem(currItem);
            break;
        }
        case 3:{
            rightTriangle *newitem = new rightTriangle(event->scenePos());
            newitem->setPos(event->pos());
            currItem = newitem;
            this->addItem(currItem);
            break;
        }
        case 4:{
            romb *newitem = new romb(event->scenePos());
            newitem->setPos(event->pos());
            currItem = newitem;
            this->addItem(currItem);
            break;
        }
        case 5:{
            shape *newitem = new hexagon(event->scenePos());
            newitem->setPos(event->pos());
            currItem = newitem;
            this->addItem(currItem);
            break;
        }
        case 6:{
            star5 *newitem = new star5(event->scenePos());
            newitem->setPos(event->pos());
            currItem = newitem;
            this->addItem(currItem);
            break;
        }
        case 7:{
            star6 *newitem = new star6(event->scenePos());
            newitem->setPos(event->pos());
            currItem = newitem;
            this->addItem(currItem);
            break;
        }
        case 8:{
            star8 *newitem = new star8(event->scenePos());
            newitem->setPos(event->pos());
            currItem = newitem;
            this->addItem(currItem);
            break;
        }
        }
        if (currItem) {
            currItem->color = Qt::blue;
        }
        //qDebug() << currItem->getFinalPoint().x();
    } else {
        if (!selectedItem.empty()) {
            currItem = (shape*)selectedItem[0];
        }
    }
    if (typeAct==4) {
        if (currItem) {
            removeItem(currItem);
            currItem=nullptr;
        }
        deleteFlag = true;
    }
    this->QGraphicsScene::update(QRectF(0, 0, this->width(), this->height()));
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
    //qDebug () << 1;
    deleteFlag = false;
}

void Scene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (currItem) {
    if (typeAct==2) {
        if (event->delta()>0) {
            currItem->incScaleFactor(0.1);
        } else {
            currItem->incScaleFactor(-0.1);
        }
        currItem->setTransformOriginPoint(currItem->center);
        currItem->setScale(currItem->getScaleFactor());
    }
    if (typeAct==3) {
        if (event->delta()>0) {
            currItem->incRotateFactor(6);
        } else {
            currItem->incRotateFactor(-6);
        }
        currItem->setTransformOriginPoint(currItem->center);
        currItem->setRotation(currItem->getRotateFactor());
    }
    currItem->update(qMin(currItem->getStartPoint().x(),currItem->getFinalPoint().x()),
                 qMin(currItem->getStartPoint().y(),currItem->getFinalPoint().y()),
                 currItem->length, currItem->width);
    }
    this->QGraphicsScene::update(QRectF(0, 0, this->width(), this->height()));
}


















