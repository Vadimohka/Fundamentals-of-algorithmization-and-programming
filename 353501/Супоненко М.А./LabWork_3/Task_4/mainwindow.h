#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void solveHanoi();
    void clearOutput();

private:
    Ui::MainWindow *ui;
    void hanoi(int n, char from_rod, char to_rod, char aux_rod);
    void printMove(char from_rod, char to_rod);
};

#endif // MAINWINDOW_H
