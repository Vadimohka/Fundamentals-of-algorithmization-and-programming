#ifndef BST_H
#define BST_H

#include <string>
#include <vector>

struct Node {
    int key;
    std::string data;
    Node* left;
    Node* right;

    Node(int k, const std::string& d) : key(k), data(d), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST();
    ~BST();

    void insert(int key, const std::string& data);
    bool search(int key, std::string& data) const;
    void remove(int key);
    void clear();

    std::vector<std::string> inorder() const;
    std::vector<std::string> preorder() const;
    std::vector<std::string> postorder() const;

    int maxDepth() const;

    void balance();

    Node* getRoot() const { return root; }

private:
    Node* root;

    Node* insert(Node* node, int key, const std::string& data);
    Node* search(Node* node, int key) const;
    Node* remove(Node* node, int key);
    Node* findMin(Node* node) const;
    Node* balance(std::vector<Node*>& nodes, int start, int end);

    void inorder(Node* node, std::vector<std::string>& result) const;
    void preorder(Node* node, std::vector<std::string>& result) const;
    void postorder(Node* node, std::vector<std::string>& result) const;

    void storeBSTNodes(Node* node, std::vector<Node*>& nodes);
    int maxDepth(Node* node) const;
    void clear(Node* node);
};

#endif // BST_H
