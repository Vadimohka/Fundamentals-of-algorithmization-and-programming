#include "Scenes/paintscene.h"
#include "Figures/romb.h"
#include "Figures/triangle.h"
#include "Figures/square.h"
#include "Figures/rectangle.h"
#include "Figures/circle.h"
#include "Figures/star5.h"
#include "Figures/star6.h"
#include "Figures/star8.h"
#include "Figures/hexagon.h"
#include "Figures/arrow.h"
#include <QMouseEvent>
#include <QDebug>

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent) {}

PaintScene::~PaintScene() {}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

Figure* PaintScene::getFigure() const
{
    return tempFigure;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    /* Устанавливаем конечную координату положения мыши
     * в текущую отрисовываемую фигуру
     * */
   if (event->buttons() == Qt::LeftButton && !itemUnderMouse){
        //Единый для каждой фигуры подсчёт площади
        //класс figure.h и его наследников
        tempFigure->setEndPoint(event->scenePos());
        emit SetLabelS(tempFigure->GetArea());
        emit SetLabelP(tempFigure->GetPerimeter());
    }
    else  {
        QGraphicsScene::mouseMoveEvent(event);
    }
    this->update();
}


void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!event->isAccepted()) {
        //Создание списка типа QGraphicsItem*
        //В него мы записываем все элементы в позиции event->scenePos(), то есть под курсором
        //Берем верхний (имитация стека)
        itemUnderMouse = nullptr;
        QList<QGraphicsItem *> itemsUnderMouse = items(event->scenePos());   //?
        itemUnderMouse = itemsUnderMouse.isEmpty() ? nullptr : itemsUnderMouse.first();

        if (event->button() == Qt::LeftButton && !itemUnderMouse) {
            qDebug() << "Зашло";
            switch (m_typeFigure) {
                case SquareType: {
                    tempFigure = new Square(event->scenePos());
                    break;
                }
                case RombType: {
                    tempFigure = new Romb(event->scenePos());
                    break;
                }
                case TriangleType: {
                    tempFigure = new Triangle(event->scenePos());
                    break;
                }
                case RectangleType: {
                    tempFigure = new Rectangle(event->scenePos());
                    break;
                }
                case CircleType: {
                    tempFigure = new Circle(event->scenePos());
                    break;
                }
                case Star5Type: {
                    tempFigure = new Star5(event->scenePos());
                    break;
                }
                case Star6Type: {
                    tempFigure = new Star6(event->scenePos());
                    break;
                }
                case Star8Type: {
                    tempFigure = new Star8(event->scenePos());
                    break;
                }
                case HexagonType: {
                    tempFigure = new Hexagon(event->scenePos());
                    break;
                }
                case ArrowType: {
                    tempFigure = new Arrow(event->scenePos());
                    break;
                }
                default:{
                    tempFigure = new Square(event->scenePos());
                    break;
                }
            }
            tempFigure->setPos(event->pos());
            tempFigure->setStartPoint(event->scenePos());
            this->addItem(tempFigure);
        }
        else if(itemUnderMouse){
            tempFigure = qgraphicsitem_cast<Figure*>(itemUnderMouse);// приведение объекта QGraphicsItem  к оюъекту класса Figure,
                                                                     //это пришлось сделать потому что в фигуре есть доп параметр типа QPointF
            emit SetLabelS(tempFigure->GetArea());  //сигналы пересчета площади
            emit SetLabelP(tempFigure->GetPerimeter());
            QGraphicsScene::mousePressEvent(event);

        }
    }
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
}

void PaintScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Backspace)
    {
        // Удаляем элемент из сцены
        if(itemUnderMouse != NULL){
            removeItem(itemUnderMouse);
            this->update(QRectF(0,0,this->width(), this->height()));
        }
    }
}
