#include "bst.h"

BST::BST() : root(nullptr) {}

void BST::insert(QString data, int key) {
    root = insert(root, data, key);
}

BSTNode* BST::insert(BSTNode* node, QString data, int key) {
    if (node == nullptr) {
        return new BSTNode(data, key);
    }
    if (key < node->key) {
        node->left = insert(node->left, data, key);
    } else if (key > node->key) {
        node->right = insert(node->right, data, key);
    }
    return node;
}

QString BST::search(int key) {
    BSTNode* node = search(root, key);
    if (node) {
        return node->data;
    }
    return "";
}

BSTNode* BST::search(BSTNode* node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    }
    return search(node->right, key);
}

void BST::remove(int key) {
    root = remove(root, key);
}

BSTNode* BST::remove(BSTNode* node, int key) {
    if (node == nullptr) {
        return node;
    }
    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        BSTNode* temp = findMin(node->right);
        node->key = temp->key;
        node->data = temp->data;
        node->right = remove(node->right, temp->key);
    }
    return node;
}

BSTNode* BST::findMin(BSTNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void BST::balance() {
    QList<BSTNode*> nodes;
    storeBSTNodes(root, nodes);
    int n = nodes.size();
    root = balanceTree(nodes, 0, n - 1);
}

void BST::storeBSTNodes(BSTNode* node, QList<BSTNode*>& nodes) {
    if (node == nullptr) {
        return;
    }
    storeBSTNodes(node->left, nodes);
    nodes.append(node);
    storeBSTNodes(node->right, nodes);
}


BSTNode* BST::balanceTree(QList<BSTNode*>& nodes, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2;
    BSTNode* node = nodes[mid];

    node->left = balanceTree(nodes, start, mid - 1);
    node->right = balanceTree(nodes, mid + 1, end);

    return node;
}

QList<QString> BST::inOrder() {
    QList<QString> result;
    inOrderTraversal(root, result);
    return result;
}

void BST::inOrderTraversal(BSTNode* node, QList<QString>& result) {
    if (node == nullptr) {
        return;
    }
    inOrderTraversal(node->left, result);
    result.append(node->data);
    inOrderTraversal(node->right, result);
}

QList<QString> BST::preOrder() {
    QList<QString> result;
    preOrderTraversal(root, result);
    return result;
}

void BST::preOrderTraversal(BSTNode* node, QList<QString>& result) {
    if (node == nullptr) {
        return;
    }
    result.append(node->data);
    preOrderTraversal(node->left, result);
    preOrderTraversal(node->right, result);
}

QList<QString> BST::postOrder() {
    QList<QString> result;
    postOrderTraversal(root, result);
    return result;
}

BSTNode* BST::getRoot() const {
    return root;
}

void BST::postOrderTraversal(BSTNode* node, QList<QString>& result) {
    if (node == nullptr) {
        return;
    }
    postOrderTraversal(node->left, result);
    postOrderTraversal(node->right, result);
    result.append(node->data);
}
