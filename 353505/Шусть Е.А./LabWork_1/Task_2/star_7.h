#ifndef LAB0T2_STAR_7_H
#define LAB0T2_STAR_7_H

#include <QtWidgets>
#include "star.h"

class star_7 : public star {
public:
    star_7() = default;

    void setPoints(QMouseEvent *) override;
};


#endif //LAB0T2_STAR_7_H
