#ifndef LAB0T2_STAR_6_H
#define LAB0T2_STAR_6_H

#include <QtWidgets>
#include "star.h"

class star_6 : public star {
public:
    star_6() = default;

    void setPoints(QMouseEvent *) override;
};



#endif //LAB0T2_STAR_6_H
