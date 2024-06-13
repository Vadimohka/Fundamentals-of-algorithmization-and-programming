#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsEllipseItem>
#include <QVector>
#include <QString>
#include <QDebug>

template <typename T>
class BinaryHeap
{
private:
    QVector<T> heap;
    int size = 0;

    void siftUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap.at(index) <= heap.at(parent))
            {
                break;
            }
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void siftDown(int index)
    {
        while (2 * index + 1 < heap.size())
        {
            int maxChild = 2 * index + 1;
            if (maxChild + 1 < heap.size() && heap.at(maxChild + 1) > heap.at(maxChild))
            {
                maxChild++;
            }
            if (heap.at(index) >= heap.at(maxChild))
            {
                break;
            }
            std::swap(heap[index], heap[maxChild]);
            index = maxChild;
        }
    }

public:
    BinaryHeap() {}

    void insert(T element)
    {
        heap.push_back(element);
        siftUp(heap.size() - 1);
        size++;
    }

    T extractMax()
    {
        if (heap.empty())
        {
            throw std::runtime_error("Heap is empty");
        }
        T max = heap.at(0);
        heap[0] = heap.last();
        heap.pop_back();
        size--;
        siftDown(0);
        return max;
    }

    T getMax()
    {
        if (heap.empty())
        {
            throw std::runtime_error("Heap is empty");
        }
        return heap.at(0);
    }

    void remove(int index)
    {
        if (index < 0 || index >= heap.size())
        {
            throw std::runtime_error("Index out of bounds");
        }
        heap[index] = heap.last();
        heap.pop_back();
        siftDown(index);
        size--;
    }

    void changePriority(int index, T element)
    {
        if (index < 0 || index >= heap.size())
        {
            throw std::runtime_error("Index out of bounds");
        }
        T old = heap.at(index);
        heap[index] = element;
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
        qDebug() << heap;
    }

    bool isEmpty()
    {
        return heap.empty();
    }

    int getSize()
    {
        return size;
    }

    void clear()
    {
        heap.clear();
        size = 0;
    }

    void drawTree(QGraphicsScene* &scene, int x, int y, int level, int index)
    {
        if (index >= heap.size())
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
        QGraphicsTextItem* text = scene->addText(QString::number(heap[index]));
        text->setPos(x+2, y-1);

        int leftIndex = 2*index + 1;
        if (leftIndex < heap.size())
        {
            scene->addLine(x+10, y+20, x-offset+10, y+40);
            drawTree(scene, x-offset, y+40, level+1, leftIndex);
        }

        int rightIndex = 2*index + 2;
        if (rightIndex < heap.size())
        {
            scene->addLine(x+10, y+20, x+offset+10, y+40);
            drawTree(scene, x+offset, y+40, level+1, rightIndex);
        }
    }

    QString toString()
    {
        QString result = "";
        for (int i = 0; i < heap.size(); i++)
        {
            result += QString::number(heap.at(i)) + " ";
        }
        return result;
    }
};

#endif // BINARYHEAP_H
