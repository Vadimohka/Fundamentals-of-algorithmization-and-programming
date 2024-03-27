#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "product.h"

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
    void onAddProductButtonClicked();
    void writeToFile();

private:
    Ui::MainWindow *ui;
    QList<Product> products;
    double total = 0;

    void updateTable(const QList<Product> &products);
    void countPrice(const QList<Product> &products, double &total);
};

#endif // MAINWINDOW_H
