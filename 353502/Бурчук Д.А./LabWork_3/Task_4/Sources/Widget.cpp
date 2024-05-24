#include "../Headers/Widget.h"

Widget::Widget() : QWidget() {
    towerOfHanoi = new TowerOfHanoi;
    towerOfHanoi->makeRings();

    speed = 50;
    from = 1;
    to = 3;

    painter = new QPainter;

    timer = new QTimer;
    timer->start(1);
    connect(timer, SIGNAL(timeout()), SLOT(update()));
    globalTimer = new QTimer;
    globalTimer->start(1);

    closeButton = new QPushButton("Close", this);
    closeButton->setGeometry(1820, 10, 90, 30);
    connect(closeButton, SIGNAL(clicked(bool)), SLOT(close()));

    solveButton = new QPushButton("Solve", this);
    solveButton->setGeometry(1820, 50, 90, 30);
    connect(solveButton, SIGNAL(clicked(bool)), SLOT(solve()));

    setNumberOfRingsPushButton = new QPushButton("Set", this);
    setNumberOfRingsPushButton->setGeometry(1820, 90, 45, 30);
    connect(setNumberOfRingsPushButton, SIGNAL(clicked(bool)), SLOT(setNumberOfRings()));

    numberOfRingsSpinBox = new QSpinBox(this);
    numberOfRingsSpinBox->setGeometry(1870, 90, 40, 30);
    numberOfRingsSpinBox->setMinimum(MIN_COUNT_OF_RINGS);
    numberOfRingsSpinBox->setMaximum(MAX_COUNT_OF_RINGS);

    speedScrollbar = new QScrollBar(Qt::Horizontal, this);
    speedScrollbar->setGeometry(1820, 130, 90, 20);
    speedScrollbar->setMinimum(20);
    speedScrollbar->setMaximum(200);
    connect(speedScrollbar, SIGNAL(sliderMoved(int)), SLOT(changeSpeed()));
}

void Widget::paintEvent(QPaintEvent *event) {
    painter->begin(this);
    towerOfHanoi->drawStick(painter);
    painter->end();
}

void Widget::solve() {
    solveButton->setEnabled(false);
    setNumberOfRingsPushButton->setEnabled(false);
    numberOfRingsSpinBox->setEnabled(false);

    solving(from, to, towerOfHanoi->numberOfRings());
    if (to == 3 && from == 1) {
        towerOfHanoi->setStickStart(0, 0, towerOfHanoi->numberOfRings());
    } else {
        towerOfHanoi->setStickStart(towerOfHanoi->numberOfRings(), 0, 0);
    }
    std::swap(from, to);

    solveButton->setEnabled(true);
    setNumberOfRingsPushButton->setEnabled(true);
    numberOfRingsSpinBox->setEnabled(true);
}

void Widget::solving(uint from, uint to, uint number) {

    int temp = from == 3 || to == 3 ? from == 2 || to == 2 ? 1 : 2 : 3;
    if (number == 1) {
        thread.wait(10);
        towerOfHanoi->setStick(from, to);
        towerOfHanoi->_rings[number - 1].setPos(to);
        fromMovement = from;
        toMovement = to;
        numberMovement = number;
        thread.wait(10);
        moveRing();
        //QTimer::singleShot(10,this,SLOT(moveRing()));
    } else {
        solving(from, temp, number - 1);
        //moveRing(from, temp, number);

        towerOfHanoi->setStick(from, to);
        towerOfHanoi->_rings[number - 1].setPos(to);
        fromMovement = from;
        toMovement = to;
        numberMovement = number;
        thread.wait(10);
        moveRing();
        //QTimer::singleShot(10,this,SLOT(moveRing()));
        thread.wait(10);

        solving(temp, to, number - 1);
        towerOfHanoi->setStick(temp, to);
        fromMovement = temp;
        toMovement = to;
        numberMovement = number;
        thread.wait(10);
        moveRing();
        //QTimer::singleShot(10,this,SLOT(moveRing()));
        towerOfHanoi->setStick(to, temp);
        thread.wait(10);
    }
}

