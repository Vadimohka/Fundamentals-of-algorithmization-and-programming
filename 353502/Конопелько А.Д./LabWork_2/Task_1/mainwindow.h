#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QFileDialog>
#include <QVector>
#include <QString>
//#include <ios>
//#include <string>
//#include <fstream>
#include "mydate.h"

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
    void on_pushButton_clicked();

    void on_pushButton_next_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_previous_clicked();

    void on_pushButton_BD_clicked();

    void on_pushButton_diverse_clicked();

    void on_pushButton_change_clicked();

    //void on_pushButton_2_clicked();

private:
    bool cellChosen = false;
    int chosenRow = -1;
    int chosenColumn = -1;
    int szInFile = 0;
    bool choseDateCheck = false;
    QDate chosenDate;
    QString sFilePath;
    Ui::MainWindow *ui;
    MyDate* mDate;
    MyDate* date;
    MyDate* miDate;
    MyDate* mmDate;
    QVector<MyDate> vecDates;
};
#endif // MAINWINDOW_H
