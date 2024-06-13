#ifndef BINARYLIST_H
#define BINARYLIST_H

#include <memory>
#include <queue>
#include <string>

template <typename T>
class BinaryList
{
private:

    struct Node
    {
        T data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::weak_ptr<Node> parent;
    };

    std::shared_ptr<Node> root;
    size_t size{0};
    std::shared_ptr<typename BinaryList<T>::Node> lastParent()
    {
        std::queue <std::shared_ptr<Node>> queue;
        queue.push(root);
        std::shared_ptr<Node> temp;

        while(!queue.empty())
        {
            temp = queue.front();
            queue.pop();

            if(temp->left && temp->right){
                queue.push(temp->left);
                queue.push(temp->right);
            }
            else
            {
                break;
            }
        }
        return temp;
    }
    void siftUp(std::shared_ptr<Node> node)
    {
        std::shared_ptr<Node> current = node;
        while (current->parent.lock() != nullptr)
        {
            auto parent = current->parent.lock();
            if (current->data > parent->data)
            {
                swap(current, parent);
                current = parent;
            }
            else
            {
                break;
            }
        }
    }
    void siftDown(std::shared_ptr<Node> node)
    {
        std::shared_ptr<Node> current = node;
        while (current->left != nullptr && current->right != nullptr)
        {
            std::shared_ptr<Node> maxChild = current->left->data > current->right->data ? current->left : current->right;
            if (current->data < maxChild->data)
            {
                swap(current, maxChild);
                current = maxChild;
            }
            else
            {
                break;
            }
        }
    }
    void swap(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2)
    {
        T temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }
    std::string toString(std::shared_ptr<Node> node)
    {
        if (node == nullptr)
        {
            return "";
        }

        std::string result = std::to_string(node->data);

        if (node->left != nullptr)
        {
            result += "-->" + toString(node->left);
        }

        if (node->right != nullptr)
        {
            result += "-->" + toString(node->right);
        }

        return result;
    }
public:
    BinaryList() : root(nullptr){}
    ~BinaryList()
    {
        root = nullptr;
    }
    void insert(T element)
    {
        std::shared_ptr<Node> node = std::make_shared<Node>();
        node->data = element;

        if (root == nullptr)
        {
            root = node;
            size++;
            return;
        }

        auto lpar = lastParent();

        if(lpar->left == nullptr)
        {
            lpar->left = node;
            node->parent = lpar;
        }
        else
        {
            lpar->right = node;
            node->parent = lpar;
        }
        siftUp(node);
    }
    T extractMax()
    {
        if (root == nullptr)
        {
            throw std::runtime_error("Heap is empty");
        }

        T max = root->data;

        std::shared_ptr<Node> lastNode = lastParent();
        if (lastNode->right != nullptr)
        {
            root->data = lastNode->right->data;
            lastNode->right = nullptr;
        }
        else
        {
            root->data = lastNode->left->data;
            lastNode->left = nullptr;
        }

        size--;

        siftDown(root);

        return max;
    }
    T getMax()
    {
        if (root == nullptr)
        {
            throw std::runtime_error("Heap is empty");
        }
        return root->data;
    }
    bool isEmpty()
    {
        return root == nullptr;
    }
    int getSize()
    {
        return size;
    }
    void clear()
    {
        root = nullptr;
        size = 0;
    }
    std::string toString()
    {
        return toString(root);
    }

};

#endif // BINARYLIST_H
