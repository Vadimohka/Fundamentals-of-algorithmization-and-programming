#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>

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

private:
    int accuracy, ans;
    double numb;
    QString sAnsInt = "", sAnsDbl = "";
    QString sNumb, sAccuracy;
    Ui::MainWindow *ui;
    QString funcAns(double num, int acc);
    void findIntPart(int num, QString& sAnsInt);
    void findDblPart(double num, const int& acc, QString& sAnsDbl);
};
#endif // MAINWINDOW_H
