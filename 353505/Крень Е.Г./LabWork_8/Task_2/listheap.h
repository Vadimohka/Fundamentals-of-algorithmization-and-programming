#ifndef LISTHEAP_H
#define LISTHEAP_H

#include "ListNode.h"

class ListHeap
{
private:
    std::shared_ptr<ListNode> root;
    int level;
    int level_i;

    void heapifyUp(std::shared_ptr<ListNode> node);

    void heapifyDown(std::shared_ptr<ListNode> cur);

public:
    ListHeap();

    ~ListHeap();

    void push(long x);;

    long pop();;

    bool empty();

    void clear();

    std::shared_ptr<ListNode> getRoot();
};

#endif // LISTHEAP_H
