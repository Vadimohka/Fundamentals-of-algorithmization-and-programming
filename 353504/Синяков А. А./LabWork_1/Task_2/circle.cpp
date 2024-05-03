#include "circle.h"

qreal Circle::Area(const QVector<QPointF>& var) const
{
    // Рассчитываем центр масс
    QPointF centerOfMass = centerMass(var);

    // Вычисляем радиус (расстояние от центра масс до любой точки на окружности)
    qreal radius = d(centerOfMass, var[1]);

    // Вычисляем площадь круга
    qreal area = M_PI * radius * radius;

    return area;
}


QPointF Circle::centerMass(const QVector<QPointF>& var) const
{

    return var[0];
}

qreal Circle::radius(const QVector<QPointF>& var) const
{
    // Проверяем, что в векторе есть хотя бы две точки
    if (var.size() < 2) {
        return 0.0; // Если точек меньше двух, возвращаем 0
    }

    // Выбираем две точки из вектора
    QPointF point1 = var[0];
    QPointF point2 = var[1];

    // Рассчитываем расстояние между этими двумя точками (диаметр)
    qreal diameter = d(point1, point2);

    // Разделяем диаметр пополам, чтобы получить радиус
    qreal r = diameter / 2.0;

    return r;
}
qreal Circle::Perimeter(const QVector<QPointF>& var) const
{
    // Проверяем, что вектор содержит хотя бы две точки
    if (var.size() < 2) {
        return 0.0; // Возвращаем 0, если точек недостаточно
    }

    // Рассчитываем радиус (расстояние от первой точки до центра круга)
    QPointF centerOfMass = centerMass(var);

    // Вычисляем радиус (расстояние от центра масс до любой точки на окружности)
    qreal radius = d(centerOfMass, var[1]);


    // Периметр круга - это длина его окружности, которую можно вычислить как 2 * Pi * r
    qreal perimeter = 2.0 * M_PI * radius;

    return perimeter;
}

qreal Circle::d(const QPointF& p1,const QPointF& p2 )const{

    double dx=p2.x()-p1.x();
    double dy=p2.y()-p1.y();
    return std::sqrt(dx*dx+dy*dy);
}
