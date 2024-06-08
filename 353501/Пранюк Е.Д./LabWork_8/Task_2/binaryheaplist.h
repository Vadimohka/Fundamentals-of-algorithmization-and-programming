#ifndef BINARYHEAPLIST_H
#define BINARYHEAPLIST_H


#include <memory>
#include <queue>
#include <string>

template <typename T>
class BinaryHeapList
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
    std::shared_ptr<Node> lastParent();
    void siftUp(std::shared_ptr<Node> node);
    void siftDown(std::shared_ptr<Node> node);
    void swap(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2);
    std::string toString(std::shared_ptr<Node> node);
public:
    BinaryHeapList();
    ~BinaryHeapList();

    void insert(T element);
    T extractMax();
    T getMax();
    bool isEmpty();
    int getSize();
    void clear();
    std::string toString();

};

template<typename T>
BinaryHeapList<T>::BinaryHeapList() : root(nullptr)
{}

template<typename T>
BinaryHeapList<T>::~BinaryHeapList()
{
    root = nullptr;
}

template<typename T>
void BinaryHeapList<T>::insert(T element)
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


template<typename T>
T BinaryHeapList<T>::extractMax()
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

template<typename T>
T BinaryHeapList<T>::getMax()
{
    if (root == nullptr)
    {
        throw std::runtime_error("Heap is empty");
    }
    return root->data;
}

template<typename T>
void BinaryHeapList<T>::siftUp(std::shared_ptr<Node> node)
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

template<typename T>
void BinaryHeapList<T>::siftDown(std::shared_ptr<Node> node)
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

template<typename T>
void BinaryHeapList<T>::swap(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2)
{
    T temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

template<typename T>
bool BinaryHeapList<T>::isEmpty()
{
    return root == nullptr;
}

template<typename T>
int BinaryHeapList<T>::getSize()
{
    return size;
}

template<typename T>
void BinaryHeapList<T>::clear()
{
    root = nullptr;
    size = 0;
}

template<typename T>
std::string BinaryHeapList<T>::toString()
{
    return toString(root);
}

template<typename T>
std::string BinaryHeapList<T>::toString(std::shared_ptr<Node> node)
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

template <typename T>
std::shared_ptr<typename BinaryHeapList<T>::Node> BinaryHeapList<T>::lastParent()
{
    std::queue <std::shared_ptr<Node>> q;
    q.push(root);
    std::shared_ptr<Node> temp;

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->left && temp->right){
            q.push(temp->left);
            q.push(temp->right);
        }
        else
        {
            break;
        }
    }
    return temp;
}

#endif // BINARYHEAPLIST_H
