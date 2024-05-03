#include "elevator.h"

Elevator::Elevator(int x, int y, int width, int height, QWidget* parent)
    : Rectangle(x, y, width, height)
{
    openDoorsTimer = new QTimer(this);
    connect(openDoorsTimer, &QTimer::timeout, this, &Elevator::openingDoors);

    closeDoorsTimer = new QTimer(this);
    connect(closeDoorsTimer, &QTimer::timeout, this, &Elevator::closingDoors);

    Q_UNUSED(parent);
}

Elevator::~Elevator()
{

}

void Elevator::openDoors()
{
    openDoorsTimer->start(20);
}

bool Elevator::isDoorsActive()
{
    if (openDoorsTimer->isActive() || closeDoorsTimer->isActive()) return true;
    return false;
}

bool Elevator::isMoving()
{
    if (timerDown->isActive() || timerUp->isActive()) return true;
    return false;
}

void Elevator::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(x, y, width, height, QBrush(QColor(211, 211, 211)));
    painter.fillRect(leftdoorX, y + 10, width - 20, doorHeight, QBrush(QColor(194, 194, 194)));
    painter.drawPixmap((2 * x + width) / 2 - 65, y + 30,
                       QPixmap("/home/tanya/labs/lab1/1/luk.jpg").scaled(130, 200));
    painter.fillRect(leftdoorX, y + 10, leftdoorWidth, doorHeight, QBrush(QColor(169, 169, 169)));
    painter.fillRect(rightdoorX, y + 10, rightdoorWidth, doorHeight, QBrush(QColor(169, 169, 169)));

    Q_UNUSED(event);
}

void Elevator::openingDoors()
{
    if (this->isMoving()) return;

    leftdoorWidth -= 1;
    rightdoorX += 1;
    rightdoorWidth -=1;
    update();

    if (rightdoorWidth == 0) {
        openDoorsTimer->stop();
        closeDoorsTimer->start(20);
    }
}

void Elevator::closingDoors()
{
    leftdoorWidth += 1;
    rightdoorX -= 1;
    rightdoorWidth += 1;
    update();

    if (leftdoorWidth == width / 2 - 11) {
        closeDoorsTimer->stop();
    }
}

void Elevator::stopMovingDoors()
{
    openDoorsTimer->stop();
    closeDoorsTimer->stop();
}
