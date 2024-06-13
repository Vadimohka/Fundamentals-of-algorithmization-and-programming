//
// Created by acryoz on 7.3.24.
//

#include "../headers/Party.h"


Party::Party() {
    this->m_name = "Default";
    this->m_candidates = new QVector<Candidate>;
}

Party::Party(QString name) {
    this->m_candidates = new QVector<Candidate>;
    this->m_name = name;
}

QString Party::name() const{
    return this->m_name;
}


QVector<Candidate> *Party::candidates() const{
    return this->m_candidates;
}


double Party::averageIncome() const{
    double avg = 0.0;
    for(int i = 0; i < this->m_candidates->size(); ++i){
        avg += this->m_candidates->at(i).income();
    }
    return avg/this->m_candidates->size();
}


double Party::averageAge() const{
    double avg = 0.0;
    for(int i = 0; i < this->m_candidates->size(); ++i){
        avg += this->m_candidates->at(i).age();
    }
    return avg/this->m_candidates->size();
}


QString Party::mostCommonProfession() const{
    QMap<QString, int> ocount;
    for(int i = 0; i < this->m_candidates->size(); ++i){
        if(ocount.contains(this->m_candidates->at(i).occupation())){
            ocount[this->m_candidates->at(i).occupation()] += 1;
        }
        else{
            ocount.insert(this->m_candidates->at(i).occupation(), 1);
        }
    }
    int max = 0;
    QString common;
    for(auto item = ocount.keyValueBegin(); item != ocount.keyValueEnd(); ++item){
        if(item->second > max){
            max = item->second;
            common = item->first;
        }
    }
    return common;
}


Party &Party::operator=(const Party &right) {
    if(&right != this){
        this->m_name = right.name();
        this->m_candidates = new QVector<Candidate>;
        for(int i = 0; i < right.candidates()->size(); ++i){
            (*this->m_candidates)[i] = (*right.candidates())[i];
        }
    }
    return *this;
}

void Party::edit(int n, const Candidate& c) {
    (*this->m_candidates)[n] = c;
}

void Party::add(const Candidate& c) {
    this->m_candidates->append(c);
}
