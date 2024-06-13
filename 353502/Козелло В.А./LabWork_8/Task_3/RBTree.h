#ifndef RBTREE_H
#define RBTREE_H

#include <QPair>
#include <QTreeWidget>
#include <QVector>
#include "node.h"
#include <iostream>
#include <stdexcept>

template<typename K, typename V>
class RBTree
{
private:
    Node<K, V> *root;

    void rotateLeft(Node<K, V> *&root, Node<K, V> *&pt)
    {
        Node<K, V> *pt_right = pt->right;

        pt->right = pt_right->left;

        if (pt->right != nullptr) {
            pt->right->parent = pt;
        }

        pt_right->parent = pt->parent;

        if (pt->parent == nullptr) {
            root = pt_right;
        } else if (pt == pt->parent->left) {
            pt->parent->left = pt_right;
        } else {
            pt->parent->right = pt_right;
        }

        pt_right->left = pt;
        pt->parent = pt_right;
    }

    void rotateRight(Node<K, V> *&root, Node<K, V> *&pt)
    {
        Node<K, V> *pt_left = pt->left;

        pt->left = pt_left->right;

        if (pt->left != nullptr) {
            pt->left->parent = pt;
        }

        pt_left->parent = pt->parent;

        if (pt->parent == nullptr) {
            root = pt_left;
        } else if (pt == pt->parent->left) {
            pt->parent->left = pt_left;
        } else {
            pt->parent->right = pt_left;
        }

        pt_left->right = pt;
        pt->parent = pt_left;
    }

