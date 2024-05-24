#ifndef LAB0T2_STAR_H
#define LAB0T2_STAR_H

#include <QtWidgets>
#include "figures.h"


class star : public figures {
public:
    star() = default;

protected:
    void sumPoints(int n);
};


#endif //LAB0T2_STAR_H
