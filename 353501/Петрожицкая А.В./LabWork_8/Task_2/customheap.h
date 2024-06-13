#ifndef CUSTOMHEAP_H
#define CUSTOMHEAP_H

#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsEllipseItem>

#include <iostream>
#include <memory>
#include <string>
#include <vector>

template <typename T>
class CustomHeap
{
private:
    std::unique_ptr<std::vector<T>> heapData;
    size_t heapSize = 0;

    // Функция для просеивания элемента вверх в куче
    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            swapElements(index, parent);
            index = parent;
        }
    }

    // Функция для просеивания элемента вниз в куче
    void heapifyDown(int index)
    {
        while (2 * index + 1 < heapData->size())
        {
            int largestChild = 2 * index + 1;
            if (largestChild + 1 < heapData->size() && heapData->at(largestChild + 1) > heapData->at(largestChild))
            {
                largestChild++;
            }
            if (heapData->at(index) >= heapData->at(largestChild))
            {
                break;
            }
            swapElements(index, largestChild);
            index = largestChild;
        }
    }

    // Функция для обмена элементов в куче
    void swapElements(int index1, int index2)
    {
        T temp = heapData->at(index1);
        heapData->at(index1) = heapData->at(index2);
        heapData->at(index2) = temp;
    }

public:
    CustomHeap() : heapData(std::make_unique<std::vector<T>>()) {}
    ~CustomHeap()
    {
        heapData = nullptr;
    }

    // Функция для добавления элемента в кучу
    void insert(T element)
    {
        heapData->push_back(element);
        heapifyUp(heapData->size() - 1);
        heapSize++;
    }

    // Функция для извлечения максимального элемента из кучи
    T extractMax()
    {
        if (heapData->empty())
        {
            throw std::runtime_error("Heap is empty");
        }
        T max = heapData->at(0);
        heapData->at(0) = heapData->at(heapData->size() - 1);
        heapData->pop_back();
        heapSize--;
        heapifyDown(0);
        return max;
    }

    // Функция для получения максимального элемента в куче
    T getMax()
    {
        if (heapData->empty())
        {
            throw std::runtime_error("Heap is empty");
        }
        return heapData->at(0);
    }

    // Функция для удаления элемента из кучи по индексу
    void remove(int index)
    {
        if (index < 0 || index >= heapData->size())
        {
            throw std::runtime_error("Index out of bounds");
        }
        heapData->at(index) = heapData->at(heapData->size() - 1);
        heapData->pop_back();
        heapifyDown(index);
        heapSize--;
    }

    // Функция для изменения приоритета элемента в куче
    void changePriority(int index, T newElement)
    {
        if (index < 0 || index >= heapData->size())
        {
            throw std::runtime_error("Index out of bounds");
        }
        T oldElement = heapData->at(index);
        heapData->at(index) = newElement;
        if (newElement > oldElement)
        {
            heapifyUp(index);
        }
        else
        {
            heapifyDown(index);
        }
    }

    // Функция для вывода элементов кучи
    void print()
    {
        for (int i = 0; i < heapData->size(); i++)
        {
            std::cout << heapData->at(i) << " ";
        }
        std::cout << std::endl;
    }

    // Функция для проверки, является ли куча пустой
    bool isEmpty()
    {
        return heapData->empty();
    }

    // Функция для получения размера кучи
    int getSize()
    {
        return heapSize;
    }

    // Функция для очистки кучи
    void clear()
    {
        heapData->clear();
        heapSize = 0;
    }

    // Функция для отрисовки дерева кучи в QGraphicsScene
    void drawTree(QGraphicsScene* &scene, int x, int y, int level, int index)
    {
        if (index >= heapData->size())
        {
            return;
        }

        float tab = 100;
        if(heapSize > 20)
        {
            tab *= (float)heapSize / 20.0;
        }
        int offset = tab / (level + 1);

        scene->addRect(x, y, 20, 20);
        QGraphicsTextItem* text = scene->addText(QString::number((*heapData)[index]));
        text->setPos(x+2, y-1);

        int leftIndex = 2*index + 1;
        if (leftIndex < heapData->size())
        {
            scene->addLine(x+10, y+20, x-offset+10, y+40);
            drawTree(scene, x-offset, y+40, level+1, leftIndex);
        }

        int rightIndex = 2*index + 2;
        if (rightIndex < heapData->size())
        {
            scene->addLine(x+10, y+20, x+offset+10, y+40);
            drawTree(scene, x+offset, y+40, level+1, rightIndex);
        }
    }

    // Функция для получения строкового представления кучи
    std::string toString()
    {
        std::string result = "";
        for (int i = 0; i < heapData->size(); i++)
        {
            result += std::to_string(heapData->at(i)) + " ";
        }
        return result;
    }
};

#endif // CUSTOMHEAP_H
