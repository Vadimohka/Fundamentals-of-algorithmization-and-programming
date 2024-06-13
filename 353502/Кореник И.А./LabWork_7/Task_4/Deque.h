#ifndef DEQUE_H
#define DEQUE_H

template<typename T>
class Deque
{
    static const long long BLOCK_SIZE = 4;

    struct Block
    {
        T *blockData = new T[BLOCK_SIZE];
        Block* previous = nullptr;
        Block* next = nullptr;
        int count = 0;
    };

    Block* first;
    Block* last;
    long long _size;
    long long _capacity;

public:
    Deque()
    {
        first = nullptr;
        last = nullptr;
        _size = 0;
        _capacity = 0;
    }

    ~Deque()
    {
        clear();
    }

    bool empty()
    {
        return _size == 0;
    }

    long long size()
    {
        return _size;
    }

    void clear()
    {
        while (!empty())
        {
            pop_back();
        }
    }

    void pop_front()
    {
        if (empty())
        {
            return;
        }

        if (first->count > 1)
        {
            for (int i = 0; i < first->count - 1; ++i)
            {
                first->blockData[i] = first->blockData[i + 1];
            }
            --first->count;
        }
        else
        {
            Block* temp = first;
            first = first->next;
            if (!first)
            {
                first = nullptr;
                last = nullptr;
                _capacity = 0;
                delete[] temp->blockData;
                delete temp;
            }
            else
            {
                first->previous = nullptr;
                delete temp;
            }
        }
        --_size;
    }

    void pop_back()
    {
        if (empty())
        {
            return;
        }

        if (last->count > 1)
        {
            --last->count;
        }
        else
        {
            Block* temp = last;
            last = last->previous;
            if (!last)
            {
                first = nullptr;
                last = nullptr;
                _capacity = 0;
                delete[] temp->blockData;
                delete temp;
            }
            else
            {
                last->next = nullptr;
                delete temp;
            }
        }
        --_size;
    }

    void push_front(const T& element)
    {
        if (_capacity == 0)
        {
            ++_capacity;
            last = first = new Block;
            ++first->count;
            first->blockData[0] = element;
        }
        else if (first->count >= 4)
        {
            ++_capacity;
            first->previous = new Block;
            first->previous->next = first;
            first = first->previous;
            first->blockData[0] = element;
            ++first->count;
        }
        else
        {
            for (int i = first->count; i >= 0; --i)
            {
                first->blockData[i + 1] = first->blockData[i];
            }
            first->blockData[0] = element;
            ++first->count;
        }
        ++_size;
    }

    void push_back(const T& element)
    {
        if (_capacity == 0)
        {
            ++_capacity;
            last = first = new Block;
            ++last->count;
            last->blockData[0] = element;
        }
        else if (last->count >= 4)
        {
            ++_capacity;
            last->previous = new Block;
            last->next->previous = last;
            last = last->next;
            last->blockData[0] = element;
            ++last->count;
        }
        else
        {
            last->blockData[last->count] = element;
            ++last->count;
        }
        ++_size;
    }

    class Iterator
    {
        friend class Deque<T>;

        Block* current;
        long long index;

    public:
        Iterator(Block* block, long long index)
        {
            this->current = block;
            this->index = index;
        }

        bool operator==(const Iterator &other) const
        {
            return current == other.current && index == other.index;
        }

        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }

        T& operator*() const
        {
            return current->blockData[index];
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        Iterator operator--(int)
        {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        Iterator operator++()
        {
            if (current != nullptr && index == current->count - 1)
            {
                index = 0;
                current = current->next;
            }
            else if (current != nullptr)
            {
                ++index;
            }
            return *this;
        }

        Iterator operator--()
        {
            if (current != nullptr && index == 0)
            {
                current = current->previous;
                index = current == nullptr ? 0 : current->count - 1;
            }
            else if (current != nullptr)
            {
                --index;
            }
            return *this;
        }
    };
    Iterator begin()
    {
        return Iterator(first, first != nullptr ? 0 : 0);
    }

    Iterator end()
    {
        return Iterator(nullptr, 0);
    }
};

#endif // DEQUE_H
