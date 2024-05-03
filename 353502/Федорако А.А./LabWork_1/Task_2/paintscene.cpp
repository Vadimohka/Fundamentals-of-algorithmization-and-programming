#include "paintscene.h"

PaintScene::PaintScene(QObject* parent) : QGraphicsScene(parent) {
  pointerSetFigure = -1;
}

int PaintScene::getTypeFigure() {
  return typeFigure;
}

void PaintScene::setTypeFigure(const int type) {
  typeFigure = type;
}

void PaintScene::actionFigureSizeIncrease() {
  if (nowFigureSelection->getTypeFigure() == FivePointerStarTypeScene ||
      nowFigureSelection->getTypeFigure() == SixPointerStarTypeScene ||
      nowFigureSelection->getTypeFigure() == EightPointerStarTypeScene) {

    QPointF firstPointToIncrease =
        nowFigureSelection->getSecondPoint() +
        0.01 * (nowFigureSelection->getSecondPoint() -
                nowFigureSelection->getCentreFigure());

    nowFigureSelection->setSecondPointExternally(firstPointToIncrease);
  } else {
    QPointF firstPointToIncrease =
        nowFigureSelection->getFirstPoint() +
        0.01 * (nowFigureSelection->getFirstPoint() -
                nowFigureSelection->getCentreFigure());

    QPointF secondPointToIncrease =
        nowFigureSelection->getSecondPoint() +
        0.01 * (nowFigureSelection->getSecondPoint() -
                nowFigureSelection->getCentreFigure());

    nowFigureSelection->setFirstPointExternally(firstPointToIncrease);
    nowFigureSelection->setSecondPointExternally(secondPointToIncrease);

    nowFigureSelection->countQuarter();
    nowFigureSelection->countHorizontalSide();
    nowFigureSelection->countVerticalSide();
  }
  update();
}

void PaintScene::actionFigureSizeDecrease() {
  if (nowFigureSelection->getTypeFigure() == FivePointerStarTypeScene ||
      nowFigureSelection->getTypeFigure() == SixPointerStarTypeScene ||
      nowFigureSelection->getTypeFigure() == EightPointerStarTypeScene) {

    QPointF firstPointToIncrease =
        nowFigureSelection->getSecondPoint() -
        0.01 * (nowFigureSelection->getSecondPoint() -
                nowFigureSelection->getCentreFigure());

    nowFigureSelection->setSecondPointExternally(firstPointToIncrease);

  } else {
    QPointF firstPointToIncrease =
        nowFigureSelection->getFirstPoint() -
        0.01 * (nowFigureSelection->getFirstPoint() -
                nowFigureSelection->getCentreFigure());

    QPointF secondPointToIncrease =
        nowFigureSelection->getSecondPoint() -
        0.01 * (nowFigureSelection->getSecondPoint() -
                nowFigureSelection->getCentreFigure());

    nowFigureSelection->setFirstPointExternally(firstPointToIncrease);
    nowFigureSelection->setSecondPointExternally(secondPointToIncrease);
    nowFigureSelection->countQuarter();
    nowFigureSelection->countHorizontalSide();
    nowFigureSelection->countVerticalSide();
  }
  update();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
  switch (typeFigure) {
    case ChangePositionTypeScene: {
      QPointF pointToCheck;
      pointToCheck = (event->scenePos());

      QPointF change = pointToCheck - nowFigureSelection->getCentreFigure();

      nowFigureSelection->setPos(change);

      nowFigureSelection->setMoveFigureAlongX(
          pointToCheck.x() - nowFigureSelection->getCentreFigure().x());
      nowFigureSelection->setMoveFigureAlongY(
          pointToCheck.y() - nowFigureSelection->getCentreFigure().y());
      break;
    }

    default: {
      nowFigureSelection->resetNullRotateAngle();
      nowFigureSelection->countQuarter();
      nowFigureSelection->setCentreFigure();
      nowFigureSelection->setSecondPoint(event->scenePos());
      break;
    }
  }
  this->update(QRectF(0, 0, this->width(), this->height()));
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  if (typeFigure == ChangePositionTypeScene && getSizeSetFigures() == 0) {
    typeFigure = RectangleTypeScene;
  }
  switch (typeFigure) {
    case SquareTypeScene: {
      Square* item = new Square(event->scenePos());
      item->setPos(event->pos());
      nowFigureSelection = item;
      nowFigureSelection->setTypeFigure(SquareTypeScene);
      pointerSetFigure = setFigures.size();
      break;
    }
    case RombTypeScene: {
      Romb* item = new Romb(event->scenePos());
      item->setPos(event->pos());
      nowFigureSelection = item;
      nowFigureSelection->setTypeFigure(RombTypeScene);
      pointerSetFigure = setFigures.size();
      break;
    }
    case RectangleTypeScene: {
      Rectangle* item = new Rectangle(event->scenePos());
      item->setPos(event->pos());
      nowFigureSelection = item;
      nowFigureSelection->setTypeFigure(RectangleTypeScene);
      pointerSetFigure++;
      break;
    }
    case TriangleTypeScene: {
      Triangle* item = new Triangle(event->scenePos());
      item->setPos(event->pos());
      nowFigureSelection = item;
      nowFigureSelection->setTypeFigure(TriangleTypeScene);
      pointerSetFigure = setFigures.size();
      break;
    }
    case CircleTypeScene: {
      Circle* item = new Circle(event->scenePos());
      item->setPos(event->pos());
      nowFigureSelection = item;
      nowFigureSelection->setTypeFigure(CircleTypeScene);
      pointerSetFigure = setFigures.size();
      break;
    }
    case FivePointerStarTypeScene: {
      FivePointsStar* item = new FivePointsStar(event->scenePos());
      item->setPos(event->pos());
      nowFigureSelection = item;
      nowFigureSelection->setTypeFigure(FivePointerStarTypeScene);
      pointerSetFigure = setFigures.size();
      break;
    }
    case SixPointerStarTypeScene: {
      SixPointsStar* item = new SixPointsStar(event->scenePos());
      item->setPos(event->pos());
      nowFigureSelection = item;
      item->setTypeFigure(SixPointerStarTypeScene);
      pointerSetFigure = setFigures.size();
      break;
    }
    case EightPointerStarTypeScene: {
      EightPointsStar* item = new EightPointsStar(event->scenePos());
      item->setPos(event->pos());
      nowFigureSelection = item;
      nowFigureSelection->setTypeFigure(EightPointerStarTypeScene);
      pointerSetFigure = setFigures.size();
      break;
    }
    case ChangePositionTypeScene: {
      QPointF pointToCheck;
      pointToCheck = (event->scenePos());
      nowFigureSelection = setFigures[pointerSetFigure];
      nowFigureSelection->setPos(pointToCheck -
                                 nowFigureSelection->getCentreFigure());
      nowFigureSelection->setMoveFigureAlongX(
          pointToCheck.x() - nowFigureSelection->getCentreFigure().x());
      nowFigureSelection->setMoveFigureAlongY(
          pointToCheck.y() - nowFigureSelection->getCentreFigure().y());
      break;
    }
    case HexagonTypeScene: {
      Hexagon* item = new Hexagon(event->scenePos());
      item->setPos(event->pos());
      nowFigureSelection = item;
      nowFigureSelection->setTypeFigure(HexagonTypeScene);
      pointerSetFigure = setFigures.size();
      break;
    }
    default: {
      Rectangle* item = new Rectangle(event->scenePos());
      item->setPos(event->pos());
      nowFigureSelection = item;
      nowFigureSelection->setTypeFigure(RectangleTypeScene);
      pointerSetFigure++;
      break;
    }
  }
  this->addItem(nowFigureSelection);
  if (typeFigure != ChangePositionTypeScene)
    setFigures.push_back(nowFigureSelection);
  updateNowFigureSelection();
}

