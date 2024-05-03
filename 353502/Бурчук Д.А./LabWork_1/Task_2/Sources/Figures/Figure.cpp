#include "../../Headers/Figure.h"


Figure::Figure(QWidget *parent, std::vector <QPointF> points) : QWidget(parent), points(points) {
    this->setParent(parent);

    this->_timer = new QTimer;

    this->_center = new QPointF;

    this->_perimeter = 0;

    this->_area = 0;
}


Figure::~Figure() {
    delete this->_timer;

    delete this->_center;
}


void Figure::drawPress(QMouseEvent *event) {
    this->_insertionPoint.setX(event->x());

    this->_insertionPoint.setY(event->y());
}

void Figure::startRotationLeft() {
    _timer->start(10);

    Figure::connect(_timer,
                    SIGNAL(timeout()),
                    this,
                    SLOT(rotateLeft()));
}

void Figure::stopRotationLeft() {
    _timer->stop();

    Figure::disconnect(_timer,
                       SIGNAL(timeout()),
                       this,
                       SLOT(rotateLeft()));
}

void Figure::rotateLeft() {
    const double t = 0.01;
    for (int i = 0; i < points.size(); i++) {
        long double newX =
                (points[i].x() - _center->x()) * qCos(t) + (points[i].y() - _center->y()) * qSin(t) + _center->x();
        long double newY =
                (points[i].y() - _center->y()) * qCos(t) - (points[i].x() - _center->x()) * qSin(t) + _center->y();
        points[i].setX(newX);
        points[i].setY(newY);
    }

    this->_polygon.clear();
    for (int i = 0; i < points.size(); i++) { this->_polygon << points[i]; }

    findArea();
    findPerimeter();
    update();
}

void Figure::startRotationRight() {
    _timer->start(10);

    Figure::connect(_timer, SIGNAL(timeout()), this, SLOT(rotateRight()));
}

void Figure::stopRotationRight() {
    _timer->stop();

    Figure::disconnect(_timer, SIGNAL(timeout()), this, SLOT(rotateRight()));
}

void Figure::rotateRight() {
    const double t = -0.01;
    for (auto &point: points) {
        long double newX =
                (point.x() - _center->x()) * qCos(t) + (point.y() - _center->y()) * qSin(t) + _center->x();
        long double newY =
                (point.y() - _center->y()) * qCos(t) - (point.x() - _center->x()) * qSin(t) + _center->y();
        point.setX(newX);
        point.setY(newY);
    }

    this->_polygon.clear();
    for (auto point: points) { this->_polygon << point; }

    findArea();
    findPerimeter();
    update();
}

void Figure::startIncreasingSize() {
    _timer->start(10);

    Figure::connect(_timer, SIGNAL(timeout()), this, SLOT(increasingSize()));
}

void Figure::stopIncreasingSize() {
    _timer->stop();

    Figure::disconnect(_timer, SIGNAL(timeout()), this, SLOT(increasingSize()));
}

void Figure::increasingSize() {
    const double t = 1.01;
    if (qSqrt(qPow(points[0].x() - _center->x(), 2) + qPow(points[0].y() - _center->y(), 2)) < 600) {
        for (auto &point: points) {
            long double newX = _center->x() + (point.x() - _center->x()) * t;
            long double newY = _center->y() + (point.y() - _center->y()) * t;
            point.setX(newX);
            point.setY(newY);
        }

        long double newX = _center->x() + (_insertionPoint.x() - _center->x()) * t;
        long double newY = _center->y() + (_insertionPoint.y() - _center->y()) * t;
        _insertionPoint.setX(newX);
        _insertionPoint.setY(newY);

        this->_polygon.clear();

        for (auto point: points) { this->_polygon << point; }

        findArea();
        findPerimeter();
        update();
    }
}

void Figure::startDiminishingSize() {
    _timer->start(10);

    Figure::connect(_timer, SIGNAL(timeout()), this, SLOT(diminishingSize()));
}

void Figure::stopDiminishingSize() {
    _timer->stop();

    Figure::disconnect(_timer, SIGNAL(timeout()), this, SLOT(diminishingSize()));
}

void Figure::diminishingSize() {
    const double angle = 0.99;
    if (qSqrt(qPow(points[0].x() - _center->x(), 2) + qPow(points[0].y() - _center->y(), 2)) > 30) {
        for (auto &point: points) {
            long double newX = _center->x() + (point.x() - _center->x()) * angle;
            long double newY = _center->y() + (point.y() - _center->y()) * angle;

            point.setX(newX);
            point.setY(newY);
        }

        long double newX = _center->x() + (_insertionPoint.x() - _center->x()) * angle;
        long double newY = _center->y() + (_insertionPoint.y() - _center->y()) * angle;
        _insertionPoint.setX(newX);
        _insertionPoint.setY(newY);

        this->_polygon.clear();

        for (auto point: points) { this->_polygon << point; }

        findArea();

        findPerimeter();

        update();
    }
}


void Figure::startMoving(QMouseEvent *event) {
    //eventClickC.setX(eventMove.x());

    //eventClickC.setY(eventMove.y());
    //this->_center->setX(-eventMove.x() + _center->x());

    //this->_center->setY(-eventMove.y() + _center->y());

    eventMove.setX(event->x());

    eventMove.setY(event->y());

    movingInTime();

    update();
}


void Figure::movingInTime() {
    this->_center->setX(+eventMove.x() - eventClickC.x());

    this->_center->setY(+eventMove.y() - eventClickC.y());

    this->_insertionPoint.setX(+eventMove.x() - eventClickI.x());

    this->_insertionPoint.setY(+eventMove.y() - eventClickI.y());

    for (int i = 0; i < points.size(); i++) {
        points[i].setX(eventMove.x() - eventDifference[i].x());

        points[i].setY(eventMove.y() - eventDifference[i].y());
    }

    _polygon.clear();

    for (auto &point: points) {
        _polygon << point;
    }
}

void Figure::movingClick(QMouseEvent *event) {
    eventClickC.setX(event->x() - _center->x());

    eventClickC.setY(event->y() - _center->y());

    eventClickI.setX(event->x() - _insertionPoint.x());

    eventClickI.setY(event->y() - _insertionPoint.y());

    eventDifference = points;

    for (auto &dif: eventDifference) {
        dif.setX(event->x() - dif.x());

        dif.setY(event->y() - dif.y());
    }

    update();
}

void Figure::changeStar(int newThorns) {
    _thorns = newThorns;
    update();
}
