#ifndef BST_H
#define BST_H

#include <QDebug>
#include <QPair>
#include <QString>
#include <QTreeWidget>
#include <QVector>
#include <algorithm>
#include <utility>

struct Node
{
    int key;
    QString value;
    Node *left = nullptr;
    Node *right = nullptr;
    int height;

    Node(int key, QString value)
        : key(key)
        , value(std::move(value))
    {}
};

class BST
{
private:
    Node *root = nullptr;

    void insert(Node *, int, QString);
    QString search(Node *, int);
    Node *remove(Node *, int);
    Node *getMin(Node *);
    Node *getMax(Node *);
    void printTree(Node *, QPair<QVector<int>, QVector<QString>> &);
    void reversePrint(Node *, QPair<QVector<int>, QVector<QString>> &);
    void directPrint(Node *, QPair<QVector<int>, QVector<QString>> &);
    void deleteTree(Node *);
    void addNode(Node *, QTreeWidgetItem *, QTreeWidget *);
    int height(Node *);
    int getBalance(Node *);
    Node *rightRotate(Node *);
    Node *leftRotate(Node *);
    Node *balanceTree(Node *);
    int updateHeight(Node *);

public:
    BST();
    explicit BST(QPair<QVector<int>, QVector<QString>>);

    void insert(int, QString);
    QString search(int);
    void remove(int);
    Node *getRoot();
    void printTree(QPair<QVector<int>, QVector<QString>> &);
    void reversePrint(QPair<QVector<int>, QVector<QString>> &);
    void directPrint(QPair<QVector<int>, QVector<QString>> &);
    void buildTreeWidget(QTreeWidget *);
    QString findMiddleKeyValue();
    void balance();
};

#endif // BST_H
