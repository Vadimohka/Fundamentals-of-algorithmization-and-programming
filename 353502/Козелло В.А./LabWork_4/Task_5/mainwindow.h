#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "../../Task_4/Task_4/myvector.h"
#include "pair.h"
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void updateTable();

private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_pushBack_button_clicked();
    void on_popBack_button_clicked();
    void on_emplace_button_clicked();
    void on_erase_button_clicked();

private:
    Ui::MainWindow *ui;
    Pair<MyVector<int>, MyVector<Pair<int, double>>> matrix;
    int table{0};
};
#endif // MAINWINDOW_H
