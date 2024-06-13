//
// Created by acryoz on 7.3.24.
//

#ifndef UNTITLED5_CANDIDATE_H
#define UNTITLED5_CANDIDATE_H


#include <QString>
#include <QTextStream>

using uint = unsigned int;


class Candidate {
public:
    Candidate(QString, uint, QString, QString, uint, uint);
    QString name() const;
    uint region() const;
    QString party() const;
    QString occupation() const;
    [[nodiscard]] uint income() const;
    [[nodiscard]] uint age() const;
    bool operator<(const Candidate& right) const;
    bool operator>(const Candidate& right) const;
    Candidate& operator=(const Candidate& right);
    bool operator==(const Candidate& right) const;
    [[nodiscard]] QString print() const;
private:
    QString m_name;
    uint m_region;
    QString m_party;
    QString m_occupation;
    uint m_income;
    uint m_age;
};


#endif //UNTITLED5_CANDIDATE_H
