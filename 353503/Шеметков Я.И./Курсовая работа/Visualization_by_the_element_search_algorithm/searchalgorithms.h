#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QQueue>
#include <QSet>
#include <QStack>

#include "bst.h"

class SearchAlgorithms : public QObject
{
    Q_OBJECT
public:
    explicit SearchAlgorithms(QObject *parent = nullptr);
    QVector<QGraphicsItem *> getVector();
    QVector<QGraphicsItem *> getGraphVector();
    void linearSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue);
    void binarySearch(const QVector<QGraphicsRectItem *> &items, int searchedValue);
    void interpolationSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue);
    void quadraticStepSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue);
    void fibonacciSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue);
    void jumpSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue);
    void exponentialSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue);
    void breadthFirstSearch(const QVector<QGraphicsEllipseItem *> &nodes, const QMap<QGraphicsEllipseItem*, QVector<QGraphicsEllipseItem*>> &adjacencyList, int searchedValue);
    void depthFirstSearch(const QVector<QGraphicsEllipseItem *> &nodes, const QMap<QGraphicsEllipseItem*, QVector<QGraphicsEllipseItem*>> &adjacencyList, int searchedValue);
    void searchInBST(int target, const QVector<QGraphicsEllipseItem*> &graphNodes);
    void setBST(const BST &bst);

signals:
    void searchCompleted(const QVector<QGraphicsRectItem *> &markedItems);
    void graphSearchCompleted(const QVector<QGraphicsEllipseItem *> &markedNodes);
    void itemsForAnimationUpdated(const QVector<QGraphicsRectItem *> &items);
    void graphItemsForAnimationUpdated(const QVector<QGraphicsEllipseItem *> &items);
    void bstSearchFinished(const QVector<QGraphicsEllipseItem*> &items, int target);

private:
    BST m_bst;
    QVector<QGraphicsRectItem *> markedItems;
    QVector<QGraphicsEllipseItem *> markedNodes;
};

#endif // SEARCHALGORITHMS_H
