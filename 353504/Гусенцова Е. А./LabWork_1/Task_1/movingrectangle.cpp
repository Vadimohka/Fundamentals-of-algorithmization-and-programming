#include "movingrectangle.h"

void Rec::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    drawRec(&painter);

}

void Rec::drawRec(QPainter *painter)
{
    painter->save();

    QTransform transform;
    transform.translate(1020, 640);
    transform.rotate(angle);
    transform.translate(-1020, -640);
    painter->setTransform(transform);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);
    QBrush brushWT;
    brushWT.setColor(Qt::white);
    brushWT.setStyle(Qt::SolidPattern);

    painter->setPen(pen);
    painter->setBrush(brushWT);
    painter->drawRect(x, 340, 560, 300);
    painter->restore();
}

void Rec::UP()
{
    if (angle <89 && angle >=0) {
        angle++;
        repaint();
    }
}
// void Rec::STOP()
// {
//     per=false;
// }

void Rec::DOWN()
{
    if (angle >0 && angle <=90) {
        angle--;
        repaint();
    }
}
