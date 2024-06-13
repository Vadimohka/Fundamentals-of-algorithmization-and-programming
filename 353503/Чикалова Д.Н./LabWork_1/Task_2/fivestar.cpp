#include "fivestar.h"

FiveStar::FiveStar() {
    amountOfVertexes = 10;
    vertexes = new QPointF[amountOfVertexes];

    vertexes[0] = QPointF(269, 229);
    vertexes[1] = QPointF(330, 100);
    vertexes[2] = QPointF(398, 254);
    vertexes[3] = QPointF(575, 273);
    vertexes[4] = QPointF(370, 353);
    vertexes[5] = QPointF(407, 473);
    vertexes[6] = QPointF(284, 393);
    vertexes[7] = QPointF(136, 468);
    vertexes[8] = QPointF(203, 334);
    vertexes[9] = QPointF(111, 216);

    PrintInfo();
}
