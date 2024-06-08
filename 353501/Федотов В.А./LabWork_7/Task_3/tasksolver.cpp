#include "tasksolver.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <qcontainerfwd.h>
#include <QTableWidget>

TaskSolver::TaskSolver(QTableWidget* table, int keys, int size)
    : table(table), keys(keys), size(size), HashMap<int>(size) {
    srand(time(NULL));

    fillWithRandom();
    populateTable();
}

void TaskSolver::fillWithRandom() {
    clear();
    for (int i = 0; i < keys; i++) {
        insert(rand() % 10000, rand() % 100000);
    }
}

void TaskSolver::populateTable() {
    table->setRowCount(0);
    table->setColumnCount(3);

    table->setHorizontalHeaderLabels({"Cell", "Keys", "Values"});

    for (int i = 0; i < size; i++) {
        Node* current = nodes[i];
        int spanStart = table->rowCount();
        int spanLength = 0;

        if (current == nullptr) {
            table->insertRow(table->rowCount());
            table->setItem(spanStart, 0, new QTableWidgetItem(QString::number(i)));
            continue;
        }

        while (current != nullptr) {
            int row = table->rowCount();
            table->insertRow(row);
            table->setItem(row, 1, new QTableWidgetItem(QString::number(current->key)));
            table->setItem(row, 2, new QTableWidgetItem(QString::number(current->value)));
            current = current->next;
            spanLength++;
        }

        table->setItem(spanStart, 0, new QTableWidgetItem(QString::number(i)));
        if (spanLength > 1)
            table->setSpan(spanStart, 0, spanLength, 1);
    }
}

int TaskSolver::findMinKey() {
    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < size; i++) {
        Node* node = nodes[i];
        while (node != nullptr) {
            if (node->key < min)
                min = node->key;

            node = node->next;
        }
    }

    return min;
}