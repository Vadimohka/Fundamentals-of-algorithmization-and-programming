#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDate>
#include <QInputDialog>
#include <QMessageBox>
#include "mydata.h"

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

    void getInformation();

    void makeTable();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    bool proverka(QString vot);

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    mydata **moyaDate;
    QString pathFile;
    QString moidates;
    int kolvo;
};
#endif // MAINWINDOW_H
