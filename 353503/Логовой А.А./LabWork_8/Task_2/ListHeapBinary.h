#ifndef LISTHEAPBINARY_H
#define LISTHEAPBINARY_H

#include <memory>
#include <stdexcept>

template <typename T>
class ListBinaryHeap {
private:
    struct Node {
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::weak_ptr<Node> parent;
        T value;

        Node(const T& value)
            : value(value), left(nullptr), right(nullptr) {}
    };

    std::shared_ptr<Node> root;

    void heapify_down(std::shared_ptr<Node> node) {
        if (!node) {
            return;
        }

        auto largest = node;
        if (node->left && node->left->value > largest->value) {
            largest = node->left;
        }
        if (node->right && node->right->value > largest->value) {
            largest = node->right;
        }

        if (largest != node) {
            std::swap(node->value, largest->value);
            heapify_down(largest);
        }
    }

    void heapify_up(std::shared_ptr<Node> node) {
        if (!node) {
            return;
        }

        auto parent = node->parent.lock();
        if (parent && node->value > parent->value) {
            std::swap(node->value, parent->value);
            heapify_up(parent);
        }
    }

public:
    ListBinaryHeap() = default;
    ~ListBinaryHeap() = default;

    void push(const T& element) {
        auto new_node = std::make_shared<Node>(element);
        if (!root) {
            root = new_node;
        } else {
            std::shared_ptr<Node> current = root;
            while (true) {
                if (element > current->value) {
                    if (!current->right) {
                        current->right = new_node;
                        new_node->parent = current;
                        break;
                    } else {
                        current = current->right;
                    }
                } else {
                    if (!current->left) {
                        current->left = new_node;
                        new_node->parent = current;
                        break;
                    } else {
                        current = current->left;
                    }
                }
            }
            heapify_up(new_node);
        }
    }

    T top() const {
        if (!root) {
            throw std::out_of_range("Heap is empty");
        }
        return root->value;
    }

    void pop() {
        if (!root) {
            return;
        }

        if (!root->left && !root->right) {
            root = nullptr;
            return;
        }

        auto last_node = get_last_node(root);
        root->value = last_node->value;

        if (last_node == root->left) {
            root->left = nullptr;
        }
        else
        {
            auto parent = last_node->parent.lock();
            if (parent->left == last_node) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        }

        heapify_down(root);
    }

private:
    std::shared_ptr<Node> get_last_node(std::shared_ptr<Node> node) {
        if (!node->right) {
            return node->left ? get_last_node(node->left) : node;
        }
        return get_last_node(node->right);
    }
};

#endif // LISTHEAPBINARY_H
