//
// Created by darina on 4/2/24.
//

#ifndef TASK2_FIRM_H
#define TASK2_FIRM_H

#include <QString>
#include "Candidate.h"

class Firm {

public:
    Firm() = default;

    const QString &getNameOfFirm() const;
    void setNameOfFirm(const QString &nameOfFirm);
    const QString &getVacancy() const;
    void setVacancy(const QString &vacancy);
    double getSalary() const;
    void setSalary(double salary);
    int getVacation() const;
    void setVacation(int vacation);
    bool isEducation() const;
    void setEducation(bool education);
    int getMinAge() const;
    void setMinAge(int minAge);
    int getMaxAge() const;
    void setMaxAge(int maxAge);
    int getExperience() const;
    void setExperience(int experience);
    static bool Match(Firm firm, Candidate candidate);

private:
    QString vacancy = "vacancy";
    double salary = 1;
    int vacation = 7;
    bool education = false;
    int minAge = 0, maxAge = 100;
    int experience = 0;
    QString nameOfFirm = "firm";

};


#endif //TASK2_FIRM_H
