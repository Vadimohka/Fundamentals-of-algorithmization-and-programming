#ifndef BINARYHEAPLIST_H
#define BINARYHEAPLIST_H

#include <memory>
#include <vector>
#include <stdexcept>

class BinaryHeapList {
public:
    BinaryHeapList();
    void insert(int value);
    int extractMax();
    int getMax() const;
    bool isEmpty() const;
    int at(int index) const {
        if (index < 0 || index >= nodes.size()) {
            throw std::out_of_range("Index out of range");
        }

        std::shared_ptr<Node> nodePtr = nodes[index].lock(); // Attempt to obtain a shared_ptr from the weak_ptr
        if (!nodePtr) {
            throw std::runtime_error("Node is no longer valid"); // If weak_ptr is expired, throw an exception
        }

        return nodePtr->value; // Return the value stored in the node
    }
    int size() const {
        return nodes.size();
    }


private:
    struct Node {
        int value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::weak_ptr<Node> parent;

        Node(int val) : value(val), left(nullptr), right(nullptr), parent() {}
    };

    std::shared_ptr<Node> root;
    std::vector<std::weak_ptr<Node>> nodes;

    void heapifyUp(std::shared_ptr<Node> node);
    void heapifyDown(std::shared_ptr<Node> node);
    std::shared_ptr<Node> getLastNode() const;
    void removeLastNode();
};

#endif // BINARYHEAPLIST_H
