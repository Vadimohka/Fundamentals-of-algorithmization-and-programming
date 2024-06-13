#ifndef AVLTREE_H
#define AVLTREE_H

#include <cstddef>
#include <cstdint>

template<typename T>
class AVLTree
{
public:
    struct Node
    {
        int64_t key;      // ключ узла
        T value;          // значение узла
        Node *left;       // указатель на левое поддерево
        Node *right;      // указатель на правое поддерево
        size_t height{1}; // высота поддерва в данном узле

        Node(int64_t key, T value)
            : key(key)
            , value(value)
            , left(nullptr)
            , right(nullptr)
        {}
    };

private:
    size_t _size;
    Node *root;

public:
    AVLTree(int64_t key, T value);
    ~AVLTree();

    size_t height(Node *node) const;
    size_t size() const;
    void clear(Node *node);

    void insert(int64_t key, T value);
    Node *findMin(Node *node);
    Node *findMax(Node *node);
    Node *findAverageNode(Node *node);
    Node *find(Node *node, int64_t key);
    void remove(int64_t key);
    Node *getRoot();

    void directInput(Node *node);
    void reverseInput(Node *node);
    void increaseKeyInput(Node *node);

private:
    Node *insert(Node *node, int64_t key, T value);
    Node *remove(Node *node, int64_t key);
    Node *removeMin(Node *node);
    int64_t balanceFactor(Node *node) const;
    void fixHeight(Node *node);
    Node *rotateRight(Node *node);
    Node *rotateLeft(Node *node);
    Node *balance(Node *node);
};

#endif // AVLTREE_H
