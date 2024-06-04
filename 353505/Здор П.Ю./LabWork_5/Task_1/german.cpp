#include "german.h"

void German::change_ger(QPushButton **a,QString bel,QPushButton **aa)
{
    a=aa;
    a[0]->setText("^");
    a[11]->setText("ß");
    a[12]->setText("´");
    a[20]->setText("Z");
    a[25]->setText("Ü");
    a[26]->setText("+");
    a[38]->setText("Ö");
    a[39]->setText("Ä");
    a[42]->setText("Y");
    a[43]->setText("X");
    a[49]->setText(",");
    a[50]->setText(".");
    a[51]->setText("-");
}

std::vector <QString> German::read_ger()
{
    std::vector <QString> a;
    QFile file("/home/paul/lab5/lab5_1/german.txt");
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);
    while(!in.atEnd())
    {
        a.push_back(in.readLine());
    }
    file.close();
    return a;
}
