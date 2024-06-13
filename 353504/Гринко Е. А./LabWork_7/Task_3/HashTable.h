#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Stack.h"

#include <array>
#include "qmath.h"

const float MAX_OCCUPANCY = 0.75f;
const uint8_t INIT_CAPACITY = 31;
const uint8_t INIT_POW = 5;
const std::array<size_t, 3> LARGE_PRIME_NUMS ={
    0x165667919E3779F9ULL,
    0xABADBABEDEADBEEFULL,
    0xC0FFEEFACADEDEADULL
};
const std::array<size_t, 2> SEMIPRIME_NUMS = {
        265,
        21
};



// Storage data as KeyData struct
template <class T>
class IntHashTable {
public:
    struct KeyData {
        template<class ... Args>
        explicit KeyData(quint64 key, Args&& ... args) :
            key(key), value(std::forward<Args>(args)...) {}
        qint64 key;
        T value;
    };

protected:
    size_t _capacity = INIT_CAPACITY;
    size_t _size = 0;
    int _two_pow = INIT_POW;
    Stack<KeyData>* _data;

    size_t hash(size_t rKey) const {
        auto key = unsign(rKey);
        int lpn_cntr = 0;
        int spn_cntr = 0;
        key *=  LARGE_PRIME_NUMS[lpn_cntr++];
        key = (~key) + LARGE_PRIME_NUMS[lpn_cntr++];
        key *= SEMIPRIME_NUMS[spn_cntr++];
        key = key ^ LARGE_PRIME_NUMS[lpn_cntr++];
        key *= SEMIPRIME_NUMS[spn_cntr++];
        size_t r = key % _capacity;
        return r;
    }

    bool doResize() const {
        return static_cast<float>(_size) / _capacity > MAX_OCCUPANCY;
    }

    void resize() {
        auto formerCapacity = _capacity;
        _capacity = qPow(2, ++_two_pow) - 1;
        auto formerArr = _data;
        _data  = new Stack<KeyData>[_capacity];
        for (size_t i = 0; i < formerCapacity; ++i) {
            for (size_t j = 0; j < formerArr[i].size(); ++j) {
                _data[hash(formerArr[i].top().key)].
                    emplace(std::move_if_noexcept(formerArr[i].top()));
                formerArr[i].pop();
            }
        }
    }

    size_t unsign(qint64 x) const {
        return *reinterpret_cast<size_t*>(&x);
    }

public:
    IntHashTable() : _data(new Stack<KeyData>[INIT_CAPACITY]) {}

    ~IntHashTable() {
        delete[] _data;
    }

    template <class TT>
    void add(qint64 key, TT&& value) {
        emplace(key, std::forward<TT>(value));
    }

    template <class ... Args>
    void emplace(qint64 key, Args&& ... args) {
        if (doResize()) {
            resize();
        }
        _data[hash(key)].emplace(key, std::forward<Args>(args)...);
        ++_size;
    }

    const Stack<KeyData>& get_c(qint64 key) const {
        return _data[hash(key)];
    }

    Stack<KeyData>& get(qint64 key) {
        return _data[hash(key)];
    }

    size_t size() {
        return _size;
    }

    bool empty() {
        return 0 == _size;
    }

    void clear() {
        for (size_t i = 0; i < _size; ++i) {
            _data[i].clear();
        }

        delete[] _data;
        _data = new Stack<KeyData>[INIT_CAPACITY];
        _capacity = INIT_CAPACITY;
        _two_pow = INIT_POW;
        _size = 0;
    }
};

#endif // HASHTABLE_H
