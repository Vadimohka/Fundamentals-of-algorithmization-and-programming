#ifndef CUSTOMESHAPE_H
#define CUSTOMESHAPE_H

#include "figure.h"

class CustomeShape : public Figure
{

public:

    CustomeShape();
    QVector <QPointF> points;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* , QWidget* ) override;
    void pullPoint(const QPointF &pos);
};

#endif // CUSTOM_SHAPE_H
