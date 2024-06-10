#include "../applicants/applicant.h"
#include "fileStream.h"
#include <QFile>
#include <QTextStream>

bool FileStream::LoadFromFile(const QString &fileName, QList<Applicant> &applicants) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        Applicant applicant;
        applicant.setFullName(in.readLine());
        applicant.setAverageScore(in.readLine());
        applicant.setSpecialty(in.readLine());
        applicant.setScoresOfExams(in.readLine());

        applicants.append(applicant);
    }

    file.close();
    return true;
}

bool FileStream::SaveToFile(const QString &fileName, const QList<Applicant> &applicants) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    for (const auto &applicant : applicants) {
        out << applicant.getFullName() << '\n'
            << applicant.getAverageScore() << '\n'
            << applicant.getSpecialty() << '\n'
            << applicant.getScoresOfExams() << '\n';
    }

    file.close();
    return true;
}