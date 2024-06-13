#ifndef BST_H
#define BST_H

#include <QTreeWidget>
#include <QtMath>
#include <QString>


template <typename T> class BST {

    QTreeWidget *widget;

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
        if(root == nullptr){
            return 0;
        }
        return root->size;
    }

    Node* balance(Node* node){
        if(height(node->right) - height(node->left) > 1){
            Node* rightNode = node->right;
            node->right = rightNode->left;
            rightNode->left = node;
            int temp = node->size;
            node->size = node->size - rightNode->left->size - 1;
            rightNode->size = temp;
            return rightNode;
        }
        else if(height(node->right) - height(node->left) < -1){
            Node* leftNode = node->left;
            node->left = leftNode->right;
            leftNode->right= node;
            int temp = node->size;
            node->size = node->size - leftNode->left->size - 1;
            leftNode->size = temp;
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

    void deleteBrunch(int key){
        root = deleteBrunch(key, root);
    }

    void setTreeWidget(QTreeWidget* widget){
        this->widget = widget;
    }

    void setTree(){
        widget->clear();
        if(root == nullptr){
            return;
        }
        QTreeWidgetItem *item = new QTreeWidgetItem(widget);
        item->setText(0, QString::number(root->key)+'.'+root->value);
        item->addChild(buildTree(root->right, item));
        item->addChild(buildTree(root->left, item));
        widget->addTopLevelItem(item);
    }

    QTreeWidgetItem* buildTree(Node* node, QTreeWidgetItem* parent){
        if(node == nullptr){
            QTreeWidgetItem *item = new QTreeWidgetItem(parent);
            item->setText(0, "NULL");
            return item;
        }
        QTreeWidgetItem *item = new QTreeWidgetItem(parent);
        item->setText(0, QString::number(node->key)+'.'+node->value);
        item->addChild(buildTree(node->right, item));
        item->addChild(buildTree(node->left, item));
        return item;
    }

    Node* deleteBrunch(int key, Node* node){
        if(node == nullptr){
            return nullptr;
        }
        if(key < node->key){
            node->left = deleteBrunch(key, node->left);
        }
        else if(key > node->key){
            node->right = deleteBrunch(key, node->right);
        }
        else if(key == node->key){
            delete node;
            node = nullptr;
            return node;
        }
        while(qAbs(height(node->right) - height(node->left)) > 1){
            node = balance(node);
        }
        return node;
    }
    \
    T* travers(){
        if(size() > 0){
            T* result = new T[size()];
            int index = 0;
            travers(root, result, index);
            return result;
        }
        return nullptr;
    }

    void addBranch(BST* subTree){
        if(contains(subTree->root->key)){

        }
        else{
            root = put(root, subTree->root->key, subTree->root->value);
            Node* node = getParent(subTree->root->key, root);
            if(node->left != nullptr && node->left->key == subTree->root->key){
                delete (node->left);
                node->left = subTree->root;
                node = node->left;
            }
            else if(node->right != nullptr && node->right->key == subTree->root->key){
                delete (node->right);
                node->right = subTree->root;
                node = node->right;
            }
            while(qAbs(height(root->right) - height(root->left)) > 1){
                root = balance(root);
            }
        }
    }

    int ancestor(int key1, int key2){
        if(root == nullptr){
            return -1;
        }
        Node* node = root;
        if(key1 > node->key && key2 > node->key){
            while(key1 > node->key && key2 > node->key){
                node = node->right;
            }
        }
        else if(key1 < node->key && key2 < node->key){
            while(key1 < node->key && key2 < node->key){
                node = node->left;
            }
        }
        return node->key;
    }

private:

    void travers(Node* node, T* result, int &index){
        if(node == nullptr){
            return;
        }
        travers(node->left, result, index);
        result[index] = node->value;
        index++;
        travers(node->left, result, index);
    }

    Node* getParent(int key, Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        if(node->left != nullptr && key < node->left->key){
            return getParent(key, node->left);
        }
        else if(node->right != nullptr && key > node->right->key){
            return getParent(key, node->right);
        }
        return node;
    }
};
#endif // BST_H
