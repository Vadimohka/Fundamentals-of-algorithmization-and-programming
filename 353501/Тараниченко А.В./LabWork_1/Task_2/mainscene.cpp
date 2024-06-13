#include "mainscene.h"
#include "parallelogram.h"
#include "triangle.h"
#include "rectangle.h"
#include "ellipse.h"
#include "regularpolygon.h"
#include "star.h"
#include <QtMath>
#include <QMessageBox>

MainScene::MainScene(QObject *parent) : QGraphicsScene(parent)
{
    m_typeAction = NoneAction;
    m_typeShape = NoneType;
    tempShape = nullptr;
}

MainScene::~MainScene()
{

}


int MainScene::typeShape() const
{
    return m_typeShape;
}

int MainScene::buffTypeShape() const
{
    return m_buffTypeShape;
}

int MainScene::typeAction() const
{
    return m_typeAction;
}


void MainScene::setTypeShape(const int type)
{
    m_typeShape = type;
}

void MainScene::setTypeAction(const int type)
{
    m_typeAction = type;
}


void MainScene::moveTop()
{
    tempShape->changePoints(tempShape->startPoint() + QPointF(0, -0.05),
                             tempShape->endPoint() + QPointF(0, -0.05));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void MainScene::moveDown()
{
    tempShape->changePoints(tempShape->startPoint() + QPointF(0, +0.05),
                             tempShape->endPoint() + QPointF(0, +0.05));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void MainScene::moveLeft()
{
    tempShape->changePoints(tempShape->startPoint() + QPointF(-0.05, 0),
                             tempShape->endPoint() + QPointF(-0.05, 0));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void MainScene::moveRight()
{
    tempShape->changePoints(tempShape->startPoint() + QPointF(0.05, 0),
                             tempShape->endPoint() + QPointF(0.05, 0));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void MainScene::scaleDecrease()
{
    tempShape->scale(-1);
}

void MainScene::scaleIncrease()
{
    tempShape->scale(1);
}

void MainScene::rotateLeft()
{
    tempShape->setRotation(tempShape->rotation() - 1);
}

void MainScene::rotateRight()
{
    tempShape->setRotation(tempShape->rotation() + 1);
}


void MainScene::changeCenterX(double x)
{
    tempShape->changePoints(tempShape->startPoint() + QPointF (x - tempShape->centerPoint().x(), 0),
                             tempShape->endPoint() + QPointF (x - tempShape->centerPoint().x(), 0));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void MainScene::changeCenterY(double y)
{
    tempShape->changePoints(tempShape->startPoint() +QPointF (0, y - tempShape->centerPoint().y()),
                             tempShape->endPoint() + QPointF (0, y - tempShape->centerPoint().y()));

    this->update(QRectF(0, 0, this->width(), this->height()));
}

void MainScene::changeStartPointX(double x)
{
    tempShape->changePoints(QPointF (x, tempShape->startPoint().y()), tempShape->endPoint());
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void MainScene::changeStartPointY(double y)
{
    tempShape->changePoints(QPointF (tempShape->startPoint().x(), y), tempShape->endPoint());
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void MainScene::changeEndPointX(double x)
{
    tempShape->changePoints(tempShape->startPoint(), QPointF (x, tempShape->endPoint().y()));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void MainScene::changeEndPointY(double y)
{
    tempShape->changePoints(tempShape->startPoint(), QPointF (tempShape->endPoint().x(), y));
    this->update(QRectF(0, 0, this->width(), this->height()));
}

void MainScene::changeWidth(double x)
{
    tempShape->changePoints(tempShape->startPoint(), QPointF(tempShape->startPoint().x() + x, tempShape->endPoint().y()));
}

void MainScene::changeHeight(double y)
{
    tempShape->changePoints(tempShape->startPoint(), QPointF(tempShape->endPoint().x(), tempShape->startPoint().y() + y ));
}


QString MainScene::ShapeInformation() const
{
    QString centerX = QString::number(tempShape->centerPoint().x());
    QString centerY = QString::number(tempShape->centerPoint().y());
    QString centerMessage = "Центр: (" + centerX + ", " + centerY + ")";
    QString squareMessage = "\nПлощать: " + QString::number(tempShape->square());
    QString perimeterMessage = "\nПериметр: " + QString::number(tempShape->perimeter());
    return centerMessage + squareMessage + perimeterMessage;
}


void MainScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_typeAction == ChangeSizeAction || (tempShape && m_typeAction == NoneAction))
    {
        tempShape->changePoints(tempShape->startPoint(), event->scenePos());
        this->update(QRectF(0,0,this->width(), this->height()));
    }
}

void MainScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeShape) {
    case RectangleType: {
        Rectangle *item = new Rectangle(event->scenePos());
        item->setPos(event->pos());
        tempShape = item;
        break;
    }
    case RombType: {
        RegularPolygon *item = new RegularPolygon(event->scenePos());
        item->setPos(event->pos());
        tempShape = item;
        tempShape->setVertexCount(4);
        break;
    }
    case TriangleType: {
        Triangle *item = new Triangle(event->scenePos());
        item->setPos(event->pos());
        tempShape = item;
        tempShape->setVertexCount(3);
        break;
    }
    case ParallelogramType: {
        Parallelogram *item = new Parallelogram(event->scenePos());
        item->setPos(event->pos());
        tempShape = item;
        break;
    }
    case EllipseType: {
        Ellipse *item = new Ellipse(event->scenePos());
        item->setPos(event->pos());
        tempShape = item;
        break;
    }
    case RegularPolygonType: {
        RegularPolygon *item = new RegularPolygon(event->scenePos());
        item->setPos(event->pos());
        tempShape = item;
        break;
    }
    case StarType: {
        Star *item = new Star(event->scenePos());
        item->setPos(event->pos());
        tempShape = item;
        break;
    }
    default:{
        break;
    }
    }
    if (tempShape)
    {
        if (m_typeShape != NoneType) m_buffTypeShape = m_typeShape;

        this->addItem(tempShape);
    }
}
