#pragma once
#include <QtWidgets>

class Applicant {
private:
    QString fullName;
    QString averageScore;
    QString specialty;
    QString scoresOfExams;

public:
    Applicant() = default;

    QString getFullName() const;
    void setFullName(const QString info);

    QString getAverageScore() const;
    void setAverageScore(const QString info);

    QString getSpecialty() const;
    void setSpecialty(const QString info);

    QString getScoresOfExams() const;
    void setScoresOfExams(const QString info);

    float getTotalScore() const;

    QString getAllInfo() const;
};
