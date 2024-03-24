#ifndef PEOPLE_H
#define PEOPLE_H

#include "rectangle.h"

class People : public QGraphicsObject
{
    Q_OBJECT;
public:
    People(int floor, const QColor& color, const QString name);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QTimer *timer;

    int getFloor();

private:
    bool inside;
    int m_floor;
    QColor m_color;
    QString m_name;

    int leftLegPos;
    int rightLegPos;
    int leftArmPos;
    int rightArmPos;

    int delta;
    int shiftY;
    int shiftX;
    int targetY;
    int targetX;

signals:
    void entered(bool inside);
    void floorChanged(int newFloor);
    void incrementComplete();

public slots:
    void enter();
    void setFloor(int floor);

private slots:
    void handleEntered(bool inside);

    void handleFloorChange(int newFloor);
    void incrementYPosition();
    void incrementXPosition();
};

#endif // PEOPLE_H
