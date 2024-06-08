#ifndef RODS_H
#define RODS_H
#include <QtWidgets>

class Rods : public QGraphicsRectItem
{
public:
    Rods(int id)
        : QGraphicsRectItem(id * 400, 300, 20, 300){};
};

#endif // RODS_H
