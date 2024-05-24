#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "date.h";

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
    void on_addDat_button_clicked();

    void on_openFileButton_clicked();

    void on_SelectDate_button_clicked();

    void on_changeDate_button_clicked();

    void on_nextDay_button_clicked();

    void on_prevDay_button_clicked();

    void deactivateBtns();
    void activateBtns();

    void on_isLeap_button_clicked();

    void on_WeekNum_button_clicked();

    void on_Duration_button_clicked();

    void on_BDay_button_clicked();

    bool isDateCorrect(QString);

private:
    Ui::MainWindow *ui;
    Date* dates = new Date[100];
    int curDateInd = -1;
    int datesCount = 0;
};
#endif // MAINWINDOW_H
