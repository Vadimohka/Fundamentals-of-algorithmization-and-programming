#ifndef RBTREE_H
#define RBTREE_H

#include <iomanip>
#include <QTreeWidget>
#include <QTreeWidgetItem>

struct Node
{
    int key, val;
    int color;
    Node *left, *right, *parent;

    explicit Node(int, int);
};

class RBTree
{
    private:
        Node *root;
    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
        void fixInsertRBTree(Node *&);
        void fixDeleteRBTree(Node *&);
        int getColor(Node *&);
        void setColor(Node *&, int);
        Node *minValueNode(Node *&);
        Node *maxValueNode(Node *&);
        Node* insertBST(Node *&, Node *&);
        Node* eraseBST(Node *&, int);
        int getBlackHeight(Node *);
        void printTree(QTreeWidget *treeWidget, QTreeWidgetItem *parent, Node *root);
    public:
        RBTree();
        void insertValue(const int &, const int &);
        void eraseValue(const int &);
        void print(QTreeWidget *treeWidget, QTreeWidgetItem *parent);
};


#endif //RBTREE_H
