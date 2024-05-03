#ifndef BASES_H
#define BASES_H

#include <QtWidgets>

class Bases : public QGraphicsRectItem
{
public:
    Bases(int id)
        : QGraphicsRectItem(id * 400 - 140, 600, 300, 20){};
};

#endif // BASES_H
