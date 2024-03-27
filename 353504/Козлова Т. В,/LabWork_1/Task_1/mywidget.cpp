#include "mywidget.h"

MyWIdget::MyWIdget(QWidget* parent)
    : QWidget(parent)
{
    setFixedSize(1500, 900);

    elevator = new Elevator(700, 480, 275, 400, this);

    elevatorLayout = new QVBoxLayout(this);
    elevatorLayout->addWidget(elevator);

    fisrtFloorButton = new QPushButton("1", this);
    fisrtFloorButton->setGeometry(150, 400, 75, 75);
    fisrtFloorButton->setStyleSheet("font-size: 24px");
    connect(fisrtFloorButton, &QPushButton::clicked, this, &MyWIdget::firstFloorButtonClicked);

    secondFloorButton = new QPushButton("2", this);
    secondFloorButton->setGeometry(308, 400, 75, 75);
    secondFloorButton->setStyleSheet("font-size: 24px");
    connect(secondFloorButton, &QPushButton::clicked, this, &MyWIdget::secondFloorButtonClicked);

    openDoorsButton = new QPushButton("<>", this);
    openDoorsButton->setGeometry(308, 558, 75, 75);
    openDoorsButton->setStyleSheet("font-size: 24px");
    connect(openDoorsButton, &QPushButton::clicked, this, &MyWIdget::openDoorsButtonClicked);

    condition = new ElevatorCondition(0, 0, 0);

    moveDownTimer = new QTimer(this);
    connect(moveDownTimer, &QTimer::timeout, this, &MyWIdget::howToMove);

    moveUpTimer = new QTimer(this);
    connect(moveUpTimer, &QTimer::timeout, this, &MyWIdget::howToMove);

    openDoorsTimer = new QTimer(this);
    connect(openDoorsTimer, &QTimer::timeout, this, &MyWIdget::howToMove);
}

MyWIdget::~MyWIdget()
{

}

void MyWIdget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(0, 0, 700, 900, QBrush(QColor(128, 128, 128)));
    painter.fillRect(700, 0, 800, 490, QBrush(QColor(240, 223, 255)));
    painter.fillRect(700, 490, 800, 410, QBrush(QColor(255, 208, 203)));

    painter.fillRect(710, 90, 275, 800, QBrush(QColor(211, 211, 211, 150)));
    painter.fillRect(720, 100, 126, 790, QBrush(QColor(169, 169, 169, 150)));
    painter.fillRect(848, 100, 126, 790, QBrush(QColor(169, 169, 169, 150)));

    painter.drawLine(700, 490, 1500, 490);
    painter.drawLine(700, 889, 1500, 889);

    painter.setFont(QFont("Verdana", 40));
    painter.setPen(QColor(109, 109, 109));
    painter.drawText(50, 150, "МОГИЛЕВЛИФТМАШ");

    Q_UNUSED(event);
}

void MyWIdget::howToMove()
{
    if (elevator->isMoving()) return;
    if (elevator->isDoorsActive())
    {
        if(openDoorsTimer->isActive())
        {
            elevator->stopMovingDoors();
            elevator->openDoors();
        }
        openDoorsTimer->stop();
        return;
    }

    if (openDoorsTimer->isActive())
    {
        elevator->openDoors();
        openDoorsTimer->stop();
        return;
    }

    if (condition->currentfloor == 0)
    {
        if (condition->secondfloor == 1)
        {
            elevator->startMoveUp();
            elevator->openDoors();
            condition->currentfloor = 1;
            condition->secondfloor = 0;
            condition->firstfloor = 0;
        }
        moveDownTimer->stop();
        moveUpTimer->stop();
        return;
    }
    if (condition->currentfloor == 1)
    {
        if (condition->firstfloor == 1)
        {
            elevator->startMoveDown();
            elevator->openDoors();
            condition->currentfloor = 0;
            condition->firstfloor = 0;
            condition->secondfloor = 0;
        }
        moveDownTimer->stop();
        moveUpTimer->stop();
        return;
    }
}

void MyWIdget::firstFloorButtonClicked()
{
    condition->firstfloor = 1;
    moveDownTimer->start();
}

void MyWIdget::secondFloorButtonClicked()
{
    condition->secondfloor = 1;
    moveUpTimer->start();
}

void MyWIdget::openDoorsButtonClicked()
{
    openDoorsTimer->start();
}
