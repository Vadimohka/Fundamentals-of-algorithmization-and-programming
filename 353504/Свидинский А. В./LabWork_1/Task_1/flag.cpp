#include "flag.h"
#include <QPainter>
#include <QPropertyAnimation>

Flag::Flag(QWidget *parent) : MovingRectangle(parent)
{
    setFixedSize(100, 100);
}

void Flag::raiseFlag() {
    moveTo(QPoint(x(), 120));
}

void Flag::lowerFlag() {
    moveTo(QPoint(x(), 220));
}

void Flag::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int flagWidth = width();
    int flagHeight = flagWidth / 3;
    QRect flagRect(0, 0, flagWidth, flagHeight);

    painter.fillRect(flagRect, Qt::white);

    flagRect.translate(0, flagHeight);
    painter.fillRect(flagRect, QColorConstants::Svg::dodgerblue);

    flagRect.translate(0, flagHeight);
    painter.fillRect(flagRect, Qt::red);
}
