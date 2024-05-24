#include "hebrew.h"


void hebrew::change_hebrew(QPushButton **a,QString,QPushButton **aa)
{

    a=aa;
    a[0]->setText(";");
    a[1]->setText("1");
    a[2]->setText("2");
    a[3]->setText("3");
    a[4]->setText("4");
    a[5]->setText("5");
    a[6]->setText("6");
    a[7]->setText("7");
    a[8]->setText("8");
    a[9]->setText("9");
    a[10]->setText("0");
    a[11]->setText("-");
    a[12]->setText("=");
    a[15]->setText("/");
    a[16]->setText("'");
    a[17]->setText("ק");
    a[18]->setText("ר");
    a[19]->setText("א");
    a[20]->setText("ט");
    a[21]->setText("ו");
    a[22]->setText("ן");
    a[23]->setText("ם");
    a[24]->setText("פ");
    a[25]->setText("]");
    a[26]->setText("[");
    a[27]->setText("|");
    a[29]->setText("ש");
    a[30]->setText("ד");
    a[31]->setText("ג");
    a[32]->setText("כ");
    a[33]->setText("ע");
    a[34]->setText("י");
    a[35]->setText("ח");
    a[36]->setText("ל");
    a[37]->setText("ך");
    a[38]->setText("ף");
    a[39]->setText(",");
    a[42]->setText("ז");
    a[43]->setText("ס");
    a[44]->setText("ב");
    a[45]->setText("ה");
    a[46]->setText("נ");
    a[47]->setText("מ");
    a[48]->setText("צ");
    a[49]->setText("ת");
    a[50]->setText("ץ");
    a[51]->setText(".");

}
std::vector <QString> hebrew::read_hebrew()
{
    std::vector <QString> a;
    QFile file("/home/paul/lab5/lab5_1/hebrew.txt");
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);
    while(!in.atEnd())
    {
        a.push_back(in.readLine());
    }
    file.close();
    return a;
}

