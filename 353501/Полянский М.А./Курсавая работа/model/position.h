#ifndef MODEL_POSITION_H_
#define MODEL_POSITION_H_

#include "app/shortcuts.h"

namespace model {

struct Position {
    U_INT x;
    U_INT y;

    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

}  // namespace model

#endif