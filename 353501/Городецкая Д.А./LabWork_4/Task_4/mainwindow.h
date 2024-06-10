
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include "vector.h"
#include "vector.cpp"

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
    Vector<int> vec;
    void showVector();
    void createVector();
    QTimer* timer;


private slots:
    void on_ErasepushButton_clicked();

    void on_max_sizepushButton_5_clicked();

    void on_pop_backpushButton_9_clicked();

    void on_push_backpushButton_13_clicked();

    void on_capacitypushButton_14_clicked();

    void on_emptypushButton_15_clicked();

    void on_datapushButton_12_clicked();

    void on_sizepushButton_10_clicked();

    void on_ResizepushButton_6_clicked();

    void on_AtpushButton_3_clicked();

    void on_RevercepushButton_2_clicked();

    void on_pushButton_clicked();

    void on_ClearpushButton_7_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
