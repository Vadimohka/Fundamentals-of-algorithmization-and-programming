#ifndef DRAFT_SQUARE_H
#define DRAFT_SQUARE_H

#include <QtWidgets>
#include "figures.h"


class Square : public Figures {
public:
    Square();

    void setPoints(QMouseEvent*) override;
    void updateData() override;
    void setParameters(const double, const int) override;
};


#endif //SQUARE_H
