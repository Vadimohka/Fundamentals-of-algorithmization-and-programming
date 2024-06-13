#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <algorithm>
#include "dish.h"
#include "order.h"
#include "filestream.h"

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
    void on_openButton_clicked();

    void on_saveButton_clicked();

    void on_addDishButton_clicked();

    void on_addOrderButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_buttonBox_2_rejected();

    void on_buttonBox_2_accepted();

    void on_deleteDishButton_clicked();

    void on_deleteOrderButton_clicked();

    void on_changedishButton_clicked();

    void on_changeOrderButton_clicked();

    void on_pushButton_clicked();

    void on_sortingMenu_clicked();



private:
    Ui::MainWindow *ui;

    void setUpTables();

    void fillTables();

    QVector<Dish*>menu;

    QVector<Order*>orders;

    QString filename = "/home/lidskae/Lab2_task2/menu.txt";

    FileStream fileManager;

    QSet<int>tables;

    int change;

    void getTablesList();

    void getPopularDishes();
};
#endif // MAINWINDOW_H
