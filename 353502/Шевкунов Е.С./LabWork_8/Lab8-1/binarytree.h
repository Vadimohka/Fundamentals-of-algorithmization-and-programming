#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <QString>
#include <functional>

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    struct Node
    {
    public:
        QString data;
        int key;
        Node *right, *left;

        Node(const QString &data, int key) : data(data), key(key), left(nullptr), right(nullptr) {}
    };

    void add(const QString &data, int key);
    void remove(int key);
    Node* find(int key);
    void traverseInOrder(std::function<void(Node*)> visit);
    void insertSubtree(Node *subtree, int parentKey);
    void removeSubtree(int key);
    void insertBranch(const QString &data, int key, int parentKey);
    void removeBranch(int key);
    Node* findLowestCommonAncestor(int key1, int key2);

private:
    Node *root;

    void add(Node *&node, const QString &data, int key);
    void remove(Node *&node, int key);
    Node* find(Node *node, int key);
    void traverseInOrder(Node *node, std::function<void(Node*)> visit);
    Node* findLowestCommonAncestor(Node *node, int key1, int key2);
    void deleteTree(Node *node);
};

#endif // BINARYTREE_H
