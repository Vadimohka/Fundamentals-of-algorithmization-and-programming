#include "circle.h"

constexpr int FIVE = 5;

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(QRectF((getEP().x() > getSP().x() ? getSP().x() : getEP().x()) + FIVE,
                                (getEP().y() > getSP().y() ? getSP().y() : getEP().y()) + FIVE,
                                qAbs(getEP().x() - getSP().x()) - (2 * FIVE),
                                qAbs(getEP().y() - getSP().y()) - (2 * FIVE)));

    setArea(M_PI * qAbs(getEP().x() - getSP().x()) * qAbs(getEP().y() - getSP().y())/4);
    setPerimeter(2 * M_PI * sqrt((pow(getEP().x() - getSP().x(), 2) + pow(getEP().y() - getSP().y(), 2))/2));

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
