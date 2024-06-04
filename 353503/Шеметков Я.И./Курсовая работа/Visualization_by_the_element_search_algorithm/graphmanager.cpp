#include "graphmanager.h"
#include <QGraphicsTextItem>
#include <QPen>
#include <QRandomGenerator>
#include <QQueue>

constexpr int NODE_DIAMETER = 30;
constexpr int TEXT_FONT_SIZE = 10;
constexpr int SCENE_BOUND_X = 400;
constexpr int SCENE_BOUND_Y = 400;

GraphManager::GraphManager(QGraphicsScene *scene, QObject *parent)
    : QObject(parent), m_scene(scene), m_animationRunning(false),
      selectedNode1(nullptr), selectedNode2(nullptr) {}

void GraphManager::setupGraph(int nodeCount, int minValue, int maxValue) {
    m_scene->clear();
    m_nodes.clear();
    m_edges.clear();
    m_nodeEdges.clear();
    m_existingEdges.clear();

    for (int i = 0; i < nodeCount; ++i) {
        int value = QRandomGenerator::global()->bounded(minValue, maxValue + 1);
        addNodeItem(value);
    }
}

void GraphManager::addNode(int value) {
    if (m_animationRunning) return;

    addNodeItem(value);
    updateNodePositions();
}

void GraphManager::deleteNode(int value) {
    int nodeIndex = -1;
    for (int i = 0; i < m_nodes.size(); ++i) {
        if (m_nodes[i]->data(0).toInt() == value) {
            nodeIndex = i;
            break;
        }
    }

    if (nodeIndex != -1) {
        emit nodeDeleted(nodeIndex);
        removeEdgesConnectedToNode(nodeIndex);
        m_scene->removeItem(m_nodes[nodeIndex]);
        delete m_nodes[nodeIndex];
        m_nodes.removeAt(nodeIndex);
        updateNodePositions();
    }
}

void GraphManager::addEdge(int startNode, int endNode) {
    if (startNode >= m_nodes.size() || endNode >= m_nodes.size()) return;

    GraphNodeItem *start = m_nodes[startNode];
    GraphNodeItem *end = m_nodes[endNode];

    if (edgeExists(start, end)) return;

    QGraphicsLineItem *line = new QGraphicsLineItem(QLineF(start->sceneBoundingRect().center(), end->sceneBoundingRect().center()));
    line->setPen(QPen(Qt::black));
    m_scene->addItem(line);
    m_edges.append(line);
    m_nodeEdges[start].append(line);
    m_nodeEdges[end].append(line);
    m_existingEdges.insert(qMakePair(start, end));
    m_existingEdges.insert(qMakePair(end, start));
    emit edgeAdded(startNode, endNode);

    connect(start, &GraphNodeItem::positionChanged, this, &GraphManager::updateEdges);
    connect(end, &GraphNodeItem::positionChanged, this, &GraphManager::updateEdges);
}

QVector<GraphNodeItem *> GraphManager::getNodes() const {
    return m_nodes;
}

QVector<QGraphicsLineItem *> GraphManager::getEdges() const {
    return m_edges;
}

void GraphManager::addNodeItem(int value) {
    int x = QRandomGenerator::global()->bounded(0, SCENE_BOUND_X);
    int y = QRandomGenerator::global()->bounded(0, SCENE_BOUND_Y);
    GraphNodeItem *ellipse = new GraphNodeItem(value);
    ellipse->setRect(x, y, NODE_DIAMETER, NODE_DIAMETER);
    ellipse->setPen(QPen(Qt::black));
    ellipse->setBrush(Qt::NoBrush);
    ellipse->setData(0, value);
    connect(ellipse, &GraphNodeItem::nodeClicked, this, &GraphManager::handleNodeClicked);
    m_scene->addItem(ellipse);

    QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(value), ellipse);
    text->setDefaultTextColor(Qt::black);
    text->setFont(QFont("Arial", TEXT_FONT_SIZE, QFont::Bold));
    QRectF ellipseBounds = ellipse->boundingRect();
    QRectF textBounds = text->boundingRect();
    text->setPos(ellipseBounds.center() - textBounds.center());

    m_nodes.append(ellipse);
}

void GraphManager::updateNodePositions() {
    for (int i = 0; i < m_nodes.size(); ++i) {
        QGraphicsTextItem *text = static_cast<QGraphicsTextItem *>(m_nodes[i]->childItems().first());
        QRectF ellipseBounds = m_nodes[i]->boundingRect();
        QRectF textBounds = text->boundingRect();
        text->setPos(ellipseBounds.center() - textBounds.center());
    }

    updateEdges();
}

