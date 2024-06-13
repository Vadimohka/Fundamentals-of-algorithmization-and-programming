//
// Created by acryoz on 7.3.24.
//

#include "../headers/Candidate.h"


Candidate::Candidate(QString n_name, uint n_region, QString n_party, QString n_occupation
                     , uint n_income, uint n_age) {
    this->m_name = n_name;
    this->m_region = n_region;
    this->m_party = n_party;
    this->m_occupation = n_occupation;
    this->m_income = n_income;
    this->m_age = n_age;
}


QString Candidate::name() const{
    return this->m_name;
}


uint Candidate::income() const{
    return this->m_income;
}


uint Candidate::region() const{
    return this->m_region;
}


QString Candidate::occupation() const{
    return this->m_occupation;
}


QString Candidate::party() const{
    return this->m_party;
}


uint Candidate::age() const {
    return this->m_age;
}

bool Candidate::operator<(const Candidate &right) const {
    int i = 0;
    while (this->m_name[i].unicode() == right.name().at(i).unicode()){
        ++i;
    }
    return this->m_name[i].unicode() < right.name().at(i).unicode();
}


bool Candidate::operator>(const Candidate &right) const {
    int i = 0;
    while (this->m_name[i].unicode() == right.name().at(i).unicode()){
        ++i;
    }
    return this->m_name[i].unicode() > right.name().at(i).unicode();
}


bool Candidate::operator==(const Candidate& right) const{
    return this->m_name == right.name();
}


Candidate &Candidate::operator=(const Candidate &right) {
    if(this == &right){
        return *this;
    }
    this->m_name = right.name();
    this->m_age = right.age();
    this->m_party = right.party();
    this->m_occupation = right.occupation();
    this->m_income = right.income();
    this->m_region = right.region();
    return *this;
}


QString Candidate::print() const{
    QString res;
    QTextStream out(&res);
    out << "Candidate: " << this->name() << '\n';
    out << "Age: " << this->age() << '\n';
    out << "Party: " << this->party() << '\n';
    out << "Region: " << this->region() << '\n';
    out << "Occupation: " << this->occupation() << '\n';
    out << "Income: " << this->income() << '\n';
    out << "-----------------------------------------------\n";
    return res;
}