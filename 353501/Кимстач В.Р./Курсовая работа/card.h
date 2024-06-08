#pragma once
#include <ctime>
#include <cstdlib>
#include <QGraphicsScene>
#include "Constants.h"
#include <QObject>
#include <QDebug>
#include <QGraphicsRectItem>
class Card: public QObject
{
Q_OBJECT
public:
    QGraphicsRectItem* rect;
    QGraphicsRectItem* topRect;
    QGraphicsRectItem* bottomRect;
    QGraphicsRectItem* leftRect;
    QGraphicsRectItem* rightRect;
    QGraphicsRectItem* topCastle;
    QGraphicsRectItem* bottomCastle;
    QGraphicsRectItem* leftCastle;
    QGraphicsRectItem* rightCastle;
    bool isConnected;
    short left;
    short right;
    short top;
    short bottom;
    short x=-100;
    short y=-100;
    Card();
    void Paint(QGraphicsScene* scene, int n, int turnNumber);

};
