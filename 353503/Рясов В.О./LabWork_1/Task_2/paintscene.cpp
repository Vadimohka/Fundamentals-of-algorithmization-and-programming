#include "paintscene.h"
#include "rectangle.h"
#include "rhomb.h"
#include "triangle.h"
#include "ellipse.h"
#include "star.h"
#include "eightpointedstar.h"
#include "sixpointedstar.h"

#include <QKeyEvent>

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent), rotateTimer(new QTimer(this))
{
    setTypeFigure(RectType);
    this->setSceneRect(0,0,w,h);
    connect(rotateTimer, SIGNAL(timeout()), this, SLOT(rotateEvent()));
}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

QPointF PaintScene::getEndPoint()
{
    return this->endp;
}

QPointF PaintScene::getStartPoint()
{
    return this->startp;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::setStartPoint(QPointF startPoint)
{
    startp = startPoint;
}

void PaintScene::setEndPoint(QPointF endPoint)
{
    endp = endPoint;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (isRotating){
        return;
    }

    if(isMoving and !foundItems.isEmpty()){
        if (!foundItems.empty() && foundItems[0] != nullptr){
            foundItems[0]->setFlag(QGraphicsItem::ItemIsMovable);
            foundItems[0]->moveBy(event->scenePos().x() - event->lastScenePos().x(), event->scenePos().y() - event->lastScenePos().y());
            update(sceneRect());
            qDebug () <<"Move event ";
        }
    }

    else {
        setEndPoint(event->scenePos());

        tempFigure->setEndPoint(event->scenePos());
        tempFigure->setCenterPoint();

    this->update(tempFigure->boundingRect());
    this->update(sceneRect());
    }
}

void PaintScene::keyPressEvent(QKeyEvent *key)
{
    if (key->key() == Qt::Key_Delete and !paintedItems.empty()) {
        if (tempFigure != nullptr && tempFigure->scene() != nullptr) {
            removeItem(tempFigure);
            this->QGraphicsScene::update(QRectF(0, 0, this->width(),this->height()));
        }
    }

    if(key->key() == Qt::Key_Shift and !paintedItems.empty()) {
        qDebug () <<"Shift event";
        QPointF endPoint = getEndPoint();
        QPointF startPoint = getStartPoint();
        QPointF diff = endPoint - startPoint;
        if (diff.x() < diff.y()){
            endPoint.rx() = startPoint.x() + diff.y();
            tempFigure->setEndPoint(endPoint);
        }
        else if (diff.x() > diff.y()){
            endPoint.ry() = startPoint.y() + diff.x();
            tempFigure->setEndPoint(endPoint);
        }
        update(QRectF(0,0,this->width(),this->height()));
    }

    if(key->key() == Qt::Key_Plus and !paintedItems.empty()) {
        qDebug () <<"Plus event";
        if (tempFigure != nullptr){
            tempFigure->setTransformOriginPoint(tempFigure->boundingRect().center());
            tempFigure->setScale(tempFigure->scale() * 1.1); // Увеличиваем размер на 10%
            update(QRectF(0,0,this->width(),this->height()));
        }
    }

    if(key->key() == Qt::Key_Minus and !paintedItems.empty()) {
        qDebug () <<"Minus event";
        if (tempFigure != nullptr){
            tempFigure->setTransformOriginPoint(tempFigure->boundingRect().center());
            tempFigure->setScale(tempFigure->scale() * 0.9); // Уменьшаем размер на 10%
            update(QRectF(0,0,this->width(),this->height()));
        }
    }
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)

{
    foundItems = this->items(QPolygonF()
                                                    << QPointF(event->scenePos().x(), event->scenePos().y())
                                                    << QPointF(event->scenePos().x(), event->scenePos().y() + 1)
                                                    << QPointF(event->scenePos().x() + 1, event->scenePos().y() + 1)
                                                    << QPointF(event->scenePos().x() + 1, event->scenePos().y()));
    setStartPoint(event->scenePos());
    item = nullptr;
    switch (m_typeFigure) {
    case RectType:{
        item = new Rectangle(event->scenePos());
        break;
    }
    case RhombType:{
        item = new Rhomb(event->scenePos());
        break;
    }
    case TriangleType:
        item = new Triangle(event->scenePos());
        break;
    case EllipseType:
        item = new Ellipse(event->scenePos());
        break;
    case StarType:
        item = new Star(event->scenePos());
        break;
    case SixStarType:
        item = new SixPointedStar(event->scenePos());
        break;
    case EightStarType:
        item = new EightPointedStar(event->scenePos());
        break;
    case DeleteType:
        if (tempFigure != nullptr){
            if (!foundItems.isEmpty()){
                qDebug() << " DELETE ITEM ";
                for (auto & foundItem : foundItems) {
                    if (foundItem == tempFigure){
                        foundItem->hide();
                    }
                    else{
                        removeItem(foundItem);
                    }
                }
                this->QGraphicsScene::update(0,0,this->width(),this->height());
        }
        break;
        }
    case MoveType:
        if (tempFigure != nullptr and event->buttons() & Qt::RightButton){
            isMoving = true;
        }
        break;
    case RotateType:
        if(!foundItems.empty() && (event->button() == Qt::RightButton)) {
            isRotating = true;
            rotate = foundItems[0]->rotation();

            if(event->button() == Qt::RightButton) {
                rotateTimer->start(rotSpeed);
            }
        }
        break;
    default:

        break;
    }

    if (item != nullptr) {
        item->setPos(event->pos());
        tempFigure = item;
        tempFigure->setStartPoint(event->scenePos());
    }

    if(m_typeFigure != RotateType and m_typeFigure !=DeleteType and m_typeFigure != MoveType){
        this->addItem(tempFigure);
    }

    if(!foundItems.empty()){
        xCenter = foundItems[0]->boundingRect().center().x();
        yCenter = foundItems[0]->boundingRect().center().y();
    }
}

void PaintScene::rotateEvent()
{
    ++rotate;
    foundItems[0]->setTransformOriginPoint(foundItems[0]->boundingRect().center());
    foundItems[0]->setRotation(rotate);
    update(sceneRect());
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(tempFigure != nullptr and isMoving){
        paintedItems.append(tempFigure);
        isMoving = false;
    }
    if (event->button() == Qt::RightButton and isRotating) {
        isRotating = false;
        rotateTimer->stop();
    }

}


