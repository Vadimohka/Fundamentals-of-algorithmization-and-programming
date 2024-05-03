#include "basicfigure.h"
#include <QPainter>

BasicFigure::BasicFigure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    // Устанавливаем стартовую координату для отрисовки фигуры
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    /* Подключаем сигнал изменения координат к слоту запуска обновления содержимого объекта
         * Сигнал и слот присутствуют в базовом классе
         * */
    connect(this, &BasicFigure::pointChanged, this, &BasicFigure::updateRomb);
}

BasicFigure::~BasicFigure()
{

}

QRectF BasicFigure::boundingRect() const
{
    /* Возвращаем область, в которой лежит фигура.
         * Обновляемая область зависит от стартовой точки отрисовки и от конечной точки
         * */
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                  qAbs(endPoint().x() - startPoint().x()) + 10,
                  qAbs(endPoint().y() - startPoint().y()) + 10);
}

void BasicFigure::updateRomb()
{
    // Вызываем обновление области, в которой лежит фигура
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                 qAbs(endPoint().x() - startPoint().x()) + 10,
                 qAbs(endPoint().y() - startPoint().y()) + 10);
}

void BasicFigure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void BasicFigure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}

double BasicFigure::area() { return 0.0; }

double BasicFigure::perimeter() { return 0.0;}

QPointF BasicFigure::startPoint() const
{
    return m_startPoint;
}

QPointF BasicFigure::endPoint() const
{
    return m_endPoint;
}
