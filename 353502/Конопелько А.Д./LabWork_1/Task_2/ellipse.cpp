#include "ellipse.h"

Ellipse::Ellipse() {

}

qreal Ellipse::findPerimeter()
{
    return 4 * (M_PI * 70 * 90 + 90 - 70) / (90 + 70);
}

qreal Ellipse::findSquare()
{
    return M_PI * 90 * 70;
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter -> drawEllipse(-70, -90, 140, 180);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

Ellipse::~Ellipse()
{

}
