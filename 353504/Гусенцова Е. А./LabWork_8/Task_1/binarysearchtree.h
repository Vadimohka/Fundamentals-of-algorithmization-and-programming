#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "node.h"
#include <string>
#include <vector>

class BinarySearchTree {
private:
    Node* root;

    Node* add(Node* node, int value, std::string& message);
    Node* remove(Node* node, int value, std::string& message);
    Node* find(Node* node, int value);
    void traverse(Node* node, std::vector<int>& elements);
    Node* findLCA(Node* node, int n1, int n2);

public:
    BinarySearchTree() : root(nullptr) {}

    void add(int value);
    void remove(int value);
    Node* find(int value);
    std::vector<int> traverse();
    Node* findLCA(int n1, int n2);

    void insertSubtree(Node* subtree);
    void removeSubtree(Node* subtree);

    std::string getMessageForAdd(int value);
    std::string getMessageForRemove(int value);
    std::string getMessageForInsertSubtree(Node* subtree);
    std::string getMessageForRemoveSubtree(Node* subtree);

    void insertAtPosition(int parentValue, int value, bool asLeftChild);

    void insertBranch(Node* branch, int parentValue, bool asLeftChild);
    void removeBranch(int branchValue);
};

#endif // BINARYSEARCHTREE_H