void GraphManager::updateEdges() {
    for (auto edge : m_edges) {
        QGraphicsEllipseItem *start = nullptr;
        QGraphicsEllipseItem *end = nullptr;

        for (auto it = m_nodeEdges.begin(); it != m_nodeEdges.end(); ++it) {
            if (it.value().contains(edge)) {
                if (!start) {
                    start = it.key();
                } else {
                    end = it.key();
                    break;
                }
            }
        }

                if (start && end) {
                    edge->setLine(QLineF(start->sceneBoundingRect().center(), end->sceneBoundingRect().center()));
                }
            }
        }

        void GraphManager::setAnimationRunning(bool running) {
            m_animationRunning = running;
        }

        bool GraphManager::isAnimationRunning() const {
            return m_animationRunning;
        }

        void GraphManager::removeEdgesConnectedToNode(int nodeIndex) {
            GraphNodeItem* node = m_nodes[nodeIndex];
            QVector<QGraphicsLineItem*> edges = m_nodeEdges[node];

            for (QGraphicsLineItem* edge : edges) {
                m_scene->removeItem(edge);
                m_edges.removeOne(edge);
            }

            m_nodeEdges.remove(node);

            QSet<QPair<QGraphicsEllipseItem*, QGraphicsEllipseItem*>> newExistingEdges;
            for (const auto& pair : m_existingEdges) {
                if (pair.first != node && pair.second != node) {
                    newExistingEdges.insert(pair);
                }
            }
            m_existingEdges = newExistingEdges;
        }

        bool GraphManager::edgeExists(QGraphicsEllipseItem *start, QGraphicsEllipseItem *end) const {
            return m_existingEdges.contains(qMakePair(start, end));
        }

        void GraphManager::handleNodeClicked(QGraphicsEllipseItem *node) {
            if (!selectedNode1) {
                selectedNode1 = dynamic_cast<GraphNodeItem*>(node);
            } else if (!selectedNode2) {
                selectedNode2 = dynamic_cast<GraphNodeItem*>(node);
                if (selectedNode1 != selectedNode2) {
                    int startIndex = m_nodes.indexOf(selectedNode1);
                    int endIndex = m_nodes.indexOf(selectedNode2);
                    addEdge(startIndex, endIndex);
                }
                selectedNode1 = nullptr;
                selectedNode2 = nullptr;
            }
        }

        QMap<QGraphicsEllipseItem*, QVector<QGraphicsEllipseItem*>> GraphManager::getAdjacencyList() const {
            QMap<QGraphicsEllipseItem*, QVector<QGraphicsEllipseItem*>> adjacencyList;
            for (auto node : m_nodes) {
                QVector<QGraphicsEllipseItem*> neighbors;
                for (auto edge : m_nodeEdges[node]) {
                    for (auto neighbor : m_nodes) {
                        if (neighbor != node && (edge->line().p1() == neighbor->sceneBoundingRect().center() || edge->line().p2() == neighbor->sceneBoundingRect().center())) {
                            neighbors.append(neighbor);
                        }
                    }
                }
                adjacencyList.insert(node, neighbors);
            }
            return adjacencyList;
        }

        void GraphManager::rebuildBST() {
            m_bst = BST(); // Инициализируем пустой BST
            QSet<GraphNodeItem*> visitedNodes;
            for (auto node : m_nodes) {
                if (!visitedNodes.contains(node)) {
                    buildBSTRecursive(m_bst, visitedNodes, node);
                }
            }

            emit bstRebuilt(m_bst); // Отправляем сигнал с новым BST
            updateTreeNodeAndEdgePositions(); // Обновляем позиции узлов и линий
        }

        void GraphManager::buildBSTRecursive(BST &bst, QSet<GraphNodeItem*> &visitedNodes, GraphNodeItem *node) {
            if (!node) return;
            visitedNodes.insert(node);
            bst.insert(node->data(0).toInt());
            QVector<GraphNodeItem*> neighbors = getNeighbors(node);
            for (auto neighbor : neighbors) {
                if (!visitedNodes.contains(neighbor)) {
                    buildBSTRecursive(bst, visitedNodes, neighbor);
                }
            }
        }

        QVector<GraphNodeItem*> GraphManager::getNeighbors(GraphNodeItem *node) const {
            QVector<GraphNodeItem*> neighbors;
            QVector<QGraphicsLineItem*> edges = m_nodeEdges[node];
            for (auto edge : edges) {
                for (auto it = m_nodeEdges.begin(); it != m_nodeEdges.end(); ++it) {
                    if (it.value().contains(edge) && it.key() != node) {
                        GraphNodeItem *neighborNode = dynamic_cast<GraphNodeItem*>(it.key());
                        if (neighborNode) {
                            neighbors.append(neighborNode);
                            break;
                        }
                    }
                }
            }
            return neighbors;
        }

        void GraphManager::updateTreeNodeAndEdgePositions() {
            if (m_nodes.isEmpty()) return;

            qreal sceneWidth = m_scene->width();
            qreal sceneHeight = m_scene->height();
            qreal levelHeight = NODE_DIAMETER * 2;
            qreal centerX = sceneWidth / 2;
            qreal startY = levelHeight;


            QQueue<GraphNodeItem*> queue;
            QSet<GraphNodeItem*> visitedNodes;

            // Начнем с корневого узла BST
            GraphNodeItem* rootNode = findRootNode(); // Найти случайный корневой узел
            if (!rootNode) return;

            queue.enqueue(rootNode);
            visitedNodes.insert(rootNode);

            // Уровни для каждого узла
            QMap<GraphNodeItem*, int> nodeLevels;
            nodeLevels[rootNode] = 0;

            while (!queue.isEmpty()) {
                GraphNodeItem* currentNode = queue.dequeue();
                int currentLevel = nodeLevels[currentNode];

                QVector<GraphNodeItem*> neighbors = getNeighbors(currentNode);
                qreal totalWidth = neighbors.size() * NODE_DIAMETER;
                qreal startX = centerX - (totalWidth / 2);

                // Расставим соседей на следующем уровне
                for (int i = 0; i < neighbors.size(); ++i) {
                    GraphNodeItem* neighbor = neighbors[i];
                    if (!visitedNodes.contains(neighbor)) {
                        qreal posX = startX + i * NODE_DIAMETER;
                        qreal posY = startY + currentLevel * levelHeight;
                        neighbor->setPos(posX, posY);
                        queue.enqueue(neighbor);
                        visitedNodes.insert(neighbor);
                        nodeLevels[neighbor] = currentLevel + 1;

                        // Обновление позиции текстовых меток
                        auto childItems = neighbor->childItems();
                        if (!childItems.isEmpty()) {
                            QGraphicsTextItem *text = dynamic_cast<QGraphicsTextItem *>(childItems.first());
                            if (text) {
                                QRectF nodeBounds = neighbor->boundingRect();
                                QRectF textBounds = text->boundingRect();
                                text->setPos(nodeBounds.center() - textBounds.center());
                            }
                        }
                    }
                }
            }

            updateEdges(); // Обновление позиций линий
        }

        void GraphManager::updateTreeEdges() {
            for (auto it = m_nodeEdges.begin(); it != m_nodeEdges.end(); ++it) {
                GraphNodeItem* node = it.key();
                QVector<QGraphicsLineItem*> edges = it.value();
                for (auto edge : edges) {
                    QLineF line = edge->line();
                    line.setP1(node->pos());
                    for (auto neighborIt = m_nodeEdges.begin(); neighborIt != m_nodeEdges.end(); ++neighborIt) {
                        if (neighborIt.value().contains(edge) && neighborIt.key() != node) {
                            line.setP2(neighborIt.key()->pos());
                            break;
                        }
                    }
                    edge->setLine(line);
                }
            }
        }

        GraphNodeItem* GraphManager::findRootNode() const {
            if (m_nodes.isEmpty()) return nullptr;

            // Инициализация генератора случайных чисел
            std::srand(static_cast<unsigned int>(std::time(nullptr)));

            // Выбор случайного индекса
            int randomIndex = std::rand() % m_nodes.size();

            return m_nodes[randomIndex];
        }


        QVector<GraphNodeItem*> GraphManager::getTreeNodes(const QVector<int> &targetValues) const {
            QVector<GraphNodeItem*> nodesForAnimation;
            for (int value : targetValues) {
                for (auto node : m_nodes) {
                    if (node->data(0).toInt() == value) {
                        nodesForAnimation.append(node);
                        break;
                    }
                }
            }
            return nodesForAnimation;
        }

        QVector<int> GraphManager::getNodeValues() const {
            QVector<int> values;
            for (auto node : m_nodes) {
                values.append(node->data(0).toInt());
            }
            return values;
        }
