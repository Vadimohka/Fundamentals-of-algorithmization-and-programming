#ifndef LAB7_BST_H
#define LAB7_BST_H
#pragma once
#include <iostream>
#include <QString>

template<typename K, typename V>
struct Node {
    K key;
    V value;
    Node<K, V>* left;
    Node<K, V>* right;

    static Node<K, V>* getNode(K key, V value) {
        Node<K, V>* newNode = new Node<K, V>;
        newNode->key = key;
        newNode->value = value;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }
};

template<typename K, typename V>
class BST {
private:

    /*Node<K,V>* insert(Node<K, V>* r, K key, V value) {
        if (!r) {
            root = r = Node<K, V>::getNode(key, value);
            root->left = root->right = r->left = r->right = nullptr;
        } else if (key > r->key) {
            r->right = insert(r->right, key, value);
        } else if (key <= r->key) {
            r->left = insert(r->left, key, value);
        }
        return r;
    }*/
    Node<K,V>* insert(Node<K,V>* node, K key, V &value) {
        if (node == nullptr){
            Node<K,V>* temp = Node<K, V>::getNode(key, value);
            return temp;
        }
        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);

        return node;
    }

    Node<K, V>* find(Node<K, V>* r, K key) {
        if (r == nullptr) {
            return nullptr;
        } else if (r->key > key) {
            return find(r->left, key);
        } else if (r->key < key) {
            return find(r->right, key);
        } else {
            return r;
        }
    }

    Node<K, V>* findMin(Node<K, V>* r) {
        if (!r) return nullptr;
        else if (!r->left) return r;
        else return findMin(r->left);
    }

    Node<K, V>* findMax(Node<K, V>* r) {
        if (!r) return nullptr;
        else if (!r->right) return r;
        else return findMax(r->right);
    }

    Node<K,V>* remove(Node<K, V>* r, K key) {
        if (!r) return nullptr;
        else if (key > r->key) r->right = remove(r->right, key);
        else if (key < r->key) r->left = remove(r->left, key);
        else if (r->right && r->left) {
            Node<K, V>* temp = findMin(r->right);
            r->key = temp->key;
            r->value = temp->value;
            r->right = remove(r->right, r->key);
        } else {
            Node<K, V>* temp = r;
            if (r->left) r = r->left;
            else if (r->right) r = r->right;
            else r = nullptr;
            delete temp;
        }
        return r;
    }
    void printInorderTree(Node<K,V>* node, QString& InorderOrder){
        if (node == nullptr){
            return;
        }
        printInorderTree(node->left, InorderOrder);
        InorderOrder += ("key: " + QString::number(node->key) + " " + "value: " + node->value + " ");
        printInorderTree(node->right, InorderOrder);
    }
    void printPostOrder(Node<K,V>* node, QString& postOrder){
        if (node == nullptr){
            return;
        }
        printPostOrder(node->left, postOrder);
        printPostOrder(node->right, postOrder);
        postOrder += ("key: " + QString::number(node->key) + "value: " + node->value + " ");
    }
    void printPreOrder(Node<K,V>* node, QString& preOrder)
    {
        if (node == nullptr){
            return;
        }
        preOrder += ("key: " + QString::number(node->key) + "value: " + node->value + " ");
        printPreOrder(node->left, preOrder);
        printPreOrder(node->right, preOrder);
    }

    void clearTree(Node<K,V> *node) {
        if (node != nullptr) {
            clearTree(node->left);
            clearTree(node->right);
            delete node;
        }
    }

    void inOrderToVector(Node<K,V> *node, QVector<QPair<K,V>>& vec) {
        if (node != nullptr) {
            inOrderToVector(node->left, vec);
            vec.emplace_back(node->key, node->value);
            inOrderToVector(node->right, vec);
        }
    }

    int height(Node<K,V>* temp) {
        if (temp == nullptr) return 0;
        return fmax(height(temp->left), height(temp->right)) + 1;
    }
    Node<K,V>* rightRotate(Node<K,V>* y) {
        Node<K,V>* x = y->left;
        Node<K,V>* T2 = x->right;

        x->right = y;
        y->left = T2;

        return x;
    }
    Node<K,V>* leftRotate(Node<K,V>* x) {
        Node<K,V>* y = x->right;
        Node<K,V>* T2 = y->left;

        y->left = x;
        x->right = T2;

        return y;
    }
    int getBalance(Node<K,V>* N) {
        if (N == nullptr) return 0;
        return height(N->left) - height(N->right);
    }
    Node<K, V>* balanceTree(Node<K, V>* root) {
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root; // No imbalance
    }
    Node<K,V>* buildBalancedTreeFromVector(QVector<QPair<K,V>>& sortedPairs, long start, long end) {
        if (start > end){
            return nullptr;
        }
        long mid = (start + end) / 2;
        Node<K,V>* newNode = Node<K,V>::getNode(sortedPairs[mid].first, sortedPairs[mid].second);
        newNode->left = buildBalancedTreeFromVector(sortedPairs, start, mid - 1);
        newNode->right = buildBalancedTreeFromVector(sortedPairs, mid + 1, end);
        return newNode;
    }
    double getAverageKey() {
        QVector<QPair<K, V>> vec;
        inOrderToVector(root, vec);
        double sum = 0;
        for (const auto& pair : vec) {
            sum += pair.first;
        }
        return sum / vec.size();
    }
public:
    Node<K, V>* root = nullptr;

    BST() = default;

    ~BST(){ clearTree(root);}

    BST(K key, V value) {
        root = Node<K, V>::getNode(key, value);
    }
    Node<K,V>* getRoot(){
        return root;
    }
    void insert(K key, V value) {
        root = insert(root,key,value);
    }

    Node<K, V>* findMin(){
        Node<K, V>* r= findMin(root);
        return r;
    }
    Node<K, V>* findMax(){
        Node<K, V>* r= findMax(root);
        return r;
    }
    /*void balanceTree() {
        QVector<QPair<K, V>> sortedPairs;
        inOrderToVector(root, sortedPairs);
        root = buildBalancedTreeFromVector(sortedPairs, 0, sortedPairs.size() - 1);
    }*/
    Node<K, V>* balanceTree(){
        root = balanceTree(root);
    }
    void getTreeFromVec(QVector<QPair<K, V>> sortedPairs) {
        root = buildBalancedTreeFromVector(sortedPairs, 0, sortedPairs.size() - 1);
    }
    void clearTree(){
        clearTree(root);
        root = nullptr;
    }
    void printInorderTree(QString& InorderOrder){
        printInorderTree(root, InorderOrder);
    }
    void printPostOrder(QString& preOrder){
        printPostOrder(root,preOrder);
    }
    void printPreOrder(QString& postOrder){
        printPreOrder(root,postOrder);
    }
    void remove(K key) {
        root = remove(root,key);
    }
    Node<K, V>* find( K key) {
        return find(root, key);
    }
    Node<K, V>* findNearestNode() {
        double averageKey = getAverageKey();
        Node<K, V>* currentNode = root;
        Node<K, V>* nearestNode = currentNode;
        double minDiff = std::abs(currentNode->key - averageKey);

        while (currentNode) {
            double diff = std::abs(currentNode->key - averageKey);
            if (diff < minDiff) {
                minDiff = diff;
                nearestNode = currentNode;
            }
            if (currentNode->key < averageKey) {
                currentNode = currentNode->right;
            } else {
                currentNode = currentNode->left;
            }
        }
        return nearestNode;
    }
};

#endif //LAB7_BST_H