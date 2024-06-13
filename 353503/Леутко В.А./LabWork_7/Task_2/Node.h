#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>

using namespace std;

struct Node {
    int key;
    string value;
    int height;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    Node(int k, string v) : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
};


#endif // NODE_H
