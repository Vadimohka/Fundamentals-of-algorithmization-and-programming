//
// Created by acryoz on 26.05.24.
//
#include <QString>
#include <algorithm>
#include <cstdint>
#include <utility>

template <typename K, typename V>
class AVLTree {
    friend class TreeGraph;
    friend class TreeNode;

   protected:
    struct Node {
        std::pair<K, V> kv;
        int8_t height_ = 0;
        Node* left;
        Node* right;

        Node(K key, V value) {
            this->kv.first = key;
            this->kv.second = value;
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(const Node& other) {
            this->kv = other.kv;
            this->left = other.left;
            this->right = other.right;
            this->height_ = other.height_;
        }
    };

    Node* root_ = nullptr;

   public:
    AVLTree() {}

    void insert(std::pair<K, V> kv_pair) {
        this->ins(this->root_, kv_pair.first, kv_pair.second);
    }

    void del(K key) { this->root_ = rmKey(this->root_, key); }

    QString infTraverse() {
        QString ans;
        infixTraverse(this->root_, ans);
        return ans;
    }

    QString prefTraverse() {
        QString ans;
        prefixTraverse(this->root_, ans);
        return ans;
    }

    QString postfTraverse() {
        QString ans;
        postfixTraverse(this->root_, ans);
        return ans;
    }

   private:
    int8_t height(Node* node) { return (node) ? node->height_ : -1; }

    int32_t balanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return this->height(node->right) - this->height(node->left);
    }

    void updateHeight(Node* node) {
        if (node != nullptr) {
            node->height_ =
                std::max(this->height(node->right), this->height(node->left)) +
                1;
            updateHeight(node->left);
            updateHeight(node->right);
        }
    }

    void swap(Node* n1, Node* n2) {
        K n1_key = n1->kv.first;
        n1->kv.first = n2->kv.first;
        n2->kv.first = n1_key;
        V n1_val = n1->kv.second;
        n1->kv.second = n2->kv.second;
        n2->kv.second = n1_val;
    }

    void rotateLeft(Node* node) {
        swap(node, node->right);
        Node* q = node->left;
        node->left = node->right;
        node->right = node->left->right;
        node->left->right = node->left->left;
        node->left->left = q;
        this->updateHeight(node->left);
        this->updateHeight(node);
    }

    void rotateRight(Node* node) {
        swap(node, node->left);
        Node* q = node->right;
        node->right = node->left;
        node->left = node->right->left;
        node->right->left = node->right->right;
        node->right->right = q;
        this->updateHeight(node->right);
        this->updateHeight(node);
    }

    void rebalance(Node* node) {
        this->updateHeight(node);
        if (this->balanceFactor(node) == -2) {
            if (this->balanceFactor(node->left) > 0) {
                this->rotateLeft(node->left);
            }
            this->rotateRight(node);
            return;
        }
        if (this->balanceFactor(node) == 2) {
            if (this->balanceFactor(node->right) < 0) {
                this->rotateRight(node->right);
            }
            this->rotateLeft(node);
            return;
        }
    }

    void ins(Node*& root, K key, V val) {
        if (root == nullptr) {
            root = new Node(key, val);
            return;
        }
        if (key < root->kv.first) {
            ins(root->left, key, val);
        } else {
            ins(root->right, key, val);
        }
        rebalance(root);
    }

    Node* min(Node* node) {
        return (node->left != nullptr) ? this->min(node->left) : node;
    }

    Node* max(Node* node) {
        return (node->right != nullptr) ? this->max(node->right) : node;
    }

    Node* rmMin(Node* node) {
        if (node->left == nullptr) {
            return node->right;
        }
        node->left = this->rmMin(node->left);
        return this->rebalance(node);
    }

    Node* rmKey(Node* node, K key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (key < node->kv.first) {
            node->left = this->rmKey(node->left, key);
        } else if (key > node->kv.first) {
            node->right = this->rmKey(node->right, key);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                node = (node->left == nullptr) ? node->right : node->left;
            } else {
                Node* max_left = this->max(node->left);
                swap(node, max_left);
                node->left = rmKey(node->left, max_left->kv.first);
            }
        }
        rebalance(node);
        return node;
    }

    Node* find(Node* root, K key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (key == root->kv.first) {
            return root;
        }
        if (key < root->kv.first) {
            return find(root->left, key);
        }
        return find(root->right, key);
    }

    void infixTraverse(Node* root, QString& elems) {
        if (root == nullptr) {
            return;
        }
        infixTraverse(root->left, elems);
        elems += root->kv.second + " ";
        infixTraverse(root->right, elems);
    }

    void prefixTraverse(Node* root, QString& elems) {
        if (root == nullptr) {
            return;
        }
        elems += root->kv.second + " ";
        prefixTraverse(root->left, elems);
        prefixTraverse(root->right, elems);
    }

    void postfixTraverse(Node* root, QString& elems) {
        if (root == nullptr) {
            return;
        }
        postfixTraverse(root->left, elems);
        postfixTraverse(root->right, elems);
        elems += root->kv.second + " ";
    }
};
