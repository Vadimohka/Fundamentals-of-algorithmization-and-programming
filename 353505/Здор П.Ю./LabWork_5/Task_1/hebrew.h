#ifndef HEBREW_H
#define HEBREW_H
#include <QString>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <QTextStream>
class hebrew
{
public:
    void change_hebrew(QPushButton **,QString,QPushButton **);
    std::vector <QString> read_hebrew();
};

#endif // HEBREW_H
