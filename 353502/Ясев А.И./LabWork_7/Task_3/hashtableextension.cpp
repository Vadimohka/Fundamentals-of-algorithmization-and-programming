#include "hashtableextension.h"

void HashTableExtension::createRandomHashTable()
{
    int n = QRandomGenerator::global()->bounded(0, size);
    for (int i = 0; i < n; ++i)
    {
        addItem(QRandomGenerator::global()->bounded(-50, 50), QRandomGenerator::global()->bounded(0, 100));
    }
}

QPair<HashTableExtension*, HashTableExtension*> HashTableExtension::divide()
{
    HashTableExtension* pos = new HashTableExtension(size);
    HashTableExtension* neg = new HashTableExtension(size);

    for (int i = -50; i < 0; ++i)
    {
        auto vec = table[hash(i)].toVector();
        for (auto& e : vec)
        {
            neg->addItem(i, e.value);
        }
    }

    for (int i = 0; i <= 50; ++i)
    {
        auto vec = table[hash(i)].toVector();
        for (auto& e : vec)
        {
            pos->addItem(i, e.value);
        }
    }
    return qMakePair(neg, pos);
}
