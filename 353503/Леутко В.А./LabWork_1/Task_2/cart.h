#ifndef CART_H
#define CART_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class Cart : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Cart(QObject *parent = nullptr);
    void timerEvent(QTimerEvent *event);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
private:
    int direction;
    int rotationAngle;
    bool isMoving;
private slots:
    void btnClicked();
};

#endif // CART_H
