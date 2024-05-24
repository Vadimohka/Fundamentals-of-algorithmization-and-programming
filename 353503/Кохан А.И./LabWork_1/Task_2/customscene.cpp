#include "customscene.h"
#include "romb.h"
#include "triangle2.h"
#include "rectangle.h"
#include "ellipse.h"
#include "circle.h"
#include "square.h"
#include "hexagon.h"
#include "triangle90.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "Line.h"

CustomScene::CustomScene(QObject *parent) : QGraphicsScene(parent) {
    rotateTimerPlus = new QTimer(this);
    rotateTimerMinys = new QTimer(this);
    connect(rotateTimerPlus, SIGNAL(timeout()), this, SLOT(rotateEventPlus()));
    connect(rotateTimerMinys, SIGNAL(timeout()), this, SLOT(rotateEventMinys()));
}

int CustomScene::getTypeFigure() const
{
    return typeFigure;
}

void CustomScene::setTypeFigure(const int type)
{
    typeFigure = type;
}

qreal CustomScene::getYCenter() const
{
    return yCenter;
}

qreal CustomScene::getXCenter() const
{
    return xCenter;
}

qreal CustomScene::getSFigure() const
{
    return sFigure;
}

qreal CustomScene::getPFigure() const
{
    return pFigure;
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(typeFigure == MoveType && founded) {
        foundItems[0]->moveBy(event->scenePos().x() - event->lastScenePos().x(), event->scenePos().y() - event->lastScenePos().y());
    }

    else if(typeFigure != MoveType && typeFigure != DeleteType && typeFigure != BroomType
             && typeFigure != ScaleType && typeFigure != RotationType){
        tempFigure->setEndPoint(event->scenePos());
    }
    this->QGraphicsScene::update(QRectF(0, 0, this->width(), this->height()));
}

void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if(typeFigure == RotationType && isRotate){
        rotateTimerMinys->stop();
        rotateTimerPlus->stop();
    }

    else if(typeFigure == MoveType && founded) {
        founded = false;
    }
}

void CustomScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if(typeFigure == ScaleType && !foundItems.empty()) {
        if(event->delta() > 0) {
            scroll += 0.12;
        }

        else if(event->delta() < 0 && scroll > 0.12) {
              scroll -= 0.12;
        }

        foundItems[0]->setTransformOriginPoint(foundItems[0]->boundingRect().center());
        foundItems[0]->setScale(scroll);
        this->QGraphicsScene::update(QRectF(0, 0, this->width(), this->height()));
    }
}

void CustomScene::rotateEventPlus()
{
    ++rotate;
    foundItems[0]->setTransformOriginPoint(foundItems[0]->boundingRect().center());
    foundItems[0]->setRotation(rotate);
}

void CustomScene::rotateEventMinys()
{
    --rotate;
    foundItems[0]->setTransformOriginPoint(foundItems[0]->boundingRect().center());
    foundItems[0]->setRotation(rotate);
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
        rotateTimerMinys->stop();
        rotateTimerPlus->stop();

        foundItems = QGraphicsScene::items(
            QPolygonF() << QPointF(event->scenePos().x(), event->scenePos().y())
                        << QPointF(event->scenePos().x(), event->scenePos().y() + 1)
                        << QPointF(event->scenePos().x() + 1, event->scenePos().y() + 1)
                        << QPointF(event->scenePos().x() + 1, event->scenePos().y()));

        switch (typeFigure) {
        case RectangleType: {
            Rectangle *item = new Rectangle(event->scenePos());
            item->setPos(event->pos());
            tempFigure = item;
            break;
    }
    case RombType: {
        Romb *item = new Romb(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case Triangle2Type: {
        Triangle2 *item = new Triangle2(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case EllipseType: {
        Ellipse *item = new Ellipse(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case CircleType: {
        Circle *item = new Circle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case SquareType: {
        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case HexagonType: {
        Hexagon *item = new Hexagon(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case Triangle90Type: {
        Triangle90 *item = new Triangle90(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case Star5Type: {
        Star5 *item = new Star5(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case Star6Type: {
        Star6 *item = new Star6(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case Star8Type: {
        Star8 *item = new Star8(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case LineType: {
        Line *item = new Line(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case MoveType: {
        if(!foundItems.empty()) founded = true;

        break;
    }
    case DeleteType: {
        if(!foundItems.empty()) {
            removeItem(foundItems[0]);
            this->QGraphicsScene::update(QRectF(0, 0, this->width(), this->height()));
        }
        break;
    }
    case BroomType: {
            foundItems = items();

            for(int i = 0; i < foundItems.size(); ++i) {
                removeItem(foundItems[i]);
            }

            this->QGraphicsScene::update(QRectF(0, 0, this->width(), this->height()));

        break;
    }
    case RestartType: {
        if(!foundItems.empty()) {
            tempFigure = (Figure*)foundItems[0];
        }

        break;
    }
    case ScaleType: {
        if(!foundItems.empty()) {
            scroll = 1;
        }

        break;
    }
    case RotationType: {
        if(!foundItems.empty() && (event->button() == Qt::XButton2 || event->button() == Qt::XButton1)) {
            rotate = foundItems[0]->rotation();
            isRotate = true;

            if(event->button() == Qt::XButton2) {
                rotateTimerPlus->start(12);
            }

            else if(event->button() == Qt::XButton1) {
                rotateTimerMinys->start(12);
            }
        }

        else isRotate = false;

        break;
    }
    }

    if(!foundItems.empty()) {
        Figure* temp = (Figure*)foundItems[0];
        xCenter = foundItems[0]->boundingRect().center().x();
        yCenter = foundItems[0]->boundingRect().center().y();
        pFigure = temp->getPFigure();
        sFigure = temp->getSFigure();
    }

    if(typeFigure != MoveType && typeFigure != DeleteType && typeFigure != BroomType
        && typeFigure != ScaleType && typeFigure != RotationType) {
    this->addItem(tempFigure);   
    }
}
