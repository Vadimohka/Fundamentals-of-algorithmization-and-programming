#ifndef BEZIERCURVEPATH_H
#define BEZIERCURVEPATH_H

#include <QtWidgets>
#include "path.h"

class BezierCurvePath : public Path
{
public:
    BezierCurvePath(const std::vector<QPointF> &pts);
    // void paint(QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    static std::vector<QPointF> curve1();
    static std::vector<QPointF> curve1H();
    static std::vector<QPointF> curve1Mir();
    static std::vector<QPointF> curve2();
    static std::vector<QPointF> curve3();
    static std::vector<QPointF> curve3Mir();
    static std::vector<QPointF> circle();
    static std::vector<QPointF> circleRev();

    QPointF PointAt(float p) const override;

    int Size() const override { return pts.size() / 4; }

private:
    std::vector<QPointF> pts;
};

#endif // BEZIERCURVEPATH_H
