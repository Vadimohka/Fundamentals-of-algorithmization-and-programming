#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class student
{
public:
    student();

    void setFio(QString name);
    void setMat(int x);
    void setPhys(int x);
    void setRus(int x);
    void setAt(int x);
    QString fio();
    int mat();
    int phys();
    int rus();
    int at();
    double avarage();


private:
    QString Fio;
    int Mat;
    int Phys;
    int Rus;
    int At;
};

#endif // STUDENT_H
