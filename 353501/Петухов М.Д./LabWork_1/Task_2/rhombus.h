#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class Rhombus : public Figure
{
private:
    qreal width;
    qreal height;
public:
    Rhombus();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void setRhombWidth(double value) override;
    void setRhombHeight(double value) override;
    void calculatePoints() override;
};

#endif // RHOMBUS_H
