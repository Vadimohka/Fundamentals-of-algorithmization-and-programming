#include "myhashtable.h"

MyHashTable::MyHashTable(int initialCapacity) : m_table(getNextPrime(initialCapacity)), m_capacity(getNextPrime(initialCapacity)) {}

bool MyHashTable::isPrime(int n) const {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int MyHashTable::getNextPrime(int n) const {
    while (!isPrime(n))
        n++;
    return n;
}

int MyHashTable::hashFunction(int key) const {
    const double A = 0.6180339887; // Золотое сечение
    double fractionalPart = key * A - int(key * A);
    return int(m_capacity * fractionalPart);
}

void MyHashTable::generateRandomTable(int minKey, int maxKey, int numItems)
{
    srand(time(0));

    for (int i = 0; i < numItems; ++i) {
        int key = minKey + rand() % (maxKey - minKey + 1);
        int value = minKey + rand() % (maxKey - minKey + 1);
        insert(key, value);
    }
}

int MyHashTable::find(int key) const
{
    int index = hashFunction(key);
    if (m_table[index].isEmpty()) {
        return -1;
    }

    for (int i = 0; i < m_table[index].size(); ++i) {
        if (m_table[index][i] == key) {
            return index;
        }
    }

    return -1;
}

void MyHashTable::insert(int key, int value) {
    int index = hashFunction(key);
    m_table[index].push(value);
}

void MyHashTable::remove(int key) {
    int index = hashFunction(key);
    if (!m_table[index].isEmpty()) {
        while (!m_table[index].isEmpty() && m_table[index].top() == key) {
            m_table[index].pop();
        }
    }
}

QVector<QVector<int>> MyHashTable::display() const {
    QVector<QVector<int>> result;
    for (int i = 0; i < m_capacity; i++) {
        QVector<int> slotContent;
        for (int j = 0; j < m_table[i].size(); ++j) {
            slotContent.append(m_table[i][j]);
        }
        result.append(slotContent);
    }
    return result;
}

void MyHashTable::clear() {
    for (auto &stack : m_table) {
        stack.clear();
    }
}
