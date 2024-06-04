#ifndef STATISTIC_H
#define STATISTIC_H
#include<QtCharts/QChart>
#include<QtCharts/QtCharts>
#include<QtCharts/QChartGlobal>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QValueAxis>
#include<encryption.h>
#include <QDate>
#include <QString>
class statistic
{
public:
    void process();
    void show();
private:
    QChartView *c_view;
    QDialog d;
     QBarSeries*b;

};

#endif // STATISTIC_H
