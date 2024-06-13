#pragma once
#include <QGraphicsItem>
#include <QTimer>

class Line: public QObject, public QGraphicsItem
{

    Q_OBJECT

    qint8 dir;
    // bool isMovingRight = true;

public:
    Line();

    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void Forward();
    void Back();


protected slots:
    void Tick();





protected:
    int wx;
    int x;

private:
    QTimer timer;
};
