#ifndef LAB0T2_FIGURERHOMBUS_H
#define LAB0T2_FIGURERHOMBUS_H

#include <QtWidgets>
#include "figures.h"

class figureRhombus : public figures {
public:
    figureRhombus() = default;

    void setPoints(QMouseEvent *me) override;

};


#endif //LAB0T2_FIGURERHOMBUS_H
