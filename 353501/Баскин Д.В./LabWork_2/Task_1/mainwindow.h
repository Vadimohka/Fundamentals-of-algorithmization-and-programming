#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <date.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget * = nullptr);
    ~MainWindow();

    void setItem(int);
private:
    Ui::MainWindow *ui;
    QFile file;
    QVector<Date> dates;
    void updateBirthday();
    QString input();
    QString birthday();
protected:
    bool formatCheck(QString);
private slots:
    void on_pushButton_addDate_clicked();
    void on_pushButton_changeDate_clicked();
    void on_pushButton_saveFile_clicked();
    void on_pushButton_openFile_clicked();
    void on_spinBox_day_valueChanged(int);
    void on_spinBox_month_valueChanged(int);
    void on_spinBox_year_valueChanged(int);
    void on_spinBox_dayB_valueChanged(int);
    void on_spinBox_monthB_valueChanged(int);
    void on_spinBox_yearB_valueChanged(int);
};
#endif // MAINWINDOW_H
