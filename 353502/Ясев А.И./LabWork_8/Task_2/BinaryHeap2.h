#ifndef BINARYHEAP2_H
#define BINARYHEAP2_H

#include <memory>

template<typename T>
class BinaryHeap2
{
private:
    struct Node
    {
        T value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        explicit Node(int64_t value)
            : value(value)
        {}
    };

    std::shared_ptr<Node> _root;
    size_t _size;

private:
    std::shared_ptr<Node> getLastNode();
    void removeLastNode();
    void sift_up(std::shared_ptr<Node> node);
    void sift_down(std::shared_ptr<Node> node);

public:
    BinaryHeap2();
    ~BinaryHeap2();

    void clear();
    void push(T value);
    T pop();
    T &max();
    size_t size();
    bool empty();
};

#endif // BINARYHEAP2_H
