#include "abiturient.h"
#include <qjsondocument.h>
#include <qjsonobject.h>

Abiturient::Abiturient(const QString &name, const QString &specialty, double averageScore, int math, int russian, int physics)
    : m_name(name), m_specialty(specialty), m_averageScore(averageScore), m_math(math), m_russian(russian), m_physics(physics) {}

Abiturient::Abiturient(QJsonObject doc) {
    m_name = doc["fio"].toString();
    m_specialty = doc["specialty"].toString();
    m_averageScore = doc["averageScore"].toDouble();
    m_physics = doc["physics"].toInt();
    m_math = doc["math"].toInt();
    m_russian = doc["russian"].toInt();
}

QString Abiturient::getName() const {
    return m_name;
}

QString Abiturient::getSpecialty() const {
    return m_specialty;
}

double Abiturient::getAverageScore() const {
    return m_averageScore;
}

int Abiturient::getMath() const {
    return m_math;
}

int Abiturient::getRussian() const {
    return m_russian;
}

int Abiturient::getPhysics() const {
    return m_physics;
}
QJsonObject Abiturient::toJson() const {
    QJsonObject res;
    res["fio"] = m_name;
    res["specialty"] = m_specialty;
    res["averageScore"] = m_averageScore;
    res["physics"] = m_physics;
    res["math"] = m_math;
    res["russian"] = m_russian;
    return res;
}