#ifndef BINARYHEAPARRAY_H
#define BINARYHEAPARRAY_H

#include <QVector>
#include <QTreeWidget>

template <typename T> class BinaryHeapArray
{
    struct Node {
        int key;
        T value;

        Node(int key, T value){
            this->key = key;
            this->value = value;
        }
    };
    QTreeWidget* widget;
    QVector<Node*> array;
public:
    BinaryHeapArray(){}

    int heapSize(){
        return array.size();
    }

    void add(int key, T value)
    {
        array.push_back(new Node(key, value));
        int i = heapSize() - 1;
        int parent = (i - 1) / 2;

        while (i > 0 && array[parent] < array[i])
        {
            Node* node = array[i];
            array[i] = array[parent];
            array[parent] = node;

            i = parent;
            parent = (i - 1) / 2;
        }
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

            if (leftChild < heapSize() && array[leftChild].key > array[largestChild].key)
            {
                largestChild = leftChild;
            }

            if (rightChild < heapSize() && array[rightChild].key > array[largestChild].key)
            {
                largestChild = rightChild;
            }

            if (largestChild == i)
            {
                break;
            }

            Node* node = array[i];
            array[i] = array[largestChild];
            array[largestChild] = node;
            i = largestChild;
        }
    }

    int getMax()
    {
        int result = array[0];
        array[0] = array[heapSize() - 1];
        array.RemoveAt(heapSize()- 1);
        return result;
    }
    void setTreeWidget(QTreeWidget* widget){
        this->widget = widget;
    }

    void setTree(){
        widget->clear();
        if(array.empty()){
            return;
        }
        QTreeWidgetItem *item = new QTreeWidgetItem(widget);
        item->setText(0, QString::number(array[0]->key) + '.' + array[0]->value);
        item->addChild(buildTree(1, item));
        item->addChild(buildTree(2, item));
        widget->addTopLevelItem(item);
    }

    QTreeWidgetItem* buildTree(int index, QTreeWidgetItem* parent){
        if(index >= array.size()){
            QTreeWidgetItem *item = new QTreeWidgetItem(parent);
            item->setText(0, "NULL");
            return item;
        }
        QTreeWidgetItem *item = new QTreeWidgetItem(parent);
        QString str = QString::number(array[index]->key)+'.';
        str.append(array[index]->value);
        item->setText(0, str);
        item->addChild(buildTree(2*index + 1, item));
        item->addChild(buildTree(2*index + 2, item));
        return item;
    }

    bool contains(int key){
        for(int i = 0; i < array.size(); i++){
            if(array.get(i)->Key == key){
                return true;
            }
        }
        return false;
    }

};

#endif // BINARYHEAPARRAY_H
