#ifndef FACE_H
#define FACE_H

#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QObject>
#include <QWidget>
#include "movingellips.h"

class Face : public MovingEllips
{
    Q_OBJECT
public:
    Face(QRectF ellips = QRectF(0,0,0,0),QColor color = QColor(Qt::white));
    ~Face(){};
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option,QWidget * widget = nullptr) override;
private:
    QRectF face;
    QGraphicsEllipseItem *nose;
    QGraphicsEllipseItem *left_ear;
    QGraphicsEllipseItem *right_ear;
};

#endif // FACE_H
