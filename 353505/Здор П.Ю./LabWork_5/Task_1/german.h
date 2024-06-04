#ifndef GERMAN_H
#define GERMAN_H
#include <QString>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <QTextStream>
class German
{
public:
    void change_ger(QPushButton **,QString,QPushButton **);
    std::vector <QString> read_ger();
};

#endif // GERMAN_H
