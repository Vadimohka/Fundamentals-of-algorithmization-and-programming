#include "star.h"


qreal Star::d(const QPointF &p1, const QPointF &p2) const
{
    double dx=p2.x()-p1.x();
    double dy=p2.y()-p1.y();
    return std::sqrt(dx*dx+dy*dy);
}


qreal FivePointStar::Area(const QVector<QPointF> &var) const
{
    qreal area = 0;
    int vertexCount = var.size();

    for (int i = 0; i < vertexCount; ++i)
    {
        const QPointF &currentVertex = var[i];
        const QPointF &nextVertex = var[(i + 1) % vertexCount]; // Получаем следующую вершину

        area += (currentVertex.x() * nextVertex.y() - nextVertex.x() * currentVertex.y());
    }

    return std::abs(area) / 2;
}

qreal FivePointStar::Perimeter(const QVector<QPointF> &var) const
{
    qreal p = 0;

    int numVertices = var.size();

    for (int i = 0; i < numVertices; ++i) {
        const QPointF &currentVertex = var[i];
        const QPointF &nextVertex = var[(i + 1) % numVertices];

        // Используем вашу функцию для расчета длины стороны
        qreal sideLength = d(currentVertex, nextVertex);

        p += sideLength;
    }

    return p;
}

QPointF FivePointStar::centerMass(const QVector<QPointF> &var) const
{
    QPointF centerMass(0,0);
    for (int i = 0; i < var.size(); ++i) {
        const QPointF &currentVertex = var[i];
        const QPointF &nextVertex = var[(i + 2) % 5]; // Получаем следующую вершину, пропуская одну

        centerMass.rx() += (currentVertex.x() + nextVertex.x()) / 2.0;
        centerMass.ry() += (currentVertex.y() + nextVertex.y()) / 2.0;
    }

    centerMass.rx() /= var.size();
    centerMass.ry() /= var.size();

    return centerMass;
}



qreal SixPointStar::Area(const QVector<QPointF> &var) const
{
    qreal area = 0;
    int numVar = var.size();
    // Вычисление площади по формуле многоугольника
    for (int i = 0; i < numVar; ++i) {
        const QPointF &currentVertex = var[i];
        const QPointF &nextVertex = var[(i + 1) % numVar];

        area += (currentVertex.x() * nextVertex.y() - nextVertex.x() * currentVertex.y());
    }

    area = 0.5 * qAbs(area);

    return area;
}

qreal SixPointStar::Perimeter(const QVector<QPointF> &var) const
{
    qreal p = 0;

    int numVertices = var.size();

    for (int i = 0; i < numVertices; ++i) {
        const QPointF &currentVertex = var[i];
        const QPointF &nextVertex = var[(i + 1) % numVertices];

        // Используем вашу функцию для расчета длины стороны
        qreal sideLength = d(currentVertex, nextVertex);

        p += sideLength;
    }

    return p;
}

QPointF SixPointStar::centerMass(const QVector<QPointF> &var) const
{
    qreal totalArea = 0; // Общая площадь звезды
    QPointF centerOfMass(0,0); // Инициализация координат центра масс
    int numVar = var.size();
    // Вычисление общей площади и центра масс
    for (int i = 0; i < numVar; ++i) {
        const QPointF &currentVertex = var[i];
        const QPointF &nextVertex = var[(i + 1) % numVar];

        // Вычисление векторного произведения текущей и следующей вершин
        qreal crossProduct = currentVertex.x() * nextVertex.y() - nextVertex.x() * currentVertex.y();
        totalArea += crossProduct; // Суммирование вклада каждого ребра в общую площадь

        // Суммирование координат центра масс с учетом вклада текущего ребра
        centerOfMass.rx() += (currentVertex.x() + nextVertex.x()) * crossProduct;
        centerOfMass.ry() += (currentVertex.y() + nextVertex.y()) * crossProduct;
    }

    totalArea /= 2; // Деление общей площади на 2 (так как векторное произведение удваивает площадь)

    // Рассчитываем и возвращаем центр масс, учитывая коэффициент 6
    centerOfMass /= (6 * totalArea);

    return centerOfMass;
}


qreal EightPointStar::Area(const QVector<QPointF> &var) const
{
    int numVertices = var.size();

    qreal area = 0;

    // Вычисление площади восьмиконечной звезды
    for (int i = 0; i < numVertices; ++i) {
        const QPointF &currentVertex = var[i];
        const QPointF &nextVertex = var[(i + 1) % numVertices];
        area += (currentVertex.x() * nextVertex.y() - nextVertex.x() * currentVertex.y());
    }

    area = qAbs(area) / 2;

    return area;
}

qreal EightPointStar::Perimeter(const QVector<QPointF> &var) const
{
    qreal p = 0;

    int numVertices = var.size();

    for (int i = 0; i < numVertices; ++i) {
        const QPointF &currentVertex = var[i];
        const QPointF &nextVertex = var[(i + 1) % numVertices];

        // Используем вашу функцию для расчета длины стороны
        qreal sideLength = d(currentVertex, nextVertex);

        p += sideLength;
    }

    return p;
}

QPointF EightPointStar::centerMass(const QVector<QPointF> &var) const
{
    int numVertices = var.size();


    qreal totalArea = 0;
    QPointF centerOfMass(0,0);

    // Вычисление общей площади и центра масс
    for (int i = 0; i < numVertices; ++i) {
        const QPointF &currentVertex = var[i];
        const QPointF &nextVertex = var[(i + 1) % numVertices];

        qreal crossProduct = currentVertex.x() * nextVertex.y() - nextVertex.x() * currentVertex.y();
        totalArea += crossProduct;

        centerOfMass.rx() += (currentVertex.x() + nextVertex.x()) * crossProduct;
        centerOfMass.ry() += (currentVertex.y() + nextVertex.y()) * crossProduct;
    }

    totalArea /= 2.0;

    // Рассчитываем и возвращаем центр масс
    centerOfMass /= (24 * totalArea);
    return centerOfMass;
}