void Widget::moveRing() {
    qDebug() << speed;
    if (towerOfHanoi->_rings[numberMovement - 1].x() == -210 + (WIDTH + 10) * fromMovement) {
        if (towerOfHanoi->_rings[numberMovement - 1].y() > 100) {
            towerOfHanoi->_rings[numberMovement - 1].setPoint(
                    QPointF(towerOfHanoi->_rings[numberMovement - 1].x(), towerOfHanoi->_rings[numberMovement - 1].y() - speed));
            if (towerOfHanoi->_rings[numberMovement - 1].y() < 100) {
                towerOfHanoi->_rings[numberMovement - 1].setPoint(
                        QPointF(towerOfHanoi->_rings[numberMovement - 1].x(), 100.0));
                thread.wait(10);
                QCoreApplication::processEvents();
                update();
            } else {
                thread.wait(10);
                QCoreApplication::processEvents();
                update();
                moveRing();
                return;
            }
        }
    }

    if (fromMovement < toMovement) {
        towerOfHanoi->_rings[numberMovement - 1].setPoint(
                QPointF(towerOfHanoi->_rings[numberMovement - 1].x() + speed, towerOfHanoi->_rings[numberMovement - 1].y()));
        if (towerOfHanoi->_rings[numberMovement - 1].x() >= -210 + (WIDTH + 10) * toMovement) {
            towerOfHanoi->_rings[numberMovement - 1].setPoint(
                    QPointF(-210 + (WIDTH + 10) * toMovement, towerOfHanoi->_rings[numberMovement - 1].y()));
            thread.wait(10);
            QCoreApplication::processEvents();
            update();
        } else {
            thread.wait(10);
            QCoreApplication::processEvents();
            update();
            moveRing();
            return;
        }
    } else {
        towerOfHanoi->_rings[numberMovement - 1].setPoint(
                QPointF(towerOfHanoi->_rings[numberMovement - 1].x() - speed, towerOfHanoi->_rings[numberMovement - 1].y()));
        if (towerOfHanoi->_rings[numberMovement - 1].x() <= -210 + (WIDTH + 10) * toMovement) {
            towerOfHanoi->_rings[numberMovement - 1].setPoint(
                    QPointF(-210 + (WIDTH + 10) * toMovement, towerOfHanoi->_rings[numberMovement - 1].y()));
            thread.wait(10);
            QCoreApplication::processEvents();
            update();
        } else {
            thread.wait(10);
            QCoreApplication::processEvents();
            update();
            moveRing();
            return;
        }
    }

    if (towerOfHanoi->_rings[numberMovement - 1].y() <
        920 - (towerOfHanoi->stick(toMovement) + 1) * towerOfHanoi->_rings[numberMovement - 1].height() * 2) {
        towerOfHanoi->_rings[numberMovement - 1].setPoint(
                QPointF(towerOfHanoi->_rings[numberMovement - 1].x(), towerOfHanoi->_rings[numberMovement - 1].y() + speed));
        if (towerOfHanoi->_rings[numberMovement - 1].y() >
            920 - (towerOfHanoi->stick(toMovement) + 1) * towerOfHanoi->_rings[numberMovement - 1].height() * 2) {
            towerOfHanoi->_rings[numberMovement - 1].setPoint(
                    QPointF(towerOfHanoi->_rings[numberMovement - 1].x(),
                            920 - (towerOfHanoi->stick(toMovement) + 1) * towerOfHanoi->_rings[numberMovement - 1].height() * 2));
            thread.wait(10);
            QCoreApplication::processEvents();
            update();
        } else {
            thread.wait(10);
            QCoreApplication::processEvents();
            update();
            moveRing();
            return;
        }
    }
}

void Widget::setNumberOfRings() {
    from = 1;
    to = 3;
    towerOfHanoi->setNumberOfRings(numberOfRingsSpinBox->value());
    towerOfHanoi->setStickStart(towerOfHanoi->numberOfRings(), 0, 0);
    update();
}

void Widget::changeSpeed() {
    speed = speedScrollbar->value();
}
