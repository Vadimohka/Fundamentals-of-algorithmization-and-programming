#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <iostream>

class Patient
{
public:
    QString name;
    QString gender;
    long long age;
    QString diagnosis;
    long long number;
    Patient();
    ~Patient();
    Patient(QString a, QString b, long long c, QString d, long long e) : name(a), gender(b), age(c), diagnosis(d), number(e) {}
};

#endif // PATIENT_H