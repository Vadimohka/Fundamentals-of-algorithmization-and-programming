#ifndef UNORDEREDMAP_H
#define UNORDEREDMAP_H

#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <memory>

template <class Key, class Value, class Hash = std::hash<Key>>
class UnorderedMap {
private:
    struct Node {
        std::pair<const Key, Value> data;
        std::shared_ptr<Node> next;

        template <class VValue>
        Node(const Key& key, VValue&& value, std::shared_ptr<Node> next)
            : data(key, std::forward<VValue>(value)), next(next) {}
        explicit Node(std::shared_ptr<Node> next) : next(next) {}
    };

    using weakNode = std::weak_ptr<Node>;
    using sharedNode = std::shared_ptr<Node>;

    constexpr static double load_factor = 0.75;
    constexpr static uint8_t init_size = 16;
    const static sharedNode end_elem;

    Hash _hash;
    // _table[...][0] refers to objects of this cache
    // _table[...][1] refers to the prev node in the list
    std::vector<std::array<weakNode, 2>> _table;
    sharedNode _head = UnorderedMap::end_elem;
    size_t _elemNum = 0;
    size_t _tableSize = 0;

    size_t hash_(const Key& key) const {
        return _hash(key) % _tableSize;
    }

public:
    explicit UnorderedMap(size_t initSize = UnorderedMap::init_size, Hash hashFunc = Hash())
        : _hash(hashFunc), _table(initSize), _tableSize(initSize) {}

    //------------------------------------------------------------------------------------------------//

    template <class VValue>
    void insert(const Key& key, VValue&& value) {
        size_t index = hash_(key);

        auto node = find(key);
        if (node == end_elem) {
            node = _table[index][0].lock(); // head
            if (!node) { // first elem
                node = std::make_shared<Node>(key, std::forward<VValue>(value), _head);
                _table[index][0] = weakNode(node);
                if (_head != end_elem) {
                    _table[hash_(_head->data.first)][1] = weakNode(node);
                }
                _head = node;
            } else {
                while (node != end_elem && node->next != end_elem && index == hash_(node->next->data.first)) {
                    node = node->next;
                }
                auto nextIndex = node->next;
                node->next = std::make_shared<Node>(key, std::forward<VValue>(value), nextIndex);
            }
            ++_elemNum;
        }

        if (_elemNum > _tableSize * load_factor) {
            rehash(_tableSize * 2);
        }
    }

    void erase(const Key& key) {
        size_t index = hash_(key);

        if (contains(key)) {
            auto node = _table[index][0].lock();
            if (node->data.first == key) {
                _table[index][1].lock()->next = node->next;
                _table[index][0] = weakNode(node->next);
            } else {
                while (node->next->data.first != key) {
                    node = node->next;
                }
                node->next = node->next->next;
            }
            --_elemNum;
        }
    }

    //------------------------------------------------------------------------------------------------//

    bool contains(const Key& key) const {
        return find(key) != end_elem;
    }

private:

    std::shared_ptr<Node> find(const Key& key) const {
        size_t index = hash_(key);
        auto node = _table[index][0].lock();
        while (node && node != end_elem && index == hash_(node->data.first) && node->data.first != key) {
            node = node->next;
        }
        if (node == end_elem || !node || node->data.first != key) {
            return end_elem;
        }
        return node;
    }

public:

    //------------------------------------------------------------------------------------------------//

    void rehash(size_t newSize) {
        auto formerTable = std::move(_table);
        auto formerHead = std::move(_head);
        clear();
        _table.resize(newSize);
        _tableSize = newSize;
        for (auto node = formerHead; node != end_elem; node = node->next) {
            insert(node->data.first, std::move(node->data.second));
        }
    }

    //------------------------------------------------------------------------------------------------//

    void clear() {
        _table.clear();
        _table.resize(init_size);
        _head = UnorderedMap::end_elem;
        _elemNum = 0;
        _tableSize = init_size;
    }

    //------------------------------------------------------------------------------------------------//

    size_t size() const {
        return _elemNum;
    }

    bool empty() const {
        return _elemNum == 0;
    }

    //------------------------------------------------------------------------------------------------//

    Value& operator[](const Key& key) {
        auto node = find(key);
        if (node != end_elem) {
            return node->data.second;
        } else {
            insert(key, Value());
            return find(key)->data.second;
        }
    }

    const Value& operator[](const Key& key) const {
        auto node = find(key);
        if (node != end_elem) {
            return node->data.second;
        }
        throw std::out_of_range("Key not found");
    }

    //------------------------------------------------------------------------------------------------//

    class Iterator {
    private:
        std::weak_ptr<Node> ptr;

        explicit Iterator(std::weak_ptr<Node> node) : ptr(node) {}

    public:
        std::pair<const Key, Value>& operator*() const {
            return ptr.lock()->data;
        }

        std::pair<const Key, Value>* operator->() const {
            return &(ptr.lock()->data);
        }

        Iterator& operator++() {
            ptr = std::weak_ptr<Node>(ptr.lock()->next);
            return *this;
        }

        const Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) {
            return other.ptr.lock() == ptr.lock();
        }

        bool operator!=(const Iterator& other) {
            return !(*this == other);
        }

        friend UnorderedMap;
    };

    Iterator begin() const {
        return Iterator(_head);
    }

    Iterator end() const {
        return Iterator(UnorderedMap::end_elem);
    }

    //------------------------------------------------------------------------------------------------//

    std::vector<std::vector<std::pair<const Key, Value>>> table() {
        std::vector<std::vector<std::pair<const Key, Value>>> vec (_tableSize);
        for (size_t i = 0; i < _tableSize; ++i) {
            auto column = _table[i];
            auto node = column[0].lock();
            while (node && node != end_elem && hash_(node->data.first) == i) {
                vec[i].push_back(node->data);
                node = node->next;
            }
        }
        return vec;
    }
};

#define table UnorderedMap<Key, Value, Hash>
template <class Key, class Value, class Hash>
const std::shared_ptr<typename table::Node> table::end_elem = std::make_shared<typename table::Node>(nullptr);
#undef table

#endif // UNORDEREDMAP_H
