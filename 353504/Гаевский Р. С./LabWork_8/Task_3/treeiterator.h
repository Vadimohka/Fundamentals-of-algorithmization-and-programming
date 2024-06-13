#ifndef TREEITERATOR_H
#define TREEITERATOR_H

template <typename K, typename V>
class TreeIterator {
public:
    virtual ~TreeIterator() {}
    virtual void setKey(const K& key) = 0;
    virtual void setValue(const V& value) = 0;
    virtual void setColor(int color) = 0;
    virtual TreeIterator* createLeftIterator() = 0;
    virtual TreeIterator* createRightIterator() = 0;
};

#endif // TREEITERATOR_H
