#ifndef LAB3TASK1_WIDGET_H
#define LAB3TASK1_WIDGET_H

#include "QCoreApplication"
#include "QPushButton"
#include "QScrollBar"
#include "QSpinBox"
#include "QThread"
#include "QTimer"

#include "TowerOfHanoi.h"

class Widget : public QWidget {
    Q_OBJECT
    TowerOfHanoi *towerOfHanoi;
    QPushButton *closeButton;
    QPushButton *solveButton;
    QPushButton *setNumberOfRingsPushButton;
    QSpinBox *numberOfRingsSpinBox;
    QScrollBar *speedScrollbar;

    QTimer *timer;
    QTimer *globalTimer;
    QPainter *painter;
    QThread thread;

    int speed;
    int from;
    int to;

    uint fromMovement;
    uint toMovement;
    uint numberMovement;
public slots:

    void solve();

    void solving(uint from, uint to, uint number);

public:
    explicit Widget();

    void paintEvent(QPaintEvent *event) override;

public slots:

    void moveRing();

    void setNumberOfRings();
    void changeSpeed();
};

#endif//LAB3TASK1_WIDGET_H
