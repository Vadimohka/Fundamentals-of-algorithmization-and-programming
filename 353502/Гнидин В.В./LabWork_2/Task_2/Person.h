//
// Created by volodya-petarda on 4/25/24.
//
#include <string>

#ifndef LAB2_2_PERSON_H
#define LAB2_2_PERSON_H


class Person {
private:
    int index;
    bool isMan;
    std::string name, hobby;
    int age, weight, height, minAge, maxAge, minHeight, maxHeight, minWeight, maxWeight;
public:
    static int globalIndex;
    Person(bool isMan, const std::string &name, const std::string &hobby, int age, int weight, int height, int minAge,
           int maxAge, int minHeight, int maxHeight, int minWeight, int maxWeight);
    Person();

    std::string getDescription();

    bool isMan1() const;

    void setIsMan(bool isMan);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getHobby() const;

    void setHobby(const std::string &hobby);

    int getAge() const;

    void setAge(int age);

    int getWeight() const;

    void setWeight(int weight);

    int getHeight() const;

    void setHeight(int height);

    int getMinAge() const;

    void setMinAge(int minAge);

    int getMaxAge() const;

    void setMaxAge(int maxAge);

    int getMinHeight() const;

    void setMinHeight(int minHeight);

    int getMaxHeight() const;

    void setMaxHeight(int maxHeight);

    int getMinWeight() const;

    void setMinWeight(int minWeight);

    int getMaxWeight() const;

    void setMaxWeight(int maxWeight);

    bool isMatched(Person *anotherPerson);
};


#endif //LAB2_2_PERSON_H
