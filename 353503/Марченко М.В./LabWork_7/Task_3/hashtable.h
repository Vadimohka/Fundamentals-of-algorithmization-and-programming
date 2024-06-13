#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "stack.h"
#include <QString>
#include <QVector>
#include <QPair>
#include <QDebug>

struct Data {
    int key;
    QString value;
};

class HashTable {
protected:
    int tableSize;
    QVector<Stack<Data>> table;
    int filledSlots=0;

public:
    int hashFunction(int key) {
        return key % tableSize;
    }

    HashTable(int size) : tableSize(size) {
        table.resize(tableSize);
    }


    void add(int key, const QString& value) {
        int index = hashFunction(key);
        bool isNewSlot = table[index].isEmpty();
        for (int i = 0; i < table[index].getSize(); ++i) {
            if (table[index].at(i).key == key) {
                return;
            }
        }
        table[index].push({key, value});
        if (isNewSlot) {
            filledSlots++;
        }
        checkLoadFactor();
    }

    void checkLoadFactor() {
        float loadFactor = static_cast<float>(filledSlots) / tableSize;
        qDebug()<<loadFactor;
        if (loadFactor >=0.75) {
            resize();

        }
    }

    void resize() {
        int oldSize = tableSize;
        tableSize *= 2;
        QVector<Stack<Data>> newTable(tableSize);
        filledSlots = 0;
        for (int i = 0; i < oldSize; ++i) {
            while (!table[i].isEmpty()) {
                Data data = table[i].pop();
                int newIndex = hashFunction(data.key);
                if (newTable[newIndex].isEmpty()) {
                    filledSlots++;
                }
                newTable[newIndex].push(data);
            }
        }
        table = newTable;
    }

    QString find(int key) {
        int index = hashFunction(key);
        for (int i = 0; i < table[index].getSize(); i++) {
            Data& data = table[index].at(i);
            if (data.key == key) {
                return data.value;
            }
        }
        return QString();
    }

    QVector<QVector<QPair<int, QString>>> displayHash() {
        QVector<QVector<QPair<int, QString>>> result;
        for (int i = 0; i < tableSize; i++) {
            QVector<QPair<int, QString>> stackContents;
            Stack<Data>& stack = table[i];
            for (int j = 0; j < stack.getSize(); j++) {
                Data& data = stack.at(j);
                stackContents.append(qMakePair(data.key, data.value));
            }
            result.append(stackContents);
        }
        return result;
    }

    void remove(int key) {
        int index = hashFunction(key);

        table[index].pop();
    }
    void clear() {
        for (auto& stack : table) {
            stack.clear();
        }
    }
    int getTableSize(){
        return tableSize;
    }
};


#endif // HASHTABLE_H
