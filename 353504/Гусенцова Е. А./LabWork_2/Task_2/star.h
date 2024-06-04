#ifndef STAR_H
#define STAR_H

#include <QtWidgets>
#include "figures.h"

class star : public figures {
public:

    star() = default;

protected:
    void sumPoints(int n);
};

#endif
