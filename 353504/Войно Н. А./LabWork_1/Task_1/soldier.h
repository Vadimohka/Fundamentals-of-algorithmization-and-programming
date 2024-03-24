#ifndef SOLDIER_H
#define SOLDIER_H


#include "move_rec.h"

class soldier: public Move_rec
{
    Q_OBJECT
public:
    soldier(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent*) override;
};

#endif // SOLDIER_H