void PaintScene::updateNowFigureSelection() {
  if (getSizeSetFigures() > 0)
    nowFigureSelection = setFigures[pointerSetFigure];
}

void PaintScene::actionRotateFigureRight() {

  nowFigureSelection->addValueRotateAngle(1);

  nowFigureSelection->setTransformOriginPoint(
      nowFigureSelection->getCentreFigure());

  nowFigureSelection->setRotation(nowFigureSelection->getRotateAngle());
}

void PaintScene::actionRotateFigureLeft() {

  nowFigureSelection->addValueRotateAngle(-1);

  nowFigureSelection->setTransformOriginPoint(
      nowFigureSelection->getCentreFigure());

  nowFigureSelection->setRotation(nowFigureSelection->getRotateAngle());
}

Figure* PaintScene::getNowFigureSelection() {
  return setFigures[pointerSetFigure];
}

void PaintScene::changeToNextPointerSetFigure() {
  if (getSizeSetFigures() > 0) {
    if (pointerSetFigure < static_cast<int>(setFigures.size() - 1))
      pointerSetFigure++;
    nowFigureSelection = setFigures[pointerSetFigure];
  }
}

void PaintScene::changeToPreviosPointerSetFigure() {
  if (getSizeSetFigures() > 0) {
    if (pointerSetFigure > 0)
      pointerSetFigure--;
    nowFigureSelection = setFigures[pointerSetFigure];
  }
}

void PaintScene::clearScene() {
  setFigures.clear();
  pointerSetFigure = -1;
  this->clear();
}

int PaintScene::getPointerSetFigure() {
  return pointerSetFigure;
}

void PaintScene::deleteFigure() {
  if (getSizeSetFigures() > 0) {
    removeItem(setFigures[pointerSetFigure]);
    setFigures.erase(setFigures.begin() + pointerSetFigure);
    if (pointerSetFigure == 0 && setFigures.size() == 0)
      pointerSetFigure = -1;
    else if (!(pointerSetFigure == 0))
      pointerSetFigure--;
  }
}

int PaintScene::getSizeSetFigures() {
  return setFigures.size();
}

void PaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
  if (getNowFigureSelection()->getFirstPoint() ==
      getNowFigureSelection()->getSecondPoint())
    deleteFigure();
}
