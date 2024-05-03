#include "hexagon.h"

Hexagon::Hexagon(qreal R)
{
    points.resize(6);
    points[0] = QPointF(R * cos(0 * M_PI / 180.0) + R, R * sin(0 * M_PI / 180.0) + R);
    points[1] = QPointF(R * cos(60 * M_PI / 180.0) + R, R * sin(60 * M_PI / 180.0) + R);
    points[2] = QPointF(R * cos(120 * M_PI / 180.0) + R, R * sin(120 * M_PI / 180.0) + R);
    points[3] = QPointF(R * cos(180 * M_PI / 180.0) + R, R * sin(180 * M_PI / 180.0) + R);
    points[4] = QPointF(R * cos(240 * M_PI / 180.0) + R, R * sin(240 * M_PI / 180.0) + R);
    points[5] = QPointF(R * cos(300 * M_PI / 180.0) + R, R * sin(300 * M_PI / 180.0) + R);
    correct = true;
    start_R = R;
}

void Hexagon::SetStartParams()
{
    SetNewCoord(start_R);
}

bool Hexagon::isRegularHexagon() {
    double sideLength = QLineF(points[0], points[1]).length();
    for (int i = 1; i < 6; ++i) {
        if (QLineF(points[i], points[(i + 1) % 6]).length() != sideLength) {
            return false;
        }
    }
    double angle = 360.0 / 6;
    for (int i = 0; i < 6; ++i) {
        double currentAngle = QLineF(points[i], points[(i + 1) % 6]).angleTo(QLineF(points[i], points[(i + 2) % 6]));
        if (qAbs(currentAngle - angle) > 1e-6) {
            return false;
        }
    }
    return true;
}

void Hexagon::SquareHexagon()
{
    SquareCorrectHexagon();
    if (correct) squareHex = SCH;
    else {
        SCH = GetSquare();
    }
}

qreal Hexagon::GetSquareHex()
{
    return squareHex;
}

void Hexagon::SetNewCoord(qreal R)
{
    points.resize(6);
    points[0] = QPointF(R * cos(0 * M_PI / 180.0) + R, R * sin(0 * M_PI / 180.0) + R);
    points[1] = QPointF(R * cos(60 * M_PI / 180.0) + R, R * sin(60 * M_PI / 180.0) + R);
    points[2] = QPointF(R * cos(120 * M_PI / 180.0) + R, R * sin(120 * M_PI / 180.0) + R);
    points[3] = QPointF(R * cos(180 * M_PI / 180.0) + R, R * sin(180 * M_PI / 180.0) + R);
    points[4] = QPointF(R * cos(240 * M_PI / 180.0) + R, R * sin(240 * M_PI / 180.0) + R);
    points[5] = QPointF(R * cos(300 * M_PI / 180.0) + R, R * sin(300 * M_PI / 180.0) + R);
    correct = true;
}

void Hexagon::SquareCorrectHexagon()
{
    SCH = (3 * qSqrt(3) / 2) * sqrt(qPow((points[0].x()- points[1].x()),2) + qPow((points[0].y()- points[1].y()), 2));
}
