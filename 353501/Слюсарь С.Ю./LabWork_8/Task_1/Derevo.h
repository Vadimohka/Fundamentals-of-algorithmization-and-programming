#ifndef DEREVO_H
#define DEREVO_H

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
    BST() : root(nullptr) {}
    BST(BST& bst) : root(bst.getRoot())
    {
        insert(bst);
        delete bst;
    }
    BST(BST&& bst)  noexcept : root(bst.getRoot())
    {
        bst.clear();
        bst.root = nullptr;
    }
    BST<T>& operator=(const BST &bst)
    {
        if (this == &bst)
        {
            return *this;
        }
        clear();
        insert(bst);
        return *this;
    }
    ~BST()
    {
        clear();
    }
    void insert(T data)
    {
        insert(root, data);
    }
    void insert(BST<T>& bst)
    {
        insert(bst.getRoot());
    }
    Node<T>* getRoot() { return root; }
    void print()
    {
        print(root);
    }
    std::string toString()
    {
        std::string result;
        toString(root, result);
        return result;
    }
    void remove(T data)
    {
        remove(root, data);
    }
    void remove(BST& bst)
    {
        remove(bst.getRoot());
    }
    void clear()
    {
        clear(root);
    }
    T LCA(T a, T b)
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
    bool find(T data)
    {
        return find(root, data);
    }
    void drawTree(QGraphicsScene* scene, Node<T>* node, int x, int y, int level)
    {
        if (!node)
        {
            return;
        }

        int offset = 100 / (level + 1);

        scene -> addRect(x, y, 40 , 40 );
        QGraphicsTextItem* text = scene -> addText( QString::number( node->data ) );

        text -> setPos( x + 11 , y + 7 );

        if (node -> left)
        {
            scene -> addLine(x+20, y+40, x-offset+20, y+80);
            drawTree(scene, node->left, x-offset, y+80, level+1);
        }
        if (node -> right)
        {
            scene -> addLine(x+20, y+40, x+offset+20, y+80);
            drawTree(scene, node -> right, x+offset, y+80, level+1);
        }
    }

    void color( QGraphicsScene* scene, Node<T>* node, int x, int y, int level , int value )
    {

        int offset = 100 / (level + 1);

        if( node -> data < value )
        {

            color(scene, node -> right, x+offset, y+80, level+1 , value);

        }
        else if( node -> data > value )
        {

            color(scene, node -> left, x-offset, y+80, level+1 , value);

        }
        else
        {

            QGraphicsRectItem* rect = scene -> addRect(x, y, 40 , 40 );
            rect -> setBrush( QBrush( QColor( Qt :: green ) ) );

        }

    }

private:
    Node<T>* root;
    void insert(Node<T>*& node, T data)
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
    void insert(Node<T>* subtreeRoot)
    {
        if (subtreeRoot == nullptr)
            return;
        insert(subtreeRoot->data);
        insert(subtreeRoot->left);
        insert(subtreeRoot->right);
    }
    void print(Node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }
        print(node->left);
        std::cout << node->data << "-->";
        print(node->right);
    }
    std::string toString(Node<T>* node, std::string& result)
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
    void remove(Node<T>*& node, T data)
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
    void remove(Node<T>* subtreeRoot)
    {
        if (subtreeRoot == nullptr)
        {
            return;
        }
        remove(subtreeRoot->left);
        remove(subtreeRoot->right);
        remove(subtreeRoot->data);
    }
    Node<T>* findMin(Node<T>* node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
    void clear(Node<T>*& node)
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
    bool find(Node<T>* node, T data)
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

};



#endif // DEREVO_H
