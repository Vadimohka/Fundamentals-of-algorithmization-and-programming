#include "my_tree.h"

my_tree::my_tree() : root(nullptr) {}


my_tree::~my_tree() {
    destroySubTree(root);
}

tree_node *my_tree::getRoot()
{
    return root;
}

void my_tree::insert(QPair<int, QString> pair) {
    root = insertNode(root, pair);
}

tree_node* my_tree::insertNode(tree_node* node, QPair<int, QString> pair) {
    if (node == nullptr) {
        return new tree_node(pair.first, pair.second);
    }

    tree_node* current = node;
    tree_node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (pair.first < current->key) {
            current = current->left;
        } else if (pair.first > current->key) {
            current = current->right;
        } else {
            return node;
        }
    }

    if (pair.first < parent->key) {
        parent->left = new tree_node(pair.first, pair.second);
    } else {
        parent->right = new tree_node(pair.first, pair.second);
    }

    return node;
}

int my_tree::search(int key) {
    tree_node* node = findNodeByKey(root, key);
    if (node != nullptr) {
        return node->key;
    } else {
        return -1;
    }
}

QString my_tree::searchStringByKey(int key)
{
   tree_node* node = findNodeByKey(root, key);
    if (node != nullptr) {
        return node->data;
    } else {
        return QString("Key not found");
    }
}

tree_node* my_tree::findNodeByKey(tree_node* node, int key) {
    while (node != nullptr && node->key != key) {
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

void my_tree::remove(int key) {
    root = deleteNode(root, key);
}

tree_node* my_tree::deleteNode(tree_node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    tree_node* current = node;
    tree_node* parent = nullptr;

    while (current != nullptr && current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == nullptr) {
        return node;
    }

    // Case 1: Node has no children
    if (current == root) {
        if (current->left == nullptr && current->right == nullptr) {
            delete current;
            return nullptr; // No nodes left in the tree
        } else if (current->left == nullptr) {
            root = current->right;
            delete current;
            return root;
        } else if (current->right == nullptr) {
            root = current->left;
            delete current;
            return root;
        } else {
            tree_node* successor = findMinimum(current->right);
            current->key = successor->key;
            current->data = successor->data;
            current->right = deleteNode(current->right, successor->key);
            return root;
        }
    }
    // Case 2: Node has one child
    else if (current->left == nullptr && current->right == nullptr) {
        if (parent->left == current) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current;
    }
    // Case 3: Node has one child
    else if (current->left == nullptr) {
        if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        delete current;
    } else if (current->right == nullptr) {
        if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        delete current;
    }
    // Case 4: Node has two children
    else {
        tree_node* successor = findMinimum(current->right);
        current->key = successor->key;
        current->data = successor->data;
        current->right = deleteNode(current->right, successor->key);
    }

    return node;
}

tree_node* my_tree::findMinimum(tree_node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void my_tree::destroySubTree(tree_node* node) {
    if (node != nullptr) {
        destroySubTree(node->left);
        destroySubTree(node->right);
        delete node;
    }
}

void my_tree::preOrderTraversal(tree_node* node, QVector<QPair<int, QString>>& vec) {
    if (node != nullptr) {
        vec.append(qMakePair(node->key, node->data));
        preOrderTraversal(node->left, vec);
        preOrderTraversal(node->right, vec);
    }
}

QVector<QPair<int, QString>> my_tree::getPreOrder() {
    QVector<QPair<int, QString>> result;
    preOrderTraversal(root, result);
    return result;
}

void my_tree::postOrderTraversal(tree_node* node, QVector<QPair<int, QString>>& vec) {
    if (node != nullptr) {
        postOrderTraversal(node->left, vec);
        postOrderTraversal(node->right, vec);
        vec.append(qMakePair(node->key, node->data));
    }
}

QVector<QPair<int, QString>> my_tree::getPostOrder() {
    QVector<QPair<int, QString>> result;
    postOrderTraversal(root, result);
    return result;
}

void my_tree::inOrderTraversal(tree_node* node, QVector<QPair<int, QString>>& vec) {
    if (node != nullptr) {
        inOrderTraversal(node->left, vec);
        vec.append(qMakePair(node->key, node->data));
        inOrderTraversal(node->right, vec);
    }
}

QVector<QPair<int, QString>> my_tree::getInOrder() {
    QVector<QPair<int, QString>> result;
    inOrderTraversal(root, result);
    return result;
}

void my_tree::buildTreeFromVector(QVector<QPair<int, QString>> data) {
    for (const auto& pair : data) {
        insert(pair);
    }
}

tree_node* my_tree::buildBalancedTreeHelper(QVector<QPair<int, QString>>& sortedPairs, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    tree_node* newNode = new tree_node(sortedPairs[mid].first, sortedPairs[mid].second);
    newNode->left = buildBalancedTreeHelper(sortedPairs, start, mid - 1);
    newNode->right = buildBalancedTreeHelper(sortedPairs, mid + 1, end);
    return newNode;
}

void my_tree::balanceTree() {
    QVector<QPair<int, QString>> sortedPairs = getInOrder();
    root = buildBalancedTreeHelper(sortedPairs, 0, sortedPairs.size() - 1);
}

void my_tree::countLeavesPerLevel(tree_node* node, QVector<int>& leafCounts, int level) {
    if (node == nullptr) {
        return;
    }

    if (level >= leafCounts.size()) {
        leafCounts.resize(level + 1, 0);
    }

    if (node->left == nullptr && node->right == nullptr) {
        leafCounts[level]++;
    }

    countLeavesPerLevel(node->left, leafCounts, level + 1);
    countLeavesPerLevel(node->right, leafCounts, level + 1);
}

QVector<int> my_tree::getLeavesPerLevel() {
    QVector<int> leafCounts;
    countLeavesPerLevel(root, leafCounts, 0);
    return leafCounts;
}
