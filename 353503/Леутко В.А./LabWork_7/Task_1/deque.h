#ifndef DEQUE_H
#define DEQUE_H

#include <cstdlib>
#include <stdexcept>

template <class T>
class Deque {
public:
    Deque();
    ~Deque();

    bool empty() const;
    size_t size() const;

    T& front();
    T& back();

    void pushFront(const T& value);
    void pushBack(const T& value);

    void popFront();
    void popBack();

    void makeCircular();

    T& operator[](size_t index);
private:
    size_t theSize;
    T** blockMap;
    size_t mapSize;
    size_t firstBlock;
    size_t firstElement;
    static const size_t BlockSize = 1024;
    static const size_t numElementsInBlock = Deque<T>::BlockSize / sizeof(T);

    struct DequePosition {
        size_t blockNum;
        size_t elementNum;
    };

    void expandMap();
    DequePosition indexAt(size_t n) const;
    size_t indexOf(const DequePosition& pos) const;
    void shiftBlocks();
};

template <class T>
Deque<T>::Deque() : theSize(0), mapSize(1), firstBlock(0), firstElement(0) {
    blockMap = new T*[mapSize];
    blockMap[0] = new T[numElementsInBlock];
}

template <class T>
Deque<T>::~Deque() {
    for (size_t i = 0; i < mapSize; i++) {
        delete[] blockMap[i];
    }
    delete[] blockMap;
}

template <class T>
bool Deque<T>::empty() const {
    return theSize == 0;
}

template <class T>
size_t Deque<T>::size() const {
    return theSize;
}

template <class T>
T& Deque<T>::front() {
    if (empty()) {
        throw std::underflow_error("Deque is empty");
    }
    return blockMap[firstBlock][firstElement];
}

template <class T>
T& Deque<T>::back() {
    if (empty()) {
        throw std::underflow_error("Deque is empty");
    }
    DequePosition lastPos = indexAt(theSize - 1);
    return blockMap[lastPos.blockNum][lastPos.elementNum];
}

template <class T>
void Deque<T>::pushFront(const T& value) {
    if (firstElement == 0) {
        if (firstBlock == 0) {
            expandMap();
        }
        --firstBlock;
        firstElement = numElementsInBlock - 1;
    } else {
        --firstElement;
    }
    blockMap[firstBlock][firstElement] = value;
    ++theSize;
}

template <class T>
void Deque<T>::pushBack(const T& value) {
    DequePosition lastPos = indexAt(theSize);
    if (lastPos.elementNum == numElementsInBlock - 1) {
        expandMap();
        lastPos = indexAt(theSize);
    }
    blockMap[lastPos.blockNum][lastPos.elementNum] = value;
    ++theSize;
}

template <class T>
void Deque<T>::popFront() {
    if (empty()) {
        throw std::underflow_error("Deque is empty");
    }
    ++firstElement;
    if (firstElement == numElementsInBlock) {
        firstElement = 0;
        ++firstBlock;
    }
    --theSize;
}

template <class T>
void Deque<T>::popBack() {
    if (empty()) {
        throw std::underflow_error("Deque is empty");
    }
    DequePosition lastPos = indexAt(theSize - 1);
    --theSize;
    if (lastPos.elementNum == 0) {
        delete[] blockMap[lastPos.blockNum];
        for (size_t i = lastPos.blockNum; i < mapSize - 1; i++) {
            blockMap[i] = blockMap[i + 1];
        }
        --mapSize;
    }
}

template <class T>
void Deque<T>::makeCircular() {
    if (!empty()) {
        T frontValue = front();
        pushBack(frontValue);
        popFront();
    }
}

template <class T>
T& Deque<T>::operator[](size_t index) {
    if (index >= theSize) {
        throw std::out_of_range("Index out of range");
    }

    DequePosition pos = indexAt(index);
    return blockMap[pos.blockNum][pos.elementNum];
}

template <class T>
void Deque<T>::expandMap() {
    T** newBlockMap = new T*[mapSize * 2];
    for (size_t i = 0; i < firstBlock; i++) {
        newBlockMap[i] = blockMap[i];
    }
    newBlockMap[firstBlock] = new T[numElementsInBlock];
    for (size_t i = firstBlock + 1; i < mapSize; i++) {
        newBlockMap[i + mapSize] = blockMap[i];
    }
    delete[] blockMap;
    blockMap = newBlockMap;
    mapSize *= 2;
    firstBlock += mapSize / 2;
}

template <class T>
typename Deque<T>::DequePosition Deque<T>::indexAt(size_t n) const {
    DequePosition pos;
    pos.blockNum = firstBlock + n / numElementsInBlock;
    pos.elementNum = (firstElement + n) % numElementsInBlock;
    return pos;
}

template <class T>
void Deque<T>::shiftBlocks() {
    if (firstBlock > 0) {
        for (size_t i = 0; i < mapSize; i++) {
            blockMap[i] = blockMap[i + firstBlock];
        }
        firstBlock = 0;
    }
}

#endif // DEQUE_H
