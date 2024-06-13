#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QVector>
#include <QMainWindow>
#include "date.h"
#include "file.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void cellEdited(int row, int column);

private slots:
    void on_pushButton_clicked();

    void on_loadFile_clicked();

    void on_saveFile_clicked();

    void on_updateDate_clicked();

    void on_updateDifDate_clicked();

    void on_addDate_clicked();

    void on_deleteDate_clicked();

private:
    Ui::MainWindow *ui;
    QVector <Date> dates;
    File projFile;
    Date bithdayDate, differenceDate;

    void updateTable();

};
#endif // MAINWINDOW_H
