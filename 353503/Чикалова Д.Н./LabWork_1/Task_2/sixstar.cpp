#include "sixstar.h"

SixStar::SixStar() {
    amountOfVertexes = 12;
    vertexes = new QPointF[amountOfVertexes];

    vertexes[0] = QPointF(337, 232);
    vertexes[1] = QPointF(377, 172);
    vertexes[2] = QPointF(411, 224);
    vertexes[3] = QPointF(481, 226);
    vertexes[4] = QPointF(445, 281);
    vertexes[5] = QPointF(488, 339);
    vertexes[6] = QPointF(412, 341);
    vertexes[7] = QPointF(372, 404);
    vertexes[8] = QPointF(337, 335);
    vertexes[9] = QPointF(272, 339);
    vertexes[10] = QPointF(301, 282);
    vertexes[11] = QPointF(263, 232);

    PrintInfo();
}


