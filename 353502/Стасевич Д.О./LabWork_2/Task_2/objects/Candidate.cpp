//
// Created by darina on 4/2/24.
//

#include "Candidate.h"

#include <QDebug>

const QString &Candidate::getName() const {
    return name;
}

void Candidate::setName(const QString &name) {
    Candidate::name = name;
}

const QDate &Candidate::getDate() const {
    return date;
}

void Candidate::setDate(const QDate &date) {
    QDate today = QDate::currentDate();
    if(date <= today)
    {
        Candidate::date = date;
        qDebug() << "ok set date" << " " << Candidate::date.day() << " " << Candidate::date.month() << " " << Candidate::date.year();
    }

    else
        throw "Incorrect date.";
}

bool Candidate::isEducation() const {
    return education;
}

void Candidate::setEducation(bool education) {
    Candidate::education = education;
}

const QString &Candidate::getVacancy() const {
    return vacancy;
}

void Candidate::setVacancy(const QString &vacancy) {
    Candidate::vacancy = vacancy;
}

double Candidate::getMinValue() const {
    return minValue;
}

void Candidate::setMinValue(double minValue) {
    if(minValue < 0)
        throw "too small";
    else
        Candidate::minValue = minValue;
}

const QVector<std::tuple<QString, QDate, QDate>> &Candidate::getExperience() const {
    return experience;
}

void Candidate::setExperience(const QVector<std::tuple<QString, QDate, QDate>> &experience) {
    for(auto x : experience)
    {
        if(std::get<1>(x) > std::get<2>(x) || Candidate::date > std::get<1>(x) || std::get<2>(x) > QDate::currentDate())
        {
            qDebug() << Candidate::date.toString("dd.MM.yyyy") << " " << std::get<1>(x).toString("dd.MM.yyyy");
            throw "Incorrect date";
        }
    }
    Candidate::experience = experience;
}
