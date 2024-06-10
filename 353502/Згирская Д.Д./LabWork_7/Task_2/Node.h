//
// Created by zgdarya on 5/28/24.
//

#ifndef L7_T2_NODE_H
#define L7_T2_NODE_H

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


#endif //L7_T2_NODE_H
