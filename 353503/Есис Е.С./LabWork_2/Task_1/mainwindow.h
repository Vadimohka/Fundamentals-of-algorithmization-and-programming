#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "readtextfromfile.h"
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QObject>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QVector>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QFile file;
    void showPopup();

    bool IsValid(const QString&);//check correct date


    //QPushButton* AddDate;
    //QMessageBox* warningDate;//всплывающее окно

private:
    int day;
    int month;
    int year;



private slots:
    //void DifferenceBD();
    void UntilToday(QDate);
    void NumberOfWeek(QDate);
    void LeapYear(QDate);
    void showNextDay(QDate);
    void showPreviousDay(QDate);
    void openFile();
    void writeInFile(/*const QDate&*/);
    int calculateDateDifference(const QDate&);
    void writeDifferenceToFile(int difference);
    void readDatesAndCalculateDifferences();

    //void checkDateValidity();//slot of check
    void on_Addate_clicked();

    void on_openFile_clicked();

    //void on_saveButton_clicked();

    void on_informationButton_clicked();

    void on_differenceBD_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
