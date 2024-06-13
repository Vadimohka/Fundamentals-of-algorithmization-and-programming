#ifndef BTS_H
#define BTS_H

struct Node {
    Node(int nKey, const std::string& nValue);
    std::shared_ptr<Node> newNode(int nKey, const std::string& nValue);

    int key;
    std::string value;
    std::shared_ptr<Node> left, right;
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    std::shared_ptr<Node> insert(std::shared_ptr<Node> node, int key, const std::string& value);
    std::shared_ptr<Node> remove(std::shared_ptr<Node> root, int key);
    std::shared_ptr<Node> find(std::shared_ptr<Node> node, int key);
    void inorderTraversal(std::shared_ptr<Node> node);
    void preorderTraversal(std::shared_ptr<Node> node);
    void postorderTraversal(std::shared_ptr<Node> node);

private:
    std::shared_ptr<Node> minValueNode(std::shared_ptr<Node> node);
};

#endif // BTS_H
