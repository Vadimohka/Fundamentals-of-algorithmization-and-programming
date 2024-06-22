#ifndef MLBINARYHEAP_H
#define MLBINARYHEAP_H

#include <memory>

template<class T>
class MLBinaryHeap
{
private:
    struct binary_heap_node
    {
        T _value{T()};
        std::weak_ptr<binary_heap_node> _parent;
        std::shared_ptr<binary_heap_node> _left;
        std::shared_ptr<binary_heap_node> _right;
        size_t _leftSize{0};
        size_t _rightSize{0};

        binary_heap_node() = default;

        binary_heap_node(std::weak_ptr<binary_heap_node> parent, T value)
            : _value(value)
            , _parent(parent)
        {}
    };

    void heapifyUp(std::shared_ptr<binary_heap_node> node)
    {
        if (node->_parent.lock() == nullptr) {
            return;
        }

        if (node->_parent.lock()->_value < node->_value) {
            std::swap(node->_parent.lock()->_value, node->_value);

            heapifyUp(node->_parent.lock());
        }
    }

    void heapifyDown(std::shared_ptr<binary_heap_node> node)
    {
        auto greatest = node;

        if (node->_left && node->_left->_value > greatest->_value) {
            greatest = node->_left;
        }

        if (node->_right && node->_right->_value > greatest->_value) {
            greatest = node->_right;
        }

        if (greatest != node) {
            std::swap(greatest->_value, node->_value);
            heapifyDown(greatest);
        }
    }

    std::shared_ptr<binary_heap_node> _head;

public:
    void push(T value)
    {
        if (!_head) {
            _head = std::make_shared<binary_heap_node>(std::weak_ptr<binary_heap_node>(), value);
            return;
        }

        std::shared_ptr<binary_heap_node> curr = _head;
        std::weak_ptr<binary_heap_node> prev = std::weak_ptr<binary_heap_node>();

        while (curr) {
            prev = curr;

            if (curr->_leftSize < curr->_rightSize) {
                curr->_leftSize++;
                if (!curr->_left) {
                    curr->_left = std::make_shared<binary_heap_node>(prev, value);
                    curr = curr->_left;
                    break;
                }
                curr = curr->_left;
            } else {
                curr->_rightSize++;
                if (!curr->_right) {
                    curr->_right = std::make_shared<binary_heap_node>(prev, value);
                    curr = curr->_right;
                    break;
                }
                curr = curr->_right;
            }
        }

        heapifyUp(curr);
    }

    T top()
    {
        if (!_head) {
            throw "Underflow";
        }

        return _head->_value;
    }

    void pop()
    {
        if (!_head) {
            throw "Underflow";
        }

        std::shared_ptr<binary_heap_node> curr = _head;

        while (curr) {
            if (curr->_leftSize < curr->_rightSize) {
                if (!curr->_right) {
                    break;
                }
                curr->_rightSize--;
                curr = curr->_right;
            } else {
                if (!curr->_left) {
                    break;
                }

                curr->_leftSize--;
                curr = curr->_left;
            }
        }

        _head->_value = curr->_value;

        if (curr == _head)
        {
            _head.reset();
            return;
        }

        std::weak_ptr<binary_heap_node> parent = curr->_parent;

        if (parent.lock()->_left == curr)
        {
            parent.lock()->_left.reset();
        }
        else
        {
            parent.lock()->_right.reset();
        }

        heapifyDown(_head);
    }

    bool empty() { return !_head; }
};
\
#endif // MLBINARYHEAP_H
