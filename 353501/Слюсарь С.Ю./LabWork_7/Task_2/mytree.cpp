#include "mytree.h"

MyTree::MyTree() : root(nullptr) {}

MyTree::~MyTree() {
    destroySubTree(root);
}

TreeNode *MyTree::getRoot()
{
    return root;
}

void MyTree::insert(QPair<int, QString> pair) {
    root = insertNode(root, pair);
}

TreeNode* MyTree::insertNode(TreeNode* node, QPair<int, QString> pair) {
    if (node == nullptr) {
        return new TreeNode(pair.first, pair.second);
    }

    TreeNode* current = node;
    TreeNode* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (pair.first < current->key) {
            current = current->left_child;
        } else if (pair.first > current->key) {
            current = current->right_child;
        } else {
            return node;
        }
    }

    if (pair.first < parent->key) {
        parent->left_child = new TreeNode(pair.first, pair.second);
    } else {
        parent->right_child = new TreeNode(pair.first, pair.second);
    }

    return node;
}

int MyTree::search(int key) {
    TreeNode* node = findNodeByKey(root, key);
    if (node != nullptr) {
        return node->key;
    } else {
        return -1;
    }
}

QString MyTree::searchStringByKey(int key)
{
    TreeNode* node = findNodeByKey(root, key);
    if (node != nullptr) {
        return node->data;
    } else {
        return QString("Key not found");
    }
}

TreeNode* MyTree::findNodeByKey(TreeNode* node, int key) {
    while (node != nullptr && node->key != key) {
        if (key < node->key) {
            node = node->left_child;
        } else {
            node = node->right_child;
        }
    }
    return node;
}

void MyTree::remove(int key) {
    root = deleteNode(root, key);
}

TreeNode* MyTree::deleteNode(TreeNode* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    TreeNode* current = node;
    TreeNode* parent = nullptr;

    while (current != nullptr && current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left_child;
        } else {
            current = current->right_child;
        }
    }

    if (current == nullptr) {
        return node;
    }

    // Case 1: Node has no children
    if (current == root) {
        if (current->left_child == nullptr && current->right_child == nullptr) {
            delete current;
            return nullptr; // No nodes left in the tree
        } else if (current->left_child == nullptr) {
            root = current->right_child;
            delete current;
            return root;
        } else if (current->right_child == nullptr) {
            root = current->left_child;
            delete current;
            return root;
        } else {
            TreeNode* successor = findMinimum(current->right_child);
            current->key = successor->key;
            current->data = successor->data;
            current->right_child = deleteNode(current->right_child, successor->key);
            return root;
        }
    }
    // Case 2: Node has one child
    else if (current->left_child == nullptr && current->right_child == nullptr) {
        if (parent->left_child == current) {
            parent->left_child = nullptr;
        } else {
            parent->right_child = nullptr;
        }
        delete current;
    }
    // Case 3: Node has one child
    else if (current->left_child == nullptr) {
        if (parent->left_child == current) {
            parent->left_child = current->right_child;
        } else {
            parent->right_child = current->right_child;
        }
        delete current;
    } else if (current->right_child == nullptr) {
        if (parent->left_child == current) {
            parent->left_child = current->left_child;
        } else {
            parent->right_child = current->left_child;
        }
        delete current;
    }
    // Case 4: Node has two children
    else {
        TreeNode* successor = findMinimum(current->right_child);
        current->key = successor->key;
        current->data = successor->data;
        current->right_child = deleteNode(current->right_child, successor->key);
    }

    return node;
}

TreeNode* MyTree::findMinimum(TreeNode* node) {
    while (node->left_child != nullptr) {
        node = node->left_child;
    }
    return node;
}

void MyTree::destroySubTree(TreeNode* node) {
    if (node != nullptr) {
        destroySubTree(node->left_child);
        destroySubTree(node->right_child);
        delete node;
    }
}

void MyTree::preOrderTraversal(TreeNode* node, QVector<QPair<int, QString>>& vec) {
    if (node != nullptr) {
        vec.append(qMakePair(node->key, node->data));
        preOrderTraversal(node->left_child, vec);
        preOrderTraversal(node->right_child, vec);
    }
}

QVector<QPair<int, QString>> MyTree::getPreOrder() {
    QVector<QPair<int, QString>> result;
    preOrderTraversal(root, result);
    return result;
}

void MyTree::postOrderTraversal(TreeNode* node, QVector<QPair<int, QString>>& vec) {
    if (node != nullptr) {
        postOrderTraversal(node->left_child, vec);
        postOrderTraversal(node->right_child, vec);
        vec.append(qMakePair(node->key, node->data));
    }
}

QVector<QPair<int, QString>> MyTree::getPostOrder() {
    QVector<QPair<int, QString>> result;
    postOrderTraversal(root, result);
    return result;
}

void MyTree::inOrderTraversal(TreeNode* node, QVector<QPair<int, QString>>& vec) {
    if (node != nullptr) {
        inOrderTraversal(node->left_child, vec);
        vec.append(qMakePair(node->key, node->data));
        inOrderTraversal(node->right_child, vec);
    }
}

QVector<QPair<int, QString>> MyTree::getInOrder() {
    QVector<QPair<int, QString>> result;
    inOrderTraversal(root, result);
    return result;
}

void MyTree::buildTreeFromVector(QVector<QPair<int, QString>> data) {
    for (const auto& pair : data) {
        insert(pair);
    }
}

TreeNode* MyTree::buildBalancedTreeHelper(QVector<QPair<int, QString>>& sortedPairs, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode* newNode = new TreeNode(sortedPairs[mid].first, sortedPairs[mid].second);
    newNode->left_child = buildBalancedTreeHelper(sortedPairs, start, mid - 1);
    newNode->right_child = buildBalancedTreeHelper(sortedPairs, mid + 1, end);
    return newNode;
}

void MyTree::balanceTree() {
    QVector<QPair<int, QString>> sortedPairs = getInOrder();
    root = buildBalancedTreeHelper(sortedPairs, 0, sortedPairs.size() - 1);
}

void MyTree::countLeavesPerLevel(TreeNode* node, QVector<int>& leafCounts, int level) {
    if (node == nullptr) {
        return;
    }

    if (level >= leafCounts.size()) {
        leafCounts.resize(level + 1, 0);
    }

    if (node->left_child == nullptr && node->right_child == nullptr) {
        leafCounts[level]++;
    }

    countLeavesPerLevel(node->left_child, leafCounts, level + 1);
    countLeavesPerLevel(node->right_child, leafCounts, level + 1);
}

QVector<int> MyTree::getLeavesPerLevel() {
    QVector<int> leafCounts;
    countLeavesPerLevel(root, leafCounts, 0);
    return leafCounts;
}
