//
// Created by acryoz on 26.05.24.
//

#ifndef LAB7_TASK3_TASKSOLVER_H_
#define LAB7_TASK3_TASKSOLVER_H_

#include <QString>
#include <QTableWidget>
#include "hashtable.h"

const QString alphanumeric =
    "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
const int MAX_LEN = 10;

class TaskSolver : public HashTable<QString> {
   public:
    static QString randomString();
    TaskSolver();
    ~TaskSolver();
    void randomise();
    void fill(QTableWidget*);
    std::pair<int, QString> find(int key);
    std::pair<int, QString> doTask();
};


#endif  //LAB7_TASK3_TASKSOLVER_H_
