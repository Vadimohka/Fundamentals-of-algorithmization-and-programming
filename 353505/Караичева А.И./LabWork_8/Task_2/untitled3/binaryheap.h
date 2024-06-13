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
    void siftUp(int index)
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
    void siftDown(int index)
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
    void swap(int index1, int index2)
    {
        T temp = heap->at(index1);
        heap->at(index1) = heap->at(index2);
        heap->at(index2) = temp;
    }
public:
    BinaryHeap() : heap(std::make_unique< std::vector<T> >() ){}
    ~BinaryHeap()
    {
        heap = nullptr;
    }
    void insert(T element)
    {
        heap->push_back(element);
        siftUp(heap->size() - 1);
        size++;
    }
    T extractMax()
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
    T getMax()
    {
        if (heap->empty())
        {
            throw std::runtime_error("Heap is empty");
        }
        return heap->at(0);
    }
    void remove(int index)
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
    void changePriority(int index, T element)
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
    void print()
    {
        for (int i = 0; i < heap->size(); i++)
        {
            std::cout << heap->at(i) << " ";
        }
        std::cout << std::endl;
    }
    bool isEmpty()
    {
        return heap->empty();
    }
    int getSize()
    {
        return size;
    }
    void clear()
    {
        heap->clear();
        size = 0;
    };
    void drawTree(QGraphicsScene* &scene, int x, int y, int level, int index)
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
        int offset = tab / (level + 1);

        scene->addRect(x, y, 20, 20);
        QGraphicsTextItem* text = scene->addText(QString::number((*heap)[index]));
        text->setPos(x+2, y-1);

        int leftIndex = 2*index + 1;
        if (leftIndex < heap->size())
        {
            scene->addLine(x+10, y+20, x-offset+10, y+40);
            drawTree(scene, x-offset, y+40, level+1, leftIndex);
        }

        int rightIndex = 2*index + 2;
        if (rightIndex < heap->size())
        {
            scene->addLine(x+10, y+20, x+offset+10, y+40);
            drawTree(scene, x+offset, y+40, level+1, rightIndex);
        }
    }
    std::string toString()
    {
        std::string result = "";
        for (int i = 0; i < heap->size(); i++)
        {
            result += std::to_string(heap->at(i)) + " ";
        }
        return result;
    }

};

#endif // BINARYHEAP_H
