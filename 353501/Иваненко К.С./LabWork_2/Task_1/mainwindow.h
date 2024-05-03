#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "date.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int cnt2 = 0;
    QDate * dates = new QDate[100];
    Date * dates2 = new Date[100];
    QDate bday;
    QDate adate;
    bool chk;
    //QVector<QDate>
    MainWindow(QWidget *parent = nullptr);
    QFile file;
    ~MainWindow();
    void updatetable();
    int toChange = 0;

    int aday;
    int amonth;
    int ayear;

public slots:
    void on_selectfilebutton_clicked();
    void on_bdateEdit_userDateChanged(const QDate &date);
    void on_adddate_clicked();
    void on_spintable_valueChanged(int arg1);
    void on_changedate_clicked();

    void on_day_valueChanged(int arg1);
    void on_month_valueChanged(int arg1);
    void on_year_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H