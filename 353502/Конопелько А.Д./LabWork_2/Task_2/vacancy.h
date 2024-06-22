#ifndef VACANCY_H
#define VACANCY_H
#include <QString>
class Vacancy
{
public:
    Vacancy();

    QString firmName;
    QString speciality;
    QString postName;
    double salary;
    int vacationDuration;
    bool higherEducation;
    int minAge;
    int maxAge;
};

#endif // VACANCY_H
