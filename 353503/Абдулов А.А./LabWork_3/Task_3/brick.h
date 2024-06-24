
#include <QPen>

#ifndef BRICK_H
#define BRICK_H

class brick : public QGraphicsRectItem{
public:
    int num;
    QPoint centre;
    brick(int num, QPoint centre);
};

#endif // BRICK_H
