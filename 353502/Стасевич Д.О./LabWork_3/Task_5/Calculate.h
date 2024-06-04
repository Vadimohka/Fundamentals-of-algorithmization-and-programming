//
// Created by darina on 4/12/24.
//

#ifndef TASK5_CALCULATE_H
#define TASK5_CALCULATE_H

#include <QString>
#include <utility>
#include <QFileDialog>
#include <QDir>

class Calculate {
public:
    static int CountDirectories(QString path);
    static int CountFiles(QString path);

};


#endif //TASK5_CALCULATE_H
