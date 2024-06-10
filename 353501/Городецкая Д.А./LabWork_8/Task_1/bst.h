#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <QStringList>

struct node {
    int key;
    QString str;
    node* left;
    node* right;
    node(int k, const QString& s) : key(k), str(s), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    node* getRoot() {
        return root;
    }

    void fill(const std::vector<std::pair<int, QString>>& elements) {
        for (const auto& elem : elements) {
            insert(elem.first, elem.second);
        }
    }

    void insert(int key, const QString& value) {
        root = insertRec(root, key, value);
    }

    void remove(int key) {
        root = removeRec(root, key);
    }

    std::pair<QString, bool> find(int key) {
        node* found = findRec(root, key);
        if (found)
            return { found->str, true };
        else
            return { "", false };
    }

    void balance() {
        // Balancing logic if needed
    }

    void removeSubtree(int key) {
        root = removeSubtreeRec(root, key);
    }

    node* LCA(int k1, int k2) {
        return LCARec(root, k1, k2);
    }

    QString traverse(int order) {
        std::stringstream ss;
        if (order == 1)
            postOrder(root, ss);
        else if (order == 0)
            inOrder(root, ss);
        else
            preOrder(root, ss);
        return QString::fromStdString(ss.str());
    }

    void getVerts(node* root, QStringList& vars) {
        if (!root) return;
        vars.append(QString::number(root->key));
        getVerts(root->left, vars);
        getVerts(root->right, vars);
    }

private:
    node* root;

    node* insertRec(node* root, int key, const QString& value) {
        if (!root)
            return new node(key, value);
        if (key < root->key)
            root->left = insertRec(root->left, key, value);
        else
            root->right = insertRec(root->right, key, value);
        return root;
    }

    node* removeRec(node* root, int key) {
        if (!root) return root;
        if (key < root->key)
            root->left = removeRec(root->left, key);
        else if (key > root->key)
            root->right = removeRec(root->right, key);
        else {
            if (!root->left) {
                node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                node* temp = root->left;
                delete root;
                return temp;
            }
            node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->str = temp->str;
            root->right = removeRec(root->right, temp->key);
        }
        return root;
    }

    node* findRec(node* root, int key) {
        if (!root || root->key == key) return root;
        if (key < root->key)
            return findRec(root->left, key);
        return findRec(root->right, key);
    }

    node* minValueNode(node* root) {
        node* current = root;
        while (current && current->left)
            current = current->left;
        return current;
    }

    node* removeSubtreeRec(node* root, int key) {
        if (!root) return nullptr;
        if (root->key == key) {
            deleteSubtree(root);
            return nullptr;
        }
        if (key < root->key)
            root->left = removeSubtreeRec(root->left, key);
        else
            root->right = removeSubtreeRec(root->right, key);
        return root;
    }

    void deleteSubtree(node* root) {
        if (!root) return;
        deleteSubtree(root->left);
        deleteSubtree(root->right);
        delete root;
    }

    node* LCARec(node* root, int k1, int k2) {
        if (!root) return nullptr;
        if (root->key > k1 && root->key > k2)
            return LCARec(root->left, k1, k2);
        if (root->key < k1 && root->key < k2)
            return LCARec(root->right, k1, k2);
        return root;
    }

    void inOrder(node* root, std::stringstream& ss) {
        if (!root) return;
        inOrder(root->left, ss);
        ss << root->key << " ";
        inOrder(root->right, ss);
    }

    void preOrder(node* root, std::stringstream& ss) {
        if (!root) return;
        ss << root->key << " ";
        preOrder(root->left, ss);
        preOrder(root->right, ss);
    }

    void postOrder(node* root, std::stringstream& ss) {
        if (!root) return;
        postOrder(root->left, ss);
        postOrder(root->right, ss);
        ss << root->key << " ";
    }
};

#endif // BST_H
