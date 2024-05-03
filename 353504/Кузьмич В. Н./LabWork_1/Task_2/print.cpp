#include "print.h"

void print::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    painter -> drawPolygon(line_pol);
}
