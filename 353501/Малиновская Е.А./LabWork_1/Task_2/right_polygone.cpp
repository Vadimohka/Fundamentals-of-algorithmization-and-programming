#include "right_polygone.h"

Right_Polygone::Right_Polygone() {}
qreal Right_Polygone::calculateArea(){
    return 0.25 * apexes_num * side * side / std::tan(M_PI / apexes_num);
}
qreal Right_Polygone::calculatePerimeter(){
    return apexes_num * side;
}
void Right_Polygone::changeSide(double spinside){
    side = spinside;
    calculatePoints();
}
void Right_Polygone::calculatePoints(){
    points.resize(apexes_num);
    pointsX.resize(apexes_num);
    pointsY.resize(apexes_num);

    double angleIncrement = 2 * M_PI / apexes_num;

    for (int i = 0; i < apexes_num; ++i) {
        double angle = i * angleIncrement;
        pointsX[i]  = side * std::cos(angle);
        pointsY[i] = side * std::sin(angle);

        points[i] = QPointF(pointsX[i], pointsY[i]);
    }

    centerset();

}
void Right_Polygone::number_apexes(int number){
    apexes_num = number;
    calculatePoints();
}
