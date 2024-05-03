#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QTableWidget>
#include <QDesktopServices>
#include <QFileDialog>
#include <QLineEdit>

#include "date.h"

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

    bool CheckString(QString);
    void ExtractFile();
    void SaveFile();
    void DisplayFiles();

private slots:
    void on_ConfirmBirthday_clicked();

    void on_ConfirmDate_ckicked();

    void on_OpenFile_clicked();


    void on_EnterBirthday_clicked();

    void on_ChangeDate_clicked();

    void on_NextDay_clicked();

    void on_PreviousDay_clicked();

    void on_Deffrence_clicked();

    void on_TillBirthday_clicked();

    void on_IsLeap_clicked();

    void on_DaysFromToday_clicked();

    void on_WeekNumber_clicked();

    void on_AddDate_clicked();

    void on_ConfirmAdd_ckicked();
    void on_DisplayAll_clicked();

private:
    Ui::MainWindow *ui;

    QWidget *BirthDayWidget;
    QLineEdit *EditBirthDay;

    QWidget *AddWidget;
    QLineEdit *EditAdd;

    QWidget *ChangeWidget;
    QLineEdit *EditDate;
    QLineEdit *EditNumber;

    QString path;

    Date Birthday = Date(0,0,0);
    QVector<Date> dates;
    QVector<int> num;

    short number_of_files = 0;

    // QFile file;
};
#endif // MAINWINDOW_H
