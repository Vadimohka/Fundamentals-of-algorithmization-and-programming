#ifndef LIST_BINHEAP_H
#define LIST_BINHEAP_H

#include <node.h>

template<typename T>
class List_BinHeap
{
private:
    std::shared_ptr<Node<T>> root;
    int level;
    int level_i;

    void heapifyUp(std::shared_ptr<Node<T>> node)
    {
        if (!node->parent.lock())
        {
            return;
        }

        if (node->value > node->parent.lock()->value)
        {
            std::swap(node->value, node->parent.lock()->value);
            heapifyUp(node->parent.lock());
        }
    }

    void heapifyDown(std::shared_ptr<Node<T>> node)
    {
        std::shared_ptr<Node<T>> next = node;
        T best = node->value;
        if (node->left && node->left->value > best)
        {
            next = node->left;
            best = node->left->value;
        }

        if (node->right && node->right->value > best)
        {
            next = node->right;
        }

        if (next == node)
        {
            return;
        }

        std::swap(next->value, node->value);
        heapifyDown(next);
    }

public:
    List_BinHeap()
    {
        root = nullptr;
        level = 0;
        level_i = 0;
    }

    ~List_BinHeap() {};

    std::shared_ptr<Node<T>> getRoot()
    {
        return root;
    }

    bool empty()
    {
        return root == nullptr;
    }

    void clearHeap()
    {
        root = nullptr;
        level = 0;
        level_i = 0;
    }

    void push(T element)
    {
        if (level == 0)
        {
            root = std::make_shared<Node<T>>();
            root->value = element;
            root->parent.reset();
            root->left = nullptr;
            root->right = nullptr;
            ++level;
            level_i = 0;
            return;
        }

        std::shared_ptr<Node<T>> temp = root;
        for (int i = level - 1; i >= 0; --i)
        {
            if ((level_i & (1 << i)) != 0)
            {
                if (!temp->right)
                {
                    temp->right = std::make_shared<Node<T>>();
                    temp->right->parent = temp;
                }
                temp = temp->right;
            }
            else
            {
                if (!temp->left)
                {
                    temp->left = std::make_shared<Node<T>>();
                    temp->left->parent = temp;
                }
                temp = temp->left;
            }
        }

        temp->value = element;
        ++level_i;
        if (level_i == (1 << level))
        {
            ++level;
            level_i = 0;
        }
        heapifyUp(temp);
    }

    T pop()
    {
        T element = root->value;

        --level_i;
        if (level_i < 0)
        {
            --level;
            level_i = (1 << level) - 1;
        }
        if (!level)
        {
            root.reset();
            return element;
        }

        std::shared_ptr<Node<T>> temp = root;
        for (int i = level - 1; i >= 0; --i)
        {
            if ((level_i & (1 << i)) != 0)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }

        std::swap(temp->value, root->value);
        std::shared_ptr<Node<T>> parent = temp->parent.lock();
        if (parent->left == temp)
        {
            parent->left.reset();
        }
        if (parent->right == temp)
        {
            parent->right.reset();
        }
        heapifyDown(root);
        return element;
    }
};

#endif // LIST_BINHEAP_H
