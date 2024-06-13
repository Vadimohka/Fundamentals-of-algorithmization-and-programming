#include "firm.h"

Firm::Firm(QString firmName, QString nameOfSpeciality, QString jobTitle, QString salary,
         QString numberOfVacationDays, QString havingHigherEducation, QString minAge, QString maxAge)
    : m_firmName(firmName), m_nameOfSpeciality(nameOfSpeciality), m_jobTitle(jobTitle), m_salary(salary),
    m_numberOfVacationDays(numberOfVacationDays), m_havingHigherEducation(havingHigherEducation),
    m_minAge(minAge), m_maxAge(maxAge) {}


Firm::Firm(QString string)
{
    QStringList tokens = string.split(',');

    if (tokens.size() >= 1)
        m_firmName = tokens[0].trimmed();

    if (tokens.size() >= 2)
        m_nameOfSpeciality = tokens[1].trimmed();

    if (tokens.size() >= 3)
        m_jobTitle = tokens[2].trimmed();

    if (tokens.size() >= 4)
        m_salary = tokens[3].trimmed();

    if (tokens.size() >= 5)
        m_numberOfVacationDays = tokens[4].trimmed();

    if (tokens.size() >= 6)
        m_havingHigherEducation = tokens[5].trimmed();

    if (tokens.size() >= 7)
        m_minAge = tokens[6].trimmed();

    if (tokens.size() >= 8)
        m_maxAge = tokens[7].trimmed();
}


QString Firm::FirmName()
{
    return m_firmName;
}

QString Firm::NameOfSpeciality()
{
    return m_nameOfSpeciality;
}

QString Firm::JobTitle()
{
    return m_jobTitle;
}

QString Firm::Salary()
{
    return m_salary;
}

QString Firm::NumberOfVacationDays()
{
    return m_numberOfVacationDays;
}

QString Firm::HavingHigherEducation()
{
    return m_havingHigherEducation;
}

QString Firm::MinAge()
{
    return m_minAge;
}

QString Firm::MaxAge()
{
    return m_maxAge;
}


QString Firm::GetStr()
{
    return FirmName() + ", " + NameOfSpeciality() + ", " + JobTitle() + ", " + Salary() + ", " +
        NumberOfVacationDays() + ", " + HavingHigherEducation() + ", " + MinAge() + ", " + MaxAge();
}
