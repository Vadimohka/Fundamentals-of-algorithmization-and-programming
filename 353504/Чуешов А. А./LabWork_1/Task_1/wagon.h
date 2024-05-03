#ifndef WAGON_H
#define WAGON_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class Wagon : public QGraphicsRectItem {
public:
    Wagon(QGraphicsEllipseItem *leftWheel, QGraphicsEllipseItem *rightWheel);
    void keyPressEvent(QKeyEvent *event) override;

private:
    QGraphicsEllipseItem *leftWheel;
    QGraphicsEllipseItem *rightWheel;
};

#endif // WAGON_H
