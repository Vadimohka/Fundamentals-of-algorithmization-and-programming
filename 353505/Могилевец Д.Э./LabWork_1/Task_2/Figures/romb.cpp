#include "romb.h"

Romb::Romb() {
    amountOfVertexes = 4;
    vertexes = new QPointF[amountOfVertexes];
    Diagonal1Len = 100;
    Diagonal2Len = 200;
    vertexes[0] = QPointF(480 - Diagonal1Len, 270);
    vertexes[1] = QPointF(480, 270 - Diagonal2Len);
    vertexes[2] = QPointF(480 + Diagonal1Len, 270);
    vertexes[3] = QPointF(480, 270 + Diagonal2Len);
    this->PrintInfo();
}
