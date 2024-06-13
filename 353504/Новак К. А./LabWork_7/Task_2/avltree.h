#ifndef AVLTREE_H
#define AVLTREE_H

#include "qdebug.h"
#include <cstddef>


template<typename T>
class AVLTree
{
public:
    struct Node{
        int key;
        T value;

        Node* Left;
        Node* Right;

        size_t height = 1;

        Node(int64_t key, T value): key(key), value(value), Left(nullptr), Right(nullptr) {}
    };
private:
    Node *root;
    size_t _size;

public:
    AVLTree(int key, T value) : _size(1)
        , root(new Node(key, value)){}

    AVLTree() : _size(1)
        , root(new Node(0, "")){}

    ~AVLTree()
    {
        clear(root);
    }

    size_t height(Node *node){
        return (node) ? node->height : 0;
    }
    size_t size(){
        return _size;
    }

    void clear(Node* node){
        if(node){
            clear(node->Right);
            clear(node->Left);
            delete node;
        }
    }

    void insert(int key, T value){
        root = insert(root, key, value);
    }
    int balanceFactor(Node *node)
    {
        return (height(node->Right) - height(node->Left));
    }
    void fixHeight(Node *node)
    {
        node->height = ((height(node->Left) > height(node->Right)) ? height(node->Left)
                                                                   : height(node->Right))
                       + 1;
    }

    AVLTree<T>::Node *rotateRight(Node *node)
    {
        Node *newRootNode = node->Left;
        node->Left = newRootNode->Right;
        newRootNode->Right = node;
        fixHeight(node);
        fixHeight(newRootNode);
        return newRootNode;
    }

    AVLTree<T>::Node *rotateLeft(Node *node)
    {
        Node *newGeneralNode = node->Right;
        node->Right = newGeneralNode->Left;
        newGeneralNode->Left = node;
        fixHeight(node);
        fixHeight(newGeneralNode);
        return newGeneralNode;
    }

    AVLTree<T>::Node *balance(Node *node)
    {
        fixHeight(node);
        if (balanceFactor(node) >= 2) {
            if (balanceFactor(node->Right) < 0)
            {
                node->Right = rotateRight(node->Right);
            }
            return rotateLeft(node);
        }

        if (balanceFactor(node) <= -2) {
            if (balanceFactor(node->Left) > 0)
            {
                node->Left = rotateLeft(node->Left);
            }
            return rotateRight(node);
        }

        return node;
    }

   AVLTree<T>::Node *insert(Node *node, int key, T value)
    {
        if (node == nullptr) {
            ++_size;
            return new Node(key, value);
        }

        if (key < node->key) {
            node->Left = insert(node->Left, key, value);
        } else {
            node->Right = insert(node->Right, key, value);
        }

        return balance(node);
    }

   AVLTree<T>::Node *findMin(Node *node)
    {
        return (node->Left) ? findMin(node->Left) : node;
    }

    AVLTree<T>::Node *findMax(Node *node)
    {
        return (node->Right) ? findMax(node->Right) : node;
    }

   AVLTree<T>::Node *findAverageNode(Node *node)
    {
        if (findMin(node) == nullptr || findMax(node) == nullptr) {
            return nullptr;
        }

        int averagekey = (findMin(node)->key + findMax()->key) / 2;

        Node *averageNode = node;
        int averageDiff = (node->key > averagekey) ? (node->key - averagekey) : (averagekey - node->key);

        Node* stepNode = node;
        while(stepNode != nullptr){
            int stepDiff = (stepNode->key > averagekey) ? (stepNode->key - averagekey) : (averagekey - stepNode->key);

            if(stepDiff < averageDiff){
                averageNode = stepNode;
                averageDiff = stepDiff;
            }

            stepNode = (averagekey < stepNode->key) ? stepNode->Left : stepNode->Right;
        }
        return averageNode;
    }

   AVLTree<T>::Node *removeMin(Node *node)
    {
        if (node->Left == nullptr) {
            return node->Right;
        }
        node->Left = removeMin(node->Left);
        return balance(node);
    }

    AVLTree<T>::Node *remove(Node *node, int key){
        if(node == nullptr){
            return nullptr;
        }

        if(key < node->key){
            node->Left = remove(node->Left, key);
        }

        else if(key > node->key){
            node->Right = remove(node->Right, key);
        }
        else {
            Node *left = node->Left;
            Node *right = node->Right;
            delete node;

            --_size;

            if(right == nullptr){
                return left;
            }
            Node *min = findMin(right);
            min->Right = removeMin(right);
            min->Left = left;
            return balance(min);
        }
        return node;
    }

    AVLTree<T>::Node *getRoot()
    {
        return root;
    }

    AVLTree<T>::Node *find(Node *node, int64_t key)
    {
        if (node == nullptr) {
            return nullptr;
        }

        else if (node->key == key) {
            return node;
        }

        (key < node->key) ? find(node->Left, key) : find(node->Right, key);
        return nullptr;
    }

    void remove(int64_t key)
    {
        root = remove(root, key);
    }

    void directInput(Node *node) // Pre Order
    {
        if (node != nullptr) {
            qDebug() << node->value;
            directInput(node->Left);
            directInput(node->Right);
        }
    }

    void reverseInput(Node *node) // Post Order
    {
        if (node != nullptr) {
            reverseInput(node->Left);
            reverseInput(node->Right);
            qDebug() << node->value;
        }
    }

    void increaseKeyInput(Node *node) // In Order
    {
        if (node != nullptr) {
            increaseKeyInput(node->Left);
            qDebug() << node->value;
            increaseKeyInput(node->Right);
        }
    }
};

#endif // AVLTREE_H
