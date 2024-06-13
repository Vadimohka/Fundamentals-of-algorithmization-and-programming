#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <QString>
#include <QVector>

class BST {
public:
    class Node
    {
    public:
        QString info;
        int key;
        Node *left;
        Node *right;

        Node(QString nodeValue, int nodeKey)
        {
            info = nodeValue;
            key = nodeKey;
            left = nullptr;
            right = nullptr;
        }
    };

private:
    void insertInTree(int key, QString info, Node *&tree)
    {
        if (tree == nullptr)
            tree = new Node(info, key);
        else if (key <= tree->key)
            insertInTree(key, info, tree->left);
        else
            insertInTree(key, info, tree->right);
    }

    QString findInTree(int key, Node *tree)
    {
        if (tree == nullptr) return "";
        if (tree->key == key) return tree->info;
        if (key > tree->key)
            return findInTree(key, tree->right);
        else
            return findInTree(key, tree->left);
    }

    void removeFromTree(int key, Node *tree, Node *&parent, int side)
    {
        if (tree == nullptr) return;

        if (key < tree->key) {
            removeFromTree(key, tree->left, tree, -1);
        } else if (key > tree->key) {
            removeFromTree(key, tree->right, tree, 1);
        } else {
            if (tree->left == nullptr && tree->right == nullptr) {
                if (parent == nullptr) {
                    delete tree;
                    root = nullptr;
                } else {
                    if (side == -1)
                        parent->left = nullptr;
                    else if (side == 1)
                        parent->right = nullptr;
                    delete tree;
                }
            }

            else if (tree->left == nullptr) {
                Node *temp = tree;
                if (parent == nullptr) {
                    root = tree->right;
                    delete temp;
                } else {
                    if (side == -1)
                        parent->left = tree->right;
                    else if (side == 1)
                        parent->right = tree->right;
                    delete temp;
                }
            } else if (tree->right == nullptr) {
                Node *temp = tree;
                if (parent == nullptr) {
                    root = tree->left;
                    delete temp;
                } else {
                    if (side == -1)
                        parent->left = tree->left;
                    else if (side == 1)
                        parent->right = tree->left;
                    delete temp;
                }
            }

            else {
                Node *successor = findMin(tree->right);
                tree->key = successor->key;
                tree->info = successor->info;
                removeFromTree(successor->key, tree->right, tree, 1);
            }
        }
    }
    Node *findMin(Node *node)
    {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    int height(Node *node)
    {
        if (node == nullptr) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }

    void balanceTreeHelper(Node *&node)
    {
        if (node == nullptr) return;

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

        balanceTreeHelper(node->left);
        balanceTreeHelper(node->right);
    }

    void rotateLeft(Node *&node)
    {
        Node *temp = node->right;
        node->right = temp->left;
        temp->left = node;
        node = temp;
    }

    void rotateRight(Node *&node)
    {
        Node *temp = node->left;
        node->left = temp->right;
        temp->right = node;
        node = temp;
    }

    void preOrder(Node *node, QVector<QString> &result)
    {
        if (node == nullptr) return;
        result.push_back(QString::number(node->key) + " " + node->info);
        preOrder(node->left, result);
        preOrder(node->right, result);
    }

    void inOrder(Node *node, QVector<QString> &result)
    {
        if (node == nullptr) return;
        inOrder(node->left, result);
        result.push_back(QString::number(node->key) + " " + node->info);
        inOrder(node->right, result);
    }

    void inOrderToVector(Node *node, QVector<int> &a)
    {
        if (node == nullptr)
            return;
        inOrderToVector(node->left, a);
        a.push_back(node->key);
        inOrderToVector(node->right, a);
    }

    void postOrder(Node *node, QVector<QString> &result)
    {
        if (node == nullptr) return;
        postOrder(node->left, result);
        postOrder(node->right, result);
        result.push_back(QString::number(node->key) + " " + node->info);
    }

    int findSum(Node *root)
    {
        if (!root)
            return 0;
        return root->key + findSum(root->left) + findSum(root->right);
    }

    int countNodes(Node *root)
    {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    Node *findClosestNode(Node *root, int target)
    {
        if (!root)
            return nullptr;

        if (root->key == target)
            return root;

        Node *left = findClosestNode(root->left, target);
        Node *right = findClosestNode(root->right, target);

        if (!left)
            return right;
        if (!right)
            return left;

        return (std::abs(left->key - target) < std::abs(right->key - target)) ? left : right;
    }

public:
    Node *root = nullptr;

    BST() {}

    BST(QVector<QPair<int, QString>> info) {
        for (QPair<int, QString> el : info)
            insert(el.first, el.second);
    }

    void insert(int key, QString info) {
        insertInTree(key, info, root);
    }
    QString find(int key) {
        return findInTree(key, root);
    }
    void remove(int key) {
        Node *a = nullptr;
        removeFromTree(key, root, a, 1);
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

    QVector<int> inOrderToVectorPub()
    {
        QVector<int> result;
        inOrderToVector(root, result);
        return result;
    }

    QVector<QString> postOrderTraversal() {
        QVector<QString> result;
        postOrder(root, result);
        return result;
    }

    void balanceTree() {
        balanceTreeHelper(root);
    }

    //    int calcLeaves() {
    //        return calcLeavesOfTree(root);
    //    }

    int findClosest()
    {
        Node *answ = findClosestNode(root, static_cast<double>(findSum(root)) / countNodes(root));
        return answ->key;
    }
};

#endif // BINARYSEARCHTREE_H
