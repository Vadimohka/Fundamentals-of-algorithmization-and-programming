#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTableView>

#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString projDir;

    void getDataFromFile();
    void fillRow(int numberOfRow);

private slots:
    void on_chooseFileButton_clicked();

    void on_isLeapButton_clicked();

    void on_prevDayButton_clicked();

    void on_weekNumberButton_clicked();

    void on_addDateButton_clicked();

    void on_changeDateButton_clicked();

    void on_countBirthdayButton_clicked();

private:
    Ui::MainWindow *ui;
    QTableView *table;
    QStandardItemModel* model;
    QModelIndex index;
    QVector<Date*> dateList;
    QString pathToFile;
    QFile file;
    int numberOfRow = 0;
};
#endif // MAINWINDOW_H
