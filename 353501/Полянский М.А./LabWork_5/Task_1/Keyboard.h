#pragma once

#include "KeyObject.h"
#include <QGraphicsItemGroup>

class KeyBoard: public QGraphicsItemGroup {
public:
    KeyBoard();

    void setKeyColor(Qt::Key, QColor color);

private: 
    KeyObject *keys[33];
    KeyObject *shifts[2];
    KeyObject *space;
};