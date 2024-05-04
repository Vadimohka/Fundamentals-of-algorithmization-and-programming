#ifndef SORTVISUALS_H
#define SORTVISUALS_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <svector.h>

class SortVisuals : public QGraphicsScene
{
    Q_OBJECT

public:
    SortVisuals(QRectF, QObject*);
    Vector<int> *list;
    Vector<QGraphicsRectItem*> items;
    QGraphicsRectItem* search = nullptr;

    qreal length;
    qreal heightPerI;

    void reset(Vector<int>*);
    void updateItem(int);
    void updateSearch(int);
    void resetSearch();
};

#endif // SORTVISUALS_H
