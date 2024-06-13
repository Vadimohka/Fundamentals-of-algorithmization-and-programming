#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <stack>
#include <string>

class HashTable {
public:
    std::vector<std::stack<std::string>> table;

    HashTable(int size);
    virtual ~HashTable();

    virtual void insert(int key, const std::string& value);
    virtual bool search(int key, std::string& value) const;
    virtual void remove(int key);
    virtual void clear();
    virtual void print() const;

protected:
    int hash(int key) const;
};

#endif // HASHTABLE_H
