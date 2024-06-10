#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <QString>
#include <QDate>

class Candidate
{
public:
    Candidate(QString fullName, QString birthdayDate, QString speciality, QString minimumSalary,
              QString havingHigherEducation, QString careerObjective);
    Candidate(QString string);

    QString FullName();
    QString BirthdayDateStr();
    QString Speciality();
    QString CareerObjective();
    QString HavingHigherEducation();
    QString MinimumSalary();

    QDate BirthdayDate();

    QString GetStr();

protected:

private:
    QString m_fullName;
    QString m_birthdayDate;
    QString m_speciality;
    QString m_minimumSalary;
    QString m_havingHigherEducation;
    QString m_careerObjective;
};

#endif // CANDIDATE_H
