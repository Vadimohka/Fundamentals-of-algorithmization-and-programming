#include "circularbutton.h"
#include <QPainter>
#include <QStyleOption>

CircularButton::CircularButton(const QString &text, const double width, const double height, QWidget *parent)
    : QPushButton(text, parent) {
    setFixedSize(width, height);
}

void CircularButton::setEllipseSize(double width, double height) {
    setFixedSize(width, height);
    update();
}

void CircularButton::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    QStyleOptionButton option;
    option.initFrom(this);

    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addEllipse(rect());

    if (underMouse()) {
        painter.fillPath(path, QBrush(QColor("red")));
        painter.setPen(QColor("white"));
    } else {
        painter.fillPath(path, QBrush(QColor("yellow")));
        painter.setPen(QColor("black"));
    }

    painter.setFont(QFont("Arial", 10));
    painter.drawText(rect(), Qt::AlignCenter, text());
    painter.setPen(Qt::NoPen);
    painter.drawPath(path);
    painter.setPen(QPen(Qt::black, 1));
    painter.drawPath(path);
}
