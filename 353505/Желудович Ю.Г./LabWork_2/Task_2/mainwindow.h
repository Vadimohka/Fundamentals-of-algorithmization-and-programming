#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include "vedomosti.h"

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
    void on_pushButton_add_clicked();

    void on_pushButton_add_2_clicked();

    bool CheckFile(QString line);
    void on_pushButton_save_clicked();

    void on_pushButton_poisk_clicked();

    void on_pushButton_poisk_2_clicked();

    void on_pushButton_sort_clicked();

private:
    Ui::MainWindow *ui;
    Vedomosti* vedomosti = new Vedomosti[100];
    int row=0;
};
#endif // MAINWINDOW_H
