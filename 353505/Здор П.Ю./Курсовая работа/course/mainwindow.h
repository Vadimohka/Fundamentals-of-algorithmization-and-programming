#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <encryption.h>
#include <QCheckBox>
#include <QVector>
#include <QtWidgets>
#include <QDialog>
#include <download.h>
#include <download_nv.h>
#include <QWindow>
#include <QDate>
#include "update.h"
#include "delete.h"
#include "statistic.h"
#include <QtCharts/QChartView>
#include<QtCharts/QBarSeries>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void change(int);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QProcess process;
    QProcess check;
    Encryption aa;
    QVector <QCheckBox*>ch1;
    QVector <QPushButton*> ch2;
    bool fl1=0;
    bool fl2=0;
    bool fl3=0;
    QVector <int> state;
    QTimer timer;
    std::vector<double>st_info;
    statistic h;

};
#endif // MAINWINDOW_H
