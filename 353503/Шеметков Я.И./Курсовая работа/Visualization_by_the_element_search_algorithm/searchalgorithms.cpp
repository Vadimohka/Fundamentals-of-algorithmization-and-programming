#include "searchalgorithms.h"

SearchAlgorithms::SearchAlgorithms(QObject *parent) : QObject(parent) {}

QVector<QGraphicsItem *> SearchAlgorithms::getVector() {
    QVector<QGraphicsItem *> items;
    for (auto item : markedItems) {
        items.append(static_cast<QGraphicsItem*>(item));
    }
    return items;
}

QVector<QGraphicsItem *> SearchAlgorithms::getGraphVector() {
    QVector<QGraphicsItem *> nodes;
    for (auto node : markedNodes) {
        nodes.append(static_cast<QGraphicsItem*>(node));
    }
    return nodes;
}

void SearchAlgorithms::linearSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue) {
    markedItems.clear();
    for (auto &item : items) {
        markedItems.append(item);
        int itemValue = item->data(0).toInt();

        if (itemValue == searchedValue) {
            break;
        }
    }
    emit searchCompleted(markedItems);
    emit itemsForAnimationUpdated(markedItems);
}

void SearchAlgorithms::binarySearch(const QVector<QGraphicsRectItem *> &items, int searchedValue) {
    markedItems.clear();

    int left = 0;
    int right = items.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        markedItems.append(items[middle]);

        int itemValue = items[middle]->data(0).toInt();

        if (itemValue == searchedValue) {
            break;
        }

        if (itemValue < searchedValue) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    emit searchCompleted(markedItems);
    emit itemsForAnimationUpdated(markedItems);
}

void SearchAlgorithms::interpolationSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue) {
    markedItems.clear();

    int left = 0;
    int right = items.size() - 1;

    while (left <= right && searchedValue >= items[left]->data(0).toInt() && searchedValue <= items[right]->data(0).toInt()) {
        if (left == right) {
            if (items[left]->data(0).toInt() == searchedValue) {
                markedItems.append(items[left]);
            }
            break;
        }

        int pos = left + (((double)(right - left) / (items[right]->data(0).toInt() - items[left]->data(0).toInt())) * (searchedValue - items[left]->data(0).toInt()));

        markedItems.append(items[pos]);

        if (items[pos]->data(0).toInt() == searchedValue) {
            break;
        }

        if (items[pos]->data(0).toInt() < searchedValue) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }

    emit searchCompleted(markedItems);
    emit itemsForAnimationUpdated(markedItems);
}


void SearchAlgorithms::quadraticStepSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue) {
    markedItems.clear();

    int n = items.size();
    int i = 1;

    while (i < n && items[i]->data(0).toInt() < searchedValue) {
        markedItems.append(items[i]);
        i *= 2;
    }

    int left = i / 2;
    int right = std::min(i, n - 1);

    while (left <= right) {
        markedItems.append(items[left]);

        if (items[left]->data(0).toInt() == searchedValue) {
            break;
        }

        left++;
    }

    emit searchCompleted(markedItems);
    emit itemsForAnimationUpdated(markedItems);
}


void SearchAlgorithms::fibonacciSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue) {
    markedItems.clear();

    int n = items.size();
    int fibM_minus_2 = 0;
    int fibM_minus_1 = 1;
    int fibM = fibM_minus_1 + fibM_minus_2;

    while (fibM < n) {
        fibM_minus_2 = fibM_minus_1;
        fibM_minus_1 = fibM;
        fibM = fibM_minus_1 + fibM_minus_2;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = std::min(offset + fibM_minus_2, n - 1);

        markedItems.append(items[i]);

        if (items[i]->data(0).toInt() < searchedValue) {
            fibM = fibM_minus_1;
            fibM_minus_1 = fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
            offset = i;
        } else if (items[i]->data(0).toInt() > searchedValue) {
            fibM = fibM_minus_2;
            fibM_minus_1 -= fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
        } else {
            break;
        }
    }

    if (fibM_minus_1 && items[offset + 1]->data(0).toInt() == searchedValue) {
        markedItems.append(items[offset + 1]);
    }

    emit searchCompleted(markedItems);
    emit itemsForAnimationUpdated(markedItems);
}


