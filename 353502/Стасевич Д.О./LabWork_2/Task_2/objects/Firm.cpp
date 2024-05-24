//
// Created by darina on 4/2/24.
//

#include "Firm.h"

#include <QDebug>

bool Firm::Match(Firm firm, Candidate candidate) {

    if(firm.getVacancy() != candidate.getVacancy())
        return false;

    if(firm.isEducation() > candidate.isEducation())
        return false;


    if(firm.getSalary() < candidate.getMinValue())
        return false;

    QDate today = QDate::currentDate();
    int full = today.year() - candidate.getDate().year();
    QDate modifyDate = today;
    modifyDate.setDate(candidate.getDate().year(), today.month(), today.day());
    if(modifyDate > candidate.getDate())
        full ++;
    if(full < firm.minAge || full > firm.maxAge)
        return false;

    int sumOfDays = 0;
    for(auto x : candidate.getExperience())
    {
        if(std::get<0>(x) == firm.getVacancy())
        {
            int dayStart = std::get<1>(x).toJulianDay();
            int dayfinish = std::get<2>(x).toJulianDay();
            sumOfDays += dayfinish - dayStart;
        }
    }
    if(sumOfDays / 365 < firm.experience)
        return false;
    return true;
}

const QString &Firm::getNameOfFirm() const {
    return nameOfFirm;
}

void Firm::setNameOfFirm(const QString &nameOfFirm) {
    Firm::nameOfFirm = nameOfFirm;
}

const QString &Firm::getVacancy() const {
    return vacancy;
}

void Firm::setVacancy(const QString &vacancy) {
    Firm::vacancy = vacancy;
}

double Firm::getSalary() const {
    return salary;
}

void Firm::setSalary(double salary) {
    if(salary > 0)
        Firm::salary = salary;
    else
        throw "Incorrect salary";
}

int Firm::getVacation() const {
    return vacation;
}

void Firm::setVacation(int vacation) {
    if(vacation < 0)
        throw "Incorrect vacation";
    Firm::vacation = vacation;
}

bool Firm::isEducation() const {
    return education;
}

void Firm::setEducation(bool education) {
    Firm::education = education;
}

int Firm::getMinAge() const {
    return minAge;
}

void Firm::setMinAge(int minAge) {
    if(minAge < 0 || minAge > maxAge)
        throw "Incorrect minimal age";
    Firm::minAge = minAge;
}

int Firm::getMaxAge() const {
    return maxAge;
}

void Firm::setMaxAge(int maxAge) {
    if(maxAge < minAge)
    {
        qDebug() << minAge << " " << maxAge;
        throw "Incorrect maximal age";
    }

    Firm::maxAge = maxAge;
}

int Firm::getExperience() const {
    return experience;
}

void Firm::setExperience(int experience) {
    if(experience < 0)
        throw "Incorrect experience";
    Firm::experience = experience;
}
