#include "star.h"

star::star() {}

star::~star()
{

}

void star::initialization()
{
    perimeter = n * (w / 2 - 2 * M_PI / n); // Периметр звезды
    area = (n * pow((w / 2 - 2 * M_PI / n), 2) * tan(M_PI / n)) / 4; // Площадь звезды
    now_area = area;
    now_perimeter = perimeter;
}

void star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(hasFocus() ? QPen(QColor(255, 166, 21), 3) : QPen(QColor(95, 0, 45), 3));
    painter->drawPoint(0, 0);
    painter->setPen(QPen(QColor(R, G, B), PenSize));
    QVector<QPointF> starPoints; // Вектор точек звезды
    for (int i = 0; i < n; ++i) {
        double outerX = w/2 * cos((2 * M_PI / n) * i);
        double outerY = w/2 * sin((2 * M_PI / n) * i);
        double innerX = w/4 * cos((2 * M_PI / n) * i + 2 * M_PI / (n * 2));
        double innerY = w/4 * sin((2 * M_PI / n) * i + 2 * M_PI / (n * 2));
        starPoints.append(QPointF(outerX, outerY));
        starPoints.append(QPointF(innerX, innerY));
    }
    painter->drawPolygon(starPoints);

    QThread::msleep(10);

    double delta = ang - now_ang;
    now_ang += delta / 100;

    double deltaSize = size - now_size;
    now_size += deltaSize / 100;

    now_area = area * now_size * now_size;
    now_perimeter = perimeter * now_size;

    this->setRotation(now_ang);
    this->setScale(now_size);

    if (this->hasFocus())
        Output();

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
