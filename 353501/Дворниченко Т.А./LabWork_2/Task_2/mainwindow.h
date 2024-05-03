#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

#include "disk.h"

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
    void on_pushButton_Add_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_showAll_clicked();


    void on_pushButton_search_clicked();

    void on_pushButton_sort_clicked();

private:
    Ui::MainWindow *ui;
    QVector <Detail> details;
    QVector <Detail> range;
    int num ;
    void generateCombinations(const QVector<QVector<Detail>> &, QVector<Detail>, int);
    QVector <Detail> find;
    void arrayToTable(QVector<Detail>);
    void arrayToTableSort(QVector<Detail>);
};
#endif // MAINWINDOW_H
