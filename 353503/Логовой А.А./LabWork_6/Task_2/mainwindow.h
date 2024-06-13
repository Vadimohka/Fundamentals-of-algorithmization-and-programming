#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<airport.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QVector<long int> array;

    void wtriteToFile();

    void readFromFile();

    QVector<Airport> airports;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
