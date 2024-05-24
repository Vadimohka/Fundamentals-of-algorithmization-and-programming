#ifndef LAB0T2_STAR_8_H
#define LAB0T2_STAR_8_H


#include <QtWidgets>
#include "star.h"


class star_8 : public star {
public:
    star_8() = default;

    void setPoints(QMouseEvent *) override;
};

#endif //LAB0T2_STAR_8_H
