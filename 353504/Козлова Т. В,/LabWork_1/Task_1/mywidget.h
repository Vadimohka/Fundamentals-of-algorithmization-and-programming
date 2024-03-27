#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QPushButton>
#include <QVBoxLayout>

#include "elevator.h"

class MyWIdget : public QWidget
{
public:
    MyWIdget(QWidget* parent = nullptr);
    ~MyWIdget();

private:
    void paintEvent(QPaintEvent* event);

    void firstFloorButtonClicked();
    void secondFloorButtonClicked();
    void openDoorsButtonClicked();

    void howToMove();

    struct ElevatorCondition {
        uchar firstfloor:1;
        uchar secondfloor:1;
        uchar currentfloor:1;

        ElevatorCondition(uchar firstfloor, uchar secondfloor, uchar currentfloor)
            : firstfloor(firstfloor), secondfloor(secondfloor), currentfloor(currentfloor){}
    };

private:
    Elevator* elevator;
    ElevatorCondition* condition;
    QPushButton* fisrtFloorButton;
    QPushButton* secondFloorButton;
    QPushButton* openDoorsButton;
    QVBoxLayout* elevatorLayout;
    QTimer* moveDownTimer;
    QTimer* moveUpTimer;
    QTimer* openDoorsTimer;
};

#endif // MYWIDGET_H
