#ifndef MODEL_MYLIST_H_
#define MODEL_MYLIST_H_

#include <stdexcept>

#include "app/shortcuts.h"

namespace model {

template <class T>
class MyList {
   private:
    class Node {
       public:
        T _info;
        Node *_prev, *_next;

        Node(const T& info, Node* prev = nullptr, Node* next = nullptr);
        ~Node();
    };

    Node *_first, *_last;
    U_LINT _size;

    static Node* ricCopy(Node* from, Node* prev, Node*& last);
    static Node* ricGet(Node* from, U_LINT index, U_LINT size);
    static Node* ricFind(Node* from, const T& find);
    static void ricFindAll(Node* from, const T& find, MyList<T*>* list);

   public:
    MyList();
    MyList(const MyList<T>& list);
    MyList<T>& operator=(const MyList<T>& list);

    void pushBack(const T& info);
    void insert(const T& info, U_LINT index);
    void pushTop(const T& info);

    void popTop();
    void erase(U_LINT index);
    void erase(const T& info);
    void popBack();

    T* find(const T& info);
    const T* find(const T& info) const;

    MyList<T*>& findAll(const T& info);
    const MyList<T*>& findAll(const T& info) const;

    T& operator[](U_LINT index);
    const T& operator[](U_LINT index) const;

    U_LINT indexOf(const T& info) const;

    U_LINT size() const;

    ~MyList();

    class constIterator;

    class iterator {
        friend class MyList<T>;
        friend class constIterator;

       private:
        Node* _ptr;
        bool _pastTheEnd;

        iterator(Node* n, bool pastTheEnd = false);

       public:
        iterator();

        T& operator*() const;

        T* operator->() const;

        iterator& operator++();

        iterator& operator--();

        bool operator==(const iterator& x) const;

        bool operator!=(const iterator& x) const;
    };

    class constIterator {
        friend class MyList<T>;

       private:
        iterator _it;

        constIterator(Node* n, bool pastTheEnd = false);

       public:
        constIterator();
        constIterator(const iterator& it);  // convert iterator in constIterator

        const T& operator*() const;

        const T* operator->() const;

        constIterator& operator++();

        constIterator& operator--();

        bool operator==(const constIterator& x) const;

        bool operator!=(const constIterator& x) const;
    };

    // Se MyList<...> c; => begin, end, cbegin, cend disponibili
    // Se const MyList<...> c => solo cend, cbegin.

    iterator begin();
    iterator end();

