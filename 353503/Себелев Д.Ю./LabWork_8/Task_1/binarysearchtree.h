#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <QString>
#include <QTextStream>
#include <QTreeWidget>
#include <QTreeWidgetItem>

template <typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;
    Node<T>(T data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree();

    void add(T data);
    void add(Node<T>*& node, T data);

    void remove(T data);
    void remove(Node<T>*& node, T data);

    bool find(T data);
    bool find(Node<T>* node, T data);

    QString inOrder(Node<T>* node);
    QString postOrder(Node<T>* node);
    QString preOrder(Node<T>* node);

    void insertSubTree(Node<T>* node);
    void removeSubTree(Node<T>* node);

    Node<T>* getRoot() { return root; }
    Node<T>* lowestCommonAncestor(Node<T>* node, T data1, T data2);

    void addNodeToTree(T data, QTreeWidget *tree);
    void addNodeToTree(Node<T>* node, QTreeWidgetItem *parentItem, QString prefix);

    void update(QTreeWidget *tree);

private:
    Node<T>* root;
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template<typename T>
void BinarySearchTree<T>::add(T data)
{
    if (root == nullptr) {
        root = new Node<T>(data);
    } else {
        add(root, data);
    }
}

template<typename T>
void BinarySearchTree<T>::add(Node<T> *&node, T data)
{
    if (node == nullptr) {
        node = new Node<T>(data);
    } else if (data < node->data) {
        add(node->left, data);
    } else {
        add(node->right, data);
    }
}

template<typename T>
void BinarySearchTree<T>::remove(T data)
{
    remove(root, data);
}

template<typename T>
void BinarySearchTree<T>::remove(Node<T> *&node, T data)
{
    if (node == nullptr) {
        return;
    } else if (data < node->data) {
        remove(node->left, data);
    } else if (data > node->data) {
        remove(node->right, data);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            Node<T>* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            Node<T>* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node<T>* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->data = temp->data;
            remove(node->right, temp->data);
        }
    }
}

template<typename T>
bool BinarySearchTree<T>::find(T data)
{
    return find(root, data);
}

template<typename T>
bool BinarySearchTree<T>::find(Node<T> *node, T data)
{
    if (node == nullptr) {
        return false;
    } else if (data == node->data) {
        return true;
    } else if (data < node->data) {
        return find(node->left, data);
    } else {
        return find(node->right, data);
    }
}

template<typename T>
QString BinarySearchTree<T>::inOrder(Node<T> *node)
{
    if (node == nullptr) return "";
    QString result;
    QTextStream stream(&result);
    stream << inOrder(node->left);
    stream << node->data << " ";
    stream << inOrder(node->right);
    return result;
}

template<typename T>
QString BinarySearchTree<T>::postOrder(Node<T> *node)
{
    if (node == nullptr) return "";
    QString result;
    QTextStream stream(&result);
    stream << postOrder(node->left);
    stream << postOrder(node->right);
    stream << node->data << " ";
    return result;
}

template<typename T>
QString BinarySearchTree<T>::preOrder(Node<T> *node)
{
    if (node == nullptr) return "";
    QString result;
    QTextStream stream(&result);
    stream << node->data << " ";
    stream << preOrder(node->left);
    stream << preOrder(node->right);
    return result;
}

template<typename T>
void BinarySearchTree<T>::insertSubTree(Node<T> *node)
{
    if (node == nullptr) return;
    add(node->data);
    insertSubTree(node->left);
    insertSubTree(node->right);
}

template<typename T>
void BinarySearchTree<T>::removeSubTree(Node<T> *node)
{
    if (node == nullptr) return;
    removeSubTree(node->left);
    removeSubTree(node->right);
    remove(node->data);
}

template<typename T>
Node<T> *BinarySearchTree<T>::lowestCommonAncestor(Node<T> *node, T data1, T data2)
{
    if (node == nullptr) return nullptr;
    if (data1 < node->data && data2 < node->data) {
        return lowestCommonAncestor(node->left, data1, data2);
    } else if (data1 > node->data && data2 > node->data) {
        return lowestCommonAncestor(node->right, data1, data2);
    } else {
        return node;
    }
}

template<typename T>
void BinarySearchTree<T>::addNodeToTree(T data, QTreeWidget *tree)
{
    add(data);
    tree->clear();
    auto* item = new QTreeWidgetItem(tree);
    addNodeToTree(root, item, "");
}

template<typename T>
void BinarySearchTree<T>::addNodeToTree(Node<T> *node, QTreeWidgetItem *parentItem, QString prefix)
{
    if (node != nullptr) {
        if (node == root) {
            prefix = "Root: ";
        }
        if (parentItem != nullptr) {
            parentItem->setText(0, prefix + QString::number(node->data));
        }

        if (node->left != nullptr) {
            QTreeWidgetItem *leftItem = new QTreeWidgetItem();
            parentItem->addChild(leftItem);
            addNodeToTree(node->left, leftItem, "Left: ");
        }

        if (node->right != nullptr) {
            QTreeWidgetItem *rightItem = new QTreeWidgetItem();
            parentItem->addChild(rightItem);
            addNodeToTree(node->right, rightItem, "Right: ");
        }
    }
}

template<typename T>
void BinarySearchTree<T>::update(QTreeWidget *tree)
{
    tree->clear();
    auto* item = new QTreeWidgetItem(tree);
    addNodeToTree(root, item, "");
}

#endif // BINARYSEARCHTREE_H
