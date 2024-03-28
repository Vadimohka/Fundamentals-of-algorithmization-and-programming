#ifndef SORT_VISUALISER
#define SORT_VISUALISER

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "SVector.h"

class SortVisualiser : public QGraphicsScene {

    Q_OBJECT
private:
    QGraphicsRectItem** rectItems = nullptr;
    const size_t size = 0;
    const qreal towerLength;
    const qreal heightPerUnit;

    const SVector& elements;
    QGraphicsRectItem* highlited = nullptr;
    
public:
    SortVisualiser(QRectF initialSize, QObject* parent, const SVector& vect);
    SortVisualiser(QObject* parent, const SVector& vect);
    ~SortVisualiser();

public slots:
    void updateItem(size_t i);
    void highligtItem(long i);
};

#endif