#ifndef FIVESTAR_H
#define FIVESTAR_H

#include <QObject>
#include "abstractfigure.h"

class FiveStar : public AbstractFigure
{
    Q_OBJECT
public:
    FiveStar(int x1 =0 , int y1 = 0, int x2 = 150 , int y2 = 150);
    ~FiveStar();
private:
    void drawFigure(QPainter *painter) override;
};

#endif // FIVESTAR_H
