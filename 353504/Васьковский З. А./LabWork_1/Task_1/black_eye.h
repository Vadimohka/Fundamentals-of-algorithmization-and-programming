#ifndef BLACK_EYE_H
#define BLACK_EYE_H

#include <QGraphicsEllipseItem>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include "movingellips.h"

class Black_eye : public MovingEllips
{
    Q_OBJECT
public:
    Black_eye(QRectF ellips = QRectF(0,0,0,0),QColor color = QColor(Qt::black));
    ~Black_eye(){};
    void set_center(QPointF center);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option,QWidget * widget = nullptr) override;
public slots:
    void slotTarget(QPointF point);
    void action_move(QPointF) override;
    void action_transform() override;
    void visible();

private:
    QPointF target;
    QPointF center;
    bool isOpen = true;
};

#endif // BLACK_EYE_H
