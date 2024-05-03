#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QFile>
#include <QTimer>
#include <QFileDialog>
#include <QDesktopServices>
#include "my_date.h"
#include "functions_for_date.h"

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
    bool isColumnEmpty(int column);
    void startButtonsSetup();
    void ButtonsSetup();
    int compareStringInFile(const QString& targetString);

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_bntAddDate_clicked();

    void on_bntHB_clicked();

    void on_bntOpenDialog_clicked();

    void on_bntdatetoTable_clicked();

    void on_bntToRT_clicked();

    void on_bntIsLeepYear_clicked();

    void on_bntprev_clicked();

    void on_bntnext_clicked();

    void on_bntMoveHB_clicked();

    void on_bntWeekibYear_clicked();

    void on_bntGetnextday_clicked();

    void on_pushButton_clicked();

    void on_bnt_zamena_clicked();

private:
    bool correct_date = false;
    Ui::MainWindow *ui;
    QString my_path = "/home/fort3mio/Downloads/Labs_qt/second_lab/first_task/fileDates.txt";
    My_Date bithdaydate;
    My_Date lastDate;
    int cnt_list_of_hb = 0;
    functions_for_Date mw;
    bool HB = false;
    bool swap = false;
    QTimer *timer;
    int replacement_date = -1;
};
#endif // MAINWINDOW_H
