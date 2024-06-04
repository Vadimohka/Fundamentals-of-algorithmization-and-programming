#include "french.h"

void french::change_fre(QPushButton **a,QString,QPushButton **aa)
{

    a=aa;
    a[0]->setText("²");
    a[1]->setText("1");
    a[2]->setText("é");
    a[3]->setText(QString::fromUtf8("\u0022"));
    a[4]->setText("'");
    a[5]->setText("(");
    a[6]->setText("-");
    a[7]->setText("è");
    a[8]->setText("_");
    a[9]->setText("ç");
    a[10]->setText("à");
    a[11]->setText(")");
    a[12]->setText("=");
    a[15]->setText("A");
    a[16]->setText("Z");
    a[17]->setText("E");
    a[18]->setText("R");
    a[19]->setText("T");
    a[20]->setText("Y");
    a[21]->setText("U");
    a[22]->setText("I");
    a[23]->setText("O");
    a[24]->setText("P");
    a[25]->setText("^");
    a[26]->setText("$");
    a[27]->setText("*");
    a[29]->setText("Q");
    a[30]->setText("S");
    a[31]->setText("D");
    a[32]->setText("F");
    a[33]->setText("G");
    a[34]->setText("H");
    a[35]->setText("J");
    a[36]->setText("K");
    a[37]->setText("L");
    a[38]->setText("M");
    a[39]->setText("ù");
    a[42]->setText("W");
    a[43]->setText("X");
    a[44]->setText("C");
    a[45]->setText("V");
    a[46]->setText("B");
    a[47]->setText("N");
    a[48]->setText(",");
    a[49]->setText(";");
    a[50]->setText(":");
    a[51]->setText("!");

}
std::vector <QString> french::read_fre()
{
    std::vector <QString> a;
    QFile file("/home/paul/lab5/lab5_1/french.txt");
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);
    while(!in.atEnd())
    {
        a.push_back(in.readLine());
    }
    file.close();
    return a;
}
