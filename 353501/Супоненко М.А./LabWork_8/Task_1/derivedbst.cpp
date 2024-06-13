#include "derivedbst.h"

DerivedBST::DerivedBST() : BST() {}

DerivedBST::~DerivedBST() {}

void DerivedBST::balance() {
    QVector<QPair<int, QString>> nodes;
    storeInOrder(m_root, nodes);
    clear(m_root);
    m_root = buildBalancedTree(nodes, 0, nodes.size() - 1);
}

void DerivedBST::storeInOrder(Node* node, QVector<QPair<int, QString>>& nodes) {
    if (node) {
        storeInOrder(node->left, nodes);
        nodes.append(qMakePair(node->key, node->value));
        storeInOrder(node->right, nodes);
    }
}

Node* DerivedBST::buildBalancedTree(QVector<QPair<int, QString>>& nodes, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* node = new Node(nodes[mid].first, nodes[mid].second);

    node->left = buildBalancedTree(nodes, start, mid - 1);
    node->right = buildBalancedTree(nodes, mid + 1, end);

    return node;
}

int DerivedBST::countStartingWith(QChar letter) const {
    return countStartingWith(m_root, letter);
}

int DerivedBST::countStartingWith(Node* node, QChar letter) const {
    if (!node) return 0;

    int count = 0;
    if (node->value.startsWith(letter, Qt::CaseInsensitive)) {
        count = 1;
    }

    return count + countStartingWith(node->left, letter) + countStartingWith(node->right, letter);
}
