#ifndef TREE_H
#define TREE_H

#include <QString>
#include <QDebug>
#include <queue>
#include <vector>


class Tree{


public:
    ////
    class Node{
    public:
        int key;
        QString data;
        Node* left;
        Node* right;

        Node(QString s, int v){
            key = v;
            data = s;
            left = nullptr;
            right = nullptr;
        }

        ~Node() {
            if (left != nullptr)
                delete left;
            if (right != nullptr)
                delete right;
        }
    };
    ////

    Node* root = nullptr;

    Tree()
    {}



    void insert(int key, QString data) {
        doInsert(key, data, root);
    }
    QString find(int key) {
        return doFind(key, root);
    }
    void remove(int key) {
         root = doRemove(key, root);
    }

    QVector<QString> preOrderTraversal() {
        QVector<QString> result;
        preOrder(root, result);
        return result;
    }

    QVector<QString> inOrderTraversal() {
        QVector<QString> result;
        inOrder(root, result);
        return result;
    }

    QVector<QString> postOrderTraversal() {
        QVector<QString> result;
        postOrder(root, result);
        return result;
    }

    void balanceTree() {
        doBalance(root);
    }

    QString calcLeaves() {
        return doCalcLeaves(root);
    }

    void insertSubtree(Node* subtree, int parentKey) {
        Node* parentNode = findNode(parentKey, root);
        if (parentNode) {
            if (parentNode->left == nullptr) parentNode->left = subtree;
            else if (parentNode->right == nullptr) parentNode->right = subtree;
        }
    }

    void removeSubtree(int key) {
        Node* node = findNode(key, root);
        if (node) {
            clearTree(node);
        }
    }

    void clearTree(Node* node) {
        if (node != nullptr) {
            clearTree(node->left);
            clearTree(node->right);
            delete node;
        }
    }


    void insertBranch(Node* branch, int parentKey) {
        insertSubtree(branch, parentKey);
    }

    void removeBranch(int key) {
        removeSubtree(key);
    }

    void insertAtPosition(int key, Node* position) {
        if (position == nullptr) return;
        insertInTree(key, position);
    }
    void insertInTree(int key, Node* &tree) {
        if (tree == nullptr) tree = new Node("", key);
        else if (key <= tree->key) insertInTree(key, tree->left);
        else insertInTree(key, tree->right);
    }

    Node* findLCA(int n1, int n2) {
        return findMinSon(root, n1, n2);
    }

private:


    Node* findNode(int key, Node* tree) {
        if (tree == nullptr) return nullptr;
        if (tree->key == key) return tree;
        if (key > tree->key) return findNode(key, tree->right);
        else return findNode(key, tree->left);
    }


    Node* findMinSon(Node* node, int n1, int n2) {
        if (node == nullptr) return nullptr;

        if (node->key > n1 && node->key > n2) return findMinSon(node->left, n1, n2);

        if (node->key < n1 && node->key < n2) return findMinSon(node->right, n1, n2);

        return node;
    }



    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* findMax(Node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    void doInsert(int key, QString data, Node* &tree) {
        if (tree == nullptr)
           tree = new Node(data, key);
        else if (key < tree->key)
            doInsert(key, data, tree->left);
        else if (key > tree->key)
            doInsert(key, data, tree->right);
        else
        {
            qDebug()<<"same element";
            return;
        }
    }




    QString doFind(int key, Node* tree) {
        if (tree == nullptr)
        {
            qDebug()<<"empty tree";
            return "";
        }
        if (tree->key == key)
            return tree->data;
        if (key > tree->key)
            return doFind(key, tree->right);
        else
            return doFind(key, tree->left);
    }




    Node* doRemove(int x, Node* t) {
        Node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->key)
            t->left = doRemove(x, t->left);
        else if(x > t->key)
            t->right = doRemove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->key = temp->key;
            t->right = doRemove(t->key, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }

    void rotateLeft(Node* &node) {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node = temp;
    }

    void rotateRight(Node* &node) {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node = temp;
    }


    void doBalance(Node* &node) {
        if (node == nullptr)
            return;

        int balanceFactor = height(node->left) - height(node->right);

        if (balanceFactor > 1) {
            if (height(node->left->left) >= height(node->left->right)) {
                rotateRight(node);
            } else {
                rotateLeft(node->left);
                rotateRight(node);
            }
        }
        else if (balanceFactor < -1) {
            if (height(node->right->right) >= height(node->right->left)) {
                rotateLeft(node);
            } else {
                rotateRight(node->right);
                rotateLeft(node);
            }
        }

        doBalance(node->left);
        doBalance(node->right);
    }




    void preOrder(Node* node, QVector<QString>& result) {
        if (node == nullptr) return;
        result.push_back(QString::number(node->key) + " " + node->data);
        preOrder(node->left, result);
        preOrder(node->right, result);
    }

    void inOrder(Node* node, QVector<QString>& result) {
        if (node == nullptr) return;
        inOrder(node->left, result);
        result.push_back(QString::number(node->key) + " " + node->data);
        inOrder(node->right, result);
    }

    void postOrder(Node* node, QVector<QString>& result) {
        if (node == nullptr) return;
        postOrder(node->left, result);
        postOrder(node->right, result);
        result.push_back(QString::number(node->key) + " " + node->data);
    }


    QString doCalcLeaves(Node* root) {
        if (!root) return 0;
        using namespace std;
        queue<Node*> q;
        q.push(root);

        int level = 0;
        vector<int> leaves(1, 0); // Начинаем с уровня 0

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (!node->left && !node->right) {
                    leaves[level]++;
                } else {
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }

            leaves.push_back(0); // Добавляем новый уровень
            level++;
        }
        QString s;
        s = s + "Количество листьев на каждом уровне: \n"  ;
        for (int i = 0; i < leaves.size(); i++) {
            s+= "Уровень "+ QString::number(i) +  ": " + QString::number(leaves[i]) + "\n";
        }

        return s;
    };
};
#endif // TREE_H
