#ifndef ARAB_H
#define ARAB_H
#include <QString>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <QTextStream>
class arab
{
public:
    void change_arab(QPushButton **,QString,QPushButton **);
    std::vector <QString> read_arab();
};

#endif // ARAB_H
