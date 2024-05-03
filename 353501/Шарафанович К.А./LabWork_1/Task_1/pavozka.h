#ifndef PAVOZKA_H
#define PAVOZKA_H

#include "object.h"
#include <QGraphicsEllipseItem>
#include <QTimer>

class pavozka : public object
{
    Q_OBJECT
public:
    pavozka();
    QGraphicsEllipseItem *Rwheel;
    QGraphicsEllipseItem *Lwheel;
    QGraphicsEllipseItem *orange1;
    QGraphicsEllipseItem *orange2;
    QGraphicsEllipseItem *orange3;
    int rotation;
private slots:
    void moveWheels();

private:
    QTimer *timer;
};

#endif // PAVOZKA_H

