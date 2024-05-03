#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QRandomGenerator>
#include <QFileDialog>
#include <QDataStream>
#include <QTextStream>
#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QFile>
#include <QMap>
#include "restarauntmenu.h"
#include "errormenu.h"
#include "order.h"
#include "nichevo.h"
#include "ura.h"


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
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButtonSortByPriceUp_clicked();
    void on_pushButtonSortByPriceDown_clicked();
    void on_pushButtonDeleteOrder_clicked();

    void on_pushButtonRead_clicked();

    void on_pushButtonWrite_clicked();

private:
    Ui::MainWindow *ui;
    long long Lines = 0;
    QVector < Order > Orders;
    QVector < QString > dishesName;
    QMap < QString , long long > dishesPrice;
    QMap < QString , long long > dishesAmmount;

private:
    void setDishes();
    void setTable();
    long long QSToLong( QString number );

private:

    void ErrorMessage();
    void sortByPrice();
    void reversOrders();

};
#endif // MAINWINDOW_H