void SearchAlgorithms::jumpSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue) {
    markedItems.clear();
int n = items.size();
int step = sqrt(n);

int prev = 0;
while (items[std::min(step, n) - 1]->data(0).toInt() < searchedValue) {
    markedItems.append(items[std::min(step, n) - 1]);
    prev = step;
    step += sqrt(n);
    if (prev >= n) {
        emit searchCompleted(markedItems);
        emit itemsForAnimationUpdated(markedItems);
        return;
    }
}

while (items[prev]->data(0).toInt() < searchedValue) {
    markedItems.append(items[prev]);
    prev++;
    if (prev == std::min(step, n)) {
        emit searchCompleted(markedItems);
        emit itemsForAnimationUpdated(markedItems);
        return;
    }
}

if (items[prev]->data(0).toInt() == searchedValue) {
    markedItems.append(items[prev]);
}

emit searchCompleted(markedItems);
emit itemsForAnimationUpdated(markedItems);
}


void SearchAlgorithms::exponentialSearch(const QVector<QGraphicsRectItem *> &items, int searchedValue) {
markedItems.clear();


if (items.isEmpty()) return;

int n = items.size();
if (items[0]->data(0).toInt() == searchedValue) {
    markedItems.append(items[0]);
    emit searchCompleted(markedItems);
    emit itemsForAnimationUpdated(markedItems);
    return;
}

int i = 1;
while (i < n && items[i]->data(0).toInt() <= searchedValue) {
    markedItems.append(items[i]);
    i *= 2;
}

int left = i / 2;
int right = std::min(i, n - 1);

while (left <= right) {
    markedItems.append(items[left]);

    if (items[left]->data(0).toInt() == searchedValue) {
        break;
    }

    left++;
}

emit searchCompleted(markedItems);
emit itemsForAnimationUpdated(markedItems);
}



void SearchAlgorithms::breadthFirstSearch(const QVector<QGraphicsEllipseItem *> &nodes, const QMap<QGraphicsEllipseItem*, QVector<QGraphicsEllipseItem*>> &adjacencyList, int searchedValue) {
    markedNodes.clear();
    if (nodes.isEmpty()) return;

    QQueue<QGraphicsEllipseItem *> queue;
    QSet<QGraphicsEllipseItem *> visited;

    queue.enqueue(nodes.first());
    visited.insert(nodes.first());

    while (!queue.isEmpty()) {
        QGraphicsEllipseItem *current = queue.dequeue();
        markedNodes.append(current);

        int nodeValue = current->data(0).toInt();
        if (nodeValue == searchedValue) {
            break;
        }

        for (QGraphicsEllipseItem *neighbor : adjacencyList.value(current)) {
            if (!visited.contains(neighbor)) {
                queue.enqueue(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    emit graphSearchCompleted(markedNodes);
    emit graphItemsForAnimationUpdated(markedNodes);
}


void SearchAlgorithms::depthFirstSearch(const QVector<QGraphicsEllipseItem *> &nodes, const QMap<QGraphicsEllipseItem*, QVector<QGraphicsEllipseItem*>> &adjacencyList, int searchedValue) {
    markedNodes.clear();
    if (nodes.isEmpty()) return;

    QStack<QGraphicsEllipseItem *> stack;
    QSet<QGraphicsEllipseItem *> visited;

    stack.push(nodes.first());
    visited.insert(nodes.first());

    while (!stack.isEmpty()) {
        QGraphicsEllipseItem *current = stack.pop();
        markedNodes.append(current);

        int nodeValue = current->data(0).toInt();
        if (nodeValue == searchedValue) {
            break;
        }

        for (QGraphicsEllipseItem *neighbor : adjacencyList.value(current)) {
            if (!visited.contains(neighbor)) {
                stack.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    emit graphSearchCompleted(markedNodes);
    emit graphItemsForAnimationUpdated(markedNodes);
}


void SearchAlgorithms::setBST(const BST &bst) {
    m_bst = bst;
}


void SearchAlgorithms::searchInBST(int target, const QVector<QGraphicsEllipseItem*> &graphNodes) {
    QVector<BSTNode*> path;
    bool found = m_bst.search(target, path);

    QVector<QGraphicsEllipseItem*> nodesForAnimation;
    for (auto node : path) {
        for (auto graphNode : graphNodes) {
            if (graphNode->data(0).toInt() == node->value) {
                nodesForAnimation.append(graphNode);
                break;
            }
        }
    }

    emit graphSearchCompleted(nodesForAnimation);
    emit graphItemsForAnimationUpdated(nodesForAnimation);
}


