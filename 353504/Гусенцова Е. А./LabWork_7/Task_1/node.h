#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    std::string data;
    Node* next;
    Node* prev;

    Node(const std::string& data) : data(data), next(nullptr), prev(nullptr) {}
};

#endif // NODE_H
