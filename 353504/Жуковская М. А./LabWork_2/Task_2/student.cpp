#include "student.h"

Student::Student() {}

Student::Student(QString fio, QString fac, QString spec, QString gr, double _matan, double _oaip, double _agila, double _hist, double _dm)
{
    FIO = fio;
    faculty = fac;
    speciality = spec;

    group = gr;
    matan = _matan;
    oaip = _oaip;
    agila = _agila;
    hist = _hist;
    dm = _dm;

    avgMark = (matan + oaip + agila + hist + dm) / 5.0;
}

QString Student::getFIO() const
{
    return FIO;
}

QString Student::getFaculty() const
{
    return faculty;
}

QString Student::getSpeciality() const
{
    return speciality;
}

QString Student::getGroup() const
{
    return group;
}

double Student::getAvgMark() const
{
    return avgMark;
}

double Student::getMatan() const
{
    return matan;
}

double Student::getDm() const
{
    return dm;
}

double Student::getOaip() const
{
    return oaip;
}

double Student::getAgila() const
{
    return agila;
}

double Student::getHist() const
{
    return hist;
}


