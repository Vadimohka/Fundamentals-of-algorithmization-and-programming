#include "candidateclass.h"

QString candidateClass::getCandidateName()
{
    return candidateName;
}

void candidateClass::setCandidateName(QString info)
{
    candidateName = std::move(info);
}

QDate candidateClass::getCalendarBirthDate()
{
    return calendarBirthDate;
}

void candidateClass::setCalendarBirthDate(QDate info)
{
    calendarBirthDate = info;
}

QString candidateClass::getSpeciality()
{
    return speciality;
}

void candidateClass::setSpeciality(QString info)
{
    speciality = std::move(info);
}

QString candidateClass::getHigherEducationCandidate()
{
    return higherEducationCandidate;
}

void candidateClass::setHigherEducationCandidate(QString info)
{
    higherEducationCandidate = std::move(info);
}

QString candidateClass::getDesiredPosition()
{
    return desiredPosition;
}

void candidateClass::setDesiredPosition(QString info)
{
    desiredPosition = std::move(info);
}

QString candidateClass::getMinSalary()
{
    return minSalary;
}

void candidateClass::setMinSalary(QString info)
{
    minSalary = std::move(info);
}

QString candidateClass::getAllCandidateInfo()
{
    QString allCandidateInfo =
        "\nCandidate Name:\t\t" + candidateName + "\n" +
        "Birth Date:\t\t\t" + calendarBirthDate.toString("dd.MM.yyyy") + "\n" +
        "Speciality:\t\t\t" + speciality + "\n" +
        "Higher Education Candidate:\t" + higherEducationCandidate + "\n" +
        "Desired Position:\t\t" + desiredPosition + "\n" +
        "Minimum Salary:\t\t" + minSalary+ "\n\n";
    allCandidateInfo += "\n\n";

    return allCandidateInfo;
}
