#ifndef LIST_H
#define LIST_H

#include <QString>
#include <QList>

class List {
public:
    List();

};

class List_Array{
public:
    static List_Array& instance();
    List* get_Index(int index);
    int get_Size() const;

private:
    List_Array();

    List** array;
    int size;
};

#endif // LIST_H
