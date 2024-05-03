#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "workers.h"
#include <QString>
#include <QDate>
#include <QFileDialog>
#include <QFile>
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

private slots:
    void on_openfile_btn_clicked();

    void on_sorter_clicked();

    void on_fiosearch_btn_clicked();

    void on_pushButton_clicked();

    void on_worktime_clicked();

private:
    Ui::MainWindow *ui;
    QVector<workers> worker;
};
#endif // MAINWINDOW_H
