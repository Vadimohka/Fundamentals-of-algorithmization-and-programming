#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QDataStream>

#include "motorbike.h"

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
    void on_lineEditTask1_editingFinished();

    void on_spinBoxSize_valueChanged(int arg1);

    void on_pushButtonAddNember_clicked();

    void on_pushButtonAddBike_clicked();

    void on_lineEditTask4_editingFinished();

    void on_comboBox_currentIndexChanged(int index);

private:
    long int *array  = new long int[1];;
    int size = 0;
    int trueSize = 1;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
