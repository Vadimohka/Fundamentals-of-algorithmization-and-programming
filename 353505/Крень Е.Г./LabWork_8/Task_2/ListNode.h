#ifndef LISTNODE_H
#define LISTNODE_H

#include <memory>

struct ListNode {
    int data;
    std::weak_ptr<ListNode> parent;
    std::shared_ptr<ListNode> left;
    std::shared_ptr<ListNode> right;
};

#endif // LISTNODE_H
