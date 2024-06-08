
#include <QTableWidget>
#include "HashMap.h"
#include <random>
#ifndef LAB7_HASHMAPUI_H
#define LAB7_HASHMAPUI_H
class HashMapUI : public HashMap<int> {
public:
    HashMapUI() : HashMap(){
    }
    void fillTable(QTableWidget *table) {
        table->setRowCount(0);
        for(int i = 0;i < size;++i) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, 12);
            int num = dis(gen);
            insert(rand() % 1000,num);
        }
        printMap(table);
    }
    void printMap(QTableWidget *table){
        for (int i = 0; i < size; i++) {
            Node *elem = buckets[i];
            if (elem == nullptr) continue;
            int backets = 0;
            int firstRow = table->rowCount();
            while (elem != nullptr) {
                int row = table->rowCount();
                table->insertRow(row);
                table->setItem(row, 1, new QTableWidgetItem(QString::number(elem->key)));
                table->setItem(row, 2, new QTableWidgetItem(QString::number(elem->value)));
                elem = elem->next;
                backets++;
            }
            table->setItem(firstRow, 0, new QTableWidgetItem(QString::number(i)));
            if (backets > 1)
                table->setSpan(firstRow, 0, backets, 1);
        }
    }
};
#endif //LAB7_HASHMAPUI_H
