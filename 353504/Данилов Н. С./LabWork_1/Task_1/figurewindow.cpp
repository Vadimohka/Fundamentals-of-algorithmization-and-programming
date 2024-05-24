
#include "figurewindow.h"


figureWindow::figureWindow(QWidget *pobj) {
    *f = {250, 250};
}

void figureWindow::paintEvent(QPaintEvent *pe) {
    QWidget::paintEvent(pe);
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(int(f->rx()), int(f->ry()), 50, 100);

    if (int(f->rx()) == -50)
        f->rx() = QWidget::height();

    mymove::moveLeft(f, 0.015);

    update();
}
