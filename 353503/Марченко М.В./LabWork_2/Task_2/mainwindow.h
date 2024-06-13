#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QFile>
#include <QDate>
#include <vector>
#include <QFileDialog>
#include <QTextStream>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct OrderItem {
    QString name;
    QString code;
    int amount;
};

struct Order {
    unsigned int number;
    QString date;
    QString customer;
    QVector<OrderItem> items;
};
struct product
{
    QString code1;
    QString name;
    unsigned int price;
};
struct order
{
    unsigned int number;
    QString date;
    QString customer;
    QString code2;
    unsigned int amount;
};

void qsortPrice(product *obj,int first,int last);
void qsortNumber(order *obj,int first,int last);

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void AddButton_clicked();
    void AddButton_1_clicked();
    void File1OpenButton_clicked();
    void File2OpenButton_clicked();
    void onItemClicked();
    void onItemClicked_1();
    void SortByPriceButton_clicked();
    void SortByNumberButton_clicked();
    void NakladButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
