#include "listheap.h"

void ListHeap::heapifyUp(std::shared_ptr<ListNode> node) {
    if (node->parent.lock() == nullptr)
        return;

    if (node->data > node->parent.lock()->data) {
        std::swap(node->data, node->parent.lock()->data);
        heapifyUp(node->parent.lock());
    }
}

void ListHeap::heapifyDown(std::shared_ptr<ListNode> cur) {
    std::shared_ptr<ListNode> nextNode = cur;
    long best = cur->data;
    if (cur->left) {
        if (cur->left->data > best) {
            nextNode = cur->left;
            best = cur->left->data;
        }
    }

    if (cur->right) {
        if (cur->right->data > best) {
            nextNode = cur->right;
        }
    }

    if (nextNode == cur)
        return;

    std::swap(nextNode->data, cur->data);
    heapifyDown(nextNode);
}

ListHeap::ListHeap() {
    root = nullptr;
    level = 0;
    level_i = 0;
}

ListHeap::~ListHeap() {}

void ListHeap::push(long x) {
    if (level == 0) {
        root = std::make_shared<ListNode>();
        root->data = x;
        root->parent.reset();
        root->left = nullptr;
        root->right = nullptr;

        level++;
        level_i = 0;
        return;
    }

    std::shared_ptr<ListNode> cur = root;
    for (int i = level - 1; i >= 0; i--) {
        if ((level_i & (1 << i)) != 0) {
            if (cur->right == nullptr) {
                cur->right = std::make_shared<ListNode>();
                cur->right->parent = cur;
            }
            cur = cur->right;
        } else {
            if (cur->left == nullptr) {
                cur->left = std::make_shared<ListNode>();
                cur->left->parent = cur;
            }
            cur = cur->left;
        }
    }

    cur->data = x;
    ++level_i;

    if (level_i == (1 << level)) {
        level++;
        level_i = 0;
    }

    heapifyUp(cur);
}

long ListHeap::pop() {

    long res = root->data;

    --level_i;
    if (level_i < 0) {
        --level;
        level_i = (1 << level) - 1;
    }

    if (level == 0) {
        root.reset();
        return res;
    }

    std::shared_ptr<ListNode> cur = root;
    for (int i = level - 1; i >= 0; i--) {
        if ((level_i & (1 << i)) != 0) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }

    std::swap(cur->data, root->data);
    std::shared_ptr<ListNode> par = cur->parent.lock();
    if (par->left == cur) {
        par->left.reset();
    }
    if (par->right == cur) {
        par->right.reset();
    }
    heapifyDown(root);

    return res;
}

bool ListHeap::empty() { return root == nullptr; }

void ListHeap::clear() { root = nullptr; }

std::shared_ptr<ListNode> ListHeap::getRoot() {
    return root;
}
