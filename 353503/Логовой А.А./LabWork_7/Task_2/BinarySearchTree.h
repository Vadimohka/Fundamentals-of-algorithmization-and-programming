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
            int64_t _height{};
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

    void rightRotate(Node* node){
        swap(node, node->_left);
        Node* temp = node->_right;
        node->_right = node->_left;
        node->_left = node->_right->_left;
        node->_right->_left = node->_right->_right;
        node->_right->_right = temp;
        updateHeight(node->_right);
        updateHeight(node);
    }

    void leftRotate(Node* node){
        swap(node, node->_right);
        Node* temp = node->_left;
        node->_left = node->_right;
        node->_right = node->_left->_right;
        node->_right->_left = node->_right->_right;
        node->_left->_right = node->_left->_left;
        node->_left->_left = temp;
        updateHeight(node->_right);
        updateHeight(node);
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


    void updateHeight(Node* node){
        node->_height = std::max(getHeight(node->_left), getHeight(node->_right)) + 1;
    }

    int64_t getHeight(Node* node) const
    {
        return node == nullptr ? -1 : node->_height;
    }

    int64_t getBalance(Node* node) {
        return (node == nullptr) ? 0 : getHeight(node->_right) - getHeight(node->_left);
    }

    void swap(Node* node, Node* b){
        Myswap(node, b);
    }

    void balance(Node* node){
        int64_t balance = getBalance(node);
        if(balance == -2)
        {
            if(getBalance(node->_left) == 1)
            {
                leftRotate(node);
            }
            rightRotate(node);
        }
        else if(balance == 2)
        {
            if(getBalance(node->_right) == -1)
            {
                rightRotate(node);
            }
            leftRotate(node);
        }
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

        updateHeight(node);
        balance(node);
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
        if(node != nullptr)
        {
            updateHeight(node);
            balance(node);
        }
        return node;
    }

public:


    BinarySearchTree() : _node(nullptr){

    }

    Node* getNode(){
        return _node;
    }

    T& search(int64_t key){
        Node* node = search(_node, key);
        if(node == nullptr){
            throw std::runtime_error("Key not found");
        }
        return node->_value;
    }


    void insert(int64_t key, T value){
        if(_node == nullptr){
            _node = createNode(key, value);
        }
        else{
            insert(_node, key, value);
        }
    }

    void deleteNode(int64_t key)
    {
        if(_node == nullptr){
            throw std::runtime_error("Key not found");
        }
        _node = deleteNode(_node, key);
    }


};
#endif // BINARYSEARCHTREE_H
