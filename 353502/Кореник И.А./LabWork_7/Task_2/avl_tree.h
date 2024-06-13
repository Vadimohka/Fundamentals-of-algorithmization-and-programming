#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <QVector>
#include <QPair>
#include <QString>
#include <thread>
#include <QCoreApplication>
#include <QtWidgets>
class Node{
public:
    QString data;
    int key;
    Node* leftSon;
    Node* rightSon;

    Node(QString _data, int _key){
        data = _data;
        key = _key;
        leftSon = nullptr;
        rightSon = nullptr;
    }
};
class AVL_Tree
{
public:

    AVL_Tree(QVector<QPair<int, QString>>initial);

    AVL_Tree();

    void insert(int, QString);

    void erase(int);

    QString find(int key);

    void balance();

    Node* root = nullptr;
     bool isBalanced(Node*& node);

private:
    void insertInTree(int, QString, Node*&);

    void eraseFromTree(int, Node*, Node*&, int);

    QString findInTree(int, Node*);

    Node* findMin(Node* node);

    void balanceTreeHelper(Node*& node);

    int height(Node* node);

    void rotateLeft(Node* &node);

    void rotateRight(Node* &node);


};

#endif // AVL_TREE_H
