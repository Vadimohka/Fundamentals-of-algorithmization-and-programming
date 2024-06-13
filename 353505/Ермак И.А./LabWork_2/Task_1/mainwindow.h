#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <date.h>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QMap>
#include <QItemSelectionModel>
#include <QModelIndexList>>

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

protected:
    void InputValidation(QString checkedText);
    void DateValidation(QString checkedDate);
    Date InputValidationDate(QString checkedDate);
    void InputData(Date *InputDate);
    void CheckedTable();
    void StyleSheet();
    //void paintEvent(QPaintEvent *event);

private slots:
    void on_loadDateButton_clicked();

    void on_ButtonNextDay_clicked();

    void on_ButtonPreviousDay_clicked();

    void on_ButtonDuration_clicked();

    void on_ButtonBirthDaySearch_clicked();

    void on_ButtonLeapYear_clicked();

    void on_ButtonWeek_clicked();

    void on_ButtonAddDate_clicked();

private:
    Ui::MainWindow *ui;
    Date *date;
    QVector<Date*> dates;
};
#endif // MAINWINDOW_H
