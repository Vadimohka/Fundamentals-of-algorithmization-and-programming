#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student();
    Student(QString fio, QString fac, QString spec, QString gr, double _matan, double _oaip, double _agila, double _hist, double _dm);

    QString getFIO() const;
    QString getFaculty() const;
    QString getSpeciality() const;
    QString getGroup() const;
    double getAvgMark() const;

    double getMatan() const;

    double getDm() const;

    double getOaip() const;

    double getAgila() const;

    double getHist() const;

private:
    QString FIO, faculty, speciality, group;
    double matan, oaip, agila, hist, dm;
    double avgMark;
};

#endif // STUDENT_H
