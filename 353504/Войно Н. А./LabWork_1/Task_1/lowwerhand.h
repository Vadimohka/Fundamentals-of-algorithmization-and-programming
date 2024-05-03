#ifndef LOWWERHAND_H
#define LOWWERHAND_H
#include "upperhand.h"

class lowwerhand: public upperhand
{
public:
    lowwerhand(QWidget* parent = nullptr);
    void salute() override;
    void returnSalute() override;
protected:
    void paintEvent(QPaintEvent *) override;
};

#endif // LOWWERHAND_H
