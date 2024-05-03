#include "projectclass.h"

#include<utility>

QString projectclass::get_number_of_people(){
    return number_of_people;
}

void projectclass::set_number_of_people(QString info){
    number_of_people = std::move(info);
}

QString projectclass::get_name(){
    return name;
}

void projectclass::set_name(QString info){
    name = std::move(info);
}

QString projectclass::get_age(){
    return age;
}

void projectclass::set_age(QString info){
    age = std::move(info);
}

QString projectclass::get_height(){
    return height;
}

void projectclass::set_height(QString info){
    height = std::move(info);
}

QString projectclass::get_weight(){
    return weight;
}

void projectclass::set_weight(QString info){
    weight = std::move(info);
}

QString projectclass::get_habits(){
    return habits;
}

void projectclass::set_habits(QString info){
    habits = std::move(info);
}

QString projectclass::get_hobby(){
    return hobby;
}

void projectclass::set_hobby(QString info){
    hobby = std::move(info);
}

QString projectclass::get_age_min(){
    return age_min;
}
void projectclass::set_age_min(QString info){
    age_min = std::move(info);
}

QString projectclass::get_age_max(){
    return age_max;
}

void projectclass::set_age_max(QString info){
    age_max = std::move(info);
}

QString projectclass::get_height_min(){
    return height_min;
}

void projectclass::set_height_min(QString info){
    height_min = std::move(info);
}

QString projectclass::get_height_max(){
    return height_max;
}

void projectclass::set_height_max(QString info){
    height_max = std::move(info);
}

QString projectclass::get_weight_min(){
    return weight_min;
}

void projectclass::set_weight_min(QString info){
    weight_min = std::move(info);
}

QString projectclass::get_weight_max(){
    return weight_max;
}

void projectclass::set_weight_max(QString info){
    weight_max = std::move(info);
}

QString projectclass::get_Odin_or_Odna(){
    return Odin_or_Odna;
}

void projectclass::set_Odin_or_Odna(QString info){
    Odin_or_Odna = std::move(info);
}

QString projectclass::get_All_Info(){
    QString allDate =
        "Порядковый номер:\t" + number_of_people + "\n" +
        "Имя:\t\t" + name+ "\n" +
        "Возраст:\t\t" + age + "\n" +
        "Рост:\t\t" + height + "\n" +
        "Вес:\t\t" + weight + "\n" +
        "Привычки:\t\t" + habits + "\n" +
        "Хобби:\t\t" + hobby + "\n"+
        "Диапазон возраста\tот " + age_min +" до "+age_max  + "\n" +
        "Диапазон роста\tот " + height_min +" до "+height_max+"\n" +
        "Диапазон веса\tот " + weight_min +" до "+weight_max+"\n" +
        "В паре:\t\t" + Odin_or_Odna + "\n";
    allDate += "\n\n";

    return allDate;
}
