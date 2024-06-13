//
// Created by acryoz on 26.05.24.
//

#include "TaskSolver.h"

QString TaskSolver::randomString() {
    QString res;
    for (int i = 0; i < MAX_LEN; ++i) {
        res += alphanumeric[rand() % alphanumeric.size()];
    }
    return res;
}

TaskSolver::TaskSolver() : HashTable<QString>(127) {
    this->randomise();
}

void TaskSolver::fill(QTableWidget* table_widget) {
    table_widget->setRowCount(0);
    table_widget->setColumnCount(3);
    for (int i = 0; i < this->size; ++i) {
        Node* stack = this->stacks[i];
        if (stack == nullptr) {
            continue;
        }
        int span = 0;
        int first_row = table_widget->rowCount();
        while (stack != nullptr) {
            int row = table_widget->rowCount();
            auto twi = new QTableWidgetItem(QString::number(stack->key));
            table_widget->insertRow(row);
            table_widget->setItem(row, 1, twi);
            table_widget->setItem(row, 2, new QTableWidgetItem(stack->value));
            stack = stack->next;
            ++span;
        }
        table_widget->setItem(first_row, 0,
                              new QTableWidgetItem(QString::number(i)));
        if (span > 1) {
            //table_widget->setSpan(first_row, 0, span, 1);
        }
    }
}

std::pair<int, QString> TaskSolver::doTask() {
    std::pair<int, QString> res;
    res.first = INT32_MAX;
    for (int i = 0; i < this->size; ++i) {
        Node* stack = this->stacks[i];
        while (stack != nullptr) {
            if (stack->key < res.first) {
                res.first = stack->key;
                res.second = stack->value;
            }
            stack = stack->next;
        }
    }
    return res;
}

TaskSolver::~TaskSolver() {}

void TaskSolver::randomise() {
    this->clear();
    for (int i = 0; i < 255; ++i) {
        this->insert(rand(), this->randomString());
    }
}

std::pair<int, QString> TaskSolver::find(int key) {
    if (this->contains(key)) {
        return { key, this->get(key) };
    }
    return { -1, "aaa" };
}
