#include "elevator.h"

Elevator::Elevator(const QPointF &initPos, const QSizeF &initSize)
{
    setRect(QRectF(initPos, initSize));
    setSize(initPos, initSize);
    setSettings(2000, 2000, QPointF(0, -150), 3, false);
}

Elevator::~Elevator()
{
    delete LeftDoor;
    delete RightDoor;
    delete LeftWall;
    delete RightWall;
}

void Elevator::setSize(const QPointF& initPos, const QSizeF& initSize)
{
    QSizeF DoorsAndWallsSize = QSizeF(initSize.width()/4, initSize.height());
    QPointF LeftDoorTopLeftCorner = initPos + QPointF(initSize.width() / 4, 0);
    QPointF RightDoorTopLeftCorner = initPos + QPointF(initSize.width() / 2, 0);
    QPointF RightWallTopLeftCorner = initPos + QPointF(3 * initSize.width() / 4, 0);
    LeftWall = new MovingRectangle(initPos, DoorsAndWallsSize);
    LeftDoor = new MovingRectangle(LeftDoorTopLeftCorner, DoorsAndWallsSize);
    RightDoor = new MovingRectangle(RightDoorTopLeftCorner, DoorsAndWallsSize);
    RightWall = new MovingRectangle(RightWallTopLeftCorner, DoorsAndWallsSize);
    DoorsShift = QPointF(initSize.width() / 4, 0);
}

void Elevator::setSettings(qreal initTimeBetweenFloors, qreal initDoorOpenCloseTime,
                           const QPointF& initShiftBetweenFloors,
                           int initCurrFloor, bool initDoorAreOpened) {
    DoorOpenCloseTime = initDoorOpenCloseTime;
    BetweenFloorsTime = initTimeBetweenFloors;
    DoorsAreOpened = initDoorAreOpened;
    CurrFloor = initCurrFloor;
    ShiftBetweenFloors = initShiftBetweenFloors;
    openclosedoordelay = new QTimer;
}

void Elevator::drawCorp(QPainter & painter)
{
    painter.setBrush(Qt::darkGray);
    painter.setPen(Qt::black);
    painter.drawRect(this->getRect());
    painter.setBrush(Qt::gray);
    painter.drawRect(LeftWall->getRect());
    painter.drawRect(RightWall->getRect());
}

void Elevator::drawDoors(QPainter & painter)
{
    painter.setBrush(Qt::gray);
    painter.drawRect(LeftDoor->getRect());
    painter.drawRect(RightDoor->getRect());
}

void Elevator::openDoors()
{
    if (DoorsAreOpened) return;
    if (CheckIsAnimating(DoorOpenCloseTime)) return;
    DoorsAreOpened = true;
    LeftDoor->move(-DoorsShift, DoorOpenCloseTime);
    RightDoor->move(DoorsShift, DoorOpenCloseTime);

}

void Elevator::closeDoors()
{
    if (!DoorsAreOpened) return;
    if (CheckIsAnimating(DoorOpenCloseTime)) return;
    LeftDoor->move(DoorsShift, DoorOpenCloseTime);
    RightDoor->move(-DoorsShift, DoorOpenCloseTime);
    QObject::connect(openclosedoordelay, &QTimer::timeout, [=](){
        DoorsAreOpened = false;
        openclosedoordelay->stop();
    });
    openclosedoordelay->start(DoorOpenCloseTime);
}

void Elevator::goToFloor(int targetFloor)
{
    if (CurrFloor == targetFloor) return;
    if (DoorsAreOpened) {
        this->closeDoors();
        QTimer* closingDoorsTimer = new QTimer;
        QObject::connect(closingDoorsTimer, &QTimer::timeout, [=]{
            CheckIsAnimating(BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));
            this->move(ShiftBetweenFloors * (targetFloor - CurrFloor),
                       BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));
            LeftDoor->move(ShiftBetweenFloors * (targetFloor - CurrFloor),
                           BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));
            RightDoor->move(ShiftBetweenFloors * (targetFloor - CurrFloor),
                            BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));;
            LeftWall->move(ShiftBetweenFloors * (targetFloor - CurrFloor),
                           BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));
            RightWall->move(ShiftBetweenFloors * (targetFloor - CurrFloor),
                            BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));

            QTimer* rideTimer = new QTimer();
            QObject::connect(rideTimer, &QTimer::timeout, [=]{
                openDoors();
                delete rideTimer;
            });
            rideTimer->start(BetweenFloorsTime * qAbs((targetFloor - CurrFloor)) + 50);
            delete closingDoorsTimer;
            CurrFloor = targetFloor;
        });
        closingDoorsTimer->start(DoorOpenCloseTime + 50);
    }
    else
    {
        CheckIsAnimating(BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));
        this->move(ShiftBetweenFloors * (targetFloor - CurrFloor),
                   BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));
        LeftDoor->move(ShiftBetweenFloors * (targetFloor - CurrFloor),
                       BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));
        RightDoor->move(ShiftBetweenFloors * (targetFloor - CurrFloor),
                        BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));;
        LeftWall->move(ShiftBetweenFloors * (targetFloor - CurrFloor),
                       BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));
        RightWall->move(ShiftBetweenFloors * (targetFloor - CurrFloor),
                        BetweenFloorsTime * qAbs((targetFloor - CurrFloor)));

        QTimer* rideTimer = new QTimer();
        QObject::connect(rideTimer, &QTimer::timeout, [=]{
            openDoors();
            delete rideTimer;
        });
        rideTimer->start(BetweenFloorsTime * qAbs((targetFloor - CurrFloor)) + 50);
        CurrFloor = targetFloor;
    }
}

int Elevator::getCurrFloor()
{
    return CurrFloor;
}

bool Elevator::checkDoors()
{
    return DoorsAreOpened;
}

