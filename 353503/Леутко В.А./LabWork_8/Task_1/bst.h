#ifndef BST_H
#define BST_H

#include <memory>
#include <string>

struct Node {
    Node(int nKey, const std::string& nValue);
    static std::shared_ptr<Node> newNode(int nKey, const std::string& nValue);

    int key;
    std::string value;
    std::shared_ptr<Node> left, right;
};

class BST {
public:
    BST();
    ~BST();

    std::shared_ptr<Node> insert(std::shared_ptr<Node> node, int key, const std::string& value);
    std::shared_ptr<Node> insertAtPosition(std::shared_ptr<Node> root, int key, const std::string& value, int position);
    std::shared_ptr<Node> remove(std::shared_ptr<Node> node, int key);
    std::shared_ptr<Node> find(std::shared_ptr<Node> node, int key);
    std::shared_ptr<Node> getMin(std::shared_ptr<Node> node);
    std::shared_ptr<Node> getMax(std::shared_ptr<Node> node);
    void inorderTraversal(std::shared_ptr<Node> node);
    void preorderTraversal(std::shared_ptr<Node> node);
    void postorderTraversal(std::shared_ptr<Node> node);

    std::shared_ptr<Node> insertSubtree(std::shared_ptr<Node> root, std::shared_ptr<Node> subtree, int position);
    std::shared_ptr<Node> insertBranch(std::shared_ptr<Node> root, std::shared_ptr<Node> branch, int position);
    std::shared_ptr<Node> removeSubtree(std::shared_ptr<Node> root, int position);
    std::shared_ptr<Node> removeBranch(std::shared_ptr<Node> root, int position);
    //std::shared_ptr<Node> lca(std::shared_ptr<Node> root, int n1, int n2);
};

#endif // BST_H
