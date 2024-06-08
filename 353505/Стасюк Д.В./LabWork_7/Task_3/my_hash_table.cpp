#include "my_hash_table.h"

MyHashTable::MyHashTable(int initialCapacity) {
    // h_size = getNextPrime(initialCapacity);
    h_size = 10;
    h_table.resize(h_size);
}

bool MyHashTable::isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int MyHashTable::getNextPrime(int n) {
    while (!isPrime(n))
        n++;
    return n;
}

int MyHashTable::hashFunction(int key) {
    return abs(key % h_size);
}

// void generateRandomTable(int minKey, int maxKey, int numItems)
// {
//     srand(time(0));

//     for (int i = 0; i < numItems; ++i) {
//         int key = minKey + rand() % (maxKey - minKey + 1);
//         int value = minKey + rand() % (maxKey - minKey + 1);
//         insert(key, value);
//     }
// }
void MyHashTable::insert(int key, int value) {
    int index = hashFunction(key);
    h_table[index].push(value);
}

void MyHashTable::remove(int key) {
    int index = hashFunction(key);
    if (!h_table[index].isEmpty())
        h_table[index].pop();
}

// int my_hash_table::getRandomNumber(int min_key, int max_key) const {
//     return min_key + arc4random() % ((max_key + 1) - min_key);
// }

// void my_hash_table::generateRandomKeys(int count) {
//     for (int i = 0; i < count; ++i) {
//         int key = getRandomNumber(-50, 50);
//         int value = getRandomNumber(-50, 50);
//         insert(key, value);
//     }
// }

void MyHashTable::generateRandomTable(int numItems)
{
    // this->clear();
    srand(time(0));

    for (int i = 0; i < numItems; ++i) {
        // int key = rand() % (50 - (-50) + 1);
        int value = -50 + rand() % (50 - (-50) + 1);
        insert(value, value);
    }
}



QVector<QVector<int>> MyHashTable::display() {
    QVector<QVector<int>> result;
    for (int i = 0; i < h_size; i++) {
        QVector<int> slotContent = h_table[i].toQVector();
        result.append(slotContent);
    }
    return result;
}

void MyHashTable::clear() {
    for (auto &stack : h_table) {
        stack.clear();
    }
}
