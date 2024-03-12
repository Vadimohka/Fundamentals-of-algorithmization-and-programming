#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "ellipse.h"
#include "star.h"
 
PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{
   N = 0;
   rotation =0;
}
 
PaintScene::~PaintScene()
{

}

void PaintScene::setRotationX(int value)
{
    tempFigure->setRotationX(value);        
    update();
}

void PaintScene::setRotationY(int value)
{
    tempFigure->setRotationY(value);        
    update();
}

void PaintScene::setRotation(int value)
{
    tempFigure->setRotation(value);        
    update();
}

void PaintScene::setNumber(int value)
{
    N = value;
    tempFigure->setNumber(value);
    update();
}
 
int PaintScene::returnArea()
{
    return tempFigure->returnArea();
}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}
 
void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::setMouseMode(const int type)
{
    m_mousemode = type;
}
 
void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_mousemode != editing) {
        /* Устанавливаем конечную координату положения мыши
         * в текущую отрисовываемую фигуру
         * */
        tempFigure->setEndPoint(event->scenePos());
    }
    else {
        
        // QRectF figureRect(tempFigure->startPoint(), tempFigure->endPoint());
        // if (figureRect.contains(event->pos())) 
        if (m_typeFigure != StarType) {
            tempFigure->setPos(event->scenePos() - (tempFigure->startPoint() + tempFigure->endPoint()) / 2);
        }
        else {
            tempFigure->setPos(event->scenePos() - tempFigure->startPoint());
        }
    }

    /* Обновляем содержимое сцены,
     * необходимо для устранения артефактов при отрисовке фигур
     * */
    this->update();
}
 
/* Как только нажали кнопку мыши, создаём фигуру одного из трёх типов
 * и помещаем её на сцену или перемещаем имеющеесю,
 * сохранив указатель на неё в переменной tempFigure
 * */
void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_mousemode) {
    case editing: {
        //////


        ////
        break;
    }
    default:
    case drawing: {
        switch (m_typeFigure) {
        case SquareType: {
            Square *item = new Square(event->scenePos());
            item->setPos(event->pos());
            // item->setRotation(rotation);           
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
        case EllipseType: {
            Ellipse *item = new Ellipse(event->scenePos());
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
        default: {
            Romb *item = new Romb(event->scenePos());
            item->setPos(event->pos());
            tempFigure = item;
            break;
        }
        }
            this->addItem(tempFigure);
            break;
        }
    }
}