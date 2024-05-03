#ifndef LAB0T2_STAR_5_H
#define LAB0T2_STAR_5_H

#include <QtWidgets>
#include "star.h"

class star_5 : public star {
public:
    star_5() = default;

    void setPoints(QMouseEvent *) override;
};


#endif //LAB0T2_STAR_5_H
