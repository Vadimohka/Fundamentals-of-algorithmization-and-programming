#ifndef COMPANYCLASS_H
#define COMPANYCLASS_H

#include <QtWidgets>

class companyClass
{
private:
    QString companyName;
    QString nameOfSpecialty;
    QString positionName;
    QString salary;
    QString vacationDays;
    QString higherEducation;
    int fromAge;
    int toAge;
public:
    companyClass() = default;

    QString getCompanyName();
    void setCompanyName(QString info);

    QString getNameOfSpecialty();
    void setNameOfSpecialty(QString info);

    QString getPositionName();
    void setPositionName(QString info);

    QString getSalary();
    void setSalary(QString info);

    QString getVacationDays();
    void setVacationDays(QString info);

    QString getHigherEducation();
    void setHigherEducation(QString info);

    int getFromAge();
    void setFromAge(int info);

    int getToAge();
    void setToAge(int info);

    QString getAllCompanyInfo();
};

#endif // COMPANYCLASS_H
