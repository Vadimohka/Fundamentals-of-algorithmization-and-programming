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
    points.push_back(point);
}
 
void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
    points.push_back(point);
}
 
QPointF Figure::startPoint() const
{
    return m_startPoint;
}
 
QPointF Figure::endPoint() const
{
    return m_endPoint;
}

void Figure::setNumber(int value)
{
    N = value;
}

void Figure::setRotation(int value)
{
    rotation = value;
}

void Figure::setRotationX(int value)
{
    rotationX = value;
}

void Figure::setRotationY(int value)
{
    rotationY = value;
}

void Figure::setOuterRadius(int value)
{
    outerRadius = value;
}

void Figure::setInnerRadius(int value)
{
    innerRadius = value;
}

void Figure::setSideA(int value)
{
    sideA = value;
}

void Figure::setSideB(int value)
{
    sideB = value;
}

void Figure::setIsDrawingFirstTime(bool value)
{
    is_drawing_first_time = value;
}

double Figure::returnArea()
{
    return area;
}

double Figure::returnPerimeter()
{
    return perimeter;
}

double Figure::returnCenterX()
{
    return center.x();
}

double Figure::returnCenterY()
{
    return center.y();
}

double Figure::returnInnerRadius()
{
    return innerRadius;
}

double Figure::returnOuterRadius()
{
    return outerRadius;
}

int Figure::returnNumber()
{
    return N;
}

double Figure::returnSideA()
{
    return sideA;
}

double Figure::returnSideB()
{
    return sideB;
}

double Figure::returnAngel()
{
    return angel;
}

void Figure::setAngel(int value)
{
    angel = value;
}

void Figure::setScale(double value)
{
    scale = value;
}

// Треугольник

void Figure::setPointA_x(int value)
{
    A_x = value;
}

void Figure::setPointA_y(int value)
{
    A_y = value;
}

void Figure::setPointB_x(int value)
{
    B_x = value;
}

void Figure::setPointB_y(int value)
{
    B_y = value;
}

void Figure::setPointC_x(int value)
{
    C_x = value;
}

void Figure::setPointC_y(int value)
{
    C_y = value;
}
                 /*Возврат*/
int Figure::returnPointA_x()
{
    return A_x;
}

int Figure::returnPointA_y()
{
    return A_y;
}

int Figure::returnPointB_x()
{
    return B_x;
}

int Figure::returnPointB_y()
{
    return B_y;
}

int Figure::returnPointC_x()
{
    return C_x;
}

int Figure::returnPointC_y()
{
    return C_y;
}