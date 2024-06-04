#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "consoleedit.h"
#include <QTimer>
#include <QFile>
#include <iostream>
#include <fstream>
#include <locale>

#include <Sportsman.h>

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


    QString input();
    int inputInt();
    double inputDouble();

    void print(QString string);
    void print(wchar_t ch);

    void printMenu();
private:
    Ui::MainWindow *ui;
    ConsoleEdit* console;
    QString inputedString;
    QEventLoop* loop;

public slots:
    void run();

    void runFirstPunkt();
    void runSecondPunkt();
    void runThirdPunkt();
    void runFourthPunkt();
    void runFifthPunkt();


};
#endif // MAINWINDOW_H
