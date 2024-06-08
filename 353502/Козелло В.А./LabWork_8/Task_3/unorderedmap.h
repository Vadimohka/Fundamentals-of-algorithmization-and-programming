#ifndef UNORDEREDMAP_H
#define UNORDEREDMAP_H

#include <functional>
#include <list>
#include <stdexcept>
#include <utility>
#include <vector>

template<typename K, typename V>
class UnorderedMap
{
public:
    static const int DEFAULT_BUCKET_COUNT = 16;
    explicit UnorderedMap(size_t bucketCount = DEFAULT_BUCKET_COUNT)
        : buckets(bucketCount)
    {}

    void insert(const K &key, const V &value)
    {
        size_t index = getIndex(key);
        for (auto &pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        buckets[index].emplace_back(key, value);
    }

    bool contains(const K &key) const
    {
        size_t index = getIndex(key);
        for (const auto &pair : buckets[index]) {
            if (pair.first == key) {
                return true;
            }
        }
        return false;
    }

    V &at(const K &key)
    {
        size_t index = getIndex(key);
        for (auto &pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    const V &at(const K &key) const
    {
        size_t index = getIndex(key);
        for (const auto &pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    void erase(const K &key)
    {
        size_t index = getIndex(key);
        auto &bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }

private:
    std::vector<std::list<std::pair<K, V>>> buckets;

    size_t getIndex(const K &key) const { return std::hash<K>{}(key) % buckets.size(); }
};

#endif // UNORDEREDMAP_H
