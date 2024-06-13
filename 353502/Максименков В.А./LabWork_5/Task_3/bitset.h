#ifndef BITSET_H
#define BITSET_H

#include <QDebug>
#include <QString>

class BitSet
{
private:
    static const int BLOCKS_CAP = 16;
    static const int BLOCK_SIZE = sizeof(unsigned short) * BLOCKS_CAP;

    unsigned short* data;
    int sz;

public:
    BitSet(int size) : sz(size)
    {
        qDebug() << "Constructor";
        int arraysz = (size + BLOCKS_CAP - 1) / BLOCKS_CAP;
        data = new unsigned short[arraysz];

        for (int i = 0; i < arraysz; ++i)
        {
            data[i] = 0;
        }
    }

    ~BitSet()
    {
        delete[] data;
    }


    int getSize() const
    {
        return sz;
    }


    void set(int pos)
    {
        if (pos >= 0 && pos < sz)
        {
            data[pos / BLOCK_SIZE] |= (1 << (pos % BLOCK_SIZE));
        }
    }


    void set()
    {
        for (int i = 0; i < sz; ++i)
        {
            data[i / BLOCK_SIZE] |= (1 << (i % BLOCK_SIZE));
        }
    }


    void reset(int pos)
    {
        if (pos >= 0 && pos < sz)
        {
            data[pos / BLOCK_SIZE] &= ~(1 << (pos % BLOCK_SIZE));
        }
    }


    void reset()
    {
        for (int i = 0; i < sz; ++i)
        {
            data[i / BLOCK_SIZE] &= ~(1 << (i % BLOCK_SIZE));
        }
    }


    bool test(int pos) const
    {
        return (pos >= 0 && pos < sz) && (data[pos / BLOCK_SIZE] & (1 << (pos % BLOCK_SIZE)));
    }


    void flip(int pos)
    {
        if (pos >= 0 && pos < sz)
        {
            data[pos / BLOCK_SIZE] ^= (1 << (pos % BLOCK_SIZE));
        }
    }


    void flip()
    {
        for (int i = 0; i < sz; ++i)
        {
            data[i / BLOCK_SIZE] ^= (1 << (i % BLOCK_SIZE));
        }
    }


    bool all() const
    {
        int fullBlocks = sz / BLOCKS_CAP;
        int partialBlocksz = sz % BLOCKS_CAP;

        for (int i = 0; i < fullBlocks; ++i)
        {
            if (data[i] != static_cast<unsigned short>((1 << BLOCKS_CAP) - 1))
            {
                return false;
            }
        }

        if (partialBlocksz > 0)
        {
            unsigned short mask = (1 << partialBlocksz) - 1; // Маска для последних неполных битов
            if (data[fullBlocks] != mask)
            {
                return false;
            }
        }

        return true;
    }


    bool any() const
    {
        for (int i = 0; i < (sz + BLOCKS_CAP - 1) / BLOCKS_CAP; ++i)
        {
            if (data[i] != 0)
            {
                return true;
            }
        }

        return false;
    }


    int count() const {
        int cnt = 0;
        for (int i = 0; i < (sz + BLOCKS_CAP - 1) / BLOCKS_CAP; ++i)
        {
            unsigned short val = data[i];
            while (val)
            {
                cnt += (val & 1);
                val >>= 1;
            }
        }

        return cnt;
    }


    bool none() const
    {
        return !any();
    }


    QString to_string() const
    {
        qDebug() << "ToString";
        QString str;
        for (int i = sz - 1; i >= 0; --i)
        {
            str += test(i) ? '1' : '0';
        }

        return str;
    }


    unsigned long long to_ullong() const
    {
        unsigned long long val = 0;
        for (int i = sz - 1; i >= 0; --i)
        {
            if (test(i))
            {
                val |= (1ULL << i);
            }
        }

        return val;
    }


    unsigned long to_ulong() const
    {
        unsigned long val = 0;
        for (int i = sz - 1; i >= 0; --i)
        {
            if (test(i))
            {
                val |= (1ULL << i);
            }
        }

        return val;
    }


    bool operator[](int pos) const
    {
        return test(pos);
    }


    bool& operator[](int pos)
    {
        static bool ex;

        if (pos < 0 || pos >= sz)
        {
            return ex;
        }

        return reinterpret_cast<bool&>(data[pos / BLOCK_SIZE] |= (1 << (pos % BLOCK_SIZE)));
    }

};

#endif // BITSET_H
