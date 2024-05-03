#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "rectangle.h"
#include "ellipse.h"
#include "star.h"
#include "polygon.h"
#include "parallelogram.h"
#include "paint.h"
 
PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{
    spaceFigure();
}
 
PaintScene::~PaintScene()
{
    
}

void PaintScene::spaceFigure()
{
    Romb *spacefigure = new Romb(QPointF(0, 0));
    tempFigure = spacefigure;
    isNoFigure = true;
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
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setNumber(value);
    update();
}

void PaintScene::setOuterRadius(int value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setOuterRadius(value);
    update();
}

void PaintScene::setInnerRadius(int value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setInnerRadius(value);
    update();
}

int PaintScene::returnNumber()
{
    return tempFigure->returnNumber();
}
 
double PaintScene::returnArea()
{
    return tempFigure->returnArea();
}

double PaintScene::returnPerimeter()
{
    return tempFigure->returnPerimeter();;
}

int PaintScene::returnCenterX()
{
    return tempFigure->returnCenterX();
}

int PaintScene::returnCenterY()
{
    return tempFigure->returnCenterY();
}

double PaintScene::returnOuterRadius()
{
    return tempFigure->returnOuterRadius();
}

double PaintScene::returnInnerRadius()
{
    return tempFigure->returnInnerRadius();
}

double PaintScene::returnAngel()
{
    return tempFigure->returnAngel();
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
        if (m_typeFigure != StarType && m_typeFigure != PolygonType) {
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
        case RombType: {
            Romb *item = new Romb(event->scenePos());
            item->setPos(event->pos());
            tempFigure = item;
            isNoFigure = false;
            break;
        }
        case RectangleType: {
            Rectangle *item = new Rectangle(event->scenePos());
            item->setPos(event->pos());          
            tempFigure = item;
            isNoFigure = false;
            break;
        }
        case TriangleType: {
            Triangle *item = new Triangle(event->scenePos());
            item->setPos(event->pos());
            tempFigure = item;
            isNoFigure = false;
            break;
        }
        case EllipseType: {
            Ellipse *item = new Ellipse(event->scenePos());
            item->setPos(event->pos());
            tempFigure = item;
            isNoFigure = false;
            break;
        }
        case StarType: {
            Star *item = new Star(event->scenePos());
            item->setPos(event->pos());
            tempFigure = item;
            isNoFigure = false;
            break;
        }
        case PolygonType: {
            Polygone *item = new Polygone(event->scenePos());
            item->setPos(event->pos());
            tempFigure = item;
            isNoFigure = false;
            break;
        }
        case ParallelogramType: {
            Parallelogram *item = new Parallelogram(event->scenePos());
            item->setPos(event->pos());
            tempFigure = item;
            isNoFigure = false;
            break;
        }
        case PaintType: {
            Paint *item = new Paint(event->scenePos());
            item->setPos(event->pos());
            tempFigure = item;
            isNoFigure = false;
            break;
        }
        default: {
            Romb *item = new Romb(event->scenePos());
            item->setPos(event->pos());
            tempFigure = item;
            isNoFigure = false;
            break;
        }
        }
            this->addItem(tempFigure);
            isNew = true;
            break;
        }
    }
}

double PaintScene::returnSideA()
{
    return tempFigure->returnSideA();
}

double PaintScene::returnSideB()
{
    return tempFigure->returnSideB();
}

void PaintScene::setSideA(int value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setSideA(value);
    update();
}

void PaintScene::setSideB(int value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setSideB(value);
    update();
}

void PaintScene::setAngel(int value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setAngel(value);
    update();
}

void PaintScene::setScale(double value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setScale(value);
    update();
}

bool PaintScene::returnIsNew()
{
    return isNew;
}

void PaintScene::setIsNew()
{
    isNew = false;
}

// Треугольник

void PaintScene::setPointA_x(int value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setPointA_x(value);
    update();
}

void PaintScene::setPointA_y(int value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setPointA_y(value);
    update();
}

void PaintScene::setPointB_x(int value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setPointB_x(value);
    update();
}

void PaintScene::setPointB_y(int value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setPointB_y(value);
    update();
}

void PaintScene::setPointC_x(int value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setPointC_x(value);
    update();
}

void PaintScene::setPointC_y(int value)
{
    if (m_mousemode == editing)
    tempFigure->setIsDrawingFirstTime(false);
    else
    tempFigure->setIsDrawingFirstTime(true);

    tempFigure->setPointC_y(value);
    update();
}
                 /*Возврат*/
int PaintScene::returnPointA_x()
{
    return tempFigure->returnPointA_x();
}

int PaintScene::returnPointA_y()
{
    return tempFigure->returnPointA_y();
}

int PaintScene::returnPointB_x()
{
    return tempFigure->returnPointB_x();
}

int PaintScene::returnPointB_y()
{
    return tempFigure->returnPointB_y();
}

int PaintScene::returnPointC_x()
{
    return tempFigure->returnPointC_x();
}

int PaintScene::returnPointC_y()
{
    return tempFigure->returnPointC_y();
}

bool PaintScene::is_No_Figure()
{
    if (isNoFigure) return true; else return false;
}