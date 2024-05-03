#include "rect.h"
recta::recta(int x1,int y1,int w1,int h1){
    x=x1;
    y=y1;
    w=w1;
    h=h1;
}
QGraphicsRectItem recta::create(int n,int up) {
    QRect a=QRect(-55,125+up,35-2*n,10);

    return QGraphicsRectItem(-55,125+up,35-2*n,10,nullptr);
}
