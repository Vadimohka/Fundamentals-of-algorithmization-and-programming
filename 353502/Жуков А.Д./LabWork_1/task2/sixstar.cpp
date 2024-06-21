#include "sixstar.h"

constexpr int ANGLE_MULTIPLIER = 16;
constexpr int RIGHT_ANGLE = 90;
constexpr int STRAIGHT_ANGLE = 180;

constexpr int AREA_FORMULA_CONST = 8;

void SixStar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPointF dp = QPointF(getEP().x() - getSP().x(), getEP().y() - getSP().y());
    double a = 1;
    double b = 1;

    if (getEP().x() > getSP().x() && getEP().y() < getSP().y())
    {
        a *= -1; b *= -1;
    }
    else if (getEP().x() < getSP().x() && getEP().y() < getSP().y())
    {
        a *= -1;
    }

    double b1 = b;
    if ((getEP().x() < getSP().x() && getEP().y() < getSP().y()) || (getEP().x() < getSP().x() && getEP().y() > getSP().y()))
    {
        b1 *= -1;
    }

    QRectF rectangle(QPointF(getSP().x() + dp.x()/2, getSP().y() + dp.y()/4), QPointF(getEP().x(), getEP().y() - dp.y()/4));
    int startAngle = b1 * RIGHT_ANGLE * ANGLE_MULTIPLIER;
    int spanAngle = -b * STRAIGHT_ANGLE * ANGLE_MULTIPLIER;
    painter->drawArc(rectangle, startAngle, spanAngle);

    rectangle = QRectF(QPointF(getSP().x() + dp.x()/4, getSP().y() + dp.y()/2), QPointF(getEP().x() - dp.x()/4, getEP().y()));
    startAngle = 0;
    spanAngle = -a * STRAIGHT_ANGLE * ANGLE_MULTIPLIER;
    painter->drawArc(rectangle, startAngle, spanAngle);

    rectangle = QRectF(QPointF(getSP().x(), getSP().y() + dp.y()/4) , QPointF(getEP().x() - dp.x()/2, getEP().y() - dp.y()/4));
    startAngle = -b1 * RIGHT_ANGLE * ANGLE_MULTIPLIER;
    spanAngle = -b * STRAIGHT_ANGLE * ANGLE_MULTIPLIER;
    painter->drawArc(rectangle, startAngle, spanAngle);

    rectangle = QRectF(QPointF(getSP().x() + dp.x()/4, getSP().y()) , QPointF(getEP().x() - dp.x()/4, getEP().y() - dp.y()/2));
    startAngle = a * STRAIGHT_ANGLE * ANGLE_MULTIPLIER;
    spanAngle = -a * STRAIGHT_ANGLE * ANGLE_MULTIPLIER;
    painter->drawArc(rectangle, startAngle, spanAngle);

    setPerimeter(2 * M_2_PI * sqrt((pow((getEP().x() - getSP().x())/2, 2) + pow((getEP().y() - getSP().y())/2, 2))/2));
    setArea(dp.x()/2 * dp.y()/2 + M_PI * qAbs(dp.x()) * qAbs(dp.y())/AREA_FORMULA_CONST);

    Q_UNUSED(widget);
    Q_UNUSED(option);
}
