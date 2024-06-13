#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <QVector>


template <typename T>
class BinSearchTree {

public:
    struct node {
        T data;
        node* left;
        node* right;
    };
private:
    node* root;

    node* add_(T x, node* t)
    {
        if(t == nullptr)
        {
            t = new node;
            t->data = x;
            t->left = t->right = nullptr;
        }
        if     (x < t->data)    t->left  = add_(x, t->left);
        else if(x > t->data)    t->right = add_(x, t->right);
        return t;
    }

    node* findMin_(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin_(t->left);
    }

    node* findMax_(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove_(T x, node* t) {
        node* temp;
        if(t == nullptr)
            return nullptr;
        else if(x < t->data)
            t->left = remove_(x, t->left);
        else if(x > t->data)
            t->right = remove_(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin_(t->right);
            t->data = temp->data;
            t->right = remove_(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == nullptr)
                t = t->right;
            else if(t->right == nullptr)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void traverse_(node* root, QVector<T> result){
        if(root == nullptr) return;
        traverse_(root->left, result);
        result.push_back(root->data);
        traverse_(root->right, result);
    }

    node* find_(node* t, T x) {
        if(t == nullptr)
            return nullptr;
        else if(x < t->data)
            return find_(t->left, x);
        else if(x > t->data)
            return find_(t->right, x);
        else
            return t;
    }

    void removeTree_(node* root) {
        remove_(root->data, root);
        if (root->right)
            removeTree_(root->right);
        if (root->left)
            removeTree_(root->left);
    }

    void insertTree_(node* root) {
        add_(root->data, root);
        if (root->right)
            insertTree_(root->right);
        if (root->left)
            insertTree_(root->left);
    }

    node* makeEmpty_(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty_(t->left);
            makeEmpty_(t->right);
            delete t;
        }
        return NULL;
    }

    node* findRoot_(node* node, T data1, T data2) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->data > data1 && node->data > data2) {
            return findRoot_(node->left, data1, data2);
        }

        if (node->data < data1 && node->data < data2) {
            return findRoot_(node->right, data1, data2);
        }

        return node;
    }

public:
    BinSearchTree() {
        root = nullptr;
    }

    ~BinSearchTree() {
        root = makeEmpty_(root);
    }

    void add(T x) {
        root = add_(x, root);
    }

    T find(T data) {
        node* result = find_(root, data);
        return result ? result->data : T();
    }

    void remove(T data) {
        root = remove_(data, root);
    }

    QVector<T> traverse(){
        QVector<T> result;
        traverse_(root, result);
        return result;
    }

    void insertTree(node* subRoot) {
        if (subRoot == nullptr) return;
        insertTree_(subRoot);
    }

    void removeTree(node* subRoot) {
        if (subRoot == nullptr) return;
        removeTree_(subRoot);
    }

    inline node* getRoot() const {return root;};

    node* findRoot(T data1, T data2) {
        return findRoot_(root, data1, data2);
    }

};

#endif // BINSEARCHTREE_H
