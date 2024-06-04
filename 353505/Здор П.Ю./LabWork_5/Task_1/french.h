#ifndef FRENCH_H
#define FRENCH_H
#include <QString>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <vector>
class french
{
public:
    void change_fre(QPushButton **,QString,QPushButton **);
    std::vector <QString> read_fre();
};

#endif // FRENCH_H
