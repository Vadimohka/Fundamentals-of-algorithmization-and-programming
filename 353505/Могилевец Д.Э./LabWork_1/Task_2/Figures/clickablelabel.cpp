#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget *parent)
{
    setMouseTracking(true);
}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    QLabel::mousePressEvent(event);
    if (event->button() == Qt::LeftButton) {
        hide();
    }
}