    void fixViolation(Node<K, V> *&root, Node<K, V> *&pt)
    {
        Node<K, V> *parent_pt = nullptr;
        Node<K, V> *grand_parent_pt = nullptr;

        while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            if (parent_pt == grand_parent_pt->left) {
                Node<K, V> *uncle_pt = grand_parent_pt->right;

                if (uncle_pt != nullptr && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    if (pt == parent_pt->right) {
                        rotateLeft(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    rotateRight(root, grand_parent_pt);
                    std::swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            } else {
                Node<K, V> *uncle_pt = grand_parent_pt->left;

                if (uncle_pt != nullptr && uncle_pt->color == RED) {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                } else {
                    if (pt == parent_pt->left) {
                        rotateRight(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    rotateLeft(root, grand_parent_pt);
                    std::swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }

        root->color = BLACK;
    }

    Node<K, V> *BSTInsert(Node<K, V> *root, Node<K, V> *pt)
    {
        if (root == nullptr) {
            return pt;
        }

        if (pt->key < root->key) {
            root->left = BSTInsert(root->left, pt);
            root->left->parent = root;
        } else if (pt->key > root->key) {
            root->right = BSTInsert(root->right, pt);
            root->right->parent = root;
        }

        return root;
    }

    void inOrderHelper(Node<K, V> *root, QVector<QPair<K, V>> &arr)
    {
        if (root == nullptr) {
            return;
        }

        inOrderHelper(root->left, arr);
        arr.push_back(QPair<K, V>(root->key, root->value));
        inOrderHelper(root->right, arr);
    }

    Node<K, V> *minValueNode(Node<K, V> *node)
    {
        Node<K, V> *current = node;

        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    void _addNode(Node<K, V> *node, QTreeWidgetItem *parentItem, QTreeWidget *treeWidget)
    {
        QTreeWidgetItem *treeItem = nullptr;
        if (parentItem == nullptr) {
            treeItem = new QTreeWidgetItem(treeWidget);
        } else {
            treeItem = new QTreeWidgetItem(parentItem);
        }
        treeItem->setText(0, QString::number(node->key) + "(" + QString::number(node->color) + ")");
        treeItem->setText(1, QString(node->value));

        if (node->left) {
            _addNode(node->left, treeItem, treeWidget);
        }
        if (node->right) {
            _addNode(node->right, treeItem, treeWidget);
        }
    }

    Node<K, V> *getNode(const K &key)
    {
        Node<K, V> *current = root;
        while (current != nullptr) {
            if (key < current->key) {
                current = current->left;
            } else if (key > current->key) {
                current = current->right;
            } else {
                return current;
            }
        }
        return nullptr;
    }

    Node<K, V> *BSTDelete(Node<K, V> *root, Node<K, V> *v)
    {
        if (root == nullptr)
            return root;

        if (v->key < root->key) {
            root->left = BSTDelete(root->left, v);
        } else if (v->key > root->key) {
            root->right = BSTDelete(root->right, v);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                return root;
            }

            Node<K, V> *temp = minValueNode(root->right);
            root->key = temp->key;
            root->value = temp->value;
            root->right = BSTDelete(root->right, temp);
        }
        return root;
    }

    void fixDelete(Node<K, V> *x)
    {
        while (x != root && getColor(x) == BLACK) {
            if (x == x->parent->left) {
                Node<K, V> *sibling = x->parent->right;
                if (getColor(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(x->parent, RED);
                    rotateLeft(root, x->parent);
                    sibling = x->parent->right;
                }
                if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                    setColor(sibling, RED);
                    x = x->parent;
                } else {
                    if (getColor(sibling->right) == BLACK) {
                        setColor(sibling->left, BLACK);
                        setColor(sibling, RED);
                        rotateRight(root, sibling);
                        sibling = x->parent->right;
                    }
                    setColor(sibling, getColor(x->parent));
                    setColor(x->parent, BLACK);
                    setColor(sibling->right, BLACK);
                    rotateLeft(root, x->parent);
                    x = root;
                }
            } else {
                Node<K, V> *sibling = x->parent->left;
                if (getColor(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(x->parent, RED);
                    rotateRight(root, x->parent);
                    sibling = x->parent->left;
                }
                if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                    setColor(sibling, RED);
                    x = x->parent;
                } else {
                    if (getColor(sibling->left) == BLACK) {
                        setColor(sibling->right, BLACK);
                        setColor(sibling, RED);
                        rotateLeft(root, sibling);
                        sibling = x->parent->left;
                    }
                    setColor(sibling, getColor(x->parent));
                    setColor(x->parent, BLACK);
                    setColor(sibling->left, BLACK);
                    rotateRight(root, x->parent);
                    x = root;
                }
            }
        }
        setColor(x, BLACK);
    }

    Node<K, V> *deleteNode(Node<K, V> *root, K key)
    {
        if (root == nullptr) {
            return root;
        }

        Node<K, V> *v = getNode(key);
        Node<K, V> *u = nullptr;

        if (v == nullptr) {
            return root;
        }

        if (v->left == nullptr || v->right == nullptr) {
            u = v;
        } else {
            u = minValueNode(v->right);
            v->key = u->key;
            v->value = u->value;
        }

        Node<K, V> *x = (u->left != nullptr) ? u->left : u->right;
        Node<K, V> *parent = u->parent;

        if (x != nullptr) {
            x->parent = parent;
        }

        if (parent == nullptr) {
            root = x;
        } else if (u == parent->left) {
            parent->left = x;
        } else {
            parent->right = x;
        }

        if (getColor(u) == BLACK && x) {
            fixDelete(x);
        }

        delete u;
        return root;
    }

    Color getColor(Node<K, V> *node)
    {
        if (node == nullptr)
            return BLACK;
        return node->color;
    }

    void setColor(Node<K, V> *node, Color color)
    {
        if (node == nullptr)
            return;
        node->color = color;
    }

public:
    RBTree()
        : root(nullptr)
    {}

    void insert(const K &key, const V &value)
    {
        Node<K, V> *temp = getNode(key);
        if (temp) {
            temp->value = value;
        } else {
            Node<K, V> *pt = new Node<K, V>(key, value);
            root = BSTInsert(root, pt);
            fixViolation(root, pt);
        }
    }

    V getValue(const K &key)
    {
        Node<K, V> *current = root;
        while (current != nullptr) {
            if (key < current->key) {
                current = current->left;
            } else if (key > current->key) {
                current = current->right;
            } else {
                return current->value;
            }
        }
        throw std::runtime_error("Key not found in the tree");
    }

    QVector<QPair<K, V>> inOrder()
    {
        QVector<QPair<K, V>> arr;
        inOrderHelper(root, arr);
        return arr;
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

    void remove(const K &key) { root = deleteNode(root, key); }
};

#endif // RBTREE_H
