#ifndef STARS_H
#define STARS_H

#include <QtWidgets>
#include "../figures.h"

class stars : public figures
{
public:
    stars() = default;

protected:
    void numOfPoints(long long n);
};

#endif // STARS_H
