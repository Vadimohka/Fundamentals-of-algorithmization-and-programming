//
// Created by acryoz on 08.06.24.
//

#ifndef LAB3_TASK5_COUNTER_H_
#define LAB3_TASK5_COUNTER_H_
#include <QDir>
#include <QString>
#include <cstdint>

struct Res {
    uint32_t folders;
    uint32_t files;
    uint32_t errors;
};

Res count(QString path);
#endif  //LAB3_TASK5_COUNTER_H_
