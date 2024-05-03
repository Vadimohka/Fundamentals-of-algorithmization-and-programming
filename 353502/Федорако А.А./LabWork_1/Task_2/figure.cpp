#include "figure.h"

Figure::Figure(QPointF point) : QGraphicsItem() {
  this->setFirstPoint(mapFromScene(point));
  this->setSecondPoint(mapFromScene(point));
  area = 0;
  perimetr = 0;
  moveFigureAlongX = 0;
  moveFigureAlongY = 0;
}

void Figure::setTypeFigure(const int type) {
  typeFigure = type;
}

int Figure::getTypeFigure() const {
  return typeFigure;
}

void Figure::addValueRotateAngle(int valueChangeAngle) {
  rotateAngle += valueChangeAngle;
}

void Figure::resetNullRotateAngle() {
  rotateAngle = 0;
}

int Figure::getRotateAngle() {
  return rotateAngle;
}

QRectF Figure::boundingRect() const {
  return QRectF(getFirstPoint().x(), getFirstPoint().y(), getHorizontalSide(),
                getVerticalSide());
}

double Figure::getHorizontalSide() const {
  return horizontalSide;
}

double Figure::getVerticalSide() const {
  return verticalSide;
}

void Figure::countHorizontalSide() {
  if (getTypeFigure() == FigureCircle || getTypeFigure() == FigureSquare) {
    double side = sqrt(pow(getSecondPoint().x() - getFirstPoint().x(), 2) +
                       pow(getSecondPoint().y() - getFirstPoint().y(), 2)) /
                  sqrt(2);

    if (getQuarter() == 4 || getQuarter() == 1) {
      horizontalSide = side;
    } else {
      horizontalSide = -side;
    }
  } else {
    horizontalSide = getSecondPoint().x() - getFirstPoint().x();
  }
}

void Figure::countVerticalSide() {

  if (getTypeFigure() == FigureCircle || getTypeFigure() == FigureSquare) {
    double side = sqrt(powl(getSecondPoint().x() - getFirstPoint().x(), 2) +
                       powl(getSecondPoint().y() - getFirstPoint().y(), 2)) /
                  sqrt(2);
    if (getQuarter() == 4 || getQuarter() == 3) {
      verticalSide = side;
    } else
      verticalSide = -side;
  } else
    verticalSide = getSecondPoint().y() - getFirstPoint().y();
}

void Figure::setFirstPoint(const QPointF point) {

  firstPoint = mapFromScene(point);
}

void Figure::setSecondPoint(const QPointF point) {
  countHorizontalSide();
  countVerticalSide();
  secondPoint = mapFromScene(point);
}

QPointF Figure::getFirstPoint() const {
  return firstPoint;
}

QPointF Figure::getSecondPoint() const {

  return secondPoint;
}

QPointF Figure::getCentreFigure() {
  return centreFigure;
}

void Figure::setCentreFigure() {
  if (getTypeFigure() == FigureFivePointerStar ||
      getTypeFigure() == FigureSixPointerStar ||
      getTypeFigure() == FigureEightPointerStar) {
    centreFigure.setX(getFirstPoint().x());
    centreFigure.setY(getFirstPoint().y());
  } else {
    centreFigure.setX(boundingRect().center().x());
    centreFigure.setY(boundingRect().center().y());
  }
}

void Figure::setCentreFigureExternally(const QPointF point) {
  centreFigure = point;
}
void Figure::countQuarter() {
  if (getFirstPoint().x() <= getSecondPoint().x() &&
      getFirstPoint().y() >= getSecondPoint().y()) {
    quarter = 1;
  } else if (getFirstPoint().x() >= getSecondPoint().x() &&
             getFirstPoint().y() >= getSecondPoint().y()) {
    quarter = 2;
  } else if (getFirstPoint().x() >= getSecondPoint().x() &&
             getFirstPoint().y() <= getSecondPoint().y()) {
    quarter = 3;
  } else {
    quarter = 4;
  }
}

int Figure::getQuarter() const {
  return quarter;
}

void Figure::setArea(double newAreaValue) {
  area = newAreaValue;
}

double Figure::getArea() {
  return area;
}

void Figure::setPerimetr(double newPerimetrValue) {
  perimetr = newPerimetrValue;
}

double Figure::getPerimetr() {
  return perimetr;
}

void Figure::setFirstPointExternally(QPointF point) {
  firstPoint = point;
}
void Figure::setSecondPointExternally(QPointF point) {
  secondPoint = point;
}

void Figure::setMoveFigureAlongY(double newValueMoveFigureAlongY) {
  moveFigureAlongY = newValueMoveFigureAlongY;
}

void Figure::setMoveFigureAlongX(double newValueMoveFigureAlongX) {
  moveFigureAlongX = newValueMoveFigureAlongX;
}

double Figure::getMoveFigureAlongX() {
  return moveFigureAlongX;
}

double Figure::getMoveFigureAlongY() {
  return moveFigureAlongY;
}
