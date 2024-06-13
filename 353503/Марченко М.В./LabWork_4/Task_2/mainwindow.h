#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QIntValidator>
#include <QMainWindow>
#include <QMessageBox>
#include <QRandomGenerator>
#include "sort.h"

const int LEFT_BORDER = 0;
const int RIGHT_BORDER = 999;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButtonRand_clicked();
    void on_ClearButton_clicked();
    void on_SortButton_clicked();
    void on_binsearch_clicked();
    void on_binpow_clicked();

private:
    Ui::MainWindow *ui;
    Sort *sorter;
    QIntValidator validator;
    QVector<int> inputArr;
    QRandomGenerator *random;
    bool isRandomPressed;
    int countSortings{0};
    bool isSorting;
    bool isSorted;
};
#endif // MAINWINDOW_H
