#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include<cstdint>
#include <algorithm>
#include<stdexcept>
#include<QDebug>

template<typename T>
void Myswap(T& a, T& b){
    T temp = std::move(b);
    b = std::move(a);
    a = std::move(temp);
}

template<typename T>
class BinarySearchTree{
protected:

    struct Node{
    public:
        int64_t _key{};
        T _value;
        Node* _left;
        Node* _right;
    };

    Node* _node;

    Node* createNode(int64_t key, int64_t value){
        Node* temp = new Node();
        temp->_value = value;
        temp->_key = key;
        return temp;
    }

    void swap(Node* node, Node* b){
        Myswap(node, b);
    }

    void insert(Node* node, int64_t key, T value) {
        if (key < node->_key) {
            if (node->_left == nullptr) {
                node->_left = createNode(key, value);
            }
            else {
                insert(node->_left, key, value);
            }
        }
        else if (key > node->_key) {
            if (node->_right == nullptr) {
                node->_right = createNode(key, value);
            }
            else {
                insert(node->_right, key, value);
            }
        }

        else
        {
            node->_value = value;
        }
    }

    Node* getMax(Node* node){
        if(node == nullptr)
        {
            return nullptr;
        }
        else if(node->_right == nullptr)
        {
            return node;
        }

        return getMax(node->_right);
    }

    Node* getMin(Node* node){
        if(node == nullptr)
        {
            return nullptr;
        }
        else if(node->_left == nullptr)
        {
            return node;
        }

        return getMin(node->_left);
    }

    Node* search(Node* node, int64_t key){
        if(node == nullptr)
        {
            return nullptr;
        }
        else if(node->_key == key)
        {
            return node;
        }

        return (key  < node->_key)? search(node->_left, key) : search(node->_right, key);
    }

    Node* deleteNode(Node* node, int64_t key){
        if(node == nullptr)
        {
            return nullptr;
        }
        else if(node->_key < key)
        {
            node->_right = deleteNode(node->_right, key);
        }
        else if(node->_key > key) {
            node->_left =  deleteNode(node->_left, key);
        }
        else
        {
            if(node->_left == nullptr || node->_right == nullptr){
                node = (node->_left == nullptr) ? node->_right : node->_left;
            }
            else
            {
                Node* temp = getMax(node->_left);
                node->_key = temp->_key;
                node->_value = temp->_value;
                node->_left = deleteNode(node->_left, temp->_key);
            }
        }

        return node;
    }

    void insertBranch(int64_t parentKey, Node* branchRoot) {
        Node* parent = search(_node, parentKey);
        if (parent == nullptr) {
            throw std::runtime_error("Tree is empty");
            return;
        }

        if (branchRoot->_key < parent->_key)
        {
            if (parent->_left == nullptr)
            {
                parent->_left = branchRoot;
            }
            else
            {
            throw std::runtime_error("already created");
            }
        }
        else if (branchRoot->_key > parent->_key)
        {
            if (parent->_right == nullptr) {
                parent->_right = branchRoot;
            }
            else
            {
                throw std::runtime_error("already created");
            }
        }
        else
        {
            throw std::runtime_error("This key is already used");
        }
    }


    void insertSubtree(Node* parent, Node* subtreeRoot) {
        if (parent == nullptr || subtreeRoot == nullptr)
        {
            return;
        }

        if (subtreeRoot->_key < parent->_key)
        {
            if (parent->_left == nullptr)
            {
                parent->_left = subtreeRoot;
            }
            else
            {
                insertSubtree(parent->_left, subtreeRoot);
            }
        }
        else if (subtreeRoot->_key > parent->_key)
        {
            if (parent->_right == nullptr)
            {
                parent->_right = subtreeRoot;
            }
            else
            {
                insertSubtree(parent->_right, subtreeRoot);
            }
        }
    }

    Node* deleteSubtree(Node* node, int64_t key) {
        if (node == nullptr)
        {
            return nullptr;
        }
        else if (node->_key < key)
        {
            node->_right = deleteSubtree(node->_right, key);
        }
        else if (node->_key > key)
        {
            node->_left = deleteSubtree(node->_left, key);
        }
        else
        {
            if (node->_left == nullptr)
            {
                Node* temp = node->_right;
                delete node;
                return temp;
            }
            else if (node->_right == nullptr)
            {
                Node* temp = node->_left;
                delete node;
                return temp;
            }

            Node* temp = getMin(node->_right);
            node->_key = temp->_key;
            node->_value = temp->_value;
            node->_right = deleteSubtree(node->_right, temp->_key);
        }
        return node;
    }

    void traverse(Node* node){
        if(node == nullptr){
            return;
        }

        traverse(node->_left);
        ///print, hz;
        traverse(node->_right);
    }

    Node* findLowestCommonAncestor(Node* root, int64_t key1, int64_t key2) {
        if (root == nullptr) {
            return nullptr;
        }

        if (key1 < root->_key && key2 < root->_key)
        {
            return findLowestCommonAncestor(root->_left, key1, key2);
        }
        else if (key1 > root->_key && key2 > root->_key)
        {
            return findLowestCommonAncestor(root->_right, key1, key2);
        }
        else
        {
            return root;
        }
    }


public:

    BinarySearchTree() : _node(nullptr){

    }

    void removeSubTree(int64_t key){
        _node = deleteSubtree(_node, key);
    }

    void removeRightBranch(int64_t key){
        _node = deleteSubtree(_node->_right, key);
    }

    void removeLeftBranch(int64_t key){
         _node = deleteSubtree(_node->_left, key);
    }

    void traverse(){
        traverse(_node);
    }

    T& find(int64_t key){
        Node* node = search(_node, key);
        if(node == nullptr){
            throw std::runtime_error("Key not found");
        }
        return node->_value;
    }

    void insertTree(BinarySearchTree<T>& other){
        insertSubtree(_node, other._node);
    }

    void insertBranchTree(T& key, Node* &other){
        insert(key, other);
    }

    void add(int64_t key, T value){
        if(_node == nullptr){
            _node = createNode(key, value);
        }
        else{
            insert(_node, key, value);
        }
    }

    void remove(int64_t key)
    {
        if(_node == nullptr){
            throw std::runtime_error("Key not found");
        }
        _node = deleteNode(_node, key);
    }


};

#endif // BINARYSEARCHTREE_H
