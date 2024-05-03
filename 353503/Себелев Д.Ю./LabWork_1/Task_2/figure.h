#ifndef FIGURE_H
#define FIGURE_H

#include <QCursor>
#include <QGraphicsObject>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPoint>

class Figure : public QGraphicsObject
{
    Q_OBJECT

public:
    Figure(QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void SetPenColor(QColor color);
    void SetBrushColor(QColor brush_color);
    void SetCenter(QPointF prev_pos, QPointF curr_pos);
    void CorrectCorners(QPointF first_point, QPointF second_point);
    QPointF GetCenter();
    qreal GetPerim();
    qreal GetSquare();
    void SetInfo(qreal mult);


protected:
    QPointF start_pos;
    QPointF last_pos;
    QVector<QPointF>* points;
    QPointF center;
    QPen pen;
    QBrush brush;
    qreal perim;
    qreal square;
    QPointF top_left;
    QPointF bottom_right;
    qreal x_side;
    qreal y_side;
};

#endif // FIGURE_H
