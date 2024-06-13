#include <QVector>

class HashTable {
private:
    int capacity;
    QVector<QPair<int, int>> table;
    QVector<bool> deleted;
    QVector<bool> wasInserted;

    bool isSimple(int n);
    int nextSimpleNumber(int n);
    int hashFunction(int key, int i);
    int func1(int key);
    int func2(int key);
public:
    HashTable(int V);
    int search(int key);
    bool insertItem(int key, int data);
    void deleteItem(int key);
    QVector<QPair<int, int>> toVec();
    void clear();
};

