#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <QString>
#include <QDate>

class Candidate
{
public:    
    Candidate();
    void makeAge();
    QString candidateName;
    QDate candBirthday;
    int candAge;
    QString candSpeciality;
    bool candHigherEduc;
    QString candPost;
    double candMinSalary;
};

#endif // CANDIDATE_H
