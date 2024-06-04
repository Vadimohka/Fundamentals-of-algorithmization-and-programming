//
// Created by u on 14.04.24.
//

#ifndef TASK2_STUDENT_H
#define TASK2_STUDENT_H

#include <vector>
#include <QString>

class student
{
private:
    QString fio;
    QString speciality;
    QString group;
    std::vector<float> grades;

public:
    QString getFio();
    QString getSpeciality();
    QString getGroup();
    float getGrade(int numOfSubject);

    student(QString fio, QString speciality, QString group, float math, float programming, float philosophi);
};


#endif //TASK2_STUDENT_H
