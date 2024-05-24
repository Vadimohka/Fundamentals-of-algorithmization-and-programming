//
// Created by u on 14.04.24.
//

#include "student.h"

#include <utility>

QString student::getFio()
{
    return fio;
}

QString student::getSpeciality()
{
    return speciality;
}

QString student::getGroup()
{
    return group;
}

float student::getGrade(int numOfSubject)
{
    return grades[numOfSubject];
}

student::student(QString fio, QString speciality, QString group, float math, float programming, float philosophi)
    : fio(std::move(fio)), speciality(std::move(speciality)), group(std::move(group)), grades({math, programming, philosophi}) {}
