#include "hashTable.h"

HashTable::HashTable(int V) {
    capacity = nextSimpleNumber(V);
    table.resize(capacity);
}

bool HashTable::isSimple(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int HashTable::nextSimpleNumber(int n) {
    while (!isSimple(n))
        n++;
    return n;
}

int HashTable::hashFunction(int key) {
    return key % capacity;
}

void HashTable::insertItem(int key, int data) {
    int index = hashFunction(key);
    //table[index].push(data);
    QPair<int, int> myPair(key, data);
    table[index].push(myPair);
}

void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    table[index].pop();
}

QVector<QVector<QPair<int, int>>> HashTable::hashTableToVector() {
    QVector<QVector<QPair<int, int>>> result;
    for (int i = 0; i < capacity; i++) {
        QVector<QPair<int, int>> slotContent = table[i].toQVector();
        result.append(slotContent);
    }
    return result;
}

void HashTable::clear() {
    for (auto & i : table) {
        i.clearStack();
    }
}

int HashTable::get(int key) {
    int index = hashFunction(key);
    int valueToReturn;
    bool wasFound = false;

    Stack tempStack;
    while (!table[index].isEmpty()) {
        QPair<int, int> element = table[index].peek();
        table[index].pop();
        tempStack.push(element);

        if(element.first == key){
            valueToReturn = element.second;
            wasFound = true;
            break;
        }
    }
    while (!tempStack.isEmpty()) {
        QPair<int, int> element = tempStack.peek(); 
        tempStack.pop();
        table[index].push(element);
    }

    if (wasFound) {
        return valueToReturn;
    } else {
        throw std::invalid_argument("Key not found");
    }
}