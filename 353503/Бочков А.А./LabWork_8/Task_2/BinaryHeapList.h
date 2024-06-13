#ifndef BINARYHEAPLIST_H
#define BINARYHEAPLIST_H

#include <climits>
#include <memory>
#include <queue>

class BinaryHeapList
{
public:
    struct Node
    {
        int data;
        std::shared_ptr<Node> leftSon;
        std::shared_ptr<Node> rightSon;
        std::weak_ptr<Node> parent;

        Node(int d)
            : data(d)
            , leftSon(nullptr)
            , rightSon(nullptr)
            , parent()
        {}
    };

private:
    void siftDown(std::shared_ptr<Node> node)
    {
        while (node->leftSon != nullptr) {
            auto left = node->leftSon;
            auto right = node->rightSon;
            auto j = left;
            if (right != nullptr && right->data > left->data)
                j = right;
            if (node->data >= j->data)
                break;
            std::swap(node->data, j->data);
            node = j;
        }
    }

    void siftUp(std::shared_ptr<Node> node)
    {
        while (auto parent = node->parent.lock()) {
            if (node->data <= parent->data)
                break;
            std::swap(node->data, parent->data);
            node = parent;
        }
    }

    std::shared_ptr<Node> findInsertionNode()
    {
        std::queue<std::shared_ptr<Node>> q;
        q.push(root);
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            if (current->leftSon == nullptr || current->rightSon == nullptr)
                return current;
            q.push(current->leftSon);
            q.push(current->rightSon);
        }
        return nullptr;
    }

    std::shared_ptr<Node> findLastNode()
    {
        std::queue<std::shared_ptr<Node>> q;
        q.push(root);
        std::shared_ptr<Node> last = nullptr;
        while (!q.empty()) {
            last = q.front();
            q.pop();
            if (last->leftSon != nullptr)
                q.push(last->leftSon);
            if (last->rightSon != nullptr)
                q.push(last->rightSon);
        }
        return last;
    }

public:
    std::shared_ptr<Node> root;

    BinaryHeapList()
        : root(nullptr)
    {}

    void insert(int key)
    {
        if (root == nullptr) {
            root = std::make_shared<Node>(key);
            return;
        }
        auto insertPos = findInsertionNode();
        auto newNode = std::make_shared<Node>(key);
        newNode->parent = insertPos;
        if (insertPos->leftSon == nullptr) {
            insertPos->leftSon = newNode;
        } else {
            insertPos->rightSon = newNode;
        }
        siftUp(newNode);
    }

    int extractMax()
    {
        if (root == nullptr)
            return INT_MAX;
        int max = root->data;
        if (root->leftSon == nullptr && root->rightSon == nullptr) {
            root = nullptr;
            return max;
        }
        auto lastNode = findLastNode();
        root->data = lastNode->data;
        if (auto parent = lastNode->parent.lock()) {
            if (parent->rightSon == lastNode) {
                parent->rightSon = nullptr;
            } else {
                parent->leftSon = nullptr;
            }
        }
        siftDown(root);
        return max;
    }
};

#endif // BINARYHEAPLIST_H
