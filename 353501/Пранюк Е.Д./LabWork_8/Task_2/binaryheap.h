#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsEllipseItem>

#include <iostream>
#include <memory>
#include <string>
#include <vector>

template <typename T>
class BinaryHeap
{
private:
    std::unique_ptr<std::vector<T>> heap;
    size_t size = 0;
    void siftUp(int index);
    void siftDown(int index);
    void swap(int index1, int index2);
public:
    BinaryHeap();
    ~BinaryHeap();

    void insert(T element);
    T extractMax();
    T getMax();
    void remove(int index);
    void changePriority(int index, T element);
    void print();
    bool isEmpty();
    int getSize();
    void clear()
    {
        heap->clear();
        size = 0;
    };
    void drawTree(QGraphicsScene* scene, int x, int y, int level, int index = 0);
    std::string toString();

};

template<typename T>
BinaryHeap<T>::BinaryHeap() : heap(std::make_unique<std::vector<T>>())
{}

template<typename T>
BinaryHeap<T>::~BinaryHeap()
{
    heap = nullptr;
}

template<typename T>
void BinaryHeap<T>::insert(T element)
{
    heap->push_back(element);
    siftUp(heap->size() - 1);
    size++;
}

template<typename T>
T BinaryHeap<T>::extractMax()
{
    if (heap->empty())
    {
        throw std::runtime_error("Heap is empty");
    }
    T max = heap->at(0);
    heap->at(0) = heap->at(heap->size() - 1);
    heap->pop_back();
    size--;
    siftDown(0);
    return max;
}

template<typename T>
T BinaryHeap<T>::getMax()
{
    if (heap->empty())
    {
        throw std::runtime_error("Heap is empty");
    }
    return heap->at(0);
}

template<typename T>
void BinaryHeap<T>::remove(int index)
{
    if (index < 0 || index >= heap->size())
    {
        throw std::runtime_error("Index out of bounds");
    }
    heap->at(index) = heap->at(heap->size() - 1);
    heap->pop_back();
    siftDown(index);
    size--;
}

template<typename T>
void BinaryHeap<T>::changePriority(int index, T element)
{
    if (index < 0 || index >= heap->size())
    {
        throw std::runtime_error("Index out of bounds");
    }
    T old = heap->at(index);
    heap->at(index) = element;
    if (element > old)
    {
        siftUp(index);
    }
    else
    {
        siftDown(index);
    }
}

template<typename T>
void BinaryHeap<T>::print()
{
    for (int i = 0; i < heap->size(); i++)
    {
        std::cout << heap->at(i) << " ";
    }
    std::cout << std::endl;
}

template<typename T>
bool BinaryHeap<T>::isEmpty()
{
    return heap->empty();
}

template<typename T>
int BinaryHeap<T>::getSize()
{
    return size;
}

template<typename T>
std::string BinaryHeap<T>::toString()
{
    std::string result = "";
    for (int i = 0; i < heap->size(); i++)
    {
        result += std::to_string(heap->at(i)) + " ";
    }
    return result;
}

template<typename T>
void BinaryHeap<T>::siftUp(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap->at(index) <= heap->at(parent))
        {
            break;
        }
        swap(index, parent);
        index = parent;
    }
}

template<typename T>
void BinaryHeap<T>::siftDown(int index)
{
    while (2 * index + 1 < heap->size())
    {
        int maxChild = 2 * index + 1;
        if (maxChild + 1 < heap->size() && heap->at(maxChild + 1) > heap->at(maxChild))
        {
            maxChild++;
        }
        if (heap->at(index) >= heap->at(maxChild))
        {
            break;
        }
        swap(index, maxChild);
        index = maxChild;
    }
}

template<typename T>
void BinaryHeap<T>::swap(int index1, int index2)
{
    T temp = heap->at(index1);
    heap->at(index1) = heap->at(index2);
    heap->at(index2) = temp;
}

template <typename T>
void BinaryHeap<T>::drawTree(QGraphicsScene* scene, int x, int y, int level, int index)
{
    if (index >= heap->size())
    {
        return;
    }

    float tab = 100;
    if(size > 20)
    {
        tab *= (float)size / 20.0;
    }
    int offset = tab / (level + 1);  // Adjust this value to change the spacing between nodes

    QGraphicsEllipseItem* ellipse = scene->addEllipse(x, y, 20, 20);
    ellipse->setBrush(QColor(QRandomGenerator::global()->bounded(200),QRandomGenerator::global()->bounded(210),QRandomGenerator::global()->bounded(200)));
    QGraphicsTextItem* text = scene->addText(QString::number((*heap)[index]));
    text->setDefaultTextColor(Qt::white);
    text->setPos(x+2, y-1);  // Adjust these values to center the text in the ellipse

    // Draw left child
    int leftIndex = 2*index + 1;
    if (leftIndex < heap->size())
    {
        scene->addLine(x+10, y+20, x-offset+10, y+40);  // Draw line to left child
        drawTree(scene, x-offset, y+40, level+1, leftIndex);
    }

    // Draw right child
    int rightIndex = 2*index + 2;
    if (rightIndex < heap->size())
    {
        scene->addLine(x+10, y+20, x+offset+10, y+40);  // Draw line to right child
        drawTree(scene, x+offset, y+40, level+1, rightIndex);
    }
}

#endif // BINARYHEAP_H
