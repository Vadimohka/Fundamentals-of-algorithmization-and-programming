#ifndef BINARYHEAPLIST_H
#define BINARYHEAPLIST_H

#include "BinaryHeapList_global.h"
#include <memory>
#include <QTreeWidget>

template <typename T> class BINARYHEAPLIST_EXPORT BinaryHeapList
{
    struct Node {
        int key;
        T value;
        std::weak_ptr<Node> next;
        std::weak_ptr<Node> previous;
        Node(int key, T value){
            this->key = key;
            this->value = value;
        }
    };
    QTreeWidget* widget;
    std::weak_ptr<Node> first;
    std::weak_ptr<Node> end;
    int size = 0;

    std::weak_ptr<Node> *get(int index){
        if(index >= size){
            return nullptr;
        }
        std::weak_ptr<Node> node = first;
        for(int i = 0; i < index; i++){
            node = node.lock()->next;
        }
        return node.lock();
    }

public:
    BinaryHeapList(){}

    int heapSize(){
        return size;
    }

    void add(int key, T value)
    {
        if(size == 0){
            first = std::make_shared<Node>(key, value);
            end = first;
        }
        else{
            end.lock()->next = std::make_shared<Node>(key, value);
            end = end.lock()->next;
        }
        size++;
        int i = heapSize() - 1;
        int parent = (i - 1) / 2;

        while (i > 0 && get(parent)->lock()->key < get(i)->lock()->key)
        {
            std::weak_ptr<Node> node = *get(i);
            *get(i) = *get(parent);
            *get(parent) = node;

            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void removeAt(int index)
    {
        if(size == 0){
            return;
        }
        std::weak_ptr<Node> node = *get(index);
        std::weak_ptr<Node> nextNode = node->next;
        nextNode->previous = node->previous;
        node->previous->next = nextNode;
        delete node;
        node = nullptr;
    }

    void heapify(int i)
    {
        int leftChild;
        int rightChild;
        int largestChild;

        while(true)
        {
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
            largestChild = i;

            if (leftChild < heapSize() && *get(leftChild).key > *get(largestChild).key)
            {
                largestChild = leftChild;
            }

            if (rightChild < heapSize() && *get(rightChild).key > *get(largestChild).key)
            {
                largestChild = rightChild;
            }

            if (largestChild == i)
            {
                break;
            }

            std::weak_ptr<Node> node = *get(i);
            *get(i) = *get(largestChild);
            *get(largestChild) = node;
            i = largestChild;
        }
    }

    int getMax()
    {
        int result = get(0).key;
        *get(0) = *get(heapSize() - 1);
        removeAt(heapSize()- 1);
        return result;
    }

    void setTreeWidget(QTreeWidget* widget){
        this->widget = widget;
    }

    void setTree(){
        widget->clear();
        if(size == 0){
            return;
        }
        QTreeWidgetItem *item = new QTreeWidgetItem(widget);
        item->setText(0, QString::number(*get(0)->key) + '.' + *get(0)->value);
        item->addChild(buildTree(1, item));
        item->addChild(buildTree(2, item));
        widget->addTopLevelItem(item);
    }

    QTreeWidgetItem* buildTree(int index, QTreeWidgetItem* parent){
        if(index >= size){
            QTreeWidgetItem *item = new QTreeWidgetItem(parent);
            item->setText(0, "NULL");
            return item;
        }
        QTreeWidgetItem *item = new QTreeWidgetItem(parent);
        item->setText(0, QString::number(*get(index)->key())+'.'+*get(index)->value());
        item->addChild(buildTree(2*index + 1, item));
        item->addChild(buildTree(2*index + 2, item));
        return item;
    }

};

#endif // BINARYHEAPLIST_H
