#include "polygon.h"

Polygon::Polygon() {

}

Polygon::~Polygon()
{
    delete[] vertexes;
}

void Polygon::draw(QPainter &painter)
{
    painter.setBrush(Qt::green);
    painter.setPen(Qt::black);
    painter.drawPolygon(vertexes, amountOfVertexes);
}

void Polygon::deltaRotation(qreal angle)
{
    qreal xtranslated{};
    qreal ytranslated{};
    for (int i = 0; i < amountOfVertexes; ++i) {
        xtranslated = vertexes[i].rx() - massCenter.rx();
        ytranslated = vertexes[i].ry() - massCenter.ry();
        vertexes[i].rx() = massCenter.rx() + xtranslated * qCos(angle) - ytranslated * qSin(angle);
        vertexes[i].ry() = massCenter.ry() + xtranslated * qSin(angle) + ytranslated * qCos(angle);
    }
}

void Polygon::deltaScale(qreal currsize, qreal deltascale)
{
    for (int i = 0; i < amountOfVertexes; ++i) {
        vertexes[i] = massCenter + (vertexes[i] - massCenter) * (currsize + deltascale) / currsize;
    }
}

void Polygon::deltaShift(QPointF shift)
{
    for (int i = 0; i < amountOfVertexes; ++i) {
        vertexes[i] += shift;
    }
}

void Polygon::updateArea()
{
    qreal newArea = 0;
    int next = 0;
    for (int i = 0; i < amountOfVertexes; ++i) {
        next = (i + 1) % amountOfVertexes;
        newArea += (vertexes[i].x() * vertexes[next].y()) - (vertexes[next].x() * vertexes[i].y());
    }

    newArea /= 2.0;
    area = qAbs(newArea);
}

void Polygon::updatePerimetr()
{
    qreal newPerimetr = 0;
    int nextvertex = 0;
    QPointF side{};
    for (int currvertex = 0; currvertex < amountOfVertexes; ++currvertex) {
        nextvertex = (currvertex + 1) % amountOfVertexes;
        side = vertexes[currvertex] - vertexes[nextvertex];
        newPerimetr += qSqrt(QPointF::dotProduct(side, side));
    }
    perimetr = newPerimetr;
}

void Polygon::updateMassCenter()
{
    QPointF newMassCenter = QPointF(0, 0);
    for (int i = 0; i < amountOfVertexes; ++i) {
        newMassCenter += vertexes[i];
    }
    massCenter = newMassCenter / amountOfVertexes;
}
