//
// Created by shosh on 5/29/24.
//
#include <QApplication>
#include <QPushButton>
#include "QDebug"
#include "hashTable/HashTable.h"
#include "QCryptographicHash"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    HashTable table(456);
    table.insertItem(10, 40, HashTable::ShaHashing);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}

