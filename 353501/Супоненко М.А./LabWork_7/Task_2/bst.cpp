#include "bst.h"

BST::BST() : m_root(nullptr) {}

BST::~BST() {
    clear(m_root);
}

void BST::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void BST::insert(int key, const QString& value) {
    m_root = insert(m_root, key, value);
}

Node* BST::insert(Node* node, int key, const QString& value) {
    if (!node) return new Node(key, value);

    if (key < node->key) {
        node->left = insert(node->left, key, value);
    } else {
        node->right = insert(node->right, key, value);
    }
    return node;
}

void BST::remove(int key) {
    m_root = remove(m_root, key);
}

Node* BST::remove(Node* node, int key) {
    if (!node) return node;

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = minValueNode(node->right);
        node->key = temp->key;
        node->value = temp->value;
        node->right = remove(node->right, temp->key);
    }
    return node;
}

Node* BST::minValueNode(Node* node) const {
    Node* current = node;
    while (current && current->left) current = current->left;
    return current;
}

QString BST::find(int key) const {
    Node* result = find(m_root, key);
    return result ? result->value : QString();
}

Node* BST::find(Node* node, int key) const {
    if (!node || node->key == key) return node;

    if (key < node->key) {
        return find(node->left, key);
    } else {
        return find(node->right, key);
    }
}

QStringList BST::inOrder() const {
    QStringList list;
    inOrder(m_root, list);
    return list;
}

void BST::inOrder(Node* node, QStringList& list) const {
    if (node) {
        inOrder(node->left, list);
        list.append(QString("%1: %2").arg(node->key).arg(node->value));
        inOrder(node->right, list);
    }
}

QStringList BST::preOrder() const {
    QStringList list;
    preOrder(m_root, list);
    return list;
}

void BST::preOrder(Node* node, QStringList& list) const {
    if (node) {
        list.append(QString("%1: %2").arg(node->key).arg(node->value));
        preOrder(node->left, list);
        preOrder(node->right, list);
    }
}

QStringList BST::postOrder() const {
    QStringList list;
    postOrder(m_root, list);
    return list;
}

void BST::postOrder(Node* node, QStringList& list) const {
    if (node) {
        postOrder(node->left, list);
        postOrder(node->right, list);
        list.append(QString("%1: %2").arg(node->key).arg(node->value));
    }
}
