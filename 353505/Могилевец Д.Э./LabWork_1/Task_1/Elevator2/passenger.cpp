#include "passenger.h"

Passenger::Passenger() {}

Passenger::~Passenger()
{
    delete head;
    delete openclosedoorsdelay;
}

Passenger::Passenger(QPointF initPos, qreal initinoutElevatorTime, qreal initonoutFloorTime, QColor color)
{
    head = new MovingRectangle(initPos, QSizeF(20, 20));
    this->setRect(QRectF(initPos.rx() + 5, initPos.ry(), 10, 70));
    onoutFloorShift = QPointF(-710, 0);
    onoutFloorTime = initonoutFloorTime;
    inoutElevatorShift = QPointF(-150, 0);
    inoutElevatorTime = initinoutElevatorTime;
    isInsideElevator = false;
    isOnFloor = false;
    ShiftBetweenFloors = QPointF(0, -150);
    BetweenFloorsTime = 2000;
    shirtColor = color;
    currFloor = 1;
    openclosedoorsdelay = new QTimer;
}

void Passenger::comeOnFloor()
{
    if (isOnFloor || isInsideElevator) return;
    if (CheckIsAnimating(onoutFloorTime)) return;
    this->move(onoutFloorShift, onoutFloorTime);
    head->move(onoutFloorShift, onoutFloorTime);
    QTimer* comingTimer = new QTimer();
    comingTimer->start(onoutFloorTime);
    QObject::connect(comingTimer, &QTimer::timeout, [=]{
        isOnFloor = true;
        delete comingTimer;
    });
}

void Passenger::comeOutFloor()
{
    if (!isOnFloor || isInsideElevator) return;
    if (CheckIsAnimating(onoutFloorTime)) return;
    this->move(-onoutFloorShift, onoutFloorTime);
    head->move(-onoutFloorShift, onoutFloorTime);
    isOnFloor = false;
}

void Passenger::goInElevator()
{
    if (!isOnFloor || isInsideElevator) return;
    if (CheckIsAnimating(inoutElevatorTime)) return;
    this->move(inoutElevatorShift, inoutElevatorTime);
    head->move(inoutElevatorShift, inoutElevatorTime);
    QObject::connect(openclosedoorsdelay, &QTimer::timeout, [=](){
        isInsideElevator = true;
        openclosedoorsdelay->stop();
    });
    openclosedoorsdelay->start(inoutElevatorTime);
}

void Passenger::goOutElevator()
{
    if (!isOnFloor || !isInsideElevator) return;
    if (CheckIsAnimating(inoutElevatorTime)) return;
    this->move(-inoutElevatorShift, inoutElevatorTime);
    head->move(-inoutElevatorShift, inoutElevatorTime);
    isInsideElevator = false;
}

void Passenger::draw(QPainter &painter)
{
    painter.setBrush(shirtColor);
    painter.drawRect(this->getRect());
    painter.setBrush(QColor(245, 237, 220));
    painter.drawRect(head->getRect());
}

void Passenger::goToFloor(int targetFloor)
{
    if (!isInsideElevator) return;
    if (CheckIsAnimating(qAbs(currFloor - targetFloor) * BetweenFloorsTime)) return;
    QTimer* doorsClosingTimer = new QTimer();
    doorsClosingTimer->start(2050);
    QObject::connect(doorsClosingTimer, &QTimer::timeout, [=]{
        this->move(-ShiftBetweenFloors * (currFloor - targetFloor), qAbs(currFloor - targetFloor) * BetweenFloorsTime);
        head->move(-ShiftBetweenFloors * (currFloor - targetFloor), qAbs(currFloor - targetFloor) * BetweenFloorsTime);
        currFloor = targetFloor;
        delete doorsClosingTimer;
    });
}

bool Passenger::checkIsInsideElevator()
{
    return isInsideElevator;
}

int Passenger::getCurrFloor()
{
    return currFloor;
}

bool Passenger::IsOnFloor()
{
    return isOnFloor;
}
