#ifndef ANIMATION_H
#define ANIMATION_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QPointF>

class moving_rectangle : public QGraphicsRectItem, public QObject
{
public:
    moving_rectangle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    int maxPosX, minPosX;
private:
    QPointF coordinates = pos();
    QTimer *timerRight;
    QTimer *timerLeft;
public slots:
    void move_left();
    void move_right();
    void timerRightTimeout();
    void timerLeftTimeout();
};
#endif // ANIMATION_H
