#ifndef FIRM_H
#define FIRM_H

#include <QString>
#include <QDate>

class Firm
{
public:
    Firm(QString firmName, QString nameOfSpeciality, QString jobTitle, QString salary,
         QString numberOfVacationDays, QString havingHigherEducation, QString minAge, QString maxAge);
    Firm(QString string);

    QString FirmName();
    QString NameOfSpeciality();
    QString JobTitle();
    QString Salary();
    QString NumberOfVacationDays();
    QString HavingHigherEducation();
    QString MinAge();
    QString MaxAge();

    QString GetStr();

protected:

private:
    QString m_firmName;
    QString m_nameOfSpeciality;
    QString m_jobTitle;
    QString m_salary;
    QString m_numberOfVacationDays;
    QString m_havingHigherEducation;
    QString m_minAge;
    QString m_maxAge;
};

#endif // FIRM_H
