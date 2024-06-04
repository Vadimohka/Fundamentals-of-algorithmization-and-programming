#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_convertButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    //QPushButton *convertButton;
    QString decimalToBinary(double number);
    QString decimalPartToBinary(double decimalPart);
};

#endif // MAINWINDOW_H
