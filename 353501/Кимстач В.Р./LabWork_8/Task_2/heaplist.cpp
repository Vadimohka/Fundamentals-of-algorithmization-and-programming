#include <iostream>
#include "HeapList.h"

HeapList::HeapList() {
    root = nullptr;
    _level = 0;
    _number_level = 0;
    _size = 0;
}

void HeapList::siftUp(std::shared_ptr<Node> node) {
    if (node->parent.lock() == nullptr)
        return;

    int parent_value = node->parent.lock()->value;
    int value = node->value;

    if(parent_value < value)
    {
        std::swap(node->value, node->parent.lock()->value);
        siftUp(node->parent.lock());
    }
}

void HeapList::siftDown(std::shared_ptr<Node> node) {
    if(node->left == nullptr && node->right == nullptr)
    {
        return;
    }

    if(node->right == nullptr)
    {
        // one son

        int value = node->value;
        int son_value = node->left->value;
        if(value < son_value)
        {
            std::swap(node->value, node->left->value);
        }

        return;
    }

    int max_value = node->value;
    if(node->left->value > max_value)
    {
        max_value = node->left->value;
    }
    if(node->right->value > max_value)
    {
        max_value = node->right->value;
    }
    if(node->value != max_value)
    {
        if(node->left->value == max_value)
        {
            std::swap(node->value, node->left->value);
            siftDown(node->left);
        }
        else
        {
            std::swap(node->value, node->right->value);
            siftDown(node->right);
        }
    }
}

void HeapList::add(int value) {

    if(_level == 0)
    {
        // empty heap
        root = std::make_shared<Node>();
        root->value = value;
        root->parent.reset();
        root->left = nullptr;
        root->right = nullptr;
        _level ++;
        _size ++;
        return;
    }

    std::cout << "okk add value\n";
    auto node = std::make_shared<Node>();
    node->left = nullptr;
    node->right = nullptr;
    node->value = value;
    std::vector<int> path;
    int cur_index = _number_level;
    for(int i = 0; i < _level; i ++)
    {
        path.push_back(cur_index);
        cur_index /= 2;
    }
    auto cur = root;
    for(int i = path.size() - 1; i >= 0; i --)
    {
        if(i == 0)
        {
            // new
            if(path[i] % 2 == 0)
            {
                cur->left = std::make_shared<Node>();
                cur->left = node;
                node->parent = cur;
                cur = cur->left;
            }
            else
            {
                cur->right = std::make_shared<Node>();
                cur->right = node;
                node->parent = cur;
                cur = cur->right;
            }
        }
        else
        {
            if(path[i] % 2 == 0)
            {
                // left
                cur = cur->left;
            }
            else
            {
                // right
                cur = cur->right;
            }
        }
    }
    _number_level ++;
    if(_number_level == (1 << _level))
    {
        _number_level = 0;
        _level ++;
    }
    _size ++;
    siftUp(cur);
}

int HeapList::getMax() {
    if(_size == 0)
        throw "out of range";
    return root->value;
}

int HeapList::size() {
    return _size;
}

void HeapList::ExtractMax() {
    if(_size == 0)
        return;

    int value = root->value;

    _size --;
    _number_level --;
    if(_number_level < 0)
    {
        _level --;
        _number_level = (1 << _level) - 1;
    }

    if(_size == 0)
    {

        root.reset();
        return;
    }

    std::vector<int> path;
    int cur_index = _number_level;
    for(int i = 0; i < _level; i ++)
    {
        path.push_back(cur_index);
        cur_index /= 2;
    }
    auto cur = root;
    for(int i = path.size() - 1; i >= 0; i --)
    {
        if(path[i] % 2 == 0)
        {
            // left
            cur = cur->left;
        }
        else
        {
            // right
            cur = cur->right;
        }
    }

    std::swap(root->value, cur->value);
    std::shared_ptr<Node> parent = cur->parent.lock();
    if (parent->left == cur) {
        parent->left.reset();
    }
    if (parent->right == cur) {
        parent->right.reset();
    }
    siftDown(root);
}

std::vector<int> HeapList::GetHeap() {
    heap.clear();
    if(_size == 0)
        return heap;
    heap.push_back(root->value);
    GetHeap(root);
    return heap;
}

void HeapList::GetHeap(std::shared_ptr<Node> node) {
    if(node->left == nullptr && node->right == nullptr)
    {
        return;
    }
    if(node->left) {
        std::cout << "parent " << node << " left son " << node->left << std::endl;
        heap.push_back(node->left->value);
    }
    if(node->right) {
        std::cout << "parent " << node << " right son " << node->right << std::endl;
        heap.push_back(node->right->value);
    }
    if(node->left)
        GetHeap(node->left);
    if(node->right)
        GetHeap(node->right);
}

void HeapList::clear() {
    while(_size != 0)
    {
        ExtractMax();
    }
}

void HeapList::findValue(std::shared_ptr<Node> node, int value) {
    if(node->value == value)
    {
        found_node = node;
        return;
    }
    if(node->left)
    {
        if(node->left->value >= value)
            findValue(node->left, value);
    }
    if(node->right)
    {
        if(node->right->value >= value)
            findValue(node->right, value);
    }
}

void HeapList::increaseElement(std::shared_ptr<Node> node, int delta) {
    node->value += delta;
    siftUp(node);
}

void HeapList::decreaseElement(std::shared_ptr<Node> node, int delta) {
    node->value -= delta;
    siftDown(node);
}

void HeapList::increaseValue(int value, int delta) {
    if(_size == 0)
        return;
    found_node = nullptr;
    findValue(root, value);
    if(found_node != nullptr)
    {
        increaseElement(found_node, delta);
    }
}

void HeapList::decreaseValue(int value, int delta) {
    if(_size == 0)
        return;
    found_node = nullptr;
    findValue(root, value);
    if(found_node != nullptr)
    {
        decreaseElement(found_node, delta);
    }
}
