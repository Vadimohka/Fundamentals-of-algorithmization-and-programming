#include "binarytree.h"

BinaryTree::BinaryTree()
    : root(nullptr) {}

BinaryTree::~BinaryTree() {
    deleteTree(root);
}

void BinaryTree::buildTreeFromArray(const QStringList& data, const QList<int>& keys) {
    for (int i = 0; i < data.size(); ++i) {
        addNode(data[i], keys[i]);
    }
}

void BinaryTree::balanceTree() {
    if (root == nullptr) {
        return;
    }


    Node* current = root;
    while (current->left != nullptr) {
        Node* temp = current->left;
        current->left = temp->right;
        temp->right = current;
        current = temp;
    }
    root = current;


    int size = 0;
    Node* node = root;
    while (node != nullptr) {
        size++;
        node = node->right;
    }

    int height = static_cast<int>(std::log2(size)) + 1;
    int step = 1 << (height - 1);
    Node* prev = nullptr;
    node = root;

    while (step > 0) {
        while (node != nullptr) {
            for (int i = 0; i < step; i++) {
                prev = node;
                node = node->right;
            }
            prev->right = node;
            for (int i = 0; i < step - 1; i++) {
                prev = prev->right;
            }
            prev->right = nullptr;
        }
        step >>= 1;
        node = root;
    }
}
void BinaryTree::addNode(const QString& info, int key) {
    addNodePrivate(root, info, key);
}

Node* BinaryTree::findNode(int key) {
    Node* current = root;
    while (current != nullptr) {
        if (key == current->key) {
            return current;
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}

void BinaryTree::removeNode(int key) {
    root = removeNodePrivate(root, key);
}

void BinaryTree::printInOrder(QStringList& result) {
    printInOrderPrivate(root, result);
}

void BinaryTree::printPreOrder(QStringList& result) {
    printPreOrderPrivate(root, result);
}

void BinaryTree::printPostOrder(QStringList& result) {
    printPostOrderPrivate(root, result);
}

void BinaryTree::swapMaxMinKeys() {
    Node* minNode = findMinNode(root);
    Node* maxNode = findMaxNode(root);

    if (minNode && maxNode) {
        int temp = minNode->key;
        minNode->key = maxNode->key;
        maxNode->key = temp;
    }
}

void BinaryTree::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void BinaryTree::addNodePrivate(Node*& node, const QString& info, int key) {
    if (!node) {
        node = new Node(info, key);
    } else if (key < node->key) {
        addNodePrivate(node->left, info, key);
    } else {
        addNodePrivate(node->right, info, key);
    }
}

Node* BinaryTree::removeNodePrivate(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = removeNodePrivate(node->left, key);
    } else if (key > node->key) {
        node->right = removeNodePrivate(node->right, key);
    } else {
        // Node found
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* minNode = findMinNode(node->right);
        node->key = minNode->key;
        node->info = minNode->info;
        node->right = removeNodePrivate(node->right, minNode->key);
    }

    return node;
}

void BinaryTree::printInOrderPrivate(Node* node, QStringList& result) {
    if (node != nullptr) {
        printInOrderPrivate(node->left, result);
        result.append(node->info + " (" + QString::number(node->key) + ")");
        printInOrderPrivate(node->right, result);
    }
}

void BinaryTree::printPreOrderPrivate(Node* node, QStringList& result) {
    if (node != nullptr) {
        result.append(node->info + " (" + QString::number(node->key) + ")");
        printPreOrderPrivate(node->left, result);
        printPreOrderPrivate(node->right, result);
    }
}

void BinaryTree::printPostOrderPrivate(Node* node, QStringList& result) {
    if (node != nullptr) {
        printPostOrderPrivate(node->left, result);
        printPostOrderPrivate(node->right, result);
        result.append(node->info + " (" + QString::number(node->key) + ")");
    }
}

Node* BinaryTree::findMinNode(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* BinaryTree::findMaxNode(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    Node* current = node;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}

