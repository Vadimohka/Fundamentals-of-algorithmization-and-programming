#ifndef MOVINGELLIPS_H
#define MOVINGELLIPS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class MovingEllips : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    MovingEllips(QObject *parent = nullptr,QRectF ellips = QRectF(0,0,0,0),QColor color = QColor(Qt::white));
    QColor get_color();
    QRectF get_Rect();
    qreal get_x();
    qreal get_y();
    qreal get_width();
    qreal get_height();
private:
    QRectF ellips;
    QColor color = QColor(Qt::white);
    qreal x = 0, y = 0, width = 0, height = 0;
protected:
    QRectF boundingRect() const override;
protected slots:
    virtual void action_move(QPointF){};
    virtual void action_transform(){};
};

#endif // MOVINGELLIPS_H
