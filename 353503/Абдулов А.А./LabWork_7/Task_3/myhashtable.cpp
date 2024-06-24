#include "myhashtable.h"
#include <QRandomGenerator>

void MyHashTable::createRandomHashTable(int count) {

    for (int i = 0; i < count; ++i) {
        insertItem(QRandomGenerator::global()->bounded(0, 23456), QRandomGenerator::global()->bounded(0, 100));
    }
}

QString MyHashTable::findMaxKey() {
    int ind; // Инициализируем максимальный ключ как отрицательное число
    int maxKey = -1;
    QString res = "";

    for (int i = 0; i < capacity; ++i) {
        int currentMaxKey = -1;
        if(!table[i].isEmpty()){
            QVector<int> keys = table[i].toQVectorKey();

            for(auto currentKey : keys){
                if(currentKey > currentMaxKey){
                    currentMaxKey = currentKey;
                }
            }

            if(currentMaxKey > maxKey){
                maxKey = currentMaxKey;
                ind = i;
            }
            res += "STACK INDEX :" + QString::number(i) + ", max key:" + QString::number(currentMaxKey) + '\n';
        }
    }

    res += "\n INDEX of stack with MAX KEY:" + QString::number(ind);

    return res;
}
