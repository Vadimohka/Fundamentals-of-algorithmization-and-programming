#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "animal.h"

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

    void showMenu();
    void choice(int num);

private slots:
    void getInput();

    void showMenuSlot();

    void choosePointSlot();

private:
    Ui::MainWindow *ui;

    int choiceNum;

    QString file1 = "/home/dima/Lab6/Task2/СебелевЛаб20.txt";
    QString file2 = "/home/dima/Lab6/Task2/СебелевЛаб20_0.txt";
    QString file3 = "/home/dima/Lab6/Task2/СебелевЛаб20_1.txt";
    QString file4 = "/home/dima/Lab6/Task2/СебелевЛаб20_2.bin";
    QString file5 = "/home/dima/Lab6/Task2/СебелевЛаб20_3.txt";

    QVector<char> array;
    QVector<Animal> animals;
};
#endif // MAINWINDOW_H
