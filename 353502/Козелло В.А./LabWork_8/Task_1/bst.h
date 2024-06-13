#ifndef BST_H
#define BST_H

#include <QDebug>
#include <QPair>
#include <QString>
#include <QTreeWidget>
#include <QVector>
#include <algorithm>
#include <utility>

template<typename T>
struct Node
{
    int key;
    T value;
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;
    int height;

    explicit Node(int key, T value)
        : key(key)
        , value(value)
    {}
};

template<typename T>
class BST
{
private:
    Node<T> *root = nullptr;

    Node<T> *_add(Node<T> *node, int key, T value)
    {
        if (node == nullptr) {
            return new Node<T>(key, value);
        }

        if (key < node->key) {
            node->left = _add(node->left, key, value);
        } else if (key > node->key) {
            node->right = _add(node->right, key, value);
        } else {
            node->value = value;
            return node;
        }

        _updateHeight(node);
        return _balanceTree(node);
    }

    Node<T> *_find(Node<T> *node, int key)
    {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->key == key) {
            return node;
        }
        return (key < node->key) ? _find(node->left, key) : _find(node->right, key);
    }

    Node<T> *_remove(Node<T> *node, int key)
    {
        if (node == nullptr) {
            return nullptr;
        } else if (key < node->key) {
            node->left = _remove(node->left, key);
        } else if (key > node->key) {
            node->right = _remove(node->right, key);
        } else {
            if (node->left == nullptr && node->right != nullptr) {
                Node<T> temp = *node->right;
                delete node->right;
                node->right = nullptr;
                *node = temp;
            } else if (node->right == nullptr && node->left != nullptr) {
                Node<T> temp = *node->left;
                delete node->left;
                node->left = nullptr;
                *node = temp;
            } else if (node->left == nullptr && node->right == nullptr) {
                delete node;
                if (node == root) {
                    root = nullptr;
                }
                node = nullptr;
            } else {
                Node<T> maxLnLeft = *_getMax(node->left);
                node->key = maxLnLeft.key;
                node->value = maxLnLeft.value;
                node->left = _remove(node->left, maxLnLeft.key);
            }
        }
        if (node) {
            _updateHeight(node);
            node = _balanceTree(node);
        }

        return node;
    }

    Node<T> *_getMin(Node<T> *node)
    {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->left == nullptr) {
            return node;
        }
        return _getMin(node->left);
    }

    Node<T> *_getMax(Node<T> *node)
    {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->right == nullptr) {
            return node;
        }
        return _getMax(node->right);
    }

    void _deleteTree(Node<T> *&node)
    {
        if (node == nullptr) {
            return;
        }
        _deleteTree(node->left);
        _deleteTree(node->right);
        delete node;
        node = nullptr;
    }

    void _addNode(Node<T> *node, QTreeWidgetItem *parentItem, QTreeWidget *treeWidget)
    {
        QTreeWidgetItem *treeItem = nullptr;
        if (parentItem == nullptr) {
            treeItem = new QTreeWidgetItem(treeWidget);
        } else {
            treeItem = new QTreeWidgetItem(parentItem);
        }
        treeItem->setText(0, QString::number(node->key));
        treeItem->setText(1, QString::number(node->value));

        if (node->left) {
            _addNode(node->left, treeItem, treeWidget);
        }
        if (node->right) {
            _addNode(node->right, treeItem, treeWidget);
        }
    }

    int _height(Node<T> *node)
    {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int _getBalance(Node<T> *node)
    {
        if (node == nullptr) {
            return 0;
        }
        return _height(node->left) - _height(node->right);
    }

    Node<T> *_rightRotate(Node<T> *y)
    {
        Node<T> *x = y->left;
        Node<T> *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(_height(y->left), _height(y->right)) + 1;
        x->height = std::max(_height(x->left), _height(x->right)) + 1;

        return x;
    }

    Node<T> *_leftRotate(Node<T> *x)
    {
        Node<T> *y = x->right;
        Node<T> *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(_height(x->left), _height(x->right)) + 1;
        y->height = std::max(_height(y->left), _height(y->right)) + 1;

        return y;
    }

    Node<T> *_balanceTree(Node<T> *node)
    {
        if (node == nullptr) {
            return nullptr;
        }

        int balance = _getBalance(node);

        if (balance > 1) {
            if (_getBalance(node->left) >= 0) {
                return _rightRotate(node);
            } else {
                node->left = _leftRotate(node->left);
                return _rightRotate(node);
            }
        } else if (balance < -1) {
            if (_getBalance(node->right) <= 0) {
                return _leftRotate(node);
            } else {
                node->right = _rightRotate(node->right);
                return _leftRotate(node);
            }
        }
        node->left = _balanceTree(node->left);
        node->right = _balanceTree(node->right);

        return node;
    }

    int _updateHeight(Node<T> *node)
    {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = _updateHeight(node->left);
        int rightHeight = _updateHeight(node->right);

        node->height = 1 + std::max(leftHeight, rightHeight);
        return node->height;
    }

    void _inorder(Node<T> *node, QVector<Node<T> *> &arr)
    {
        if (node == nullptr) {
            return;
        }
        _inorder(node->left, arr);
        arr.push_back(node);
        _inorder(node->right, arr);
    }
    void _preorder(Node<T> *node, QVector<Node<T> *> &arr)
    {
        if (node == nullptr) {
            return;
        }
        arr.push_back(node);
        _inorder(node->left, arr);
        _inorder(node->right, arr);
    }
    void _postorder(Node<T> *node, QVector<Node<T> *> &arr)
    {
        if (node == nullptr) {
            return;
        }
        _inorder(node->left, arr);
        _inorder(node->right, arr);
        arr.push_back(node);
    }

public:
    BST() = default;

    void add(int key, T value) { root = _add(root, key, value); }

    void remove(int key) { _remove(root, key); }

    Node<T> *find(int key) { return _find(root, key); }

    QVector<Node<T> *> inorderTraverse()
    {
        QVector<Node<T> *> arr;
        _inorder(root, arr);
        return arr;
    }

    QVector<Node<T> *> preorderTraverse()
    {
        QVector<Node<T> *> arr;
        _preorder(root, arr);
        return arr;
    }

    QVector<Node<T> *> postorderTraverse()
    {
        QVector<Node<T> *> arr;
        _postorder(root, arr);
        return arr;
    }

    void insertAnother(Node<T> *rootNode)
    {
        QVector<Node<T> *> arr;
        _inorder(rootNode, arr);
        for (Node<T> *node : arr) {
            add(node->key, node->value);
        }
    }

    void removeSubtree(int key)
    {
        Node<T> *node = root;
        Node<T> *parent = nullptr;

        while (node != nullptr && node->key != key) {
            parent = node;
            if (key < node->key) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        if (node == nullptr) {
            return;
        }

        if (parent == nullptr) {
            _deleteTree(root);
        } else if (parent->left == node) {
            _deleteTree(parent->left);
        } else if (parent->right == node) {
            _deleteTree(parent->right);
        }
        QVector<Node<T> *> arr = postorderTraverse();
        for (Node<T> *node : arr) {
            _updateHeight(node);
        }
        root = _balanceTree(root);
    }

    void removeLeftSubtree(int key)
    {
        Node<T> *node = find(key);
        if (node) {
            _deleteTree(node->left);
        }
        QVector<Node<T> *> arr = postorderTraverse();
        for (Node<T> *node : arr) {
            _updateHeight(node);
        }
        root = _balanceTree(root);
    }

    void removeRightSubtree(int key)
    {
        Node<T> *node = find(key);
        if (node) {
            _deleteTree(node->right);
        }
        QVector<Node<T> *> arr = postorderTraverse();
        for (Node<T> *node : arr) {
            _updateHeight(node);
        }
        root = _balanceTree(root);
    }

    Node<T> *findParent(int key1, int key2)
    {
        Node<T> *temp = root;
        while (temp != nullptr) {
            if (temp->key > key1 && temp->key > key2) {
                temp = temp->left;
            } else if (temp->key < key1 && temp->key < key2) {
                temp = temp->right;
            } else {
                return temp;
            }
        }
        return nullptr;
    }

    void buildTreeWidget(QTreeWidget *treeWidget)
    {
        treeWidget->clear();
        treeWidget->setColumnCount(2);
        treeWidget->setHeaderLabels(QStringList() << "Key"
                                                  << "Value");
        if (root) {
            _addNode(root, nullptr, treeWidget);
        }
        QTreeWidgetItemIterator it(treeWidget);
        while (*it) {
            (*it)->setExpanded(true);
            ++it;
        }
    }
};

#endif // BST_H
