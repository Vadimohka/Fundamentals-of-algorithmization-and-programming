#pragma once

#include "KeyObject.h"
#include <QGraphicsItemGroup>

class Keyboard: public QGraphicsItemGroup {
public:
    Keyboard();

    void setKeyColor(Qt::Key, QColor color);

private:
    KeyObject *keys[33];
    KeyObject *shifts[2];
    KeyObject *space;
};
