#ifndef HEAPLIST_H
#define HEAPLIST_H

#include <memory>
#include <queue>
#include <stdexcept>

#include <QString>

template <typename T>
struct Node {
    T data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    std::weak_ptr<Node> parent;

    Node(T value) : data(value), left(nullptr), right(nullptr), parent() {}
};

template <typename T>
class BinaryHeapList {
public:
    BinaryHeapList() : root(nullptr), size(0) {}
    ~BinaryHeapList() { clear(); }

    void insert(T element);

    void remove(T element);

    T extractMax();

    T getMax();

    bool isEmpty();

    int getSize() { return size; }

    void clear();

    QString inOrder();

    std::string toString() { return toString(root); }

private:
    std::shared_ptr<Node<T>> root;
    size_t size{0};

    std::shared_ptr<Node<T>> lastParent();

    void heapifyUp(std::shared_ptr<Node<T>> node);

    void heapifyDown(std::shared_ptr<Node<T>> node);

    std::string toString(std::shared_ptr<Node<T>> node);
};

template<typename T>
std::shared_ptr<Node<T> > BinaryHeapList<T>::lastParent()
{
    if (!root) return nullptr;
    std::queue<std::shared_ptr<Node<T>>> q;
    q.push(root);

    std::shared_ptr<Node<T>> parentNode = nullptr;
    while (!q.empty()) {
        parentNode = q.front();
        q.pop();

        if (!parentNode->left || !parentNode->right) break;

        if (parentNode->left) q.push(parentNode->left);
        if (parentNode->right) q.push(parentNode->right);
    }
    return parentNode;
}

template<typename T>
void BinaryHeapList<T>::heapifyUp(std::shared_ptr<Node<T> > node)
{
    while (auto parent = node->parent.lock()) {
        if (node->data > parent->data) {
            std::swap(node->data, parent->data);
            node = parent;
        } else {
            break;
        }
    }
}

template<typename T>
void BinaryHeapList<T>::heapifyDown(std::shared_ptr<Node<T> > node)
{
    while (node) {
        auto left = node->left;
        auto right = node->right;
        std::shared_ptr<Node<T>> largest = node;

        if (left && left->data > largest->data) {
            largest = left;
        }

        if (right && right->data > largest->data) {
            largest = right;
        }

        if (largest != node) {
            std::swap(node->data, largest->data);
            node = largest;
        } else {
            break;
        }
    }
}

template<typename T>
std::string BinaryHeapList<T>::toString(std::shared_ptr<Node<T> > node)
{
    if (!node) return "";
    std::string result = std::to_string(node->data) + " ";
    result += toString(node->left);
    result += toString(node->right);
    return result;
}

template<typename T>
void BinaryHeapList<T>::insert(T element)
{
    auto newNode = std::make_shared<Node>(element);
    if (!root) {
        root = newNode;
    } else {
        auto parentNode = lastParent();
        if (!parentNode->left) {
            parentNode->left = newNode;
        } else {
            parentNode->right = newNode;
        }
        newNode->parent = parentNode;
    }
    size++;
    heapifyUp(newNode);
}

template<typename T>
void BinaryHeapList<T>::remove(T element)
{
    if (!root) throw std::runtime_error("Heap is empty");

    if (root->data == element) {
        extractMax();
        return;
    }

    std::queue<std::shared_ptr<Node<T>>> q;
    q.push(root);

    std::shared_ptr<Node<T>> nodeToRemove = nullptr;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        if (node->data == element) {
            nodeToRemove = node;
            break;
        }

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    if (!nodeToRemove) throw std::runtime_error("Element not found");

    nodeToRemove->data = root->data;
    extractMax();
}

template<typename T>
T BinaryHeapList<T>::extractMax()
{
    if (!root) throw std::runtime_error("Heap is empty");

    T maxValue = root->data;
    if (size == 1) {
        root = nullptr;
    } else {
        auto parentNode = lastParent();
        std::shared_ptr<Node<T>> lastNode;

        if (parentNode->right) {
            lastNode = parentNode->right;
            parentNode->right = nullptr;
        } else {
            lastNode = parentNode->left;
            parentNode->left = nullptr;
        }

        root->data = lastNode->data;
        heapifyDown(root);
    }
    size--;
    return maxValue;
}

template<typename T>
T BinaryHeapList<T>::getMax()
{
    if (!root) throw std::runtime_error("Heap is empty");
    return root->data;
}

template<typename T>
bool BinaryHeapList<T>::isEmpty()
{
    return size == 0;
}

template<typename T>
void BinaryHeapList<T>::clear()
{
    root = nullptr;
    size = 0;
}

template<typename T>
QString BinaryHeapList<T>::inOrder()
{
    return QString::fromStdString(toString(root));
}

#endif // HEAPLIST_H
