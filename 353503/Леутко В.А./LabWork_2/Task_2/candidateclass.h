#ifndef CANDIDATECLASS_H
#define CANDIDATECLASS_H

#include <QtWidgets>

class candidateClass
{
private:
    QString candidateName;
    QDate calendarBirthDate;
    QString speciality;
    QString higherEducationCandidate;
    QString desiredPosition;
    QString minSalary;

public:
    candidateClass()= default;

    QString getCandidateName();
    void setCandidateName(QString info);

    QDate getCalendarBirthDate();
    void setCalendarBirthDate(QDate info);

    QString getSpeciality();
    void setSpeciality(QString info);

    QString getHigherEducationCandidate();
    void setHigherEducationCandidate(QString info);

    QString getDesiredPosition();
    void setDesiredPosition(QString info);

    QString getMinSalary();
    void setMinSalary(QString info);

    QString getAllCandidateInfo();
};

#endif // CANDIDATECLASS_H
