#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QFileInfo>
#include <QInputDialog>
#include <QMainWindow>
#include <QTextStream>
#include <iostream>
#include <fstream>

#include "toy.h"
#include "toyinfodialog.h"

#define FILENAME "SvidinskyLab20.txt"
#define FILEForArray "SvidinskyLab2.txt"
#define FILEForStruct "SvidinskyLab.txt"
#define FILEBIN "SvidinskyLab.bin"

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

    void getInputForToy();

    void getOutputForToy();

    void getInputForBinToy();

     void getOutputForBinToy();

private slots:
    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QVector<float>> _array;
    QVector<Toy> _toys;
};
#endif // MAINWINDOW_H
