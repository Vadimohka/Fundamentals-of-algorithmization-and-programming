#include "hexagon.h"

Hexagon::Hexagon() {
    apexes_numH = 5;
    side = 50;
    calculate_points();
}
qreal Hexagon::area(){
    return 0.25 * apexes_numH * side * side / std::tan(M_PI / apexes_numH);
}
qreal Hexagon::perimeter(){
    return apexes_numH * side;
}
void Hexagon::change_side(double spinside){
    side = spinside;
    calculate_points();
}
void Hexagon::calculate_points(){
    points.resize(apexes_numH);
    pointsx.resize(apexes_numH);
    pointsy.resize(apexes_numH);

    double angleIncrement = 2 * M_PI / apexes_numH;

    for (int i = 0; i < apexes_numH; ++i) {
        double angle = i * angleIncrement;
        pointsx[i]  = side * std::cos(angle);
        pointsy[i] = side * std::sin(angle);

        points[i] = QPointF(pointsx[i], pointsy[i]);
    }

    setCenter(QPointF(centX, centY));

}
void Hexagon::numberApexes(int number){
    apexes_numH = number;
    calculate_points();
}
