#ifndef DISPLAYBINARYSEARCHTREE_H
#define DISPLAYBINARYSEARCHTREE_H
#include<BinarySearchTree.h>
#include <QTextEdit>

template<typename T>
class DisplayBinarySearchTree : public BinarySearchTree<T>{

public:

    DisplayBinarySearchTree() {

    }
    void displayTree(typename BinarySearchTree<T>::Node* node, QTextEdit* textEdit)
    {
        if (node == nullptr)
        {
            return;
        }

        displayTree(node->_left, textEdit);
        textEdit->append("Key: " + QString::number(node->_key) + ", Value: " + QString::number(node->_value));
        displayTree(node->_right, textEdit);
    }
};

#endif // DISPLAYBINARYSEARCHTREE_H
