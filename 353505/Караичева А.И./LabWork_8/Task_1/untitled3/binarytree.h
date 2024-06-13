#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdexcept>
#include <QVector>
#include "node.h"

template <typename T>
class BinarySearchTree {

protected:

    Node<T> *root;

    void insertFromAnother(const Node<T> *another) {
        insert(another->key, another->data);
        if (another->right)
            insertFromAnother(another->right);
        if (another->left)
            insertFromAnother(another->left);
    }

    void insertAnother(const BinarySearchTree &another) {
        this->root = nullptr;
        if (another.root)
            insertFromAnother(another.root);
    }

    void removeFromAnother(const Node<T> *another) {
        remove(another->key);
        if (another->right)
            removeFromAnother(another->right);
        if (another->left)
            removeFromAnother(another->left);
    }

    void removeAnother(const BinarySearchTree &another) {
        this->root = nullptr;
        if (another.root)
            removeFromAnother(another.root);
    }

    long intoVine(Node<T> *tail) {
        long count = 0;
        Node<T> *curNode = tail->right;
        while (curNode != nullptr) {
            if (curNode->left == nullptr) {
                count++;
                tail = curNode;
                curNode = curNode->right;
            } else {
                // Rotate to make left node higher
                Node<T> *temp = curNode->left;
                curNode->left = temp->right;
                temp->right = curNode;
                curNode = temp;
                tail->right = temp;
            }
        }

        return count;
    }

    void compress(Node<T> *root, long count) {

        for (int i = 0; i < count; i++) {
            Node<T> *child = root->right;
            root->right = child->right;
            root = root->right;
            child->right = root->left;
            root->left = child;
        }
    }

public:
    BinarySearchTree() { this->root = nullptr; }

    BinarySearchTree(const BinarySearchTree &another) { insertAnother(another); }

    BinarySearchTree &operator=(const BinarySearchTree &another) {
        delete root;
        this->root = nullptr;

        insertAnother(another);
        return *this;
    }

    BinarySearchTree(BinarySearchTree &&another) {
        this->root = another.root;
        another.root = nullptr;
    }

    ~BinarySearchTree() {
        if (this->root)
            delete this->root;
    }

    void clear() {
        delete this->root;
        this->root = nullptr;
    }

    void insert(long key, const T &value) {
        Node<T> **target = &this->root;
        while (*target != nullptr) {
            long targkey = (*target)->key;
            if (targkey == key) {
                (*target)->data = value;
                return;
            } else if (key < (*target)->key) {
                target = &(*target)->left;
            } else {
                target = &(*target)->right;
            }
        }

        *target = new Node<T>(key, value);
    }

    bool contains(long key) {
        Node<T> *s = this->root;
        while (s != nullptr) {
            if (s->key == key)
                return true;

            if (key < s->key) {
                s = s->left;
            } else {
                s = s->right;
            }
        }

        return false;
    }

    T &find(long key) {
        Node<T> *s = this->root;
        while (s != nullptr) {
            if (s->key == key)
                return s->data;

            if (key < s->key) {
                s = s->left;
            } else {
                s = s->right;
            }
        }

        throw new std::invalid_argument("Key not found");
    }

    void remove(long key) {
        Node<T> **parBefDel = &this->root;

        while (*parBefDel != nullptr) {
            if ((*parBefDel)->key == key)
                break;
            else
                if (key < (*parBefDel)->key) {
                    parBefDel = &(*parBefDel)->left;
                } else {
                    parBefDel = &(*parBefDel)->right;
                }
        }
        if(*parBefDel == nullptr) return;

        Node<T> *toDel = *parBefDel;
        if (toDel->key != key)
            return;

        Node<T> *replaceWith;
        if (toDel->left == nullptr) {
            replaceWith = toDel->right;
        } else if (toDel->right == nullptr) {
            replaceWith = toDel->left;
        } else {
            Node<T> **rightmostLeft = &toDel->left;
            while ((*rightmostLeft)->right != nullptr) {
                rightmostLeft = &(*rightmostLeft)->right;
            }

            replaceWith = *rightmostLeft;
            *rightmostLeft = replaceWith->left;

            replaceWith->left = toDel->left;
            replaceWith->right = toDel->right;
        }

        *parBefDel = replaceWith;
        toDel->left = nullptr;
        toDel->right = nullptr;
        delete toDel;

        return;
    }

    long size() const { return countNodes(root); }

    void appendTree(const BinarySearchTree &another) {
        if (another.root)
            insertFromAnother(another.root);
    }

    void appendSubTree(const Node<T> * another) {
        if (another)
            insertFromAnother(another);
    }

    void removeTree(const BinarySearchTree &another) {
        if (another.root)
            removeFromAnother(another.root);
    }

    void removeSubTree(const Node<T> * another) {
        if (another)
            removeFromAnother(another);
    }

    Node<T> * findCommonKey(Node<T> * key_a, Node<T> * key_b) {
        Node<T> *s = this->root;
        while (s != nullptr) {
            if (s == key_a || s == key_b)
                return s;

            if(key_a->key < s->key && key_b->key < s->key) {
                s = s->left;
            } else if(key_a->key > s->key && key_b->key > s->key) {
                s = s->right;
            } else {
                return s;
            }
        }
        return 0;
    }

    Node<T> * getRoot(){
        return root;
    }

    void traverseRecursive(Node<T>* node, QVector<T> & vec) {
        if (node != nullptr) {
            traverseRecursive(node->left, vec);
            vec.push_back(node->data);
            traverseRecursive(node->right, vec);
        }
    }

    QVector<T> traverse() {
        QVector<T> vec;
        traverseRecursive(root, vec);
        return vec;
    }
};

#endif
