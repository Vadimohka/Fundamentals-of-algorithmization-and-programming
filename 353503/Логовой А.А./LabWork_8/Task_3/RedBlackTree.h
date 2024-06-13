#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include<QDebug>
template<typename K, typename D>
class RedBlackTree {
private:
    struct Node {
        D data;
        K key;
        Node *parent;
        Node *left;
        Node *right;
        bool color;
    };
    Node* root;
    Node* TNULL;
    size_t _size{};

    void clearRecursive(Node* node) {
        if (node != TNULL) {
            clearRecursive(node->left);
            clearRecursive(node->right);
            delete node;
        }
    }

    void initializeNULLNode(Node* node, Node* parent) {
        node->data = 0;
        node->key = 0;
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = false;
    }

    void preOrderHelper(Node* node) {
        if (node != TNULL)
        {
            qDebug() <<"key: "<< node->key << " " << "value: " << node->data;
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    void inOrderHelper(Node* node) {
        if (node != TNULL)
        {
            inOrderHelper(node->left);
            qDebug() <<"key: "<< node->key << " " << "value: " << node->data;
            inOrderHelper(node->right);
        }
    }

    void postOrderHelper(Node* node) {
        if (node != TNULL)
        {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            qDebug() <<"key: "<< node->key << " " << "value: " << node->data;
        }
    }

    D searchTreeHelper(Node* node, K key) {
        if (node == TNULL || key == node->key)
        {
            return node->data;
        }

        if (key < node->key)
        {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }

    void deleteFix(Node* x) {
        Node* s;
        while (x != root && x->color == false) {
            if (x == x->parent->left)
            {
                s = x->parent->right;

                if (s->color == true)
                {
                    s->color = false;
                    x->parent->color = true;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == false && s->right->color == false)
                {
                    s->color = true;
                    x = x->parent;
                }
                else
                {
                    if (s->right->color == false)
                    {
                        s->left->color = false;
                        s->color = true;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = false;
                    s->right->color = false;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else
            {
                s = x->parent->left;
                if (s->color == true)
                {
                    s->color = false;
                    x->parent->color = true;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == false && s->right->color == false)
                {
                    s->color = true;
                    x = x->parent;
                }
                else
                {
                    if (s->left->color == false)
                    {
                        s->right->color = false;
                        s->color = true;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = false;
                    s->left->color = true;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = false;
    }

    void rbTransplant(Node* u, Node* v) {
        if (u->parent == nullptr)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void deleteNodeHelper(Node* node, K key) {
        Node* z = TNULL;
        Node* x;
        Node* y;
        while (node != TNULL) {
            if (node->key == key)
            {
                z = node;
            }

            if (node->key <= key)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }

        if (z == TNULL) {
            qDebug() << "Key not found in the tree" << "\n";
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;

            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == false)
        {
            deleteFix(x);
        }
    }

    void insertFix(Node* k) {
        Node* u;
        while (k->parent->color == true) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if (u->color == true) {
                    u->color = false;
                    k->parent->color = false;
                    k->parent->parent->color = true;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = false;
                    k->parent->parent->color = true;
                    leftRotate(k->parent->parent);
                }
            }
            else {
                u = k->parent->parent->right;

                if (u->color == true)
                {
                    u->color = false;
                    k->parent->color = false;
                    k->parent->parent->color = true;
                    k = k->parent->parent;
                }
                else
                {
                    if (k == k->parent->right)
                    {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = false;
                    k->parent->parent->color = true;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root)
            {
                break;
            }
        }
        root->color = 0;
    }

    void printHelper(Node* root, QString indent, bool last) {
        if (root != TNULL) {
            qDebug() << indent;
            if (last) {
                qDebug() << "R----";
                indent += "   ";
            } else {
                qDebug() << "L----";
                indent += "|  ";
            }

            QString sColor = root->color ? "RED" : "BLACK";
            qDebug() << root->key << "(" << sColor << ")" << "\n" << "value: " << root->data;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

public:

    RedBlackTree() {
        TNULL = new Node;
        TNULL->color = false;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }

    void preorder() {
        preOrderHelper(this->root);
    }

    void inorder() {
        inOrderHelper(this->root);
    }

    void postorder() {
        postOrderHelper(this->root);
    }

    D searchTree(K key) {
        return searchTreeHelper(this->root, key);
    }

    K minimum() {
        Node* node = root;
        while (node->left != TNULL) {
            node = node->left;
        }
        return node->key;
    }

    K maximum() {
        Node* node = root;
        while (node->right != TNULL) {
            node = node->right;
        }
        return node;
    }

    Node* minimum(Node* node) {
        while (node->left != TNULL) {
            node = node->left;
        }
        return node;
    }

    Node* maximum(Node* node) {
        while (node->right != TNULL) {
            node = node->right;
        }
        return node;
    }

    Node* successor(Node* x) {
        if (x->right != TNULL) {
            return minimum(x->right);
        }

        Node* y = x->parent;
        while (y != TNULL && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    Node* predecessor(Node* x) {
        if (x->left != TNULL) {
            return maximum(x->left);
        }

        Node* y = x->parent;
        while (y != TNULL && x == y->left) {
            x = y;
            y = y->parent;
        }

        return y;
    }


    void insert(K key, D value) {
        _size++;
        Node* node = new Node;
        node->parent = nullptr;
        node->data = value;
        node->key = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = true;

        Node* y = nullptr;
        Node* x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr)
        {
            root = node;
        }
        else if (node->key < y->key)
        {
            y->left = node;
        }
        else
        {
            y->right = node;
        }

        if (node->parent == nullptr) {
            node->color = false;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        insertFix(node);
    }

    Node* getRoot() {
        return this->root;
    }

    void deleteNode(K key) {
        deleteNodeHelper(this->root, key);
    }

    size_t size() const{
        return _size;
    }

    void printTree() {
        if (root) {
            printHelper(this->root, "", true);
        }
    }

    bool isEmpty() const{
        return _size == 0;
    }
    void clear() {
        clearRecursive(root);

        root = TNULL;
        _size = 0;
    }

};

#endif // REDBLACKTREE_H
