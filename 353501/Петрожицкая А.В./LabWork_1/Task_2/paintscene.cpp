#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include"circle.h"
#include "rect.h"
#include "hexagon.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "custom.h"
#include "arrow.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{
    tempFigure = 0;
    posX = 0;
    posY = 0;
}

PaintScene::~PaintScene()
{

}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::setRotation(const int angle) {
    tempFigure->setRotation(angle);
}

void PaintScene::setScale(qreal factor) { tempFigure->setScale(factor); }

void PaintScene::setX(int x) {
    posX = x;
    tempFigure->setPos(posX, posY);
}

void PaintScene::setY(int y) {
    posY = y;
    tempFigure->setPos(posX, posY);
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем конечную координату положения мыши
     * в текущую отрисовываемую фигуру
     * */
    tempFigure->setEndPoint(event->scenePos());
    /* Обновляем содержимое сцены,
     * необходимо для устранения артефактов при отрисовке фигур
     * */
    this->update(QRectF(0,0,this->width(), this->height()));
}

/* Как только нажали кнопку мыши, создаём фигуру одного из трёх типов
 * и помещаем её на сцену, сохранив указатель на неё в переменной
 * tempFigure
 * */
void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {
    case SquareType: {
        Square *item = new Square(event->scenePos());
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
    case TriangleType: {
        Triangle *item = new Triangle(event->scenePos());
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
    case RectangleType: {
        Rectangle *item = new Rectangle(event->scenePos());
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
    case CustomType: {
        Custom *item = new Custom(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case ArrowType: {
        Arrow *item = new Arrow(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    default:{

        break;
    }
    }
    this->addItem(tempFigure);
}
