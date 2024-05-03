#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <date.h>
#include <ctime>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_buttonNextDay_clicked();

    void on_buttonPreviousDay_clicked();

    void on_buttonIsLeap_clicked();

    void on_buttonWeekNumber_clicked();

    void on_buttonDuration_clicked();

    void on_buttonDaysBirthday_clicked();

    void on_buttonBirth_clicked();

    void on_spinBoxBirthYear_valueChanged(int);

    void on_pushButtonDelete_clicked();

    void on_spinBoxBirthMonth_valueChanged(int);

    void on_spinBoxNewYear_valueChanged(int);

    void on_spinBoxNewMonth_valueChanged(int);

    void setTodayDate();

    void on_buttonNew_clicked();

private:
    Ui::MainWindow *ui;

    Date* dates;
    int count = 0;
    Date birthdayDate;
    Date today;
    QString sourseFile;

};
#endif // MAINWINDOW_H
