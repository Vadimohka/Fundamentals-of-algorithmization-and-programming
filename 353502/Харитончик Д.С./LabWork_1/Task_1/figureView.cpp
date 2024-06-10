#include "figureView.h"

figureView::figureView(QWidget *pobj) {
    *f = {80, 100};
}

void figureView::paintEvent(QPaintEvent *pe) {
    QWidget::paintEvent(pe);
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::yellow);
    painter.drawRect(int(f->rx()), int(f->ry()), 150, 60);

    if (int(f->ry()) == -60) f->ry() = QWidget::height();

    Rect::elevate(f, 0.0015);

    update();
}
