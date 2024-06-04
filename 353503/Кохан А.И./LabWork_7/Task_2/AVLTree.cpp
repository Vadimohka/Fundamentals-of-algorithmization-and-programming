#include "AVLTree.h"

#include <QDebug>
#include <QString>

template<typename T>
AVLTree<T>::AVLTree(int64_t key, T value)
    : _size(1)
    , root(new Node(key, value))
{}

template<typename T>
AVLTree<T>::~AVLTree()
{
    clear(root);
}

template<typename T>
size_t AVLTree<T>::height(Node *node) const // Высота определённого узла
{
    return (node) ? node->height : 0;
}

template<typename T>
size_t AVLTree<T>::size() const
{
    return _size;
}

template<typename T>
void AVLTree<T>::clear(Node *node)
{
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template<typename T>
void AVLTree<T>::insert(int64_t key, T value)
{
    root = insert(root, key, value);
}

template<typename T>
int64_t AVLTree<T>::balanceFactor(Node *node) const // Если -1, 0, 1, то дерево сбалансированное
{
    return height(node->right) - height(node->left);
}

template<typename T>
void AVLTree<T>::fixHeight(Node *node) // Функция пересчёта высоты определённого узла
{
    node->height = ((height(node->left) > height(node->right)) ? height(node->left)
                                                               : height(node->right))
                   + 1;
}

template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::rotateRight(Node *node)
{
    /*
               node                        newGeneralNode
            /        \                   /                \
    newGeneralNode    C       =>        A                node
          / \                                          /      \
         A   B                                        B        C

        h(A) = h + 1
        h(B) = h
        h(C) = h
        leftBalance = h + 2               leftBalance = h + 1
                                  =>     
        rightBalance = h                  rightBalance = h + 1
    */

    Node *newGeneralNode = node->left; // Balance = -1
    node->left = newGeneralNode->right;
    newGeneralNode->right = node;
    fixHeight(node);
    fixHeight(newGeneralNode);
    return newGeneralNode;
}

template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::rotateLeft(Node *node)
{
    /*
                node                                      newGeneralNode
             /        \                                 /                \
            A      newGeneralNode         =>          node                C
                      /      \                      /      \
                     B        C                    A        B
        
        h(A) = h
        h(B) = h + 1
        h(C) = h + 1
        leftBalance = h                             leftBalance = h + 2
                                        =>      
        rightBalance = h + 2                        rightBalance = h + 1
    */
    Node *newGeneralNode = node->right; // Balance = 0
    node->right = newGeneralNode->left;
    newGeneralNode->left = node;
    fixHeight(node);
    fixHeight(newGeneralNode);
    return newGeneralNode;
}

template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::balance(Node *node)
{
    /*
                node                                                    S
              /      \               большой левый поворот        /           \
             A      node->right               =>                node      node->right
                      /     \                                  /    \        /   \
                     S       D                                A      B      C     D
                   /   \
                  B     C

        h(S) > h(D) - Balance(node->right) < 0
    */
    fixHeight(node);
    if (balanceFactor(node) == 2) {
        if (balanceFactor(node->right) < 0) // большой левый поворот
        {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    if (balanceFactor(node) == -2) {
        if (balanceFactor(node->left) > 0) // большой правый поворот
        {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    return node;
}

template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::insert(Node *node,
                                              int64_t key,
                                              T value) // Вставка в дерево с корнем node
{
    if (node == nullptr) {
        ++_size;
        return new Node(key, value);
    }

    if (key < node->key) {
        node->left = insert(node->left, key, value);
    } else {
        node->right = insert(node->right, key, value);
    }

    return balance(node);
}

template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::findMin(Node *node)
{
    return (node->left) ? findMin(node->left) : node;
}

template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::findMax(Node *node)
{
    return (node->right) ? findMax(node->right) : node;
}

template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::findAverageNode(Node *node)
{
    if (findMin(node) == nullptr || findMax(node) == nullptr) {
        return nullptr;
    }

    int64_t averageKey = (findMin(node)->key + findMax(node)->key) / 2;

    Node *averageNode = node;
    int64_t averageDiff = (node->key > averageKey) ? (node->key - averageKey)
                                                   : (averageKey - node->key);

    Node *stepNode = node;
    while (stepNode != nullptr) {
        int64_t stepDiff = (stepNode->key > averageKey) ? (stepNode->key - averageKey)
                                                        : (averageKey - stepNode->key);
        if (stepDiff < averageDiff) {
            averageNode = stepNode;
            averageDiff = stepDiff;
        }

        stepNode = (averageKey < stepNode->key) ? stepNode->left : stepNode->right;
    }

    return averageNode;
}

template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::removeMin(Node *node)
{
    if (node->left == nullptr) {
        return node->right;
    }
    node->left = removeMin(node->left);
    return balance(node);
}

template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::remove(Node *node, int64_t key)
{
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = remove(node->left, key);
    }

    else if (key > node->key) {
        node->right = remove(node->right, key);
    }

    else { // Элемент найден
        Node *left = node->left;
        Node *right = node->right;
        delete node;
        --_size;
        if (right == nullptr) {
            return left;
        }
        Node *min = findMin(right);
        min->right = removeMin(right);
        min->left = left;
        return balance(min);
    }
    return node;
}

template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::getRoot()
{
    return root;
}

template<typename T>
void AVLTree<T>::directInput(Node *node)
{
    if (node != nullptr) {
        qDebug() << node->value;
        directInput(node->left);
        directInput(node->right);
    }
}

template<typename T>
void AVLTree<T>::reverseInput(Node *node)
{
    if (node != nullptr) {
        reverseInput(node->left);
        reverseInput(node->right);
        qDebug() << node->value;
    }
}

template<typename T>
void AVLTree<T>::increaseKeyInput(Node *node)
{
    if (node != nullptr) {
        increaseKeyInput(node->left);
        qDebug() << node->value;
        increaseKeyInput(node->right);
    }
}

template<typename T>
typename AVLTree<T>::Node *AVLTree<T>::find(Node *node, int64_t key)
{
    if (node == nullptr) {
        return nullptr;
    }

    else if (node->key == key) {
        return node;
    }

    (key < node->key) ? find(node->left, key) : find(node->right, key);
    return nullptr;
}

template<typename T>
void AVLTree<T>::remove(int64_t key)
{
    root = remove(root, key);
}

template class AVLTree<QString>;
