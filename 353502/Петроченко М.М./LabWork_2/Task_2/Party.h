//
// Created by acryoz on 7.3.24.
//

#ifndef UNTITLED5_PARTY_H
#define UNTITLED5_PARTY_H

#include <QMap>
#include <QVector>
#include "Candidate.h"

class Party {
public:
    Party();
    Party(QString);
    QVector<Candidate>* candidates() const;
    QString name() const;
    double averageIncome() const;
    double averageAge() const;
    QString mostCommonProfession() const;
    void add(const Candidate&);
    Party& operator=(const Party& right);
    void edit(int, const Candidate&);
private:
    QVector<Candidate>* m_candidates;
    QString m_name;
};


#endif //UNTITLED5_PARTY_H
