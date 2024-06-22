#ifndef MOVEITEM_H
#define MOVEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <QWheelEvent>
#include <cmath>

class MoveItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MoveItem(QObject *parent = nullptr);
    void setItem(const QString& nameNewItem);
    void setMoving(const QString& newMoving);
    void setScaling(QPointF pos);
    void setAngle(const qreal& newAngle);
    void setXPos(const qreal& newXPos);
    void setYPos(const qreal& newYPos);
    void setItemPosition(QPointF pointPos);
    void getAngleSpeed(qreal angleSpeedNew);
    //void anglePlus(qreal angleSpeed);
    QTimer* smoothMoveTimer;
    ~MoveItem();

signals:
    void signalChangeScene();
    void deleteItem(MoveItem* deleteItem);
    void sharePosition(QPointF posToShare);
    void clearFields();
    void signalBlockOK();
    void signalReleaseOK();
    void signalAskForTypeOfMoving();
    void sharePerimeterSquare(qreal perim, qreal square);
private:
    static bool allow;
    static QString nameOfTheItem;
    static QString typeOfMoving;
    static qreal angleSpeed;
    static qreal xPos, yPos, xToMove, yToMove;
    static qreal xSpeed, ySpeed;
    static qreal perimeter, square;
    static qreal scale;
    QPointF positionOfTheItem;
    virtual QRectF boundingRect() const;
    virtual qreal findPerimeter();
    virtual qreal findSquare();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void changePerimSquare(qreal scale);

    // QGraphicsItem interface
public slots:
    void slotGetPosition(QPointF pointSetPos);
    // QGraphicsItem interface
public:
    virtual void advance();
    virtual void advanceRotate();
};

#endif // MOVEITEM_H
