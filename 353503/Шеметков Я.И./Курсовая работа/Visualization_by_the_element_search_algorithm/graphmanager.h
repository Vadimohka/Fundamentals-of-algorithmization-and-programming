#ifndef GRAPHMANAGER_H
#define GRAPHMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QVector>
#include <QMap>
#include <QSet>
#include <QPair>
#include <QRandomGenerator>
#include <ctime>
#include <cstdlib>

#include "GraphNodeItem.h"
#include "bst.h"

class GraphManager : public QObject {
    Q_OBJECT

public:
    explicit GraphManager(QGraphicsScene *scene, QObject *parent = nullptr);

    void setupGraph(int nodeCount, int minValue, int maxValue);
    void addNode(int value);
    void deleteNode(int value);
    void addEdge(int startNode, int endNode);

    QVector<GraphNodeItem*> getNodes() const;
    QVector<QGraphicsLineItem*> getEdges() const;

    QMap<QGraphicsEllipseItem*, QVector<QGraphicsEllipseItem*>> getAdjacencyList() const;
     QVector<int> getNodeValues() const;

    void rebuildBST();
    void updateTreeNodeAndEdgePositions();
    void updateTreeEdges();
    QVector<GraphNodeItem*> getTreeNodes(const QVector<int> &targetValues) const;

    void setAnimationRunning(bool running);
    bool isAnimationRunning() const;

    void removeEdgesConnectedToNode(int nodeIndex);
    bool edgeExists(QGraphicsEllipseItem *start, QGraphicsEllipseItem *end) const;

signals:
    void nodeDeleted(int index);
    void edgeAdded(int startNode, int endNode);
    void bstRebuilt(const BST& bst);

private slots:
    void handleNodeClicked(QGraphicsEllipseItem *node);
    void updateEdges();

private:
    QGraphicsScene *m_scene;
    QVector<GraphNodeItem*> m_nodes;
    QVector<QGraphicsLineItem*> m_edges;
    QMap<GraphNodeItem*, QVector<QGraphicsLineItem*>> m_nodeEdges;
    QSet<QPair<QGraphicsEllipseItem*, QGraphicsEllipseItem*>> m_existingEdges;
    BST m_bst;
    bool m_animationRunning;
    GraphNodeItem *selectedNode1;
    GraphNodeItem *selectedNode2;

    void addNodeItem(int value);
    void updateNodePositions();
    QVector<GraphNodeItem*> getNeighbors(GraphNodeItem *node) const;
    GraphNodeItem* findRootNode() const;
    void buildBSTRecursive(BST &bst, QSet<GraphNodeItem*> &visitedNodes, GraphNodeItem *node);
};

#endif // GRAPHMANAGER_H
