#include "people.h"

People::People(int floor, const QColor& color, const QString name) : QGraphicsObject(), m_floor(floor), m_color(color), m_name(name)
{
    inside = false;
    m_floor = floor;
    connect(this, &People::entered, this, &People::handleEntered);
    connect(this, &People::floorChanged, this, &People::handleFloorChange);

    leftLegPos = 0;
    rightLegPos = 40;

    leftArmPos = 0;
    rightArmPos = 40;

    if (this->m_name == "Red")
        shiftX = 80;

    else if (this->m_name == "Green")
        shiftX = 90;

    else if (this->m_name == "Blue")
        shiftX = 100;

    shiftY = -(m_floor-1)*250 + 150;

    timer = new QTimer(this);
}

QRectF People::boundingRect() const
{
    return QRectF(110 + shiftX, shiftY, 50, 100);
}

void People::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush(m_color);
    QPen pen(m_color);

    pen.setWidth(2);

    painter->setPen(pen);
    painter->setBrush(brush);

    painter->translate(rect.bottomLeft());

    int hipY = -40;
    int hipX = 20;

    painter->drawLine(leftLegPos, 0, hipX, hipY);
    painter->drawLine(rightLegPos, 0, hipX, hipY);
    painter->drawLine(hipX, hipY, hipX, -80);
    painter->drawLine(leftArmPos, -50, 20, -70);
    painter->drawLine(rightArmPos, -50, 20, -70);
    painter->drawEllipse(QRectF(10, -100, 20, 20));
}

int People::getFloor()
{
    return m_floor;
}

void People::enter()
{
    inside = !inside;
    emit entered(inside);
}

void People::setFloor(int floor)
{
    if (inside) {
        m_floor = floor;
        emit floorChanged(floor);
    }
}

void People::handleFloorChange(int newFloor)
{
    targetY = -(newFloor-1)*250 + 150;
    connect(timer, &QTimer::timeout, this, &People::incrementYPosition);
    timer->start(1);
}

void People::incrementYPosition()
{
    if(shiftY < targetY){
        shiftY++;
        update();
    } else if (shiftY > targetY){
        shiftY--;
        update();
    } else {
        disconnect(timer, &QTimer::timeout, this, &People::incrementYPosition);
        timer->stop();
    }
}

void People::handleEntered(bool inside)
{

    delta = 0;

    if (this->m_name == "Red")
        delta += 80;

    else if (this->m_name == "Green")
        delta += 90;

    else if (this->m_name == "Blue")
        delta += 100;

    targetX = inside ? -delta : delta;
    connect(timer, &QTimer::timeout, this, &People::incrementXPosition);
    timer->start(1);

    update();
}

void People::incrementXPosition()
{
    const int minPos = 0;
    const int maxPos = 40;
    const int step = 1;

    leftLegPos = (leftLegPos + step) % (maxPos + 1);
    // leftArmPos = (leftArmPos + step) % (maxPos + 1);
    rightLegPos = (rightLegPos - step + maxPos + 1) % (maxPos + 1);
    // rightArmPos = (rightArmPos - step + maxPos + 1) % (maxPos + 1);
    if (shiftX < targetX) {
        shiftX++;
        update();
    } else if (shiftX > targetX) {
        shiftX--;
        update();
    } else {
        disconnect(timer, &QTimer::timeout, this, &People::incrementXPosition);
        leftLegPos = 0;
        rightLegPos = 40;
        update();
        timer->stop();
        emit incrementComplete();
    }
}
