#include "binarytree.h"

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    deleteTree(root);
}

void BinaryTree::deleteTree(Node *node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void BinaryTree::add(const QString &data, int key) {
    add(root, data, key);
}

void BinaryTree::add(Node *&node, const QString &data, int key) {
    if (node == nullptr) {
        node = new Node(data, key);
    } else if (key < node->key) {
        add(node->left, data, key);
    } else {
        add(node->right, data, key);
    }
}

void BinaryTree::remove(int key) {
    remove(root, key);
}

void BinaryTree::remove(Node *&node, int key) {
    if (node == nullptr) {
        return;
    }

    if (key < node->key) {
        remove(node->left, key);
    } else if (key > node->key) {
        remove(node->right, key);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            Node *temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            Node *temp = node;
            node = node->left;
            delete temp;
        } else {
            Node *temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->key = temp->key;
            node->data = temp->data;
            remove(node->right, temp->key);
        }
    }
}

BinaryTree::Node* BinaryTree::find(int key) {
    return find(root, key);
}

BinaryTree::Node* BinaryTree::find(Node *node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    } else if (key < node->key) {
        return find(node->left, key);
    } else {
        return find(node->right, key);
    }
}

void BinaryTree::traverseInOrder(std::function<void(Node*)> visit) {
    traverseInOrder(root, visit);
}

void BinaryTree::traverseInOrder(Node *node, std::function<void(Node*)> visit) {
    if (node != nullptr) {
        traverseInOrder(node->left, visit);
        visit(node);
        traverseInOrder(node->right, visit);
    }
}

void BinaryTree::insertSubtree(Node *subtree, int parentKey) {
    Node* parent = find(parentKey);
    if (parent) {
        if (!parent->left) {
            parent->left = subtree;
        } else if (!parent->right) {
            parent->right = subtree;
        } else {
            // Родительский узел уже имеет два дочерних узла
        }
    }
}

void BinaryTree::removeSubtree(int key) {
    Node *subtree = find(key);
    if (subtree) {
        remove(subtree->left, subtree->left->key);
        remove(subtree->right, subtree->right->key);
        delete subtree;
    }
}

void BinaryTree::insertBranch(const QString &data, int key, int parentKey) {
    Node* parent = find(parentKey);
    if (parent) {
        if (!parent->left) {
            parent->left = new Node(data, key);
        } else if (!parent->right) {
            parent->right = new Node(data, key);
        } else {
            return;
        }
    }
}

void BinaryTree::removeBranch(int key) {
    remove(root, key);
}

BinaryTree::Node* BinaryTree::findLowestCommonAncestor(int key1, int key2) {
    return findLowestCommonAncestor(root, key1, key2);
}

BinaryTree::Node* BinaryTree::findLowestCommonAncestor(Node *node, int key1, int key2) {
    if (node == nullptr) return nullptr;

    if (node->key > key1 && node->key > key2) {
        return findLowestCommonAncestor(node->left, key1, key2);
    }
    if (node->key < key1 && node->key < key2) {
        return findLowestCommonAncestor(node->right, key1, key2);
    }
    return node;
}

