#include "myhashtable.h"

MyHashTable::MyHashTable(int initialCapacity) : m_capacity(getNextPrime(initialCapacity)), m_table(m_capacity) {}

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
    return key % m_capacity;
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

int MyHashTable::findMinKeyStack() const
{
    for (int i = 0; i < m_capacity; ++i) {
        if (!m_table[i].isEmpty()) {
            return i;
        }
    }
    return -1;

    /*int minKeyStack = -1;
    int minKey = std::numeric_limits<int>::max();

    for (int i = 0; i < m_capacity; ++i) {
        if (!m_table[i].isEmpty()) {
            int topKey = m_table[i].peek();
            if (topKey < minKey) {
                minKey = topKey;
                minKeyStack = i;
            }
        }
    }

    return minKeyStack;*/
}

void MyHashTable::insert(int key, int value) {
    int index = hashFunction(key);
    m_table[index].push(value);
}

void MyHashTable::remove(int key) {
    int index = hashFunction(key);
    if (!m_table[index].isEmpty())
        m_table[index].pop();
}

QVector<QVector<int>> MyHashTable::display() const {
    QVector<QVector<int>> result;
    for (int i = 0; i < m_capacity; i++) {
        QVector<int> slotContent = m_table[i].toQVector();
        result.append(slotContent);
    }
    return result;
}

void MyHashTable::clear() {
    for (auto &stack : m_table) {
        stack.clear();
    }
}
