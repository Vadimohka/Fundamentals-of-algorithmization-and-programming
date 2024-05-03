#include "figure.h"
#include <QPainter>

Figure::Figure(QPointF point, QObject *parent):
    QObject(parent), QGraphicsItem()
{
    this->setStartPoint(mapFromScene(point));
    setFlag(QGraphicsItem::ItemIsMovable);
}

Figure::~Figure()
{

}

QRectF Figure::boundingRect() const
{
    return QRect(0, 0, 10000, 10000);
}

QPainterPath Figure::shape() const
{
    return m_shape;
}

void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
}

QPointF Figure::startPoint() const
{
    return m_startPoint;
}

QColor Figure::randomColor()
{
    QRandomGenerator *randomGenerator = QRandomGenerator::global();

    // Генерируем случайные значения для красного, зеленого и синего цветов
    int red = (*randomGenerator).bounded(256);   // От 0 до 255
    int green = (*randomGenerator).bounded(256); // От 0 до 255
    int blue = (*randomGenerator).bounded(256);  // От 0 до 255

    // Создаем и возвращаем случайный цвет
    return QColor(red, green, blue);
}
