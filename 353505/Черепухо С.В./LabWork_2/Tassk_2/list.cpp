#include "bibl.h"
#include "student.h"
class List
{
private:
    struct node
    {
        student data;
        ll next;
        ll prev;
    };
    node *_arr;
    ll _begin;
    ll _end;
    ll _size;
    ll move(ll ind)
    {
        ll it = _begin;
        for(ll i = 0; i < ind; i++)
        {
            it = _arr[it].next;
        }
        return it;
    }
public:
    List()
    {
        _arr = nullptr;
        _begin = -1;
        _end = -1;
        _size = 0;
    }
    List(const List& lst)
    {
        node *newArr = new node[lst._size];
        for(ll i = 0; i < lst._size; i++)
        {
            newArr[i] = lst._arr[i];
        }
        _begin = lst._begin;
        _end = lst._end;
        _size = lst._size;
    }
    void push_back(const student& data)
    {
        node *newArr = new node[_size + 1];
        for(ll i = 0; i < _size; i++)
        {
            newArr[i] = _arr[i];
        }
        newArr[_size].data = data;
        if(!_size)
        {
            newArr[_size].prev = -1;
            newArr[_size].next = -1;
            _begin = _end = _size;
        }
        else
        {
            newArr[_size].prev = _end;
            newArr[_size].next = -1;
            newArr[_end].next = _size;
            _end = _size;
        }
        _arr = newArr;
        _size++;
    }
    void push_front(const student& data)
    {
        node *newArr = new node[_size + 1];
        for(ll i = 0; i < _size; i++)
        {
            newArr[i] = _arr[i];
        }
        newArr[_size].data = data;
        if(!_size)
        {
            newArr[_size].prev = -1;
            newArr[_size].next = -1;
            _begin = _end = _size;
        }
        else
        {
            newArr[_size].prev = -1;
            newArr[_size].next = _begin;
            newArr[_begin].prev = 0;
            _begin = _size;
        }
        _arr = newArr;
        _size++;
    }
    void erase(ll index)
    {
        if(!_size or (index < 0 and index >= _size))
            return;
        if(_size == 1)
        {
            if(_arr)
            {
            delete[] _arr;
            _size = 1;
            _begin = -1;
            _end = -1;
            }
        }
        else if(!index)
        {
            _arr[_arr[_begin].next].prev = -1;
            _begin = move(index + 1);
        }
        else if(index == _size - 1)
        {
            _arr[move(_end - 1)].next = -1;
            _end = move(index - 1);
        }
        else
        {
            ll next = _arr[move(index)].next;
            ll prev = _arr[move(index)].prev;
            _arr[move(index - 1)].next = next;
            _arr[move(index + 1)].prev = prev;
        }
        _size--;
    }
    void clear()
    {
        if(_arr)
        {
        delete[] _arr;
        _size = 0;
        _begin = -1;
        _end = -1;
        }
    }
    student &at(ll index)
    {
        return _arr[move(index)].data;
    }
   [[nodiscard]] ll size() const
    {
        return _size;
    }
    node *begin()
    {
        return &_arr[_begin];
    }
    node *end()
    {
        return &_arr[_end];
    }
    List &operator = (const List &other)
    {
        _arr = other._arr;
        _begin = other._begin;
        _end = other._end;
        _size = other._size;
        return *this;
    }
    student &operator[](ll ind)
    {
        return at(ind);
    }
};
