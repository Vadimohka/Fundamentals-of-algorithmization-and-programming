#include "student.h"

student::student()
{

}

void student::setFio(QString name){
    Fio = name;
}
void student::setMat(int x){
    Mat = x;
}
void student::setPhys(int x){
    Phys = x;
}
void student::setRus(int x){
    Rus = x;
}
void student::setAt(int x){
    At = x;
}
QString student::fio(){
    return Fio;
}
int student::mat(){
    return Mat;
}
int student::phys(){
    return Phys;
}
int student::rus(){
    return Rus;
}
int student::at(){
    return At;
}
double student::avarage(){
    return (Mat+Phys+Rus+At)/4;
}
