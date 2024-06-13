#include "square.h"

Square::Square() {
    amountOfVertexes = 4;
    vertexes = new QPointF[amountOfVertexes];
    HalfDiagonal = 60;
    vertexes[0] = QPointF(480 - HalfDiagonal, 270);
    vertexes[1] = QPointF(480, 270 - HalfDiagonal);
    vertexes[2] = QPointF(480 + HalfDiagonal, 270);
    vertexes[3] = QPointF(480, 270 + HalfDiagonal);
    this->PrintInfo();
}
