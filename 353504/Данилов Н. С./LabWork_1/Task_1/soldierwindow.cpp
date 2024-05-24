
#include "soldierwindow.h"

soldierWindow::soldierWindow(QWidget *) {
    *f = {250, 250};
}

void soldierWindow::paintEvent(QPaintEvent *pe) {
    QWidget::paintEvent(pe);
    QPainter painter(this);

    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(int(f->rx())-1000, int(f->ry()) + 200, 100000, 100);

    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(int(f->rx()) + 5, int(f->ry()) + 100, 10, 80 + 20 * sin(int(f->rx())/2));
    painter.drawRect(int(f->rx()) + 35, int(f->ry()) + 100, 10, 80 + 20 * sin(int(f->rx())/2 + 3.1415));
    painter.drawRect(int(f->rx()) - 10, int(f->ry()) + 170 + 20 * sin(int(f->rx())/2), 20, 10);
    painter.drawRect(int(f->rx()) + 25, int(f->ry()) + 170 + 20 * sin(int(f->rx())/2 + 3.1415), 20, 10);

    painter.setPen(Qt::darkGreen);
    painter.setBrush(Qt::darkGreen);
    painter.drawRect(int(f->rx()), int(f->ry()), 50, 100);
    painter.drawEllipse(int(f->rx()) + 5, int(f->ry()-50), 40, 40);
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawEllipse(int(f->rx()), int(f->ry()-40), 50, 50);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawEllipse(int(f->rx()) + 15, int(f->ry()-25), 5, 5);
    painter.drawEllipse(int(f->rx()) + 30, int(f->ry()-25), 5, 5);
    painter.drawEllipse(int(f->rx()) + 23, int(f->ry()-15), 2, 5);
    painter.drawEllipse(int(f->rx()) + 18, int(f->ry()-5), 12, 2);
    QPointF *points = new QPointF[3];
    points[0] = QPointF(int(f->rx())+5, int(f->ry())-20);
    points[1] = QPointF(int (f->rx())-30, int(f->ry())+20);
    points[2] = QPointF(int(f->rx())+5, int(f->ry())+20);
    painter.setPen(QPen(Qt::darkGreen, 10));
    painter.drawPolyline(points,3);
    if (int(f->rx()) == -50)
        f->rx() = QWidget::height();

    mymove::moveLeft(f, 0.015);

    update();
}
