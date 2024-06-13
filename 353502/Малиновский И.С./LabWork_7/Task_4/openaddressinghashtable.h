#ifndef OPEN_ADDRESSING_HASHTABLE_H
#define OPEN_ADDRESSING_HASHTABLE_H

#include <vector>
#include <string>

class OpenAddressingHashTable {
public:
    OpenAddressingHashTable(int size);
    void insert(int key, const std::string& value);
    bool search(int key, std::string& value);
    void remove(int key);

private:
    struct Node {
        int key;
        std::string value;
        bool deleted;
    };

    std::vector<Node> table;
    int hash(int key);
};

#endif // OPEN_ADDRESSING_HASHTABLE_H
