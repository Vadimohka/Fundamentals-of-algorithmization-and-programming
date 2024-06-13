#ifndef BST_H
#define BST_H

#include <QtMath>
#include <QString>

template <typename T> class BST {

public:
    struct Node {
        int key;
        int size;
        Node *left = nullptr;
        Node *right = nullptr;
        T value;

        Node(int key, T value, int size){
            this->key = key;
            this->value = value;
            this->size = size;
        }

        ~Node(){
            if (this->left != nullptr){
                delete this->left;
            }
            if (this->right != nullptr){
                delete this->right;
            }
        }
    };

    Node *root = nullptr;

    BST() {}

    BST(int key[], T value[], int size) {
        for(int i = 0; i < size; i++){
            put(key[i], value[i]);
        }
    }


    ~BST() {
        if (root != nullptr){
            delete root;
        }
    }

    void clear() {
        delete this->root;
        this->root = nullptr;
    }

    void put(int key, T val){
        root = put(root, key, val);
    }



    bool contains(int key) {
        Node *node = root;
        while (node != nullptr) {
            if (key < node->key) {
                node = node->left;
            }
            else if(key > node->key){
                node = node->right;
            }
            else{
                return true;
            }
        }

        return false;
    }

    T* get(int key) {
        Node *node = root;
        while (node != nullptr) {
            if (key < node->key) {
                node = node->left;
            }
            else if(key > node->key){
                node = node->right;
            }
            else{
                return &(node->value);
            }
        }
        return nullptr;
    }




    void remove(int key){
        root = remove(root, key);
    }



    int size(){
        return root->size;
    }

    Node* balance(Node* node){
        if(height(node->right) - height(node->left) > 1){
            Node* rightNode = node->right;
            node->right = rightNode->left;
            rightNode->left = node;
            return rightNode;
        }
        else if(height(node->right) - height(node->left) < -1){
            Node* leftNode = node->left;
            node->left = leftNode->right;
            leftNode->right= node;
            return leftNode;
        }
        return node;
    }

    Node* get(int key, Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        if(key < node->key){
            return get(node->left, key);
        }
        else if(key > node->key){
            return get(node->right, key);
        }
        return node;
    }

    int size(Node* node){
        if(node != nullptr){
            return node->size;
        }
        return 0;
    }

    int height(Node* node){
        if(node != nullptr){
            return qMax(height(node->left), height(node->right)) + 1;
        }
        return 0;
    }

    Node* put(Node* node, int key, T value){
        if(node == nullptr){
            return new Node(key, value, 1);
        }
        if(key < node->key){
            node->left = put(node->left, key, value);
        }
        else if(key > node->key){
            node->right = put(node->right, key, value);
        }
        else{
            node->value = value;
        }
        node->size = size(node->left) + size(node->right) + 1;
        node = balance(node);
        return node;
    }

    Node* min(Node* node){
        if(node == nullptr){
            return nullptr;
        }
        while(node->left != nullptr){
            node = node->left;
        }
        return node;
    }

    Node* deleteMin(Node* node){
        if(node->left == nullptr){
            return node->right;
        }
        node->left = deleteMin(node->left);
        node = balance(node);
        node->size = size(node->left) + size(node->right) + 1;
        return node;
    }

    Node* remove(Node* node, int key){
        if(node->right == nullptr){
            return nullptr;
        }

        if(key < node->key){
            node->left = remove(node->left, key);
        }
        else if(key > node->key){
            node->right = remove(node->right, key);
        }
        else{
            if(node->right == nullptr){
                return node->left;
            }
            else if(node->left == nullptr){
                return node->right;
            }
            Node* temp = node;
            node = min(temp->right);
            if(node == nullptr){
                return nullptr;
            }
            node->right = deleteMin(node->right);
            node->left = temp->left;
        }
        node = balance(node);
        node->size = size(node->left) + size(node->right) + 1;
        return node;
    }
};

#endif // BST_H
