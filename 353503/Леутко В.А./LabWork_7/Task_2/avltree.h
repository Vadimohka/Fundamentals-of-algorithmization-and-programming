#ifndef AVLTREE_H
#define AVLTREE_H

#include "Node.h"
#include <memory>

using namespace std;

class AVLTree {
public:
    static shared_ptr<Node> insert(shared_ptr<Node> node, int key, string value);
    static shared_ptr<Node> deleteNode(shared_ptr<Node> root, int key);
    static shared_ptr<Node> findNode(shared_ptr<Node> root, int key);

    static int countNodesInLeftSubtree(std::shared_ptr<Node> node);
private:
    static int getHeight(shared_ptr<Node> node);
    static int max(int a, int b);
    static shared_ptr<Node> rightRotate(shared_ptr<Node> node);
    static shared_ptr<Node> leftRotate(shared_ptr<Node> node);
    static int getBalance(shared_ptr<Node> node);
    static shared_ptr<Node> minValueNode(shared_ptr<Node> node);
};

#endif // AVLTREE_H
