#ifndef ABITURIENT_H
#define ABITURIENT_H

#include <QString>
#include <QVector>
#include <QJsonObject>
#include <qjsondocument.h>
#include <qjsonobject.h>

class Abiturient {
public:
    Abiturient(const QString &name, const QString &specialty, double averageScore, int math, int russian, int physics);
    Abiturient(QJsonObject obj);

    QString getName() const;
    QString getSpecialty() const;
    double getAverageScore() const;
    int getPhysics() const;
    int getMath() const;
    int getRussian() const;
    QJsonObject toJson() const;

private:
    QString m_name;
    QString m_specialty;
    double m_averageScore;
    int m_physics;
    int m_math;
    int m_russian;
};

#endif // ABITURIENT_H
