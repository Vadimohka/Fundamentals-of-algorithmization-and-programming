//
// Created by darina on 4/2/24.
//

#ifndef TASK2_CANDIDATE_H
#define TASK2_CANDIDATE_H

#include <QString>
#include <QDate>

class Candidate {

public:
    Candidate() = default;

    const QString &getName() const;
    void setName(const QString &name);
    const QDate &getDate() const;
    void setDate(const QDate &date);
    bool isEducation() const;
    void setEducation(bool education);
    const QString &getVacancy() const;
    void setVacancy(const QString &vacancy);
    double getMinValue() const;
    void setMinValue(double minValue);
    const QVector<std::tuple<QString, QDate, QDate>> &getExperience() const;
    void setExperience(const QVector<std::tuple<QString, QDate, QDate>> &experience);

private:

    QString name = "name";
    QDate date = QDate(1,1,1);
    bool education = false;
    QString vacancy = "vacancy";
    double minValue = 0;
    QVector<std::tuple<QString, QDate, QDate> > experience;

};


#endif //TASK2_CANDIDATE_H
