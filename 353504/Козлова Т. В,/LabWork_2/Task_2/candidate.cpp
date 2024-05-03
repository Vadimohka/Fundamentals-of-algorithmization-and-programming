#include "candidate.h"

Candidate::Candidate(QString fullName, QString birthdayDate, QString speciality, QString minimumSalary,
                     QString havingHigherEducation, QString careerObjective)
    : m_fullName(fullName), m_birthdayDate(birthdayDate), m_speciality(speciality), m_minimumSalary(minimumSalary),
    m_havingHigherEducation(havingHigherEducation), m_careerObjective(careerObjective) {}


Candidate::Candidate(QString string)
{
    QStringList tokens = string.split(',');

    if (tokens.size() >= 1)
        m_fullName = tokens[0].trimmed();

    if (tokens.size() >= 2)
        m_birthdayDate = tokens[1].trimmed();

    if (tokens.size() >= 3)
        m_speciality = tokens[2].trimmed();

    if (tokens.size() >= 4)
        m_havingHigherEducation = tokens[3].trimmed();

    if (tokens.size() >= 5)
        m_careerObjective = tokens[4].trimmed();

    if (tokens.size() >= 6)
        m_minimumSalary = tokens[5].trimmed();
}


QString Candidate::FullName()
{
    return m_fullName;
}

QString Candidate::BirthdayDateStr()
{
    return m_birthdayDate;
}

QString Candidate::Speciality()
{
    return m_speciality;
}

QString Candidate::CareerObjective()
{
    return m_careerObjective;
}

QString Candidate::HavingHigherEducation()
{
    return m_havingHigherEducation;
}

QString Candidate::MinimumSalary()
{
    return m_minimumSalary;
}


QDate Candidate::BirthdayDate()
{
    QStringList tokens = BirthdayDateStr().split('.');

    int day = 0, month = 0, year = 0;
    if (tokens.size() >= 1)
        day = tokens[0].trimmed().toInt();

    if (tokens.size() >= 2)
        month = tokens[1].trimmed().toInt();

    if (tokens.size() >= 3)
        year = tokens[2].trimmed().toInt();

    return QDate(year, month, day);
}


QString Candidate::GetStr()
{
    return FullName() + ", " + BirthdayDateStr() + ", " + Speciality() + ", " +
           HavingHigherEducation() + ", " + CareerObjective() + ", " + MinimumSalary();
}
