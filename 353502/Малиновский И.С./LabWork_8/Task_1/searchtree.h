#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <iomanip>
#include <QDebug>
#include <qtreewidget.h>

template <typename T> class SearchTree {

private:
    struct TreeNode {
        T val;
        TreeNode* left;
        TreeNode* right;
        int height;

        TreeNode(T x) : val(x), left(nullptr), right(nullptr), height(1) {}
    };

    TreeNode *root;

    int height(TreeNode* node) {
        return node ? node->height : 0;
    }

    int getBalance(TreeNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    TreeNode* balance(TreeNode* node) {
        node->height = 1 + std::max(height(node->left), height(node->right));
        int balance = getBalance(node);

        // Левый Левый случай
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }

        // Левый Правый случай
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Правый Правый случай
        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }

        // Правый Левый случай
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    TreeNode* insert(TreeNode* node, T key) {
        qDebug() << "2";
        if (!node) {
            return new TreeNode(key);
        }

        if (key < node->val) {
            node->left = insert(node->left, key);
        } else if (key > node->val) {
            node->right = insert(node->right, key);
        } else {
            return node; // Дублирующиеся ключи не допускаются
        }

        return balance(node);
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    TreeNode* deleteNode(TreeNode* root, T key) {
        if (!root) {
            return root;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if ((!root->left) || (!root->right)) {
                TreeNode* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = NULL;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                TreeNode* temp = minValueNode(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }

        if (!root) {
            return root;
        }

        return balance(root);
    }

    T findLCA(TreeNode* root, T n1, T n2) {
        while (root != NULL) {
            if (root->val > n1 && root->val > n2) {
                root = root->left;
            } else if (root->val < n1 && root->val < n2) {
                root = root->right;
            } else {
                break;
            }
        }
        return root->val;
    }

    bool contains(TreeNode* root, T val) {
        if (!root) return 0;
        if (root->val == val) return 1;
        if (root->val > val) return contains(root->left, val);
        return contains(root->right, val);
    }

    void printTree(QTreeWidget *treeWidget, QTreeWidgetItem *parent, TreeNode* root) {
        qDebug() << "OK";
        if (root) {
            QTreeWidgetItem* item = new QTreeWidgetItem(parent ? parent : treeWidget->invisibleRootItem());
            item->setText(0, QString::number(root->val));
            printTree(treeWidget, item, root->left);
            printTree(treeWidget, item, root->right);
        }
    }

public:
    SearchTree() { this->root = nullptr; }

    void insert(const T &val) {
        qDebug() << "1";
        this->root=this->insert(this->root, val);
    }

    void erase(const T &val) {
        this->root=this->deleteNode(this->root, val);
    }

    bool contains(const T &val) {
        return this->contains(this->root, val);
    }

    T lca(const T &val1, const T &val2) {
        return this->findLCA(this->root, val1, val2);
    }

    void print(QTreeWidget *treeWidget) {
        this->printTree(treeWidget, nullptr, this->root);
    }
};

#endif // SEARCHTREE_H
