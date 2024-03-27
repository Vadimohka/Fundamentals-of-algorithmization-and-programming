#include "paintscene.h"
#include "parallelogram.h"
#include "triangle.h"
#include "rectangle.h"
#include "ellipse.h"
#include "regularpolygon.h"
#include "star.h"
#include <QtMath>
#include <QMessageBox>

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{
    m_typeAction = NoneAction;
    m_typeFigure = NoneType;
    tempFigure = nullptr;
}

PaintScene::~PaintScene()
{

}


int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

int PaintScene::buffTypeFigure() const
{
    return m_buffTypeFigure;
}

int PaintScene::typeAction() const
{
    return m_typeAction;
}


void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::setTypeAction(const int type)
{
    m_typeAction = type;
}


void PaintScene::moveTop()
{
    tempFigure->changePoints(tempFigure->startPoint() + QPointF(0, -0.05),
                             tempFigure->endPoint() + QPointF(0, -0.05));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::moveDown()
{
    tempFigure->changePoints(tempFigure->startPoint() + QPointF(0, +0.05),
                             tempFigure->endPoint() + QPointF(0, +0.05));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::moveLeft()
{
    tempFigure->changePoints(tempFigure->startPoint() + QPointF(-0.05, 0),
                             tempFigure->endPoint() + QPointF(-0.05, 0));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::moveRight()
{
    tempFigure->changePoints(tempFigure->startPoint() + QPointF(0.05, 0),
                             tempFigure->endPoint() + QPointF(0.05, 0));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::scaleDecrease()
{
    tempFigure->scale(-1);
}

void PaintScene::scaleIncrease()
{
    tempFigure->scale(1);
}

void PaintScene::rotateLeft()
{
    tempFigure->setRotation(tempFigure->rotation() - 1);
}

void PaintScene::rotateRight()
{
    tempFigure->setRotation(tempFigure->rotation() + 1);
}


void PaintScene::changeCenterX(double x)
{
    tempFigure->changePoints(tempFigure->startPoint() + QPointF (x - tempFigure->centerPoint().x(), 0),
                             tempFigure->endPoint() + QPointF (x - tempFigure->centerPoint().x(), 0));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::changeCenterY(double y)
{
    tempFigure->changePoints(tempFigure->startPoint() +QPointF (0, y - tempFigure->centerPoint().y()),
                             tempFigure->endPoint() + QPointF (0, y - tempFigure->centerPoint().y()));

    this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::changeStartPointX(double x)
{
    tempFigure->changePoints(QPointF (x, tempFigure->startPoint().y()), tempFigure->endPoint());
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::changeStartPointY(double y)
{
    tempFigure->changePoints(QPointF (tempFigure->startPoint().x(), y), tempFigure->endPoint());
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::changeEndPointX(double x)
{
    tempFigure->changePoints(tempFigure->startPoint(), QPointF (x, tempFigure->endPoint().y()));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::changeEndPointY(double y)
{
    tempFigure->changePoints(tempFigure->startPoint(), QPointF (tempFigure->endPoint().x(), y));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::changeWidth(double x)
{
    tempFigure->changePoints(tempFigure->startPoint(), QPointF(tempFigure->startPoint().x() + x, tempFigure->endPoint().y()));
}

void PaintScene::changeHeight(double y)
{
    tempFigure->changePoints(tempFigure->startPoint(), QPointF(tempFigure->endPoint().x(), tempFigure->startPoint().y() + y ));
}


QString PaintScene::figureInformation() const
{
    QString centerX = QString::number(tempFigure->centerPoint().x());
    QString centerY = QString::number(tempFigure->centerPoint().y());
    QString centerMessage = "Центр: (" + centerX + ", " + centerY + ")";
    QString squareMessage = "\nПлощать: " + QString::number(tempFigure->square());
    QString perimeterMessage = "\nПериметр: " + QString::number(tempFigure->perimeter());
    return centerMessage + squareMessage + perimeterMessage;
}


void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_typeAction == ChangeSizeAction || (tempFigure && m_typeAction == NoneAction))
    {
        tempFigure->changePoints(tempFigure->startPoint(), event->scenePos());
        this->update(QRectF(0,0,this->width(), this->height()));
    }
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {
    case RectangleType: {
        Rectangle *item = new Rectangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case RombType: {
        RegularPolygon *item = new RegularPolygon(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        tempFigure->setVertexCount(4);
        break;
    }
    case TriangleType: {
        Triangle *item = new Triangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        tempFigure->setVertexCount(3);
        break;
    }
    case ParallelogramType: {
        Parallelogram *item = new Parallelogram(event->scenePos());
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
    case RegularPolygonType: {
        RegularPolygon *item = new RegularPolygon(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case StarType: {
        Star *item = new Star(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    default:{
        break;
    }
    }
    if (tempFigure)
    {
        if (m_typeFigure != NoneType) m_buffTypeFigure = m_typeFigure;

        this->addItem(tempFigure);
    }
}
