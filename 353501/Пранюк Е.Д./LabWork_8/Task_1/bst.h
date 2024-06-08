#ifndef BST_H
#define BST_H

#include "QtWidgets/qgraphicsscene.h"
#include <QGraphicsTextItem>
#include <QRandomGenerator>

#include <iostream>
#include <string>
template <typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;
    explicit Node(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST
{
public:
    BST();
    BST(BST& bst);
    BST(BST&& bst) noexcept;
    BST& operator=(const BST& bst);
    ~BST();
    void insert(T data);
    void insert(BST<T>& bst);
    Node<T>* getRoot() { return root; }
    void print();
    std::string toString();
    void remove(T data);
    void remove(BST& bst);
    void clear();
    T LCA(T a, T b);
    bool find(T data);
    void drawTree(QGraphicsScene* scene, Node<T>* node, int x, int y, int level);
private:
    Node<T>* root;
    void insert(Node<T>*& node, T data);
    void insert(Node<T>* node);
    void print(Node<T>* node);
    std::string toString(Node<T>* node, std::string& result);
    void remove(Node<T>*& node, T data);
    void remove(Node<T>* node);
    Node<T>* findMin(Node<T>* node);
    void clear(Node<T>*& node);
    bool find(Node<T>* node, T data);
};

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::BST(BST& bst) : root(bst.getRoot())
{
    insert(bst);
    delete bst;
}

template<typename T>
BST<T>::BST(BST&& bst)  noexcept : root(bst.getRoot())
{
    bst.clear();
    bst.root = nullptr;
}

template <typename T>
BST<T>& BST<T>::operator=(const BST &bst)
{
    if (this == &bst)
    {
        return *this;
    }
    clear();
    insert(bst);
    return *this;
}

template <typename T>
BST<T>::~BST()
{
    clear();
}

template <typename T>
void BST<T>::insert(T data)
{
    insert(root, data);
}

template <typename T>
void BST<T>::insert(Node<T>*& node, T data)
{
    if (node == nullptr)
    {
        node = new Node<T>(data);
        return;
    }
    if (data < node->data)
    {
        insert(node->left, data);
    }
    else
    {
        insert(node->right, data);
    }
}

template <typename T>
void BST<T>::print()
{
    print(root);
}

template <typename T>
void BST<T>::print(Node<T>* node)
{
    if (node == nullptr)
    {
        return;
    }
    print(node->left);
    std::cout << node->data << "-->";
    print(node->right);
}

template <typename T>
std::string BST<T>::toString()
{
    std::string result;
    toString(root, result);
    return result;
}

template <typename T>
std::string BST<T>::toString(Node<T>* node, std::string& result)
{
    if (node == nullptr)
    {
        return result;
    }
    toString(node->left, result);
    result += std::to_string(node->data) + "-->";
    toString(node->right, result);
    return result;
}

template <typename T>
void BST<T>::remove(Node<T>*& node, T data)
{
    if (node == nullptr)
    {
        return;
    }
    if (data < node->data)
    {
        remove(node->left, data);
    }
    else if (data > node->data)
    {
        remove(node->right, data);
    }
    else
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr)
        {
            Node<T>* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr)
        {
            Node<T>* temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            Node<T>* temp = findMin(node->right);
            node->data = temp->data;
            remove(node->right, temp->data);
        }
    }
}

template <typename T>
void BST<T>::remove(T data)
{
    remove(root, data);
}

template <typename T>
Node<T>* BST<T>::findMin(Node<T>* node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

template <typename T>
void BST<T>::clear(Node<T>*& node)
{
    if (node == nullptr)
    {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
    node = nullptr;
}

template <typename T>
void BST<T>::clear()
{
    clear(root);
}

template <typename T>
bool BST<T>::find(Node<T>* node, T data)
{
    if (node == nullptr)
    {
        return false;
    }
    if (node->data == data)
    {
        return true;
    }
    if (data < node->data)
    {
        return find(node->left, data);
    }
    return find(node->right, data);
}

template <typename T>
bool BST<T>::find(T data)
{
    return find(root, data);
}

template <typename T>
void BST<T>::insert(Node<T>* subtreeRoot)
{
    if (subtreeRoot == nullptr)
        return;
    insert(subtreeRoot->data);
    insert(subtreeRoot->left);
    insert(subtreeRoot->right);
}

template <typename T>
void BST<T>::remove(Node<T>* subtreeRoot)
{
    if (subtreeRoot == nullptr)
    {
        return;
    }
    remove(subtreeRoot->left);
    remove(subtreeRoot->right);
    remove(subtreeRoot->data);
}

template <typename T>
void BST<T>::insert(BST<T>& bst)
{
    insert(bst.getRoot());
}

template <typename T>
void BST<T>::remove(BST& bst)
{
    remove(bst.getRoot());
}

template <typename T>
T BST<T>::LCA(T a, T b)
{
    Node<T>* node = root;
    while (node != nullptr)
    {
        if (node->data > a && node->data > b)
        {
            node = node->left;
        }
        else if (node->data < a && node->data < b)
        {
            node = node->right;
        }
        else
        {
            break;
        }
    }
    return node->data;
}

template <typename T>
void BST<T>::drawTree(QGraphicsScene* scene, Node<T>* node, int x, int y, int level)
{
    if (!node)
    {
        return;
    }

    int offset = 100 / (level + 1);  // Adjust this value to change the spacing between nodes

    QGraphicsEllipseItem* ellipse = scene->addEllipse(x, y, 40, 40);
    ellipse->setBrush(QColor(QRandomGenerator::global()->bounded(200),QRandomGenerator::global()->bounded(210),QRandomGenerator::global()->bounded(200)));
    QGraphicsTextItem* text = scene->addText(QString::number(node->data));
    text->setDefaultTextColor(Qt::white);
    text->setPos(x+7, y+7);  // Adjust these values to center the text in the ellipse
    QPen pen;
    pen.setWidth(3);
    pen.setBrush(Qt::black);
    pen.setStyle(Qt::CustomDashLine);
    if (node->left)
    {
        scene->addLine(x+20, y+40, x-offset+20, y+80);  // Draw line to left child
        drawTree(scene, node->left, x-offset, y+80, level+1);
    }
    if (node->right)
    {
        scene->addLine(x+20, y+40, x+offset+20, y+80);  // Draw line to right child
        drawTree(scene, node->right, x+offset, y+80, level+1);
    }
}

#endif // BST_H
