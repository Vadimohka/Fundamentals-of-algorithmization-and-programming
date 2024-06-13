#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <QString>

class Candidate
{
public:
    Candidate();
    int getNumOfDistrict();
    QString getFullName();
    QString getPartyName();
    int getAge();
    QString getProfession();
    int getIncome();
    void setNumOfDistrict(int num);
    void setFullName(QString fullname);
    void setPartyName(QString partyname);
    void setAge(int age);
    void setProfession(QString profession);
    void setIncome(int income);
    QString toString();

private:
    int _num_of_district;
    QString _fullname;
    QString _partyname;
    int _age;
    QString _profession;
    int _income_for_last_year;
};

#endif // CANDIDATE_H
