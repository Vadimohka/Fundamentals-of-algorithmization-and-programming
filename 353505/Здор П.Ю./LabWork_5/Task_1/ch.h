#ifndef CH_H
#define CH_H
#include <QString>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <QTextStream>
class ch
{
public:
    void change_ch(QPushButton **,QString,QPushButton **);
    std::vector <QString> read_ch();
};

#endif // CH_H
