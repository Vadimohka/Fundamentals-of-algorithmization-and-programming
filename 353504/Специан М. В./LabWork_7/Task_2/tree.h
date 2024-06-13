#ifndef TREE_H
#define TREE_H

#include <QVector>
#include <QPair>
#include <node.h>

class Tree
{
protected:
    Node* root;

    void _destruct(Node*);
    Node* _insert(Node*, QPair<int, QString>);
    Node* _remove(Node*, int);
    Node* _search(Node*, int);
    void _toVector(Node* node, QVector<QPair<int, QString>>&);
    void _reverseToVector(Node* node, QVector<QPair<int, QString>>&);
    void _byValueToVector(Node* node, QVector<QPair<int, QString>>&);
    Node* _makeBalanced(QVector<QPair<int, QString>>, int, int);

public:
    Tree();
    ~Tree();

    Node* GetTreeRoot();

    Node* insert(QPair<int, QString>);
    void remove(int);
    Node* search(int);
    QString searchValueByKey(int);

    QVector<QPair<int, QString>> toVector();
    QVector<QPair<int, QString>> reverseToVector();
    QVector<QPair<int, QString>> byValueToVector();

    void makeBalanced();
};

#endif // TREE_H
