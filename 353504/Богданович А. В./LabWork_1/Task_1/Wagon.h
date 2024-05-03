#ifndef WAGON_H
#define WAGON_H

#include "MovingRectangle.h"

class Wagon : public MovingRectangle {
    Q_OBJECT
public:
    Wagon(QWidget* parent = nullptr);
    void moveRight();
    void moveLeft();
protected:
    void paintEvent(QPaintEvent *) override;
private:
    int angle = 0;
};

#endif // WAGON_H
