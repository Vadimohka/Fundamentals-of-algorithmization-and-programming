#include "paintscene.h"
#include "circle.h"
#include "diff_figure.h"
#include "hexagon.h"
#include "painting.h"
#include "rectangle.h"
#include "romb.h"
#include "square.h"
#include "star.h"
#include "triangle.h"
#include <qgraphicsitem.h>


PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent) {
  tempFigure = 0;
  posX = 0;
  posY = 0;
}

PaintScene::~PaintScene() {}

int PaintScene::typeFigure() const { return m_typeFigure; }

void PaintScene::setTypeFigure(const int type) { m_typeFigure = type; }

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

QString PaintScene::ChangeLabel() {
  if (tempFigure == 0) {
    return "no figure";
  }
  return QString("Центр масс = (%0, %1). Площадь = %2. Периметр = %3.")
      .arg(tempFigure->returnCentralPoint().x())
      .arg(tempFigure->returnCentralPoint().y())
      .arg(tempFigure->Ploshad())
      .arg(tempFigure->Perimeter());
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  /* Устанавливаем конечную координату положения мыши
   * в текущую отрисовываемую фигуру
   * */
  tempFigure->setEndPoint(event->scenePos());

  /* Обновляем содержимое сцены,
   * необходимо для устранения артефактов при отрисовке фигур
   * */
  this->update(QRectF(0, 0, this->width(), this->height()));
}

/* Как только нажали кнопку мыши, создаём фигуру одного из трёх типов
 * и помещаем её на сцену, сохранив указатель на неё в переменной
 * tempFigure
 * */
void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  switch (m_typeFigure) {
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
  case SquareType: {
    Square *item = new Square(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
  }
  case Star5Type: {
    Star *item = new Star(event->scenePos(), 5);
    item->setPos(event->pos());
    tempFigure = item;
    break;
  }
  case Star6Type: {
    Star *item = new Star(event->scenePos(), 6);
    item->setPos(event->pos());
    tempFigure = item;
    break;
  }
  case Star8Type: {
    Star *item = new Star(event->scenePos(), 8);
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
  case diff_figureType: {
    diff_figure *item = new diff_figure(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
  }
  case PainttType: {
    Paintt *item = new Paintt(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
  }
  default: {
    Rectangle *item = new Rectangle(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
  }
  }
  this->addItem(tempFigure);
}
