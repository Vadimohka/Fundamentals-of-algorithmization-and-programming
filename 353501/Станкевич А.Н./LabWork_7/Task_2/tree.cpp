#include "tree.h"

TreeNode *Tree::insertUtil(TreeNode *node, QPair<int, QString> pair) {
    if (node == nullptr) {
        return new TreeNode(pair.first, pair.second);
    }
    int key = pair.first;
    if (key < node->key) {
        node->left = insertUtil(node->left, pair);
    } else if (key > node->key) {
        node->right = insertUtil(node->right, pair);
    }

    return node;
}

TreeNode* Tree::deleteUtil(TreeNode* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = deleteUtil(node->left, key);
    } else if (key > node->key) {
        node->right = deleteUtil(node->right, key);
    } else {
        // Узел, который нужно удалить, найден
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        // Узел имеет два потомка
        node->key = findMin(node->right)->key;
        node->right = deleteUtil(node->right, node->key);
    }

    return node;
}

TreeNode *Tree::findMin(TreeNode *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode *Tree::findNode(TreeNode *node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }

    if (key < node->key) {
        return findNode(node->left, key);
    } else {
        return findNode(node->right, key);
    }
}

void Tree::destroyTree(TreeNode *node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void Tree::preOrderToVec(TreeNode *node, QVector<QPair<int, QString>> & vec) {
    if (node != nullptr) {
          vec.push_back(QPair<int, QString>(node->key, node->str));
        preOrderToVec(node->left, vec);
        preOrderToVec(node->right, vec);
    }
}

void Tree::buildTreeFromVector(QVector<QPair<int, QString>> a) {
    for (auto & i : a) {
        root = insertUtil(root, i);
    }
}

void Tree::postOrderToVec(TreeNode *node, QVector<QPair<int, QString>> & vec) {
    if (node != nullptr) {
        postOrderToVec(node->left, vec);
        postOrderToVec(node->right, vec);
          vec.push_back(QPair<int, QString>(node->key, node->str));
    }
}

void Tree::inOrderToVec(TreeNode *node, QVector<QPair<int, QString>> & vec) {
    if (node != nullptr) {
        inOrderToVec(node->left, vec);
          vec.push_back(QPair<int, QString>(node->key, node->str));
        inOrderToVec(node->right, vec);
    }
}

Tree::Tree() : root(nullptr) {}

TreeNode *Tree::insert(QPair<int, QString> pair) {
    root = insertUtil(root, pair);
    return root;
}

int Tree::search(int key) {
    TreeNode* node = findNode(root, key);
    if (node != nullptr) {
        return node->key;
    } else {
        return -1;
    }
}

void Tree::remove(int key) {
    root = deleteUtil(root, key);
}

QVector<QPair<int, QString>> Tree::preOrderToVec() {
    QVector<QPair<int, QString>> vec;
    preOrderToVec(root, vec);
    return vec;
}

QVector<QPair<int, QString>> Tree::postOrderToVec() {
    QVector<QPair<int, QString>> vec;
    postOrderToVec(root, vec);
    return vec;
}

QVector<QPair<int, QString>> Tree::inOrderToVec() {
    QVector<QPair<int, QString>> vec;
    inOrderToVec(root, vec);
    return vec;
}

Tree::~Tree() {
    destroyTree(root);
}

TreeNode* Tree::getRoot() {
    return root;
}

QString Tree::searchStringByKey(int key) {
    TreeNode* node = findNode(root, key);
    if (node != nullptr) {
        return node->str;
    } else {
        return "";
    }
}

TreeNode* Tree::buildBalancedTree(QVector<QPair<int, QString>>& sortedPairs, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode* newNode = new TreeNode(sortedPairs[mid].first, sortedPairs[mid].second);

    newNode->left = buildBalancedTree(sortedPairs, start, mid - 1);
    newNode->right = buildBalancedTree(sortedPairs, mid + 1, end);

    return newNode;
}

void Tree::balanceTree() {
    QVector<QPair<int, QString>> sortedPairs;
    inOrderToVec(root, sortedPairs);
    root = buildBalancedTree(sortedPairs, 0, sortedPairs.size() - 1);
}


int countNodesWithTwoChildren(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int count = 0;
    if (node->left != nullptr && node->right != nullptr) {
        count = 1;
    }

    return count + countNodesWithTwoChildren(node->left) + countNodesWithTwoChildren(node->right);
}

int Tree2::nodesWith2Children() {
    return countNodesWithTwoChildren(root);
}
