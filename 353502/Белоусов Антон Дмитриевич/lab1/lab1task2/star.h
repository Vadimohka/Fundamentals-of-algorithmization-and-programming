#ifndef STAR_H
#define STAR_H

#include "figure.h"

class star : public figure
{
private:
    int numberOfEdges{3};

public:
    star();
    ~star() override;
    double getSquare() override;
    double getPerimeter() override;
    void setFigure(QPointF* points) override;
    void setNumberOfEdges(int numberOfEdges);
    bool isPointInside(QPointF point) override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // STAR_H

