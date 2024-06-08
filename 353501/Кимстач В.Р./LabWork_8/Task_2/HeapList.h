#ifndef TASK2_HEAPLIST_H
#define TASK2_HEAPLIST_H


#include <cstddef>
#include <vector>
#include <memory>

class HeapList {
    size_t _level = 0;
    int _number_level = 0;
    size_t _size = 0;

    std::vector<int> heap;

    struct Node
    {
        int value;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };

    std::shared_ptr<Node> root;
    std::shared_ptr<Node> found_node;

    void siftUp(std::shared_ptr<Node> node);
    void siftDown(std::shared_ptr<Node> node);

    void findValue(std::shared_ptr<Node> node, int value);

    void GetHeap(std::shared_ptr<Node> node);

public:
    HeapList();

    void add(int value);
    int getMax();
    void ExtractMax();
    void increaseElement(std::shared_ptr<Node> node, int delta);
    void decreaseElement(std::shared_ptr<Node> node, int delta);

    void increaseValue(int value, int delta);
    void decreaseValue(int value, int delta);

    int size();
    void clear();
    std::vector<int> GetHeap();

};


#endif //TASK2_HEAPLIST_H
