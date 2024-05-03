#include "hexagon.h"

Hexagon::Hexagon() {
    amountOfVertexes = 6;
    vertexes = new QPointF[amountOfVertexes];
    vertexes[0] = QPointF(380, 270);
    vertexes[1] = QPointF(430, 190);
    vertexes[2] = QPointF(530, 190);
    vertexes[3] = QPointF(580, 270);
    vertexes[4] = QPointF(530, 350);
    vertexes[5] = QPointF(430, 350);
    this->PrintInfo();
}
