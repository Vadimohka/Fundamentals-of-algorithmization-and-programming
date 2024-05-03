#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_solveButton_clicked();

private:
    Ui::MainWindow *ui;
    QString& hanoi(int n, char fromTower, char additionalTower, char toTower, QString& solution);
    long long _steps = 0;
    QString _solution;
};
#endif // MAINWINDOW_H
