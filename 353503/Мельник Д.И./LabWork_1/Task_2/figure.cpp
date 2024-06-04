#include "figure.h"
#include <QPainter>

Figure::Figure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    // Устанавливаем стартовую координату для отрисовки фигуры
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    /* Подключаем сигнал изменения координат к слоту запуска обновления содержимого объекта
         * Сигнал и слот присутствуют в базовом классе
         * */
    connect(this, &Figure::pointChanged, this, &Figure::updateRomb);
}

Figure::~Figure()
{

}

QRectF Figure::boundingRect() const
{
    /* Возвращаем область, в которой лежит фигура.
         * Обновляемая область зависит от стартовой точки отрисовки и от конечной точки
         * */
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                  qAbs(endPoint().x() - startPoint().x()) + 10,
                  qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::updateRomb()
{
    // Вызываем обновление области, в которой лежит фигура
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                 qAbs(endPoint().x() - startPoint().x()) + 10,
                 qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}

QPointF Figure::startPoint() const
{
    return m_startPoint;
}

QPointF Figure::endPoint() const
{
    return m_endPoint;
}
