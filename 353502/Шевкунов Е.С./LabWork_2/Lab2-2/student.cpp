#include "student.h"

Student::Student(QString name, QString marks, QString group, QString form, QString speciality)
{
    NAME = new QString(name);
    MARKS = new QString(marks);
    GROUP = new QString(group);
    FORM = new QString(form);
    SPECIALITY = new QString(speciality);
}

double Student::getAverageMark()
{
    QString markString = *MARKS;
    QStringList markList = markString.split(" ");
    int sum = 0;
    int count = 0;
    foreach (QString mark, markList) {
        int value = mark.toInt();
        if (value >= 1 && value <= 10) {
            sum += value;
            count++;
        }
    }
    float avgMark = count > 0 ? static_cast<float>(sum) / count : 0.0f;
    return avgMark;
}
