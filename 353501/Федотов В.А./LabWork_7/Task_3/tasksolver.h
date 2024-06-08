#pragma once

#include "hashmap.h"
#include <qtablewidget.h>

class TaskSolver : public HashMap<int> {
public:
    TaskSolver(QTableWidget *table, int keys, int size);

    void fillWithRandom();
    void populateTable();
    int findMinKey();

private:
    QTableWidget *table;

    int keys;
    int size;

};