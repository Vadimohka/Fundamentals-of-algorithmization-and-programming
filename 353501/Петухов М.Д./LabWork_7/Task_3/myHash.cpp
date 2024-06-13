#include "myHash.h"

void myHash::generateRandomHashTable(int size){
    capacity = nextSimpleNumber(size);
    table.resize(capacity);
    for(int i = 0; i < capacity; i++){
            int randomValue = QRandomGenerator::global()->bounded(71);
            insertItem(QRandomGenerator::global()->bounded(600, 30000), randomValue);
    }
}

int myHash::findStackWithMinKey(){
    int minKey = std::numeric_limits<int>::max();
    int stackNumber = 0;
    for (int i = 0; i < capacity; ++i) {
        Stack tempStack;
        while (!table[i].isEmpty()) {
            QPair<int, int> element = table[i].peek();
            table[i].pop();
            tempStack.push(element);

            if(element.first < minKey){
                minKey = element.first;
                stackNumber = i;
            }
        }
        while (!tempStack.isEmpty()) {
            QPair<int, int> element = tempStack.peek(); 
            tempStack.pop();
            table[i].push(element);
        }
    }
    return stackNumber;
}