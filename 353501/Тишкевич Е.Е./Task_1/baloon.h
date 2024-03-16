#ifndef BALOON_H
#define BALOON_H

#include "ellips.h"
#include <QTimer>
#include <QPolygon>

class Balloon : public Ellips, public QObject {
private:
    QLineF line;
    QPolygon polygon;
    QPointF originalPos;
    QTimer *timer;
    qreal originalWidth;
    bool poped;
public:
    Balloon(int x, int y, int width, int height, QGraphicsEllipseItem* parent = nullptr);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
public slots:
    void shake(int value);
    void reset();
    void pop();
    void updatePosition(int value);
    void shrink();
};


#endif // BALOON_H
