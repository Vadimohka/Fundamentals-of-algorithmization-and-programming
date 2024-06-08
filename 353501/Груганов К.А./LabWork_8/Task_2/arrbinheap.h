#ifndef ARRBINHEAP_H
#define ARRBINHEAP_H
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <vector>
using namespace std;

class Node
{
public:
    int value;
    Node *parent;
    //shared так как куча - дерево
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    Node(int val)
        : value(val)
    {}
};

//мин-куча
class ArrBinHeap
{
private:
    vector<shared_ptr<Node>> heap;

    //проталкивание вверх
    void heapify_up(int index)
    {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            //род элемент должен быть меньше дочернего
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    int parent(int index) { return (index - 1) / 2; }
    int left_child(int index) { return 2 * index + 1; };
    int right_child(int index) { return 2 * index + 2; };

public:
    ArrBinHeap();

    void insert(int value)
    {
        shared_ptr<Node> node = make_shared<Node>(value);
        heap.push_back(node);
        int index = heap.size() - 1;
        heapify_up(index);
    }

    int size() { return heap.size(); }

    void buildHeap(const vector<int> &data)
    {
        for (int i : data) {
            insert(i);
        }
    }

    void clear() { heap.clear(); }

    int extract_min()
    {
        if (heap.size() == 0)
            throw std::runtime_error("Heap is empty");

        int root_value = heap[0]->value;
        heap[0] = heap.back();
        heap.pop_back();

        heapify_down(0);
        return root_value;
    }

    void heapify_down(size_t index)
    {
        size_t smallest = index;
        size_t left = left_child(index);
        size_t right = right_child(index);

        if (left < heap.size() && heap[left]->value < heap[smallest]->value)
            smallest = left;

        if (right < heap.size() && heap[right]->value < heap[smallest]->value)
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapify_down(smallest);
        }
    }
};

#endif // ARRBINHEAP_H
