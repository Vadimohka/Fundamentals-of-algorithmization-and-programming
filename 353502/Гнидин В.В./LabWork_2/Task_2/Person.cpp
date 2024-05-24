//
// Created by volodya-petarda on 4/25/24.
//

#include "Person.h"

int Person::globalIndex = 0;

Person::Person(bool isMan, const std::string &name, const std::string &hobby, int age, int weight, int height,
               int minAge, int maxAge, int minHeight, int maxHeight, int minWeight, int maxWeight) : isMan(isMan),
                                                                                                     name(name),
                                                                                                     hobby(hobby),
                                                                                                     age(age),
                                                                                                     weight(weight),
                                                                                                     height(height),
                                                                                                     minAge(minAge),
                                                                                                     maxAge(maxAge),
                                                                                                     minHeight(
                                                                                                             minHeight),
                                                                                                     maxHeight(
                                                                                                             maxHeight),
                                                                                                     minWeight(
                                                                                                             minWeight),
                                                                                                     maxWeight(
                                                                                                             maxWeight) {
    this->index = globalIndex++;
}

Person::Person() {

}

bool Person::isMan1() const {
    return isMan;
}

void Person::setIsMan(bool isMan) {
    Person::isMan = isMan;
}

const std::string &Person::getName() const {
    return name;
}

void Person::setName(const std::string &name) {
    Person::name = name;
}

const std::string &Person::getHobby() const {
    return hobby;
}

void Person::setHobby(const std::string &hobby) {
    Person::hobby = hobby;
}

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    Person::age = age;
}

int Person::getWeight() const {
    return weight;
}

void Person::setWeight(int weight) {
    Person::weight = weight;
}

int Person::getHeight() const {
    return height;
}

void Person::setHeight(int height) {
    Person::height = height;
}

int Person::getMinAge() const {
    return minAge;
}

void Person::setMinAge(int minAge) {
    Person::minAge = minAge;
}

int Person::getMaxAge() const {
    return maxAge;
}

void Person::setMaxAge(int maxAge) {
    Person::maxAge = maxAge;
}

int Person::getMinHeight() const {
    return minHeight;
}

void Person::setMinHeight(int minHeight) {
    Person::minHeight = minHeight;
}

int Person::getMaxHeight() const {
    return maxHeight;
}

void Person::setMaxHeight(int maxHeight) {
    Person::maxHeight = maxHeight;
}

int Person::getMinWeight() const {
    return minWeight;
}

void Person::setMinWeight(int minWeight) {
    Person::minWeight = minWeight;
}

int Person::getMaxWeight() const {
    return maxWeight;
}

void Person::setMaxWeight(int maxWeight) {
    Person::maxWeight = maxWeight;
}

bool Person::isMatched(Person *anotherPerson) {
    return ((anotherPerson->isMan ^ isMan) && anotherPerson->age >= minAge && anotherPerson->age <= maxAge && anotherPerson->height >= minHeight && anotherPerson->height <= maxHeight && anotherPerson->weight >= minWeight && anotherPerson->weight <= maxWeight);
}

std::string Person::getDescription() {
    return this->name + " " + std::to_string(this->age) + "\n" + "age: " + std::to_string(this->age) + "\n" + "weight: " + std::to_string(this->weight) + "\n"+ this->hobby;
}
