#ifndef UNORDERED_MAP_H
#define UNORDERED_MAP_H

#include <QString>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

constexpr short INIT_BUCKET_SIZE = 16;
constexpr float START_MAX_LOAD_FACTOR = 0.5;

template<typename Key, typename Value, typename Hash = std::hash<Key>>
class Unordered_Map
{
private:
    struct Node
    {
        std::pair<const Key, Value> keyValue;
        size_t hash;
        Node *next = nullptr;
        Node(const Key &key, const Value &value, const size_t hash, Node *next)
            : keyValue(std::make_pair(key, value))
            , hash(hash)
            , next(next)
        {}
    };

    std::vector<Node *> _buckets;
    Node *_fakeNode;
    size_t _bucketCapacity{INIT_BUCKET_SIZE};
    size_t _size{0};
    float _maxLoadFactor{START_MAX_LOAD_FACTOR};

public:
    class Iterator
    {
    private:
        Node *current;

    public:
        using iterator_category = std::forward_iterator_tag;

        explicit Iterator(Node *it)
            : current(it)
        {}

        std::pair<const Key, Value> &operator*() { return current->keyValue; }

        std::pair<const Key, Value> *operator->() { return &(current->keyValue); }

        Iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator &other) const { return current != other.current; }

        bool operator==(const Iterator &other) const { return current == other.current; }
    };

    Iterator begin() const { return Iterator(_fakeNode->next); }

    Iterator end() const { return Iterator(_fakeNode); }

    explicit Unordered_Map(size_t initBucketCount = INIT_BUCKET_SIZE)
        : _fakeNode(reinterpret_cast<Node *>(new int8_t[sizeof(Node)]))
        , _bucketCapacity(initBucketCount)
    {
        _buckets.resize(_bucketCapacity, nullptr);
        _fakeNode->next = _fakeNode;
    }

    ~Unordered_Map() noexcept
    {
        clear();
        delete _fakeNode;
    }

    void rehash()
    {
        _bucketCapacity *= 2;
        std::vector<Node *> newBuckets(_bucketCapacity, nullptr);
        Node *oldFirstNode = _fakeNode->next;
        _fakeNode->next = _fakeNode;

        for (Node *node = oldFirstNode; node != _fakeNode; node = node->next) {
            size_t newHash = Hash()(node->keyValue.first) % _bucketCapacity;
            Node *newNode = new Node(node->keyValue.first,
                                     node->keyValue.second,
                                     newHash,
                                     _fakeNode->next); // создаем новую node с перехешированным ключом

            if (newBuckets[newHash] == nullptr) {
                if (_fakeNode->next != _fakeNode) {
                    newBuckets[_fakeNode->next->hash % _bucketCapacity] = newNode;
                }
                _fakeNode->next = newNode;
                newBuckets[newHash] = _fakeNode;
            } else {
                Node *temp = newBuckets[newHash];
                newNode->next = temp->next->next;
                temp->next = newNode;
            }
        }

        for (Node *node = oldFirstNode; node != _fakeNode;) { // освобождаем память старых node
            Node *temp = node->next;
            delete node;
            node = temp;
        }

        _buckets.swap(newBuckets); // заменяем старый массив на новый
    }

    std::pair<Iterator, bool> insert(const std::pair<const Key, Value> &keyValue)
    {
        if (load_factor() >= _maxLoadFactor) {
            rehash();
        }

        size_t hash = Hash()(keyValue.first) % _bucketCapacity;
        Node *temp = _buckets[hash];

        if (!empty() && temp != nullptr) { // Проверка, если есть элементы с этим хешем
            temp = temp->next;
            while (temp != _fakeNode && temp->hash == hash) {
                if (temp->keyValue.first == keyValue.first) {
                    return {Iterator(temp), false}; // элемент с таким ключом уже лежит
                }
                temp = temp->next;
            }
            temp = _buckets[hash];
            Node *newNode = new Node(keyValue.first,
                                     keyValue.second,
                                     hash % _bucketCapacity,
                                     temp->next);
            temp->next = newNode;
            ++_size;
            return {Iterator(newNode), true};
        } else {
            Node *newNode = new Node(keyValue.first,
                                     keyValue.second,
                                     hash % _bucketCapacity,
                                     _fakeNode->next);
            if (_fakeNode->next != _fakeNode) {
                _buckets[_fakeNode->next->hash % _bucketCapacity] = newNode;
            }
            _fakeNode->next = newNode;
            _buckets[hash] = _fakeNode;
            ++_size;
            return {Iterator(newNode), true};
        }
    }

    bool empty() const { return _size == 0; }

    size_t size() const { return _size; }

    Iterator find(const Key &key)
    {
        size_t hash = Hash()(key) % _bucketCapacity;
        Node *temp = _buckets[hash];
        if (temp != nullptr) {
            temp = temp->next;
            while (temp != _fakeNode && temp->hash == hash) {
                if (temp->keyValue.first == key) {
                    return Iterator(temp);
                }
                temp = temp->next;
            }
        }
        return end();
    }

    Value &operator[](const Key &key)
    {
        size_t hash = Hash()(key) % _bucketCapacity;
        Node *temp = _buckets[hash];

        if (temp != nullptr) {
            temp = temp->next;
            while (temp != _fakeNode && temp->hash == hash) {
                if (temp->keyValue.first == key) {
                    return temp->keyValue.second;
                }
                temp = temp->next;
            }
        }

        std::pair<Iterator, bool> result = insert(std::make_pair(key, Value()));
        return (*result.first).second;
    }

    Value &at(const Key &key) const
    {
        size_t hash = Hash()(key) % _bucketCapacity;
        Node *temp = _buckets[hash];
        if (temp != nullptr) {
            temp = temp->next;
            while (temp != _fakeNode && temp->hash == hash) {
                if (temp->keyValue.first == key) {
                    return temp->keyValue.second;
                }
                temp = temp->next;
            }
        }
        throw std::out_of_range("...");
    }

    bool contains(const Key &key) const
    {
        size_t hash = Hash()(key) % _bucketCapacity;
        Node *temp = _buckets[hash];

        if (temp != nullptr) {
            temp = temp->next;
            while (temp != _fakeNode && temp->hash == hash) {
                if (temp->keyValue.first == key) {
                    return true;
                }
                temp = temp->next;
            }
        }
        return false;
    }

    bool erase(const Key &key)
    {
        size_t hash = Hash()(key) % _bucketCapacity;
        Node *temp = _buckets[hash];
        Node *prevBucket = nullptr;

        if (temp != nullptr) {
            prevBucket = temp;
            temp = temp->next;
            while (temp != _fakeNode && temp->hash == hash) {
                if (temp->keyValue.first == key) {
                    Value value = temp->keyValue.second;

                    prevBucket->next = temp->next;
                    if (temp->next != _fakeNode
                        && _buckets[temp->next->hash % _bucketCapacity] == temp) {
                        _buckets[temp->next->hash % _bucketCapacity] = prevBucket;
                    }
                    if ((prevBucket == _fakeNode || prevBucket->hash != temp->hash)
                        && (temp->next == _fakeNode || temp->hash != temp->next->hash)) {
                        _buckets[temp->hash % _bucketCapacity] = nullptr;
                    }

                    delete temp;
                    --_size;
                    return true;
                }

                prevBucket = temp;
                temp = temp->next;
            }
        }
        return false;
    }

    void clear() noexcept
    {
        std::pair<Key, Value> keyValue;
        while (!empty()) {
            keyValue = *begin();
            erase(keyValue.first);
        }
    }

    float max_load_factor() const { return _maxLoadFactor; }

    void max_load_factor(float ml) { _maxLoadFactor = ml; }

    float load_factor() const { return static_cast<float>(_size) / _bucketCapacity; }
};

//template class Unordered_Map<int32_t, std::string>;
//template class Unordered_Map<int32_t, QString>;

#endif // UNORDERED_MAP_H
