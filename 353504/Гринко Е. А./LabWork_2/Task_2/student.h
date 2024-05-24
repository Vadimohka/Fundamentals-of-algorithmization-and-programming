#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student();
    Student(int g, QString fio);
    Student(int g, QString fio, int m1, int p1, int h1, int m2, int p2, int h2);
    QString printStudent();
    QString printFio();
    int numOfGroup_;
    QString fio_;
    int w_math = 0;
    int w_prog = 0;
    int w_history = 0;
    int s_math = 0;
    int s_prog = 0;
    int s_history = 0;
    int w_averageMark = 0;
    int s_averageMark = 0;
};

#endif // STUDENT_H
