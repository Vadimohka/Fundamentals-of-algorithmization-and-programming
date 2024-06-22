#include "binarytree.h"

BinaryTree::BinaryTree()
{
    root = nullptr;
}

void BinaryTree::Add_element(QString str, int key){
    root = Get_node_to_add(root, str, key);
}

Node* BinaryTree::Get_node_to_add(Node* &node, QString value, int key){

    if(node == nullptr){
        return new Node(value, key);
    }

    if(key < node -> key){

        node -> left = Get_node_to_add(node -> left, value, key);

    }

    else if (key > node -> key){
        node -> right = Get_node_to_add(node -> right, value, key);
    }


    return node;
}

int BinaryTree::Get_tree_size(){
    return Get_nodes_count(root);
}

int BinaryTree::Get_nodes_count(Node* &node){
    if(node == nullptr){
        return 0;
    }

    return 1 + Get_nodes_count(node -> left) + Get_nodes_count(node -> right);
}


QString BinaryTree::Info_from_key(int key){

    Node* node = Get_node(root, key);

    if(node == nullptr){
        return "Not node with this key";
    }
    else{
        return node -> value;
    }
}


Node* BinaryTree::Get_node(Node* &node, int key){

    if(node == nullptr){
        return nullptr;
    }

    if(node -> key == key){
        return node;
    }

    else if(node -> key < key){
        return Get_node(node -> right, key);

    }
    else {
        return Get_node(node -> left, key);
    }

}

void BinaryTree::Delete_information_from_key(int key){

    root = Delete_node(root, key);
}

Node* BinaryTree::Delete_node(Node* node,int key){

    if(node == nullptr){
        QMessageBox::warning(nullptr, "Предупреждение", "Такого элемента нет");
        return nullptr;
    }
    if(key < node -> key){
        node -> left = Delete_node(node -> left, key);
    }
    else if(key > node -> key){
        node -> right = Delete_node(node -> right, key);
    }
    else{
        if(node -> left == nullptr && node -> right == nullptr){

            delete node;
            return nullptr;
        }

        if(node -> left == nullptr && node -> right != nullptr){

            Node* temp = node -> right;
            delete node;

            return temp;
        }

        if(node -> left != nullptr && node -> right == nullptr){

            Node* temp = node -> left;
            delete node;

            return temp;
        }

        Node* successor = Find_min_node(node -> right);

        node -> key = successor -> key;
        node -> value = successor -> value;

        node -> right = Delete_node(node -> right, successor -> key);
    }

    return node;
}

Node* BinaryTree::Find_min_node(Node* node){
    while(node -> left){
        node = node -> left;
    }
    return node;
}

int BinaryTree::Get_right_node_nodes_count(){
    int result = 0;
    if(root != nullptr){
        result = Get_nodes_count(root -> right);
    }
    return result;
}


Node* BinaryTree::Rotate_right(Node* node) {
    Node* new_root = node -> left;

    node -> left = new_root -> right;
    new_root -> right = node;

    return new_root;
}


Node* BinaryTree::Rotate_left(Node* node){
    Node* new_root = node -> right;

    node -> right = new_root -> left;

    new_root -> left = node;

    return new_root;

}

int BinaryTree::Get_balance_factor(Node* node){
    if(!node){
        return 0;
    }
    return Get_nodes_count(node -> left) - Get_nodes_count(node -> right);
}

Node* BinaryTree::Balance(Node* node){

    if(!node){
        return nullptr;
    }

    int balance_factor = Get_balance_factor(node);

    if(balance_factor > 1){

        if(Get_balance_factor(node -> left) >= 0){
            return Rotate_right(node);
        }
        else{
            node -> left = Rotate_left(node -> left);
            return Rotate_right(node);
        }
    }
    else if(balance_factor < -1){

        if (Get_balance_factor(node->right) <= 0) {

            return Rotate_left(node);
        }

        else {
            node -> right = Rotate_right(node -> right);
            return Rotate_left(node);
        }
    }

    node -> left = Balance(node -> left);
    node -> right = Balance(node -> right);

    return node;
}

void BinaryTree::Balance_tree(){


    while(abs(Get_balance_factor(root)) > 1){

        root = Balance(root);
    }
}


void BinaryTree::Debug(Node* node){
    if (node == nullptr) {
        return;
    }

    qDebug() << "Node key" << node -> key;


    if (node -> left) {
        qDebug() << "Левый потомок: " << node -> left -> key;
    }
    else {
        qDebug() << "Левый потомок: NULL";
    }

    if (node -> right) {
        qDebug() << "Правый потомок: " << node -> right -> key;
    }
    else {
        qDebug() << "Правый потомок: NULL";
    }



    qDebug() << '\n';


    Debug(node ->left);

    Debug(node->right);

}


void BinaryTree::Get_all_nodes(Node* node, QList<Node*> &list){
    if(node){

        list.append(node);

        Get_all_nodes(node -> left, list);
        Get_all_nodes(node -> right, list);
    }


}

void BinaryTree::Debug_tree() {
    Debug(root);
}
