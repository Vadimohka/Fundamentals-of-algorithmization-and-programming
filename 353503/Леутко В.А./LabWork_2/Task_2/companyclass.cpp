#include "companyclass.h"

QString companyClass::getCompanyName()
{
    return companyName;
}

void companyClass::setCompanyName(QString info)
{
    companyName = std::move(info);
}

QString companyClass::getNameOfSpecialty()
{
    return nameOfSpecialty;
}

void companyClass::setNameOfSpecialty(QString info)
{
    nameOfSpecialty = std::move(info);
}

QString companyClass::getPositionName()
{
    return positionName;
}

void companyClass::setPositionName(QString info)
{
    positionName = std::move(info);
}

QString companyClass::getSalary()
{
    return salary;
}

void companyClass::setSalary(QString info)
{
    salary = std::move(info);
}

QString companyClass::getVacationDays()
{
    return vacationDays;
}

void companyClass::setVacationDays(QString info)
{
    vacationDays = std::move(info);
}

QString companyClass::getHigherEducation()
{
    return higherEducation;
}

void companyClass::setHigherEducation(QString info)
{
    higherEducation = std::move(info);
}

int companyClass::getFromAge()
{
    return fromAge;
}

void companyClass::setFromAge(int info)
{
    fromAge = std::move(info);
}

int companyClass::getToAge()
{
    return toAge;
}

void companyClass::setToAge(int info)
{
    toAge = std::move(info);
}

QString companyClass::getAllCompanyInfo()
{
    QString allCompanyInfo =
        "Company Name:\t\t" + companyName + "\n" +
        "Name Of Specialty:\t\t" + nameOfSpecialty + "\n" +
        "Position Name:\t\t" + positionName + "\n" +
        "Salary:\t\t\t" + salary + "\n" +
        "Vacation Days:\t\t\t" + vacationDays + "\n" +
        "Higher Education:\t\t" + higherEducation + "\n" +
        "From Age:\t\t\t" + QString::number(fromAge) + "\n" +
        "To Age:\t\t\t" + QString::number(toAge) + "\n\n" ;
    allCompanyInfo += "\n\n";

    return allCompanyInfo;
}
