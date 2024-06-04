#ifndef LIST_H
#define LIST_H
#include <QString>

class List
{
public:
    List();
    QString Name;
    QString Surname;
    QString Dadsname;

    QString speciality;
    int group;

    int markMATH;
    int markProgramming;
    int markEnglish;

    float averageScore();

    void setName(QString name);
    void setSurname(QString surname);
    void setDadsname(QString dadsname);
    void setspeciality(QString speciality);
    void setgroup(QString group);
    void setmarkMATH(QString mark);
    void setmarkProgramming(QString mark);
    void setmarkEnglish(QString mark);
};

#endif // LIST_H
