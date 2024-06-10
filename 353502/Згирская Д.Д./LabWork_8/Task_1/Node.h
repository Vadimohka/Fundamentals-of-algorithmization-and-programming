//
// Created by zgdarya on 6/5/24.
//

#ifndef L8_T1_NODE_H
#define L8_T1_NODE_H


#define longl long

class Node {
public:
    Node* left;
    Node* right;
    longl value;
    longl height;

    Node();
    Node(longl it);

    static void change(Node* node_1, Node* node_2);

    //void operator=(Node& other);
};


#endif //L8_T1_NODE_H
