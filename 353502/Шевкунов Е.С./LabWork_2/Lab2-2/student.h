#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include <QStringList>

class Student
{
public:
    Student(QString name, QString marks, QString group, QString form, QString speciality);

    QString getName() const { return *NAME; }
    QString getMarks() const { return *MARKS; }
    QString getGroup() const { return *GROUP; }
    QString getForm() const { return *FORM; }
    QString getSpeciality() const { return *SPECIALITY; }
    double getAverageMark();

private:
    QString *NAME;
    QString *MARKS;
    QString *GROUP;
    QString *FORM;
    QString *SPECIALITY;
};

#endif // STUDENT_H
