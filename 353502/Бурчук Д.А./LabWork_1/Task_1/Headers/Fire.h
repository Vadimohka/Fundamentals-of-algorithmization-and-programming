#ifndef FIRE_H
#define FIRE_H

#include "MovingLine.h"

class Fire : public QWidget
{
    Q_OBJECT
public:
    explicit Fire(QWidget* parent);

    void paintEvent(QPaintEvent *event);
private:
    QTimer* timer = new QTimer;
public slots:
            void MoveObject();

    void StopMoving();

    void Up();
};

#endif // FIRE_H

