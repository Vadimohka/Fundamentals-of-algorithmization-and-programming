  #include "candidate.h"

Candidate::Candidate()
    {}

int Candidate::getNumOfDistrict()
{
    return this->_num_of_district;
}

QString Candidate::getFullName()
{
    return this->_fullname;
}

QString Candidate::getPartyName()
{
    return this->_partyname;
}

int Candidate::getAge()
{
    return this->_age;
}

QString Candidate::getProfession()
{
    return this->_profession;
}

int Candidate::getIncome()
{
    return this->_income_for_last_year;
}

void Candidate::setNumOfDistrict(int num)
{
    this->_num_of_district = num;
}

void Candidate::setFullName(QString fullname)
{
    this->_fullname = fullname;
}

void Candidate::setPartyName(QString partyname)
{
    this->_partyname = partyname;
}

void Candidate::setAge(int age)
{
    this->_age = age;
}

void Candidate::setProfession(QString profession)
{
    this->_profession = profession;
}

void Candidate::setIncome(int income)
{
    this->_income_for_last_year = income;
}

QString Candidate::toString()
{
    QString str = QString::number(this->getNumOfDistrict()) + "-" + this->getFullName() + "-" +
                      this->getPartyName() + "-" + QString::number(this->getAge()) + "-" + this->getProfession() +
                      "-" + QString::number(this->getIncome()) + "\n";
        return str;
}
