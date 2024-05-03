#ifndef VEDOMOSTI_H
#define VEDOMOSTI_H

#include <QString>

class Vedomosti{
    QString name;
    QString surname;
    QString fathername;
    QString speciality;
    int attestat;
    int math;
    int fiz;
    int rus;
public:
    Vedomosti();
    QString getName();
    QString getSurname();
    QString getFathername();
    QString getSpeciality();
    int getAttestat();
    int getMath();
    int getFiz();
    int getRus();
    void setName(QString name);
    void setSurname(QString surname);
    void setFathername(QString fathername);
    void setSpeciality(QString speciality);
    void setAttestat(int);
    void setMath(int);
    void setFiz(int);
    void setRus(int);
    int SummaBallov();
};

#endif // VEDOMOSTI_H
