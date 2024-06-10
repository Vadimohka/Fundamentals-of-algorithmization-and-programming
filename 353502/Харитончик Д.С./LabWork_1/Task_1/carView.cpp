#include "carView.h"
#include <QTimer>

carView::carView(QWidget *) {
    *f = {15, 65};
    doorsOpen = !doorsOpen;
    lightsOn = !lightsOn;

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &carView::animate);
    const int timeOfAction = 1000;
    timer->start(timeOfAction);
}

void carView::animate() {
    doorsOpen = !doorsOpen;
    lightsOn = !lightsOn;

    update();
}

void carView::paintEvent(QPaintEvent *pe) {
    QWidget::paintEvent(pe);
    QPainter painter(this);
    painter.setPen(Qt::black);

    QVector<QPoint> trapezoidPoints;
    int centerX = width() / 2;
    int trapezoidWidth = 80;
    int trapezoidHeight = 40;

    trapezoidPoints << QPoint(centerX - trapezoidWidth / 2, 120)
                    << QPoint(centerX + trapezoidWidth / 2, 120)
                    << QPoint(centerX + trapezoidWidth / 4, 120 - trapezoidHeight)
                    << QPoint(centerX - trapezoidWidth / 4, 120 - trapezoidHeight);

    painter.setBrush(Qt::black);
    painter.drawPolygon(trapezoidPoints);

    painter.setBrush(Qt::gray);
    painter.drawRect(centerX - trapezoidWidth / 2 - 10, 110, trapezoidWidth + 30, 30);
    painter.setBrush(Qt::white);
    painter.drawEllipse(centerX - trapezoidWidth / 2 - 15, 120 + 10, 30, 30);
    painter.drawEllipse(centerX + trapezoidWidth / 2 - 15, 120 + 10, 30, 30);

    painter.setBrush(Qt::black);
    painter.drawEllipse(centerX - trapezoidWidth / 2 - 5, 120 + 20, 10, 10);
    painter.drawEllipse(centerX + trapezoidWidth / 2 - 5, 120 + 20, 10, 10);

    // отрисовка дверей
    if (doorsOpen) {
        // открытые двери
        painter.setBrush(Qt::black);

        // отрисовка левой двери
        QVector<QPoint> leftDoorPoints;
        leftDoorPoints << QPoint(centerX - trapezoidWidth / 4 - 10, 110)
                       << QPoint(centerX - trapezoidWidth / 4 + 10, 110)
                       << QPoint(centerX - trapezoidWidth / 4 + 10, 140);
        painter.drawPolygon(leftDoorPoints);

        // отрисовка правой двери
        QVector<QPoint> rightDoorPoints;
        rightDoorPoints << QPoint(centerX + trapezoidWidth / 4 - 10, 110)
                        << QPoint(centerX + trapezoidWidth / 4 + 10, 110)
                        << QPoint(centerX + trapezoidWidth / 4 + 10, 140);
        painter.drawPolygon(rightDoorPoints);
    } else {
        // закрытые двери
        painter.setBrush(Qt::black);

        // отрисовка ручек
        painter.drawEllipse(centerX - trapezoidWidth / 4 - 5, 115, 5, 5);
        painter.drawEllipse(centerX + trapezoidWidth / 4, 115, 5, 5);
    }

    // отрисовка фар
    if (lightsOn) {
        // включенные фары
        painter.setBrush(Qt::red);
        painter.drawRect(centerX - trapezoidWidth / 2 - 15, 110, 17, 17); // отрисовка левой фары

        painter.setBrush(Qt::yellow);
        painter.drawEllipse(centerX + trapezoidWidth / 2 + 5, 110, 20, 20); // отрисовка правой фары
    } else {
        // выключенные фары
        painter.setBrush(Qt::gray);
        painter.drawRect(centerX - trapezoidWidth / 2 - 15, 110, 17, 17); // отрисовка левой фары
        painter.drawEllipse(centerX + trapezoidWidth / 2 + 5, 110, 20, 20); // отрисовка правой фары
    }

    update();
}