    constIterator cbegin() const;
    constIterator cend() const;
};

template <class T>
MyList<T>::Node::Node(const T& info, Node* prev, Node* next) : _info(info), _prev(prev), _next(next) {}

template <class T>
MyList<T>::Node::~Node() {
    delete _next;
}

template <class T>
MyList<T>::MyList() : _first(nullptr), _last(nullptr), _size(0) {}

template <class T>
typename MyList<T>::Node* MyList<T>::ricCopy(Node* from, Node* prev, Node*& last) {
    if (from == nullptr) {
        last = prev;
        return nullptr;
    }

    Node* temp = new Node(from->_info);
    temp->_prev = prev;
    temp->_next = ricCopy(from->_next, temp, last);
    return temp;
}

template <class T>
typename MyList<T>::Node* MyList<T>::ricGet(Node* from, U_LINT index, U_LINT size) {
    if (index < 0 || index > size)
        return nullptr;
    if (index == 0)
        return from;
    return ricGet(from->_next, --index, size);
}

template <class T>
typename MyList<T>::Node* MyList<T>::ricFind(Node* from, const T& find) {
    if (from == nullptr)
        return nullptr;
    if (from->_info == find)
        return from;
    return ricFind(from->_next, find);
}

template <class T>
void MyList<T>::ricFindAll(Node* from, const T& find, MyList<T*>* lista) {
    Node* temp = ricFind(from, find);
    if (temp != nullptr) {
        lista->pushBack(&temp->_info);
        ricFindAll(temp->_next, find, lista);
    }
}

template <class T>
MyList<T>::MyList(const MyList<T>& list) {
    _first = ricCopy(list._first, _first, _last);
    _size = list._size;
}

template <class T>
MyList<T>& MyList<T>::operator=(const MyList<T>& list) {
    if (this != &list) {
        delete _first;
        _first = ricCopy(list._first, _first, _last);
        _size = list._size;
    }
    return *this;
}

template <class T>
MyList<T>::~MyList() {
    delete _first;
}

template <class T>
void MyList<T>::pushBack(const T& info) {
    if (_size != 0) {
        _last->_next = new Node(info, _last, nullptr);
        _last = _last->_next;
    } else
        _first = _last = new Node(info, nullptr, nullptr);
    _size++;
}

template <class T>
void MyList<T>::pushTop(const T& info) {
    if (_size != 0) {
        _first->_prev = new Node(info, nullptr, _first);
        _first = _first->_prev;
    } else
        _first = _last = new Node(info, nullptr, nullptr);
    _size++;
}

template <class T>
void MyList<T>::insert(const T& info, U_LINT index) {
    if (index == 0)
        pushTop(info);
    else if (index == _size)
        pushBack(info);
    else if (index > 0 && index < _size) {
        Node* temp = ricGet(_first, --index, _size);
        temp->_next = new Node(info, temp, temp->_next);
        temp->_next->_prev = temp;
        _size++;
    } else {
        throw std::out_of_range("Index must be >= 0 and <= of list size");
    }
}

template <class T>
void MyList<T>::popBack() {
    Node* ultimo = _last;
    _last = _last->_prev;
    _last->_next = nullptr;
    delete ultimo;
    _size--;
}

template <class T>
void MyList<T>::popTop() {
    Node* primo = _first;
    if (_size == 1) {
        _first = _last = nullptr;
    } else {
        _first = _first->_next;
        _first->_prev = nullptr;
        primo->_next = nullptr;
    }
    delete primo;
    _size--;
}

template <class T>
T& MyList<T>::operator[](U_LINT index) {
    return ricGet(_first, index, _size)->_info;
}

template <class T>
const T& MyList<T>::operator[](U_LINT index) const {
    return ricGet(_first, index, _size)->_info;
}

template <class T>
void MyList<T>::erase(U_LINT index) {
    if (index == 0)
        popTop();
    else if (index == _size)
        popBack();
    else if (index > 0 && index < _size) {
        Node* temp = ricGet(_first, index, _size);
        temp->_prev->_next = temp->_next;
        temp->_next->_prev = temp->_prev;
        temp->_next = temp->_prev = nullptr;
        delete temp;
        _size--;
    }
}

template <class T>
void MyList<T>::erase(const T& info) {
    Node* del = ricFind(_first, info);
    if (del == _first)
        popTop();
    else if (del == _last)
        popBack();
    else if (del != nullptr) {
        del->_prev->_next = del->_next;
        del->_next->_prev = del->_prev;
        del->_next = del->_prev = nullptr;
        delete del;
        _size--;
    }
}

template <class T>
U_LINT MyList<T>::indexOf(const T& info) const {
    U_LINT index = 0;
    bool trovato = false;
    for (auto i = cbegin(); i != cend() && !trovato; ++i) {
        if (*i == info) {
            trovato = true;
        } else {
            index++;
        }
    }
    return index;  // return _size if not found
}

template <class T>
T* MyList<T>::find(const T& find) {
    Node* ret = ricFind(_first, find);
    return (ret ? &ret->_info : nullptr);
}

template <class T>
const T* MyList<T>::find(const T& find) const {
    Node* ret = ricFind(_first, find);
    return (ret ? &ret->_info : nullptr);
}

template <class T>
MyList<T*>& MyList<T>::findAll(const T& find) {
    MyList<T*>* ret = new MyList<T*>();
    ricFindAll(_first, find, ret);
    return *ret;
}

template <class T>
const MyList<T*>& MyList<T>::findAll(const T& find) const {
    MyList<T*>* ret = new MyList<T*>();
    ricFindAll(_first, find, ret);
    return *ret;
}

template <class T>
U_LINT MyList<T>::size() const {
    return _size;
}

template <class T>
MyList<T>::iterator::iterator() : _ptr(nullptr), _pastTheEnd(false) {}

template <class T>
MyList<T>::iterator::iterator(Node* n, bool pastTheEnd) : _ptr(n), _pastTheEnd(pastTheEnd) {}

template <class T>
T& MyList<T>::iterator::operator*() const {
    return _ptr->_info;
}

template <class T>
T* MyList<T>::iterator::operator->() const {
    return &(_ptr->_info);
}

template <class T>
typename MyList<T>::iterator& MyList<T>::iterator::operator++() {
    if (_ptr != nullptr) {
        if (!_pastTheEnd) {
            if (_ptr->_next == nullptr) {
                _ptr++;
                _pastTheEnd = true;
            } else {
                _ptr = _ptr->_next;
            }
        }
    }
    return *this;
}

template <class T>
typename MyList<T>::iterator& MyList<T>::iterator::operator--() {
    if (_ptr != nullptr) {
        if (_pastTheEnd) {
            _ptr--;
            _pastTheEnd = false;
        } else
            _ptr = _ptr->_prev;
    }
    return *this;
}

template <class T>
bool MyList<T>::iterator::operator==(const iterator& x) const {
    return _ptr == x._ptr;
}

template <class T>
bool MyList<T>::iterator::operator!=(const iterator& x) const {
    return _ptr != x._ptr;
}

template <class T>
typename MyList<T>::iterator MyList<T>::begin() {
    return _first;
}

template <class T>
typename MyList<T>::iterator MyList<T>::end() {
    if (_last == nullptr)
        return nullptr;
    return iterator(_last + 1, true);
}

template <class T>
MyList<T>::constIterator::constIterator() {}

template <class T>
MyList<T>::constIterator::constIterator(const iterator& it) : _it(it) {}

template <class T>
MyList<T>::constIterator::constIterator(Node* n, bool pastTheEnd) : _it(n, pastTheEnd) {}

template <class T>
const T& MyList<T>::constIterator::operator*() const {
    return _it.operator*();
}

template <class T>
const T* MyList<T>::constIterator::operator->() const {
    return _it.operator->();
}

template <class T>
typename MyList<T>::constIterator& MyList<T>::constIterator::operator++() {
    ++_it;
    return *this;
}

template <class T>
typename MyList<T>::constIterator& MyList<T>::constIterator::operator--() {
    --_it;
    return *this;
}

template <class T>
bool MyList<T>::constIterator::operator==(const constIterator& x) const {
    return _it == x._it;
}

template <class T>
bool MyList<T>::constIterator::operator!=(const constIterator& x) const {
    return _it != x._it;
}

template <class T>
typename MyList<T>::constIterator MyList<T>::cbegin() const {
    return _first;
}

template <class T>
typename MyList<T>::constIterator MyList<T>::cend() const {
    if (_last == nullptr)
        return nullptr;
    return constIterator(_last + 1, true);
}

}  // namespace model

#endif
