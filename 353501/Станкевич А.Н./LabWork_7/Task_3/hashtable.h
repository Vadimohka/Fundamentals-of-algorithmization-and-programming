#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <memory>
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QString>

struct My_pair
{
    int key = 0;
    int value = 0;

    My_pair() = default;

    My_pair(const int &index, const int &value) : key(index % 257), value(value) {}
};

class My_hashtable
{
public:
    class Node
    {
    public:
        My_pair d;
        Node *prev = nullptr;
        Node *next = nullptr;
        Node(const My_pair &tmp) : d(tmp) {}
    };

    class linkedlist
    {
    public:
        Node *head;
        Node *tail;
        linkedlist()
        {
            head = tail = nullptr;
        }
        ~linkedlist()
        {
            while (head != nullptr)
            {
                pop_front();
            }
        }
        Node *pushfront(const My_pair &tmp)
        {
            Node *ptr = new Node(tmp);

            ptr->next = head;
            if (head != nullptr)
            {
                head->prev = ptr;
            }
            if (tail == nullptr)
            {
                tail = ptr;
            }

            head = ptr;
            return ptr;
        }

        void pop_front()
        {
            if (head == nullptr)
            {
                return;
            }
            Node *ptr = head->next;
            if (ptr != nullptr)
            {
                ptr->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            delete head;
            head = ptr;
        }

        Node *getat(int index)
        {
            Node *ptr = head;
            int n = 0;
            while (n != index && ptr != nullptr)
            {
                ptr = ptr->next;
                n++;
            }
            return ptr;
        }

        Node *operator[](int index)
        {
            return getat(index);
        };
    };

public:
    std::shared_ptr<linkedlist[]> arr;
    size_t hashtablesize = 256;
    size_t am__of_el = 0;

public:
    My_hashtable()
    {
        arr.reset(new linkedlist[hashtablesize]);
    }

    explicit My_hashtable(size_t n)
    {
        hashtablesize = n;
        arr.reset(new linkedlist[n]);
    }

private:
    size_t hash_function(const My_pair &tmp)
    {
        size_t index = abs(((tmp.key ^ 50 + 1337 - tmp.key * tmp.key + tmp.key * tmp.key * tmp.key + 13769) * 47 / 13)) % hashtablesize;
        return index;
    }

public:
    void insert(const My_pair &tmp)
    {
        int index = hash_function(tmp);

        arr[index].pushfront(tmp);
        ++am__of_el;
    }

    My_pair find(int key)
    {
        if (arr[hash_function(My_pair(key, 0))].head->d.key == key)
        {
            return arr[hash_function(My_pair(key, 0))].head->d;
        }
        Node *ptr = arr[hash_function(My_pair(key, 0))].head;
        while (key != ptr->d.key)
        {

            ptr = ptr->next;
            if (ptr == nullptr)
            {
                throw std::runtime_error("no such element with this key");
            }
        }
        return ptr->d;
    }

    int find_stack_with_max_key()
    {
        int max_key = INT_MIN;
        int stack_index = -1;

        for (size_t i = 0; i < hashtablesize; ++i)
        {
            Node *ptr = arr[i].head;
            while (ptr != nullptr)
            {
                if (ptr->d.key > max_key)
                {
                    max_key = ptr->d.key;
                    stack_index = i;
                }
                ptr = ptr->next;
            }
        }

        if (stack_index == -1)
        {
            throw std::runtime_error("The hashtable is empty");
        }

        return stack_index;
    }
};

class Solve
{
public:
    My_hashtable *table;
    Ui::MainWindow *gui;

public:
    Solve(Ui::MainWindow *gui)
    {
        this->gui = gui;
        gui->hashtablebig->setColumnCount(2);
        gui->hashtablebig->setRowCount(256);
        table = new My_hashtable();

        for (int i = 0; i < 256; ++i)
        {
            table->insert(My_pair(i, rand()));
        }
    }

    void solve_problem()
    {
        QString s = "";
        for (int i = 0; i < 256; ++i)
        {
            My_hashtable::Node *ptr = table->arr[i].head;
            while (ptr != nullptr)
            {
                s += QString::number(ptr->d.key) + " - " + QString::number(ptr->d.value) + " ";
                ptr = ptr->next;
            }
            QTableWidgetItem *itm2 = new QTableWidgetItem(QString::number(i));
            gui->hashtablebig->setItem(i, 0, itm2);

            QTableWidgetItem *itm = new QTableWidgetItem(s);
            gui->hashtablebig->setItem(i, 1, itm);

            s.clear(); // Clear the string for the next iteration
        }
        gui->lineEdit->setText(QString::number(table->find_stack_with_max_key()));
    }
};

#endif // HASHTABLE_H
