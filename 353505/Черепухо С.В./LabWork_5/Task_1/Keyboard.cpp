#include "Keyboard.h"
#include <qcolor.h>
#include <qlogging.h>
#include <qnamespace.h>

const Qt::Key KEYS[] {
    Qt::Key_Q,    Qt::Key_W,         Qt::Key_E,           Qt::Key_R,
    Qt::Key_T,    Qt::Key_Y,         Qt::Key_U,           Qt::Key_I,
    Qt::Key_O,    Qt::Key_P,         Qt::Key_BracketLeft, Qt::Key_BracketRight,
    Qt::Key_A,    Qt::Key_S,         Qt::Key_D,           Qt::Key_F,
    Qt::Key_G,    Qt::Key_H,         Qt::Key_J,           Qt::Key_K,
    Qt::Key_L,    Qt::Key_Semicolon, Qt::Key_Apostrophe,  Qt::Key_Z,
    Qt::Key_X,    Qt::Key_C,         Qt::Key_V,           Qt::Key_B,
    Qt::Key_N,    Qt::Key_M,         Qt::Key_Comma,       Qt::Key_Period,
    Qt::Key_Slash
};

Keyboard::Keyboard() {
    int i = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 12 - row; col++) {
            KeyObject *key = new KeyObject;
            key->setPos(col * 70 + row * 35, row * 70);
            addToGroup(key);
            keys[i] = key;
            
            key->name = KEYS[i];
            i++;
        }
    }

    KeyObject *space = new KeyObject(320, 64);
    space->setPos(385, 210);
    addToGroup(space);
    this->space = space;

    KeyObject *shift1 = new KeyObject(128, 64);
    shift1->setPos(-35, 140);
    addToGroup(shift1);
    shifts[0] = shift1;

  
    KeyObject *shift2 = new KeyObject(128, 64);
    shift2->setPos(770, 140);
    addToGroup(shift2);
    shifts[1] = shift2;

    setScale(0.5);
}

void Keyboard::setKeyColor(Qt::Key key, QColor color) {
    if (key == Qt::Key_Space) {
        space->setColor(color);
        update();
        return;
    }

    if (key == Qt::Key_Shift) {
        shifts[0]->setColor(color);
        shifts[1]->setColor(color);
        update();
        return;
    }
    
    for (auto &keyObject : keys) {
        if (keyObject->getName() == key) {
            keyObject->setColor(color); 
            update();
            return;
        }
    }
}