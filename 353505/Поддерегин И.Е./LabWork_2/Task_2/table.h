#ifndef TABLE_H
#define TABLE_H

#include<QTableWidget>
#include <QTextStream>
#include <QDataStream>
#include <QFile>
#include "book.h"

class Table
{
public:
    explicit Table(QTableWidget *table);
    void setTableInfo(QVector<Book*> b);
    void setRow(Book*book, int n);
    void addRow(QFile*,Book*);
    void updateRowSize();
    void SortByYear();
    void SortByPublisher();
    void updateInfo();
    void ShowNecessary(QString name);
    void DelRow(QFile*, int n);
private:
    QTableWidget *table;
    QVector<Book*> library;
};

#endif // TABLE_H
