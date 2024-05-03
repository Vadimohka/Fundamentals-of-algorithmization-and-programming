#include "star.h"

Star::Star() {}
void Star::number_apexes(int number){
    apexes_num = number;
    calculatePoints();
}
qreal Star::calculateArea(){
    qreal calculateArea = 0.0;
    int vertexCount = points.size();

    for (int i = 0; i < vertexCount; ++i) {
        int nextIndex = (i + 1) % vertexCount;
        const QPointF& currentPoint = points[i];
        const QPointF& nextPoint = points[nextIndex];
        calculateArea += currentPoint.x() * nextPoint.y() - nextPoint.x() * currentPoint.y();
    }

    calculateArea = std::abs(calculateArea) / 2.0;
    calculateArea += M_PI * radius1 * radius2;

    return calculateArea;
}
qreal Star::calculatePerimeter(){
    qreal calculatePerimeter = 0.0;
    int vertexCount = points.size();

    for (int i = 0; i < vertexCount; ++i) {
        int nextIndex = (i + 1) % vertexCount;
        const QPointF& currentPoint = points[i];
        const QPointF& nextPoint = points[nextIndex];
        qreal dx = nextPoint.x() - currentPoint.x();
        qreal dy = nextPoint.y() - currentPoint.y();
        calculatePerimeter += std::sqrt(dx * dx + dy * dy);
    }

    return calculatePerimeter;
}
void Star::calculatePoints(){
    int starPoints = apexes_num * 2;

    double angleIncrement = 2 * M_PI / starPoints;

    double angleOffset = M_PI / 2;

    pointsX.resize(starPoints);
    pointsY.resize(starPoints);
    points.resize(starPoints);

    for (int i = 0; i < starPoints; i += 2)
    {
        double outerAngle = i * angleIncrement + angleOffset;

        pointsX[i] = radius2 * cos(outerAngle);
        pointsY[i] = radius2 * sin(outerAngle);
        points[i] = QPointF(pointsX[i], pointsY[i]);

        double innerAngle = (i + 1) * angleIncrement + angleOffset;

        pointsX[i+1] = radius1 * cos(innerAngle);
        pointsY[i+1] = radius1 * sin(innerAngle);
        points[i+1] = QPointF(pointsX[i+1], pointsY[i+1]);
    }
    centerset();
}
void Star::change_radius1(double spinrad1){
    radius1 = spinrad1;
    calculatePoints();
}
void Star::change_radius2(double spinrad2){
    radius2 = spinrad2;
    calculatePoints();
}
