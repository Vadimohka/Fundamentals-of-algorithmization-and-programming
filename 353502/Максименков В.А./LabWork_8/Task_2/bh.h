#ifndef BH_H
#define BH_H
#include <QDebug>
#include <QVector>

template<typename T>
class BH // ВНИМАНИЕ!!! Здесь ключ совпадает со значением
{
private:
    QVector<T> vec;
    int sz = 0;

    void heapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left >= sz) // у вершины нет потомков
        {
            return;
        }
        else if (right >= sz) // у вершины есть только левый потомок
        {
            if (vec[i] < vec[left])
            {
                std::swap(vec[i], vec[left]);
                heapify(left);
            }
        }
        else // у вершины есть два потомка
        {
            T maxChildValue = std::max(vec[left], vec[right]);

            if (vec[left] == maxChildValue)
            {
                std::swap(vec[i], vec[left]);
                heapify(left);
            }
            else
            {
                std::swap(vec[i], vec[right]);
                heapify(right);
            }
        }
    }

public:
    BH() = default;


    int size() const
    {
        return sz;
    }


    QVector<T> getVector() const
    {
        return vec;
    }


    void insert(const T& value)
    {
        int i = vec.size();
        int parent = (i - 1) / 2;
        vec.push_back(value);

        while(parent >= 0 && i > 0)
        {
            if (vec[i] > vec[parent])
            {
                std::swap(vec[i], vec[parent]);
            }
            i = parent;
            parent = (i - 1) / 2;
        }

        ++sz;
    }


    T removeMax()
    {
        if (sz == 0)
        {
            throw 1;
        }

        int ans = vec[0];
        vec[0] = vec[sz-1];
        vec.pop_back();
        --sz;
        heapify(0);
        return ans;
    }
};

#endif // BH_H
