#ifndef BST_H
#define BST_H

#include <QString>
#include <QStringList>
#include <QVector>
#include <QPair>
#include <functional>

struct Node {
    int key;
    QString value;
    Node* left;
    Node* right;

    Node(int k, const QString& v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST();
    ~BST();
    void insert(int key, const QString& value);
    void remove(int key);
    QString find(int key) const;
    QStringList inOrder() const;
    QStringList preOrder() const;
    QStringList postOrder() const;
    Node* root() const { return m_root; }

protected:
    Node* m_root;
    void clear(Node* node);
    Node* insert(Node* node, int key, const QString& value);
    Node* remove(Node* node, int key);
    Node* find(Node* node, int key) const;
    void inOrder(Node* node, QStringList& list) const;
    void preOrder(Node* node, QStringList& list) const;
    void postOrder(Node* node, QStringList& list) const;
    Node* minValueNode(Node* node) const;
};

#endif // BST_H
