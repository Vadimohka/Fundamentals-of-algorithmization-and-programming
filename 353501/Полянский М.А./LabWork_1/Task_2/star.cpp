#include "star.h"

Star::Star() {
    radius1 = 50;
    radius2 = 100;
    calculate_points();
}

qreal Star::area(){
    qreal area = 0.0;
    int vertexCount = points.size();

    for (int i = 0; i < vertexCount; ++i) {
        int nextIndex = (i + 1) % vertexCount;
        const QPointF& currentPoint = points[i];
        const QPointF& nextPoint = points[nextIndex];
        area += currentPoint.x() * nextPoint.y() - nextPoint.x() * currentPoint.y();
    }

    area = std::abs(area) / 2.0;
    area += M_PI * radius1 * radius2;

    return area;
}
qreal Star::perimeter(){
    qreal perimeter = 0.0;
    int vertexCount = points.size();

    for (int i = 0; i < vertexCount; ++i) {
        int nextIndex = (i + 1) % vertexCount;
        const QPointF& currentPoint = points[i];
        const QPointF& nextPoint = points[nextIndex];
        qreal dx = nextPoint.x() - currentPoint.x();
        qreal dy = nextPoint.y() - currentPoint.y();
        perimeter += std::sqrt(dx * dx + dy * dy);
    }

    return perimeter;
}
void Star::calculate_points(){
    int starPoints = apexes_num * 2;

    double angleIncrement = 2 * M_PI / starPoints;

    double angleOffset = M_PI / 2;
    points.clear();
    pointsx.resize(starPoints);
    pointsy.resize(starPoints);
    points.resize(starPoints);

    for (int i = 0; i < starPoints; i += 2)
    {
        double outerAngle = i * angleIncrement + angleOffset;

        pointsx[i] = radius2 * cos(outerAngle);
        pointsy[i] = radius2 * sin(outerAngle);
        points[i] = QPointF(pointsx[i], pointsy[i]);

        double innerAngle = (i + 1) * angleIncrement + angleOffset;

        pointsx[i+1] = radius1 * cos(innerAngle);
        pointsy[i+1] = radius1 * sin(innerAngle);
        points[i+1] = QPointF(pointsx[i+1], pointsy[i+1]);
    }
    setCenter(QPointF(centX, centY));
    update();
}
void Star::changeRadius1(double spinrad1){
    radius1 = spinrad1;
    calculate_points();
    update();
}
void Star::changeRadius2(double spinrad2){
    radius2 = spinrad2;
    calculate_points();
    update();
}

void Star::numberApexes(int apexes){
    apexes_num = apexes;
    calculate_points();
    update();
}
