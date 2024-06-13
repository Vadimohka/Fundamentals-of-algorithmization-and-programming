#include "eightstar.h"

EightStar::EightStar() {
    amountOfVertexes = 16;
    vertexes = new QPointF[amountOfVertexes];
    vertexes[0] = QPointF(379, 355);
    vertexes[1] = QPointF(364, 315);
    vertexes[2] = QPointF(402, 346);
    vertexes[3] = QPointF(449, 313);
    vertexes[4] = QPointF(420, 356);
    vertexes[5] = QPointF(466, 359);
    vertexes[6] = QPointF(425, 376);
    vertexes[7] = QPointF(466, 395);
    vertexes[8] = QPointF(423, 397);
    vertexes[9] = QPointF(422, 446);
    vertexes[10] = QPointF(400, 400);
    vertexes[11] = QPointF(374, 438);
    vertexes[12] = QPointF(375, 390);
    vertexes[13] = QPointF(323, 390);
    vertexes[14] = QPointF(370, 370);
    vertexes[15] = QPointF(321, 354);
    PrintInfo();
}
