#include "treeHeap.h"
#include <algorithm>

// Конструктор
TreeHeap::TreeHeap() {
    rootNode = nullptr;
    currentLevel = 0;
    indexAtLevel = 0;
}

// Деструктор
TreeHeap::~TreeHeap() {}

void TreeHeap::bubbleUp(std::shared_ptr<TreeNode> node) {
    if (node->parentNode.lock() == nullptr) return;

    if (node->value > node->parentNode.lock()->value) {
        std::swap(node->value, node->parentNode.lock()->value);
        bubbleUp(node->parentNode.lock());
    }
}

void TreeHeap::bubbleDown(std::shared_ptr<TreeNode> node) {
    std::shared_ptr<TreeNode> targetNode = node;
    int largestValue = node->value;

    if (node->leftChild && node->leftChild->value > largestValue) {
        targetNode = node->leftChild;
        largestValue = node->leftChild->value;
    }

    if (node->rightChild && node->rightChild->value > largestValue) {
        targetNode = node->rightChild;
        largestValue = node->rightChild->value;
    }

    if (targetNode != node) {
        std::swap(node->value, targetNode->value);
        bubbleDown(targetNode);
    }
}

void TreeHeap::insert(long value) {
    if (currentLevel == 0) {
        rootNode = std::make_shared<TreeNode>();
        rootNode->value = value;
        rootNode->parentNode.reset();
        rootNode->leftChild = nullptr;
        rootNode->rightChild = nullptr;

        currentLevel++;
        indexAtLevel = 0;
        return;
    }

    std::shared_ptr<TreeNode> currentNode = rootNode;
    for (int i = currentLevel - 1; i >= 0; i--) {
        bool moveRight = (indexAtLevel & (1 << i)) != 0;
        if (moveRight) {
            if (currentNode->rightChild == nullptr) {
                currentNode->rightChild = std::make_shared<TreeNode>();
                currentNode->rightChild->parentNode = currentNode;
            }
            currentNode = currentNode->rightChild;
        } else {
            if (currentNode->leftChild == nullptr) {
                currentNode->leftChild = std::make_shared<TreeNode>();
                currentNode->leftChild->parentNode = currentNode;
            }
            currentNode = currentNode->leftChild;
        }
    }

    currentNode->value = value;
    indexAtLevel++;

    if (indexAtLevel == (1 << currentLevel)) {
        currentLevel++;
        indexAtLevel = 0;
    }

    bubbleUp(currentNode);
}

long TreeHeap::remove() {
    long rootValue = rootNode->value;

    indexAtLevel--;
    if (indexAtLevel < 0) {
        currentLevel--;
        indexAtLevel = (1 << currentLevel) - 1;
    }

    if (currentLevel == 0) {
        rootNode.reset();
        return rootValue;
    }

    std::shared_ptr<TreeNode> currentNode = rootNode;
    for (int i = currentLevel - 1; i >= 0; i--) {
        bool moveRight = (indexAtLevel & (1 << i)) != 0;
        if (moveRight) {
            currentNode = currentNode->rightChild;
        } else {
            currentNode = currentNode->leftChild;
        }
    }

    std::swap(currentNode->value, rootNode->value);
    std::shared_ptr<TreeNode> parentNode = currentNode->parentNode.lock();
    if (parentNode->leftChild == currentNode) {
        parentNode->leftChild.reset();
    }
    if (parentNode->rightChild == currentNode) {
        parentNode->rightChild.reset();
    }
    bubbleDown(rootNode);

    return rootValue;
}

QTreeWidgetItem* TreeHeap::createGuiNode(std::shared_ptr<TreeNode> node) {
    auto guiNode = new QTreeWidgetItem;
    guiNode->setText(0, QString::number(node->value));
    if (node->leftChild) {
        guiNode->addChild(createGuiNode(node->leftChild));
    }
    if (node->rightChild) {
        guiNode->addChild(createGuiNode(node->rightChild));
    }
    return guiNode;
}

void TreeHeap::display(QTreeWidget* widget) {
    widget->clear();
    if (rootNode) {
        widget->insertTopLevelItem(0, createGuiNode(rootNode));
    }
    widget->expandAll();
}

bool TreeHeap::isEmpty() const {
    return rootNode == nullptr;
}

void TreeHeap::reset() {
    rootNode.reset();
}

int& TreeHeap::top() const {
    return rootNode->value;
}
