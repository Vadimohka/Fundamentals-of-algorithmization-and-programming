#ifndef HEAPLIST_H
#define HEAPLIST_H

#include <memory>
#include <stdexcept>

#if defined(_WIN32) || defined(_WIN64)
#ifdef BUILD_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif
#else
#define DLL_EXPORT
#endif

class DLL_EXPORT HeapList {

public:
    HeapList();

    void insert(int key);
    int extractMax();
    int getMax() const;
    bool isEmpty() const;

private:
    struct Node {
        int key;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::shared_ptr<Node> next;  // For list structure

        Node(int k) : key(k), parent(), left(nullptr), right(nullptr), next(nullptr) {}
    };

    std::shared_ptr<Node> root;
    std::shared_ptr<Node> head;  // Head of the list
    std::shared_ptr<Node> tail;  // Tail of the list

    void heapifyUp(std::shared_ptr<Node> node);
    void heapifyDown(std::shared_ptr<Node> node);

    std::shared_ptr<Node> getLastNode() const;
    void removeLastNode();
};

#endif // HEAPLIST_H
