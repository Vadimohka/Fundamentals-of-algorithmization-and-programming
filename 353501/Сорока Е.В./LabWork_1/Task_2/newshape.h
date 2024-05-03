#ifndef NEWSHAPE_H
#define NEWSHAPE_H

#include "shape.h"
#include "newscene.h"

class NewShape : public Shape
{

public:

    NewShape();
    QVector <QPointF> points;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* , QWidget* ) override;
    void pullPoint(const QPointF &pos);
};

#endif // NEWSHAPE_H
