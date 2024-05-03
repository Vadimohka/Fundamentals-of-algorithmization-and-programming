#ifndef STAR7_H
#define STAR7_H


#include <QtWidgets>
#include "stars.h"

class star7 : public stars {
public:
    star7() = default;

    void setPoints(QMouseEvent *) override;
};

#endif // STAR7_H
