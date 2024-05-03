#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "date.h" // Включаем заголовочный файл с классом Date

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateNextDayTable(const QString &nextDay);
    void updatePreviousDayTable(const QString &previousDay);
    void updateIsLeapTable(const QString &leapStatus);
    void updateWeekNumberTable(short weekNumber);

    void calculateDaysTillBirthday();







    void on_readfiledata_clicked();

    void on_nextdayfile_clicked();

    void on_differenceDay_clicked();



    void on_adddays_clicked();

    void on_removeDate_clicked();

    void on_calculateDaysToBirthday_clicked();

private:
    Ui::MainWindow *ui;
    Date *date; // Добавляем объект класса Date
Date** readDatesFromFile(const QString& filePath, int& count);
    void removeDateFromFile( int index);

};
#endif // MAINWINDOW_H
