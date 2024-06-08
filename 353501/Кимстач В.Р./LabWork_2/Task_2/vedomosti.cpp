#include "vedomosti.h"

Vedomosti::Vedomosti(){

}

QString Vedomosti::getName() {
    return this->name;
}

QString Vedomosti::getSurname() {
    return this->surname;
}

QString Vedomosti::getFathername() {
    return this->fathername;
}

QString Vedomosti::getSpeciality() {
    return this->speciality;
}

int Vedomosti::getAttestat() {
    return this->attestat;
}

int Vedomosti::getMath() {
    return this->math;
}

int Vedomosti::getFiz(){
    return this->fiz;
}

int Vedomosti::getRus() {
    return this->rus;
}

void Vedomosti::setName(QString name) {
    this->name=name;
}

void Vedomosti::setSurname(QString surname) {
    this->surname=surname;
}

void Vedomosti::setFathername(QString fathername) {
    this->fathername=fathername;
}

void Vedomosti::setSpeciality(QString spec) {
    this->speciality=spec;
}

void Vedomosti::setAttestat(int attestat) {
    this->attestat=attestat;
}

void Vedomosti::setMath(int math) {
    this->math=math;
}

void Vedomosti::setFiz(int fiz){
    this->fiz=fiz;
}

void Vedomosti::setRus(int rus) {
    this->rus=rus;
}

int Vedomosti::SummaBallov() {
    return (attestat)*10+math+fiz+rus;
}
Vedomosti::~Vedomosti(){}
