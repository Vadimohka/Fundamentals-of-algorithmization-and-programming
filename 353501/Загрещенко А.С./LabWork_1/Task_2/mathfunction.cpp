#include "mathfunction.h"
#include "QtMath"


double calculateAngle(const double dx, const double dy) {
    double angleInRadians = atan2(dx, dy);

    // Преобразуем угол в градусы
    double angleInDegrees = (angleInRadians * 180.0) / M_PI;

    return angleInDegrees;
}
