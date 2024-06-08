#ifndef DEQUE_H
#define DEQUE_H

#include <QVector>
#include <algorithm>
#include <vector>

const uint8_t BLOCKSIZE = 16;
const uint8_t INITBLOCKAMNT = 4;

template<class T>
class Deque
{
private:
    std::vector<std::vector<T>> blocks;
    size_t headBlock{0};
    size_t tailBlock{0};
    uint8_t headIndex;
    uint8_t tailIndex;
    size_t size{0};

    void resize()
    {
        std::vector<std::vector<T>> newArrs(blocks.size() * 2 + 1, std::vector<T>(BLOCKSIZE));
        size_t newBlockIdx = 0;

        for (size_t i = 0; i < size; ++i) {
            size_t absInd = (headIndex + i) % (blocks.size() * BLOCKSIZE);
            size_t blInd = (absInd / BLOCKSIZE + headBlock) % blocks.size();
            size_t elInd = absInd % BLOCKSIZE;

            newArrs[newBlockIdx][i % BLOCKSIZE] = blocks[blInd][elInd];

            if ((i + 1) % BLOCKSIZE == 0) {
                ++newBlockIdx;
            }
        }

        for (size_t i = newBlockIdx + 1; i < newArrs.size(); ++i) {
            newArrs[i] = std::vector<T>(BLOCKSIZE);
        }

        headBlock = 0;
        tailBlock = newBlockIdx;
        headIndex = 0;
        tailIndex = size % BLOCKSIZE;
        blocks = std::move(newArrs);
    }

    typename std::vector<T>::iterator getNextBlock(typename std::vector<T>::iterator block)
    {
        auto it = std::find(blocks.begin(), blocks.end(), block);
        if (it == blocks.end()) {
            return blocks.end();
        }
        size_t pos = std::distance(blocks.begin(), it);
        if (pos == blocks.size() - 1) {
            return blocks.begin();
        }
        return ++it;
    }

    typename std::vector<T>::iterator getPrevBlock(typename std::vector<T>::iterator block)
    {
        auto it = std::find(blocks.begin(), blocks.end(), block);
        if (it == blocks.end()) {
            return blocks.end();
        }
        size_t pos = std::distance(blocks.begin(), it);
        if (pos == 0) {
            return blocks.end() - 1;
        }
        return --it;
    }

    template<class TT>
    void initFirst(TT &&value)
    {
        clear();
        blocks[tailBlock][tailIndex] = std::forward<TT>(value);
        ++size;
    }

public:
    Deque()
        : headIndex(BLOCKSIZE / 2)
        , tailIndex(BLOCKSIZE / 2)
    {
        blocks.resize(INITBLOCKAMNT, std::vector<T>(BLOCKSIZE));
    }

    ~Deque() = default;

    void clear()
    {
        blocks.clear();
        blocks.resize(INITBLOCKAMNT, std::vector<T>(BLOCKSIZE));
        headIndex = BLOCKSIZE / 2;
        tailIndex = BLOCKSIZE / 2;
        size = 0;
        headBlock = 0;
        tailBlock = 0;
    }

    template<class TT>
    void push_back(TT &&value)
    {
        if (size == 0) {
            initFirst(std::forward<TT>(value));
            return;
        }

        if (tailIndex == BLOCKSIZE - 1) {
            if ((tailBlock + 1) % blocks.size() == headBlock) {
                resize();
            }
            tailBlock = (tailBlock + 1) % blocks.size();
            tailIndex = 0;
        } else {
            ++tailIndex;
        }
        blocks[tailBlock][tailIndex] = std::forward<TT>(value);
        ++size;
    }

    template<class TT>
    void push_front(TT &&value)
    {
        if (size == 0) {
            initFirst(std::forward<TT>(value));
            return;
        }

        if (headIndex == 0) {
            if ((headBlock == 0 ? blocks.size() - 1 : headBlock - 1) == tailBlock) {
                resize();
            }
            headBlock = (headBlock == 0) ? blocks.size() - 1 : headBlock - 1;
            headIndex = BLOCKSIZE - 1;
        } else {
            --headIndex;
        }
        blocks[headBlock][headIndex] = std::forward<TT>(value);
        ++size;
    }

    void pop_back()
    {
        if (size == 0) {
            return;
        }

        if (tailIndex == 0) {
            if (tailBlock == 0) {
                tailBlock = blocks.size() - 1;
            } else {
                --tailBlock;
            }
            tailIndex = BLOCKSIZE - 1;
        } else {
            --tailIndex;
        }
        --size;
    }

    void pop_front()
    {
        if (size == 0) {
            return;
        }

        if (headIndex == BLOCKSIZE - 1) {
            headBlock = (headBlock + 1) % blocks.size();
            headIndex = 0;
        } else {
            ++headIndex;
        }
        --size;
    }

    T &operator[](size_t index)
    {
        size_t absInd = (headIndex + index) % (blocks.size() * BLOCKSIZE);
        size_t blInd = (absInd / BLOCKSIZE + headBlock) % blocks.size();
        size_t elInd = absInd % BLOCKSIZE;
        return blocks[blInd][elInd];
    }

    T &front() { return blocks[headBlock][headIndex]; }

    T &back() { return blocks[tailBlock][tailIndex]; }

    const T &front() const { return blocks[headBlock][headIndex]; }

    const T &back() const { return blocks[tailBlock][tailIndex]; }

    class Iterator
    {
    private:
        Deque *deque;
        typename std::vector<T>::iterator block;
        uint8_t elementIndex;

    public:
        Iterator(Deque *d, typename std::vector<T>::iterator b, int eIndex)
            : deque(d)
            , block(b)
            , elementIndex(eIndex)
        {}

        T &operator*() { return *block; }

        Iterator &operator++()
        {
            if (elementIndex == BLOCKSIZE - 1) {
                block = deque->getNextBlock(block);
                elementIndex = 0;
            } else {
                ++elementIndex;
            }
            return *this;
        }

        const Iterator operator++(int)
        {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        Iterator &operator--()
        {
            if (elementIndex == 0) {
                block = deque->getPrevBlock(block);
                elementIndex = BLOCKSIZE - 1;
            } else {
                --elementIndex;
            }
            return *this;
        }

        const Iterator operator--(int)
        {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const Iterator &other) const
        {
            return block == other.block && elementIndex == other.elementIndex;
        }

        bool operator!=(const Iterator &other) const { return !(*this == other); }
    };

    Iterator begin() { return Iterator(this, blocks[headBlock].begin() + headIndex, headIndex); }

    Iterator end() { return Iterator(this, blocks[tailBlock].begin() + tailIndex + 1, 0); }

    size_t getSize() const { return size; }

    bool empty() const { return size == 0; }
};

#endif // DEQUE_H
