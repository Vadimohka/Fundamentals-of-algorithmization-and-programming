#include "HashMap.h"
#include <QTableWidget>
#include <random>

#ifndef LAB7_HASHMAPUI_H
#define LAB7_HASHMAPUI_H

class HashMapUI : public HashMap {
public:
    QString generateRandomString(int length) {
        const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, static_cast<int>(characters.size() - 1));

        QString result;
        result.reserve(length);
        for (int i = 0; i < length; ++i) {
            result += characters[dis(gen)];
        }
        return result;
    }

    void fillTable(QTableWidget* table) {
        table->setRowCount(0);
        clear();
        for (int i = 0; i < 20; ++i) {
            QString k = generateRandomString(8);
            QString v = generateRandomString(4);
            insert(k, v);
        }
        printMap(table);
    }

    void printMap(QTableWidget* table) const {
        table->setRowCount(0); // Clear the table before printing

        for (size_t i = 0; i < size; i++) {
            const Node* elem = &this->table[i];
            if (!elem->isOccupied) continue;

            int buckets = 0;
            int firstRow = table->rowCount();
            while (elem != nullptr && elem->isOccupied) {
                int row = table->rowCount();
                table->insertRow(row);
                table->setItem(row, 1, new QTableWidgetItem(elem->key));
                table->setItem(row, 2, new QTableWidgetItem(elem->value));
                elem = nullptr; // This is to comply with the current structure, as we don't have chaining
                buckets++;
            }
            table->setItem(firstRow, 0, new QTableWidgetItem(QString::number(i)));
            if (buckets > 1) {
                table->setSpan(firstRow, 0, buckets, 1);
            }
        }
        table->setColumnCount(3);
        QStringList headers = {"Bucket","Key","Value"};
        table->setHorizontalHeaderLabels(headers);
    }
};

#endif // LAB7_HASHMAPUI_H
