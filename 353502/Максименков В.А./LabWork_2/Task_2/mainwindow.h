#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "pricelist.h"
#include "listoforders.h"

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
    void on_showPriceButton_clicked();

    void on_addingPriceButton_clicked();

    void on_priceHideButton_clicked();

    void on_priceCorrectButton_clicked();

    void on_priceDeleteButton_clicked();

    void on_showOrderButton_clicked();

    void on_addingOrderButton_clicked();

    void on_addGoodsButton_clicked();

    void on_formingButton_clicked();

    void on_orderHideButton_clicked();

    void on_priceFileAddingButton_clicked();

    void on_orderFileAddingButton_clicked();

    void on_orderCorrectButton_clicked();

    void on_orderDeleteButton_clicked();

    void on_priceFileWritingButton_clicked();

    void on_orderFileWriteButton_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    PriceList priceList;
    ListOfOrders listOfOrders;

    void showPriceList();
    void showOrderList();
    void showForm();
};
#endif // MAINWINDOW_H
