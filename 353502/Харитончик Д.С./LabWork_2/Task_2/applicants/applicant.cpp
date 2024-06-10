#include "applicant.h"
#include <QFile>
#include <QTextStream>

//Applicant::Applicant() = default;

QString Applicant::getFullName() const {
    return fullName;
}

QString Applicant::getAverageScore() const {
    return averageScore;
}

QString Applicant::getSpecialty() const {
    return specialty;
}

QString Applicant::getScoresOfExams() const {
    return scoresOfExams;
}

void Applicant::setFullName(const QString info) {
    fullName = info;
}

void Applicant::setAverageScore(const QString info) {
    averageScore = info;
}

void Applicant::setSpecialty(const QString info) {
    specialty = info;
}

void Applicant::setScoresOfExams(const QString info) {
    scoresOfExams = info;
}

float Applicant::getTotalScore() const {
    float totalScore = 0;
    QStringList scoresList = scoresOfExams.split(", ");
    for (const QString &scoreStr : scoresList) {
        // Разбиваем строку на название предмета и оценку
        QStringList parts = scoreStr.split(": ");
        if (parts.size() == 2) {
            float score = parts[1].toFloat();
            totalScore += score;
        }
    }
    return totalScore;
}

QString Applicant::getAllInfo() const {
    QString allData =
            "Full name:\t" + fullName + "\n" +
            "Average score:\t" + averageScore + "\n" +
            "Specialty:\t" + specialty + "\n" +
            "Score of exams:\t" + scoresOfExams + "\n" +
            "Total score:\t" + QString::number(getTotalScore()) + "\n";

    allData += "\n\n";

    return allData;
}