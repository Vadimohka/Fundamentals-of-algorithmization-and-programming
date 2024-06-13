#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <QList>
#include <QPair>
#include <QDebug>
#include <QMessageBox>

#include "node.h"

class BinaryTree
{    

private:
    Node* Get_node_to_add(Node* &node, QString, int);
    int Get_nodes_count(Node* &);

    Node* Get_node(Node* & node,int key);

    Node* Delete_node(Node* node, int key);

    Node* Find_min_node(Node* node);

    Node* Rotate_left(Node*);
    Node* Rotate_right(Node*);

    Node* Balance(Node* node);

    int Get_balance_factor(Node* node);
    void Debug(Node* node);


public:
    BinaryTree();

    Node* root;

    void Add_element(QString name, int key);

    int Get_tree_size();

    QString Info_from_key(int key);

    void Delete_information_from_key(int key);

    int Get_right_node_nodes_count();

    void Balance_tree();

    void Get_all_nodes(Node* node,  QList<Node*> &);

    void Debug_tree();

};

#endif // BINARYTREE_H
