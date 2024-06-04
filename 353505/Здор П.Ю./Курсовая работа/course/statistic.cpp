#include "statistic.h"

void statistic::process() {
    Encryption hamil;
    std::string ss1;
    QFile file ("../../logs.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        std::string ss1=line.toStdString();

        hamil.Hamil_cipher(ss1);
    }
    file.close();
}
void statistic::show()
{
    QVector <QString> info;
    QFile file ("../../logs.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
        info.push_back(in.readLine());
    }
    file.close();
    double sum=0,sum1=0,sum3=0;
    QChart *chart=new QChart();
    b=new QBarSeries();
    QBarSet *barset1=new QBarSet("Количество использований за сегодня");
    QBarSet *barset2=new QBarSet("Количество использований за последний месяц");
    for(int i=info[info.size()-1].size()-1;i>-1;--i)
    {
        if(info[info.size()-1][i]=='1') sum++;
    }
    for(int i=info[info.size()-1].size()-1;i>-1;--i)
    {
        if(info[info.size()-1][i]=='1' &&info[info.size()-2]==QDate::currentDate().toString(Qt::ISODate) ) sum1++;
    }
    QDate date=QDate::currentDate();
    QString data=date.toString(Qt::ISODate);
    for(int i=info[info.size()-1].size()-1;i>-1;--i)
    {
        if(info[info.size()-1][i]=='1' &&info[info.size()-2][6]==data[6] ) sum3++;
    }
    QBarSet *barset3=new QBarSet("Количество использований за год");
    *barset3 << sum/15;
    *barset1 << sum1/30;
    *barset2 << sum3/250;
    b->append(barset3);
    b->append(barset1);
    b->append(barset2);
     chart->setTitle("Статистика использования приложения");
    QValueAxis *axis_y=new QValueAxis();
     axis_y->setRange(0,28);
    chart->addAxis(axis_y,Qt::AlignLeft);
   chart->addSeries(b);
    c_view=new QChartView(chart);

    QVBoxLayout *l=new QVBoxLayout(&d);
    l->addWidget(c_view);
    d.resize(1000,1000);
    d.show();
}
