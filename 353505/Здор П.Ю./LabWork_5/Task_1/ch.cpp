#include "ch.h"
void ch::change_ch(QPushButton **a,QString ch,QPushButton **aa)
{
    a=aa;
    a[0]->setText("｀");
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
    a[11]->setText("－");
    a[12]->setText("＝");
    a[15]->setText("手");
    a[16]->setText("田");
    a[17]->setText("水");
    a[18]->setText("口");
    a[19]->setText("廿");
    a[20]->setText("卜");
    a[21]->setText("山");
    a[22]->setText("戈");
    a[23]->setText("人");
    a[24]->setText("心");
    a[25]->setText("「");
    a[26]->setText("」");
    a[27]->setText("、");
    a[29]->setText("日");
    a[30]->setText("尸");
    a[31]->setText("木");
    a[32]->setText("火");
    a[33]->setText("土");
    a[34]->setText("竹");
    a[35]->setText("十");
    a[36]->setText("大");
    a[37]->setText("中");
    a[38]->setText("；");
    a[39]->setText("'");
    a[42]->setText("　");
    a[43]->setText("║");
    a[44]->setText("金");
    a[45]->setText("女");
    a[46]->setText("月");
    a[47]->setText("弓");
    a[48]->setText("一");
    a[49]->setText("，");
    a[50]->setText("。");
    a[51]->setText("／");
}
std::vector <QString> ch::read_ch()
{
    std::vector <QString> a;
    QFile file("/home/paul/lab5/lab5_1/china.txt");
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);
    while(!in.atEnd())
    {
        a.push_back(in.readLine());
    }
    file.close();
    return a;
}
