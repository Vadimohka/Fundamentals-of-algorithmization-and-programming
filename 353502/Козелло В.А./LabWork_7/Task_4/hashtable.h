#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QDebug>
#include <QString>
#include <QVector>
#include <functional>

class HashTable
{
private:
    QVector<QString> table;
    QVector<bool> occupied;
    size_t num_elements{0};
    size_t table_size;

    size_t hash(const QString &key, size_t size) const
    {
        return std::hash<std::string>{}(key.toStdString()) % size;
    }

    void resize()
    {
        size_t new_size = table_size * 2;
        QVector<QString> new_table(new_size);
        QVector<bool> new_occupied(new_size, false);

        for (size_t i = 0; i < table_size; ++i) {
            if (occupied[i]) {
                size_t new_index = hash(table[i], new_size);
                while (new_occupied[new_index]) {
                    new_index = (new_index + 1) % new_size;
                }
                new_table[new_index] = table[i];
                new_occupied[new_index] = true;
            }
        }

        table = std::move(new_table);
        occupied = std::move(new_occupied);
        table_size = new_size;
    }

public:
    explicit HashTable(size_t initial_size = 8)
        : table(initial_size)
        , occupied(initial_size, false)
        , table_size(initial_size)
    {}

    void insert(const QString &key)
    {
        if (num_elements >= table_size / 2) {
            resize();
        }

        size_t index = hash(key, table_size);
        while (occupied[index]) {
            if (table[index] == key) {
                return;
            }
            index = (index + 1) % table_size;
        }

        table[index] = key;
        occupied[index] = true;
        ++num_elements;
    }

    bool find(const QString &key) const
    {
        size_t index = hash(key, table_size);
        size_t start_index = index;
        while (occupied[index]) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % table_size;
            if (index == start_index) {
                break;
            }
        }
        return false;
    }

    void remove(const QString &key)
    {
        size_t index = hash(key, table_size);
        size_t start_index = index;
        while (occupied[index]) {
            if (table[index] == key) {
                occupied[index] = false;
                --num_elements;
                return;
            }
            index = (index + 1) % table_size;
            if (index == start_index) {
                break;
            }
        }
    }

    void print() const
    {
        for (size_t i = 0; i < table_size; ++i) {
            if (occupied[i]) {
                qDebug() << i << ": " << table[i];
            } else {
                qDebug() << i << ": "
                         << "<empty>";
            }
        }
    }
};

#endif // HASHTABLE_H
