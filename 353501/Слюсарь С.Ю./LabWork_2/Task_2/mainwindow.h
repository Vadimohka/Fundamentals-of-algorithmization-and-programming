#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

#include"car.h"

#include <QFile>
#include <QTextStream>
#include <QLineEdit>

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

    void ExtractData();
    void DisplayData();
    void UpdateComboBox();

    void Search();

private slots:
    void on_ButtonAdd_clicked();
    void on_comfirmAdd_clicked();

    void on_confirmDelete_clicked();
    void on_ButtonDelete_clicked();

    void on_BoxMarks_activated(int index);
    void on_BoxEngine_activated(int index);

    void on_ButtonReset_clicked();

    void on_ApplyCost_clicked();
    void on_ApplyGas_clicked();
    void on_ApplyReliability_clicked();
    void on_ApplyComfort_clicked();



    void on_ButtonSearch_clicked();

private:
    Ui::MainWindow *ui;

    QWidget *AddWidget;
    QLineEdit *AddMark;
    QLineEdit *AddModel;
    QLineEdit *AddPrice;
    QLineEdit *AddCountry;
    QLineEdit *AddEngine;
    QLineEdit *AddGasoline;
    QLineEdit *AddReliability;
    QLineEdit *AddComfort;

    QWidget *DeleteWidget;
    QLineEdit *DeleteNumber;

    QString path = "../Task_2/test.txt";

    QString Pr_engine;
    QString Pr_mark;
    int Pr_price;
    int Pr_gas;
    int Pr_comf;
    int Pr_rel;

    int total_cars = 0;
    QVector<Car> Cars;
    QVector<QString> CurrEngines;
    QVector<QString> CurrMarks;
};
#endif // MAINWINDOW_H
