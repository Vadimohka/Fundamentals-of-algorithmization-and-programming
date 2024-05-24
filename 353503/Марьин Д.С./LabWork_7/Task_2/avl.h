#ifndef AVL_H
#define AVL_H

#include "QtWidgets/qtreewidget.h"
#include <QString>
#include <QDebug>

template <typename T>
class AVL
{
public:
    struct Node
    {
        int key;
        T value;
        size_t height;
        Node* left;
        Node* right;
        Node(int key,T val):key(key),value(val),height(1),left(nullptr),right(nullptr){}
    };

    AVL();
    AVL(int key ,T value);
    AVL(AVL const &tree);
    ~AVL();

    Node *getRoot();
    void addToTree(Node *p, QTreeWidgetItem *parentItem, QString prefix = "");
    void addToTree(int key , T val, QTreeWidget *tree);
    void insert(int key, T val);
    void remove(int key);
    void clear(Node* p);

    void print(Node* p, QString &str);
    QString print();
    void reverse_print(Node* p,QString& s);
    QString reverse_print();

    T find(int key);
    size_t Height(Node* p);
    size_t maxDepth(Node* node);
    size_t maxDepth();
    int BFactor(Node* p);
    void FixHeight(Node* p);

    void clear();
    void Balance();
    void updateTree(QTreeWidget* tree);

private:
    Node* root;
    size_t _size{};

    Node* insert(Node* p,int key , T val);
    Node* RotateRight(Node* p);
    Node* RotateLeft(Node* p);
    Node* Balance(Node* p);
    Node* FindMin(Node* p);
    Node* FindMax(Node* p);
    Node* RemoveMin(Node* p);
    Node* remove(Node* p,int key);
};

#endif // AVL_H
