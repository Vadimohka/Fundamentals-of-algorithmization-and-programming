#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "ellipse.h"
#include "circle.h"
#include "rectangle.h"
#include "hexagon.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"


PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

PaintScene::~PaintScene()
{

}

int PaintScene::typeBasicFigure() const
{
    return m_typeBasicFigure;
}

QPointF PaintScene::getEndPoint()
{
    return this->endp;
}

QPointF PaintScene::getStartPoint()
{
    return this->startp;
}

void PaintScene::setTypeBasicFigure(const int type)
{
    m_typeBasicFigure = type;
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
    if (deletButtonActive){
        return;
    }
    if (tempBasicFigure != nullptr && event->buttons() & Qt::RightButton){
        moveFigure(event);
    }
    if (tempBasicFigure != nullptr && (event->buttons() & (Qt::ForwardButton | Qt::BackButton))){
        return;
    }
    setEndPoint(event->scenePos());

    this->update(QRectF(0,0,this->width(), this->height()));
    // Устанавливаем конечную координату положения мыши
    // в текущую отрисовываемую фигуру

    tempBasicFigure->setEndPoint(event->scenePos());
    //Обновляем содержимое сцены,
    //     необходимо для устранения артефактов при отрисовке фигур

    if (tempBasicFigure != nullptr){
        emit areaChanged(tempBasicFigure->area());
        emit perimeterChanged(tempBasicFigure->perimeter());
    }

    this->update(QRectF(0,0,this->width(), this->height()));
}

// Как только нажали кнопку мыши, создаём фигуру одного из трёх типов
//       и помещаем её на сцену, сохранив указатель на неё в переменной
//       tempBasicFigure

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    deletButtonActive = false;
    setStartPoint(event->scenePos());


    switch (m_typeBasicFigure) {
    case Rectanglet: {
        Rectangle *item = new Rectangle(event->scenePos());
        item->setPos(event->pos());
        tempBasicFigure = item;
        break;
    }
    case Rombt: {
        Romb *item = new Romb(event->scenePos());
        item->setPos(event->pos());
        tempBasicFigure = item;
        break;
    }
    case Trianglet: {
        Triangle *item = new Triangle(event->scenePos());
        item->setPos(event->pos());
        tempBasicFigure = item;
        break;
    }
    case Ellipset: {
        Ellipse *item = new Ellipse(event->scenePos());
        item->setPos(event->pos());
        tempBasicFigure = item;
        break;
    }
    case Squaret:{
        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempBasicFigure = item;
        break;
    }
    case Circlet: {
        Circle *item = new Circle(event->scenePos());
        item->setPos(event->pos());
        tempBasicFigure = item;
        break;
    }
    case Hexagont:{
        Hexagon *item = new Hexagon(event->scenePos());
        item->setPos(event->pos());
        tempBasicFigure = item;
        break;
    }
    case Star_5t:{
        Star5 *item = new Star5(event->scenePos());
        item->setPos(event->pos());
        tempBasicFigure = item;
        break;
    }
    case Star_6t:{
        Star6 *item = new Star6(event->scenePos());
        item->setPos(event->pos());
        tempBasicFigure = item;
        break;
    }
    case Star_8t:{
        Star8 *item = new Star8(event->scenePos());
        item->setPos(event->pos());
        tempBasicFigure = item;
        break;
    }
    case Deletet:{
        if (tempBasicFigure != nullptr){
            deletButtonActive = true;

            QList<QGraphicsItem *> foundItems = this->items(QPolygonF()
                                                            << QPointF(event->scenePos().x(), event->scenePos().y())
                                                            << QPointF(event->scenePos().x(), event->scenePos().y() + 1)
                                                            << QPointF(event->scenePos().x() + 1, event->scenePos().y() + 1)
                                                            << QPointF(event->scenePos().x() + 1, event->scenePos().y()));

            if (!foundItems.isEmpty()){
                for (int i =0; i < foundItems.size(); ++i) {
                    if (foundItems[i] == tempBasicFigure){
                        foundItems[i]->hide();
                    }
                    else{
                        removeItem(foundItems[i]);
                    }
                }
            }
            this->QGraphicsScene::update(QRectF(0, 0, this->width(), this->height()));
            break;
        }
    }
    case Warpt:{
        if (tempBasicFigure != nullptr){
            tempBasicFigure->setStartPoint(event->scenePos());
            this->update(QRectF(0,0,this->width(), this->height()));
            break;
        }
    }
    default:{
        Rectangle *item = new Rectangle(event->scenePos());
        item->setPos(event->pos());
        tempBasicFigure = item;
        break;
    }
    }
    if (!(event->buttons() & Qt::RightButton)){
        this->addItem(tempBasicFigure);
    }
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->button() == Qt::BackButton || event->button() == Qt::ForwardButton) && rotationTimer) {
        rotationTimer->stop(); // Остановка таймера при отпускании боковой кнопки мыши
        delete rotationTimer;
        rotationTimer = nullptr;
    }
}

void PaintScene::keyPressEvent(QKeyEvent *event)
{
    if (tempBasicFigure !=nullptr){
        QPointF endPoint = getEndPoint();
        QPointF startPoint = getStartPoint();
        endPoint   += QPointF(5, 5);
        startPoint -= QPoint(5, 5);
        if(event->key() == Qt::Key_Plus){
            endPoint   += QPointF(5, 5);
            startPoint -= QPoint(5, 5);

        }
         else if (event->key() == Qt::Key_Minus){
             endPoint   -= QPointF(10, 10);
             startPoint += QPoint(10, 10);

         }
        setEndPoint(endPoint);
        setStartPoint(startPoint);

        tempBasicFigure->setStartPoint(startPoint);
        tempBasicFigure->setEndPoint(endPoint);

        emit areaChanged(tempBasicFigure->area());
        emit perimeterChanged(tempBasicFigure->perimeter());
    }
    update(QRectF(0,0,this->width(), this->height()));
}

BasicFigure* PaintScene::currentBasicFigure() const {
    return tempBasicFigure;
}

void PaintScene::moveFigure(QGraphicsSceneMouseEvent *event)
{

    QList<QGraphicsItem *> foundItems = this->items(QPolygonF()
                                                    << QPointF(event->scenePos().x(), event->scenePos().y())
                                                    << QPointF(event->scenePos().x(), event->scenePos().y() + 1)
                                                    << QPointF(event->scenePos().x() + 1, event->scenePos().y() + 1)
                                                    << QPointF(event->scenePos().x() + 1, event->scenePos().y()));
    if (!foundItems.empty()){
        QPointF diff = event->scenePos() - event->lastScenePos();
        foundItems[0]->moveBy(diff.x(), diff.y());

    }
}
