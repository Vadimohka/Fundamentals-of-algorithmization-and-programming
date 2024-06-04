#ifndef BEL_H
#define BEL_H
#include <QString>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <QTextStream>
class Bel
{
public:
   void change_bel(QPushButton **,QString,QPushButton **);
    std::vector <QString> read_bel();

};

#endif // BEL_H
