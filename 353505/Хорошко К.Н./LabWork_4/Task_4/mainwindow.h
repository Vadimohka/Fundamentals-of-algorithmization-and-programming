#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "vector.h"
#include "pair.h"
#include <QMessageBox>
#include <QHeaderView>

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

private:
    Ui::MainWindow *ui;
    QTableWidget *tableWidget;
    Vector<pair<Vector<int>, Vector<pair<int, double>>>> data;

    void setupUi();

    void displayMatrices();

    void fillData();
};
#endif // MAINWINDOW_H
