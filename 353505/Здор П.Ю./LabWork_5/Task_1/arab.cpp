#include "arab.h"


void arab::change_arab(QPushButton **a,QString,QPushButton **aa)
{

    a=aa;
    a[0]->setText("ذ");
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
    a[15]->setText("ض");
    a[16]->setText("ص");
    a[17]->setText("ث");
    a[18]->setText("ق");
    a[19]->setText("ف");
    a[20]->setText("غ");
    a[21]->setText("ع");
    a[22]->setText("ه");
    a[23]->setText("خ");
    a[24]->setText("ح");
    a[25]->setText("ج");
    a[26]->setText("د");
    a[27]->setText("|");
    a[29]->setText("ش");
    a[30]->setText("س");
    a[31]->setText("ي");
    a[32]->setText("ب");
    a[33]->setText("ل");
    a[34]->setText("ا");
    a[35]->setText("ت");
    a[36]->setText("ن");
    a[37]->setText("م");
    a[38]->setText("ك");
    a[39]->setText("ط");
    a[42]->setText("ئ");
    a[43]->setText("ء");
    a[44]->setText("ؤ");
    a[45]->setText("ر");
    a[46]->setText("لا");
    a[47]->setText("ى");
    a[48]->setText("ة");
    a[49]->setText("و");
    a[50]->setText("ز");
    a[51]->setText("ظ");

}
std::vector <QString> arab::read_arab()
{
    std::vector <QString> a;
    QFile file("/home/paul/lab5/lab5_1/arab.txt");
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);
    while(!in.atEnd())
    {
        a.push_back(in.readLine());
    }
    file.close();
    return a;
}

